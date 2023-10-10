#ifndef PARTICLE_SIMULATION_SWARM_H
#define PARTICLE_SIMULATION_SWARM_H

#include "Particle.h"

namespace ps
{

    class Swarm
    {
    public:
        // particle count
        const static int N_PARTICLES{3000};

    public:
        Swarm();
        virtual ~Swarm();
        void move(int);
        const Particle *const get_particles();

    private:
        Particle *m_particle_array{nullptr};
        int last_clock;
        int interval;
    };

} /* namespace ps */

#endif // PARTICLE_SIMULATION_SWARM_H