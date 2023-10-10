#include "Particle.h"

namespace ps
{
    Particle::Particle() : m_x_cord(0), m_y_cord(0)
    {
        initialize();
    }

    void Particle::initialize()
    {
        std::random_device rd;
        std::uniform_real_distribution<double> speed_dist(-1, 1);
        std::uniform_real_distribution<double> angle_dist(0, 2 * M_PI);
        m_x_cord = 0, m_y_cord = 0;

        m_speed = pow(speed_dist(rd) * 0.04, 2);

        m_direction = angle_dist(rd);
    }

    void Particle::move_particle(int interval)
    {
        // change the particles direction from a straight line to curved line
        m_direction += (interval * 0.0005);

        // assignning particle vector
        m_x_vector = m_speed * sin(m_direction);
        m_y_vector = m_speed * cos(m_direction);

        // move particle by the vector values
        m_x_cord += (m_x_vector * interval);
        m_y_cord += (m_y_vector * interval);

        // if particles go outside the window
        // reintialise it and yeet the paticle in
        if (m_x_cord < -1 || m_x_cord > 1 || m_y_cord < -1 || m_y_cord > 1)
        {
            initialize();
        }
    }
}