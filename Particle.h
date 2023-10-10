#ifndef PARTICLE_SIMULATION_PARTICLE_H
#define PARTICLE_SIMULATION_PARTICLE_H

#include <math.h>
#include <random>
#define M_PI 3.14159265358979323846 /* pi */

namespace ps
{

    class Particle
    {
    public:
        double m_x_cord;
        double m_y_cord;

    public:
        Particle();
        virtual ~Particle(){};
        void move_particle(int);

    private:
        double m_x_vector;
        double m_y_vector;
        double m_speed;
        double m_direction;

    private:
        void initialize();
    };

} /* namespace ps */

#endif // PARTICLE_SIMULATION_PARTICLE_H