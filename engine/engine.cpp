#include "engine.hpp"

#include <engine/window.hpp>
#include <engine/events.hpp>
#include <engine/resources/textures_cache.hpp>
#include <engine/resources/font_cache.hpp>
#include <engine/graphics/mouse_scene.hpp>
#include <game/game.hpp>
#include <game/graphics/scenes/map_scene.hpp>
#include <game/graphics/scenes/map_ui_scene.hpp>
#include <game/models/players/human_player.hpp>
#include <game/models/players/ai_player.hpp>
#include <utils/timer.hpp>
#include <utils/key_limitor.hpp>

namespace engine {

Engine::Engine(int /*argc*/, char** /*argv*/)
{
  textures::TexturesCache::init("./assets/sprites");
  fonts::FontCache::init("./assets/fonts");
  Window::init("Rugby Fantasy");
  Events::init();
}

int Engine::start()
{
  utils::KeyLimitor::init(100);

  // \todo temporary tests, this MUST go outside of engine, this is related to the game not the engine.
  {
    game::Game::startNewGame(std::make_shared<game::HumanPlayer>("The Nani's"), std::make_shared<game::AIPlayer>("Berserkers"));
    auto map_scene   = std::make_shared<game::MapScene>();
    auto map_ui_scene= std::make_shared<game::MapUIScene>();
    auto mouse_scene = std::make_shared<engine::MouseScene>("mouse.png");

    _scenes.push_back(map_scene);
    _scenes.push_back(map_ui_scene);
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
    sf::Event sf_event;
    while(window->pollEvent(sf_event))
    {
      // Close program
      if( sf_event.type == sf::Event::Closed )
        return 0;

      EventSP event = Events::createEvent(sf_event);
      if(event)
        Events::dispatch(event);
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
