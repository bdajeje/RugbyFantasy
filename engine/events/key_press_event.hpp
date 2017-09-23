#ifndef KEY_PRESS_EVENT_HPP
#define KEY_PRESS_EVENT_HPP

#include <SFML/Window/Event.hpp>

#include <engine/events/event.hpp>

namespace engine {

class KeyPressEvent final : public Event
{
  public:

    KeyPressEvent();
};

using KeyPressEventSP = std::shared_ptr<KeyPressEvent>;

}

#endif // KEY_PRESS_EVENT_HPP
