#include "integrator.h"
#include <algorithm>

void SamplerIntegrator::Render(const Scene &scene)
{
    Preprocess(scene, *sampler);

    // Determine number of tiles to use for parallel rendering
    Bounds2i sampleBounds = camera->film->GetSampleBounds();
    Vector2i sampleExtent = sampleBounds.Diagonal();
    const int tileSize = 16;  // TODO: make tile size modifiable
    Point2i numTiles((sampleExtent.x + tileSize - 1) / tileSize,
                      sampleExtent.y + tileSize - 1) / tileSize);
    
    // Iterate over tiles in parallel fashion
    ParallelFor2D([&](Point2i tile) {
        MemAllocator allocator;

        // Ensure unique pseudo-random numbers per tile
        int seed = tile.y * numTiles.x + tile.x;
        std::unique_ptr<Sampler> tileSampler = sampler->Clone(seed);

        // Tile bounds - clip to edge of sample
        int xMin = sampleBounds.pMin.x + tile.x * tileSize;
        int xMax = std::min(xMin + tileSize, sampleBounds.pMax.x);
        int yMin = sampleBounds.pMin.y + tile.y * tileSize;
        int yMax = std::min(yMin + tileSize, sampleBounds.pMax.y);
        Bounds2i tileBounds(Point2i(xMin, yMin), Point2i(xMax, yMax));

        // Reserve temporary memory for this tile
        std::unique_ptr<FilmTile> filmTile = camera->film->GetFilmTile(tileBounds);

        // Loop through pixels in tile, begin sampling
        for (Point2i pixel : tileBounds)
        {
            tileSampler->StartPixel(pixel);
            do
            {
                CameraSample cameraSample = tileSampler->GetCameraSample(pixel);
                
                // Spawn camera ray for current sample
                RayDifferential ray;
                Float rayWeight = camera->GenerateRayDifferential(cameraSample, &ray);
                ray.ScaleDifferentials(1 / std::sqrt(tileSampler->samplesPerPixel));

                // Radiance evaluation 
                Spectrum L(0.f);
                if (rayWeight > 0)
                {
                    L = Li(ray, scene, *tileSampler, allocator);
                }
                // TODO: handle bad radiance values

                // TODO: add camera ray's contribution to image
                // TODO: Free MemAllocator memory from computing image sample value
            }
            while (tileSampler->NextSample());
        }
        // TODO: merge image tile into Film
    }, numTiles);

    // TODO: save final image
}
