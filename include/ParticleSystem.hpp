#ifndef PARTICLESYSTEM_HPP
#define PARTICLESYSTEM_HPP

#include <vector>

#include <SFML/Graphics.hpp>

class ParticleSystem
{
    struct Particle;

public:
    ParticleSystem() = default;

    void init(sf::Vector2u windowSize);
    void update();
    void draw(sf::RenderWindow& window) const;
    void resetParticles(size_t count = 1024, float size = 8.0f);
    void setEmitter(sf::Vector2i pos = sf::Vector2i(0, 0));

    /**
     * Quad is:
     *       0  ---------  1
     *          |       |
     *          |       |
     *       3  ---------  2
     */
    void resetParticle(size_t index, bool first = false);

private:
    struct Particle
    {
        sf::Vector2f velocity;
        int lifetime = 0;
        float speed = 0.0f;
    };

    std::vector<Particle> m_particles;
    sf::VertexArray m_vertices;
    sf::Vector2u m_windowSize;
    sf::Vector2i m_emittor;
    float m_size = 8.0f;
};

#endif //PARTICLESYSTEM_HPP
