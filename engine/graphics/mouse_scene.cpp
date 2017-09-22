#include "mouse_scene.hpp"

#include <functional>

#include <engine/events/mouse_move_event.hpp>

namespace engine {

MouseScene::MouseScene(const std::string& mouse_sprite_filepath)
  : Scene {"Mouse"}
  , _mouse_sprite {getSprite(mouse_sprite_filepath, 25, 25)}
{
  addDrawable(_mouse_sprite);
}

bool MouseScene::updateMousePosition(const EventSP& event)
{
  MouseMoveEventSP mouse_move_event = std::dynamic_pointer_cast<MouseMoveEvent>(event);

  _mouse_sprite->setPosition(sf::Vector2f{
                               static_cast<float>(mouse_move_event->x),
                               static_cast<float>(mouse_move_event->y)
                             });
  return true;
}

void MouseScene::start()
{
  using namespace std::placeholders;
  subscribe(engine::EventType::MouseMove, std::bind(&MouseScene::updateMousePosition, this, _1));
}

}
