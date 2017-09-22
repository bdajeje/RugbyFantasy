#include "event_subscriber.hpp"

#include <engine/events.hpp>

namespace engine {

EventSubscriber::~EventSubscriber()
{
  Events::unsubscribe(shared_from_this());
}

void EventSubscriber::subscribe(engine::EventType type, EventCallback func)
{
  Events::subscribe(shared_from_this(), type, func);
}

}
