#include "Application.hpp"

#include <iostream>

Application::Application() { init(); }

void Application::init()
{
    m_window.create(sf::VideoMode(1920, 1080), "Particle System");
    m_window.setFramerateLimit(60);

    m_particles.init(m_window.getSize());

    if (const std::string path = "assets/fonts/Nightclub.otf"; !m_font.loadFromFile(path))
    {
        std::cerr << "Could not load from file: " << path << "\n";
        std::exit(-1);
    }
}

void Application::update()
{
    sUserInput();
    sRender();
    m_currentFrames++;
}

void Application::sRender()
{
    // color the background darker so you know that the game is paused
    m_window.clear(sf::Color(50, 50, 150));

    // Update the particle system
    m_particles.update();

    // Clear the window or you'll get lines effect
    m_window.clear(sf::Color::Black);

    // Draw the particles
    m_particles.draw(m_window);

    const auto text = getText("R:\t\t\trestart\nEsc:\tquit\n\nmouse button:\tfun");
    m_window.draw(text);

    m_window.display();
}

void Application::sUserInput()
{
    sf::Event event{};
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) { quit(); }
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape) { quit(); }
            if (event.key.code == sf::Keyboard::R) { m_particles.resetParticles(); }
        }

        const auto mousePos = sf::Mouse::getPosition(m_window);
        sf::Vector2i pos = (m_mouseToggle) ? sf::Vector2i(mousePos.x, mousePos.y) : sf::Vector2i(0, 0);

        if (event.type == sf::Event::MouseButtonPressed)
        {
            switch (event.mouseButton.button)
            {
                case sf::Mouse::Left:
                    m_mouseToggle = !m_mouseToggle;
                    break;
                case sf::Mouse::Right:
                    m_mouseToggle = false;
                    pos = sf::Vector2i(
                        static_cast<int>(m_window.getSize().x) / 2,
                        static_cast<int>(m_window.getSize().y) / 2
                        );
                    break;
                default:
                    std::cout << "Debug \n";
                    break;
            }
        }
        m_particles.setEmitter(pos);
    }
}

bool Application::isRunning() const { return m_running && m_window.isOpen(); }

void Application::quit() { m_running = false; }

void Application::run()
{
    while (isRunning())
    {
        update();
    }
}

sf::Text Application::getText(const std::string& textMessage) const
{
    sf::Text text(textMessage, m_font, 20);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(50, 30));
    return text;
}
