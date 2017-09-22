#include "mouse_move_event.hpp"

namespace engine {

MouseMoveEvent::MouseMoveEvent(sf::Event& event)
  : Event {EventType::MouseMove}
  , x {event.mouseMove.x}
  , y {event.mouseMove.y}
{

}

}
