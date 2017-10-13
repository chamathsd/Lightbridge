#pragma once

#include <memory>
#include <vector>

namespace lightbridge
{
/**
 * @class Scene
 *
 * The Scene represents the collection of all geometric primitives,
 * their materials, and lights throughout the world.
 */
class Scene
{
public:
    /**
    * Constructor for generating a new scene.
    *
    * @param aggregate The aggregate object which stores pointers to
    *        all other Objects within the scene.
    * @param lights A list of all lights within the scene.
    */
    Scene(std::shared_ptr<Object> aggregate,
        const std::vector<std::shared_ptr<Light>> &lights);


    std::vector<std::shared_ptr<Light>> lights;

    const Bounds3f &SceneBounds() const { return sceneBounds; } ///< Accessor for local scene bounds

private:
    std::shared_ptr<Object> aggregate;
    Bounds3f sceneBounds;

    /**
    * Intersect the given ray through the scene. Populates the
    * SurfaceInteraction structure with information about the
    * earliest object that is intersected.
    *
    * @param ray Ray to intersect.
    * @param isect SurfaceInteraction structure to detail.
    * @return Whether the ray intersects a surface or not.
    */
    bool Intersect(const Ray &ray, SurfaceInteraction *isect);

    /**
    * Checks whether the given ray intersects an object within
    * the scene.
    *
    * @param ray Ray to intersect.
    * @return Whether the ray intersects a surface or not.
    */
    bool IntersectionExists(const Ray &ray);
};

} // namespace lightbridge
