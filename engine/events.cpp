#include "events.hpp"

namespace engine {

std::unique_ptr<Events> Events::_instance;

void Events::init()
{
  _instance.reset( new Events );
}

void Events::subscribe(EventSubscriberSP subscriber, engine::EventType type, EventCallback func)
{
  _instance->_registrations[type].emplace_back(subscriber, func);
}

void Events::dispatch(const EventSP& event)
{
  auto found = _instance->_registrations.find(event->type());

  if(found == _instance->_registrations.end())
    return;

  const auto& registrations = found->second;
  for(const EventRegistration& registration : registrations)
  {
    // First encountered registration to return false, we stop propagating the event
    if(!registration.func(event))
      return;
  }
}

void Events::unsubscribe(EventSubscriberSP subscriber)
{
  for(auto registration_it : _instance->_registrations)
  {
    std::list<EventRegistration>& registrations = registration_it.second;
    for(std::list<EventRegistration>::iterator it = registrations.begin(), end = registrations.end(); it != end;)
    {
      if((*it).subscriber == subscriber)
        registrations.erase(it++);
      else
        ++it;
    }
  }
}

}
