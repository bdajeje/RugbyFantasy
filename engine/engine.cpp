#include "engine.hpp"

#include <engine/window.hpp>
#include <engine/events.hpp>
#include <engine/resources/textures_cache.hpp>
#include <engine/graphics/mouse_scene.hpp>
#include <engine/events/mouse_move_event.hpp>
#include <game/graphics/scenes/map_scene.hpp>
#include <utils/timer.hpp>
#include <utils/key_limitor.hpp>

namespace engine {

Engine::Engine(int /*argc*/, char** /*argv*/)
{
  textures::TexturesCache::init("./assets/sprites");
  Window::init("Rugby Fantasy");
  Events::init();
}

int Engine::start()
{
  utils::KeyLimitor::init(100);

  // \todo temporary tests
  {
    auto map_scene   = std::make_shared<game::MapScene>();
    auto mouse_scene = std::make_shared<engine::MouseScene>("mouse.png");

    _scenes.push_back(map_scene);
    _scenes.push_back(mouse_scene);

    for(auto& scene : _scenes)
      scene->start();
  }

  static const sf::Color background_color {0, 0, 0};
  utils::time::Timer timer;

  auto& window = Window::instance();

  while(window->isOpen())
  {
    const sf::Time elapsed_time {timer.restart()};

    // Handle SFML events
    sf::Event event;
    while(window->pollEvent(event))
    {
      // Close program
      if( event.type == sf::Event::Closed )
        return 0;

      Events::dispatch(std::make_shared<MouseMoveEvent>(event));
    }

    // Update sceens
    for(auto& scene : _scenes)
      scene->update(elapsed_time);

    // Draw
    window->clear(background_color);
    for(auto& scene : _scenes)
      window->draw(*scene);
    window->display();
  }

  return 0;
}

}
