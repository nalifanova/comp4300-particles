#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "ParticleSystem.hpp"

class Application
{
public:
    Application();
    ~Application() = default;

    bool isRunning() const;
    void quit();
    void run();

protected:
    void init();
    void update();
    void sRender();
    void sUserInput();
    sf::Text getText(const std::string& textMessage) const;

    sf::RenderWindow m_window;
    ParticleSystem m_particles;
    size_t m_simulationSpeed = 1;
    bool m_running = true;
    size_t m_currentFrames = 0;
    sf::Font m_font = sf::Font();
    bool m_mouseToggle = false;
};

#endif //APPLICATION_HPP
