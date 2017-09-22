#ifndef MOUSE_SCENE_HPP
#define MOUSE_SCENE_HPP

#include <engine/models/scene.hpp>
#include <engine/graphics/sprite.hpp>
#include <engine/events/event_subscriber.hpp>

namespace engine {

class MouseScene : public model::Scene
                 , public EventSubscriber
{
  public:

    MouseScene(const std::string& mouse_sprite_filepath);

    void start() override;

  private:

    bool updateMousePosition(const EventSP& event);

  private:

    SpriteSP _mouse_sprite;
};

}

#endif // MOUSE_SCENE_HPP
