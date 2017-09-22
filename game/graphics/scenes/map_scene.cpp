#include "map_scene.hpp"

#include <engine/graphics/animated_sprite.hpp>
#include <engine/window.hpp>
#include <utils/file.hpp>

namespace game {

MapScene::MapScene()
  : engine::model::Scene{"Map"}
{
  createBackground();
}

void MapScene::createBackground()
{
  engine::AnimatedSpriteSP background = std::make_shared<engine::AnimatedSprite>(
    "map",
    engine::Window::width(),
    engine::Window::height() * 1.5
  );

  addUpdatable(background);
  addDrawable(background);

  background->start();
}

}
