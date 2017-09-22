#include "window.hpp"

namespace engine {

std::unique_ptr<Window> Window::_instance;

std::unique_ptr<Window>& Window::init(const sf::String &title, sf::Uint32 style, const sf::ContextSettings &settings)
{
  _instance.reset(new Window{title, style, settings});
  return _instance;
}

Window::Window(const sf::String& title, sf::Uint32 style, const sf::ContextSettings& settings)
  : sf::RenderWindow{{1000, 1000}, title, style, settings}
{
  setFramerateLimit(60);
  setMouseCursorVisible(false);
}

}
