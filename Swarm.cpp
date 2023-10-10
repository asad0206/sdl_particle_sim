#include "Swarm.h"

namespace ps
{

    Swarm::Swarm() : last_clock(0)
    {
        // defining particle array
        m_particle_array = new Particle[N_PARTICLES];
    }

    Swarm::~Swarm()
    {
        delete[] m_particle_array;
    }

    void Swarm::move(int elapsed)
    {
        // interval b/w last particle position update and current update
        // this is used to enure that the particle movement stays consistent and propotional
        interval = last_clock == 0 ? 0 : elapsed - last_clock;

        last_clock = elapsed;

        // Update all particle positions within the swarm
        for (int i = 0; i < N_PARTICLES; ++i)
            m_particle_array[i].move_particle(interval);
    }

    // return the entire particle array
    const Particle *const Swarm::get_particles()
    {
        return m_particle_array;
    }

}