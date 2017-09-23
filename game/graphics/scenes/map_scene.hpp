#ifndef MAP_SCENE_HPP
#define MAP_SCENE_HPP

#include <engine/models/scene.hpp>
#include <engine/events/event.hpp>
#include <engine/events/event_subscriber.hpp>

namespace game {

class MapScene final : public engine::model::Scene
                     , public engine::EventSubscriber
{
  public:

    MapScene();

    void start();

  private:

    void createBackground();
    bool keyPressed(const engine::EventSP& /*event*/);
    void scrollUp();
    void scrollDown();

  private:

    float _background_height {0};
};

}

#endif // MAP_SCENE_HPP
