#include "scene.h"

Scene::Scene(std::shared_ptr<Object> aggregate, const std::vector<std::shared_ptr<Light>> &lights)
    : lights(lights), aggregate(aggregate)
{
    // Set up scene bounds based on aggregate
    sceneBounds = aggregate->SceneBounds();

    // Wrap up preprocessing for all lights in the scene
    for (const auto &light : lights)
    {
        light->PreprocessScene(*this);
    }
}

bool Scene::Intersect(const Ray &ray, SurfaceInteraction *isect)
{
    return aggregate->Intersect(ray, isect);
}

bool Scene::IntersectionExists(const Ray &ray)
{
    return aggregate->InteresectionExists(ray);
}
