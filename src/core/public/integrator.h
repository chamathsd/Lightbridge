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
    SamplerIntegrator(std::shared_ptr<const Camera> camera,
        std::shared_ptr<Sampler> sampler)
        : camera(camera), sampler(sampler) {}
protected:
    std::shared_ptr<const Camera> camera;
private:
    std::shared_ptr<Sampler> sampler;
};

} // namespace lightbridge
