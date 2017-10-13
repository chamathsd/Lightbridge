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

        // Sample bounds
        int xMin = sampleBounds.pMin.x + tile.x * tileSize;
        int xMax = std::min(xMin + tileSize, sampleBounds.pMax.x);

        // TODO: loop over pixels in tile to render them
        // TODO: merge image tile into Film
    }, numTiles);

    // TODO: save final image
}
