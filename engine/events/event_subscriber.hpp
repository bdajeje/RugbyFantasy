#ifndef EVENT_SUBSCRIBER_HPP
#define EVENT_SUBSCRIBER_HPP

#include <memory>

#include <SFML/Window/Event.hpp>

#include <engine/events/event_types.hpp>
#include <engine/events/event.hpp>

namespace engine {

class EventSubscriber;
using EventSubscriberSP = std::shared_ptr<EventSubscriber>;
using EventCallback = std::function<bool(const EventSP& event)>;

class EventSubscriber : public std::enable_shared_from_this<EventSubscriber>
{
  public:

    EventSubscriber() = default;
    virtual ~EventSubscriber();

    void subscribe(engine::EventType type, EventCallback func);
};

}

#endif // EVENT_SUBSCRIBER_HPP
