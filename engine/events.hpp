#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <list>
#include <map>
#include <memory>

#include <SFML/Window/Event.hpp>

#include <engine/events/event_subscriber.hpp>
#include <engine/events/event_types.hpp>
#include <engine/events/event.hpp>

namespace engine {

struct EventRegistration {
  EventRegistration(EventSubscriberSP subscriber, EventCallback func)
    : subscriber {subscriber}
    , func {func}
  {}

  EventSubscriberSP subscriber;
  EventCallback func;
};

class Events final
{
  public:

    static void init();
    static void subscribe(EventSubscriberSP subscriber, engine::EventType type, EventCallback func);
    static void unsubscribe(EventSubscriberSP subscriber);
    static void dispatch(const EventSP& event);
    static EventSP createEvent(const sf::Event& event);

  private:

    Events() = default;

  private:

    static std::unique_ptr<Events> _instance;

    std::map<engine::EventType, std::list<EventRegistration>> _registrations;
};

}

#endif // EVENTS_HPP
