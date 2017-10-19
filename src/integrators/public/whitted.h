#pragma once

#include "integrator.h"

namespace lightbridge
{
/**
* @class WhittedIntegrator
*
* An integrator which implements the Whitted ray-tracing
* algorithm.
*/
class WhittedIntegrator : public SamplerIntegrator
{
public:
    /**
    * WhitedIntegrator constructor
    *
    * @param maxDepth Depth at which recursion should be terminated
    * @param camera Camera from which the scene is rendered.
    * @param sampler Sampler from which the integrator should stream samples.
    */
    WhittedIntegrator(int maxDepth, std::shared_ptr<const Camera> camera,
        std::shared_ptr<Sampler> sampler)
        : SamplerIntegrator(camera, sampler), maxDepth(maxDepth) {}
private:
    // TODO: Add WhittedIntegrator private methods
};

} // namespace lightbridge