#include "events.hpp"

#include <engine/events/mouse_move_event.hpp>
#include <engine/events/key_press_event.hpp>

namespace engine {

std::unique_ptr<Events> Events::_instance;

void Events::init()
{
  _instance.reset( new Events );
}

Events::Events()
  : _key_limitor {5}
{}

void Events::subscribe(EventSubscriberSP subscriber, EventType type, EventCallback func)
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

EventSP Events::createEvent(const sf::Event& event)
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wswitch"
  switch(event.type)
  {
    case sf::Event::MouseMoved:
      return std::make_shared<MouseMoveEvent>(event);
    case sf::Event::KeyPressed:
    {
      if(_instance->_key_limitor.isAllowed())
        return std::make_shared<KeyPressEvent>();
    }
  }
#pragma GCC diagnostic pop

  return nullptr;
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
