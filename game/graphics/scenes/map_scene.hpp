#ifndef MAP_SCENE_HPP
#define MAP_SCENE_HPP

#include <engine/models/scene.hpp>

namespace game {

class MapScene final : public engine::model::Scene
{
  public:

    MapScene();

  private:

    void createBackground();
};

}

#endif // MAP_SCENE_HPP
