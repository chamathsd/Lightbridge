#pragma once

#include "scene.h"

namespace lightbridge 
{
/**
* @class Integrator
*
* The Integrator is the basic interface from which different
* rendering methods are implemented. All Integrator subclasses
* must provide the Render() method. 
*/
class Integrator
{
public:
    /**
    * Renders the given scene. This method should be implemented by
    * all subclasses of the Integrator class.
    *
    * @param scene Scene to render.
    */
    virtual void Render(const Scene &scene) = 0;
};

/**
* @class SamplerIntegrator
*
* An integrator whose render process is driven by a stream of
* samples from a Sampler object.
*/
class SamplerIntegrator : public Integrator
{
public:
    /**
    * SamplerIntegrator constructor.
    *
    * @param camera The camera from which the scene is rendered.
    * @param sampler Sampler from which the integrator should stream samples.
    */
    SamplerIntegrator(std::shared_ptr<const Camera> camera,
        std::shared_ptr<Sampler> sampler)
        : camera(camera), sampler(sampler) {}

    /**
    * Optional method that will be called after the scene has
    * been completely set up. Can be used by integrators that depend
    * on data within the scene itself.
    *
    * @param scene The scene to render.
    * @param sampler Sampler from which the integrator should stream samples.
    */
    virtual void Preprocess(const Scene &scene, Sampler &sampler) {}
protected:
    std::shared_ptr<const Camera> camera;
private:
    std::shared_ptr<Sampler> sampler;
};

} // namespace lightbridge
