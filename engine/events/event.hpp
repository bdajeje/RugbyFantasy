#ifndef EVENT_HPP
#define EVENT_HPP

#include <memory>

#include <engine/events/event_types.hpp>

namespace engine {

class Event
{
  public:

    Event(EventType type);
    virtual ~Event() = default;

    EventType type() const noexcept { return _type; }

  private:

    EventType _type;
};

using EventSP = std::shared_ptr<Event>;

}

#endif // EVENT_HPP
