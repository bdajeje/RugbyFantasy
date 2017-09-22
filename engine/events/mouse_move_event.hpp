#ifndef MOUSE_MOVE_EVENT_HPP
#define MOUSE_MOVE_EVENT_HPP

#include <SFML/Window/Event.hpp>

#include <engine/events/event.hpp>

namespace engine {

class MouseMoveEvent final : public Event
{
  public:

    MouseMoveEvent(sf::Event& event);

  public:

    int x;
    int y;
};

using MouseMoveEventSP = std::shared_ptr<MouseMoveEvent>;

}

#endif // MOUSE_MOVE_EVENT_HPP
