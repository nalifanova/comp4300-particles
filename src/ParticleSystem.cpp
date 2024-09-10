#include "ParticleSystem.hpp"

void ParticleSystem::init(const sf::Vector2u windowSize)
{
    m_windowSize = windowSize;

    m_emittor = sf::Vector2i(
        static_cast<int>(m_windowSize.x / 2),
        static_cast<int>(m_windowSize.y / 2)
        );
    resetParticles();
}

void ParticleSystem::update()
{
    // update positions
    for (size_t i = 0; i < m_particles.size(); i++)
    {
        if (m_particles[i].lifetime == 0)
        {
            resetParticle(i);
        }
        else
        {
            m_vertices[4 * i + 0].position += m_particles[i].velocity;
            m_vertices[4 * i + 1].position += m_particles[i].velocity;
            m_vertices[4 * i + 2].position += m_particles[i].velocity;
            m_vertices[4 * i + 3].position += m_particles[i].velocity;

            m_particles[i].lifetime--;
        }
    }
}

void ParticleSystem::draw(sf::RenderWindow& window) const
{
    window.draw(m_vertices);
}

void ParticleSystem::resetParticles(const size_t count, const float size)
{
    m_particles = std::vector<Particle>(count);
    m_vertices = sf::VertexArray(sf::Quads, count * 4);
    m_size = size;

    for (size_t p = 0; p < m_particles.size(); p++)
    {
        resetParticle(p, true); // initial reset particles
    }
}

void ParticleSystem::resetParticle(const size_t index, bool first)
{
    // give the particle an initial position
    const float x = m_emittor.x;
    const float y = m_emittor.y;

    m_vertices[4 * index + 0].position = sf::Vector2f(x, y);
    m_vertices[4 * index + 1].position = sf::Vector2f(x + m_size, y);
    m_vertices[4 * index + 2].position = sf::Vector2f(x + m_size, y + m_size);
    m_vertices[4 * index + 3].position = sf::Vector2f(x, y + m_size);

    // give the particle a color, e.g.: sf::Color(255, 0, 255, 255); <- purple
    sf::Color color(128 + rand() % 128, 55, 55, rand() % 255);

    if (first) { color.a = 0; } // to remove quad view of particles at the beginning

    m_vertices[4 * index + 0].color = color;
    m_vertices[4 * index + 1].color = color;
    m_vertices[4 * index + 2].color = color;
    m_vertices[4 * index + 3].color = color;

    // give the particle a velocity [-5; 5]
    float randomX = (static_cast<float>(rand()) / RAND_MAX) * 10.0f - 5.0f;
    float randomY = (static_cast<float>(rand()) / RAND_MAX) * 10.0f - 5.0f;
    m_particles[index].velocity = sf::Vector2f(randomX, randomY);

    // give the particle a lifespan
    m_particles[index].lifetime = 30 + rand() % 60;
}

void ParticleSystem::setEmitter(const sf::Vector2i pos)
{
    if (pos.x || pos.y) { m_emittor = pos; }
}
