#include "map_scene.hpp"

#include <engine/graphics/animated_sprite.hpp>
#include <engine/window.hpp>
#include <engine/events/key_press_event.hpp>
#include <utils/file.hpp>

namespace game {

namespace {
  constexpr float CAMERA_MOVE = 0.02;
}

MapScene::MapScene()
  : engine::model::Scene{"Map"}
{
  createBackground();
}

void MapScene::createBackground()
{
  _background_height = engine::Window::height() * 1.5;

  engine::AnimatedSpriteSP background = std::make_shared<engine::AnimatedSprite>(
    "map",
    engine::Window::width(),
    _background_height
  );

  addUpdatable(background);
  addDrawable(background);

  background->start();
}

void MapScene::start()
{
  using namespace std::placeholders;
  subscribe(engine::EventType::KeyPress, std::bind(&MapScene::keyPressed, this, _1));
}

bool MapScene::keyPressed(const engine::EventSP& /*event*/)
{
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    scrollUp();
    return false;
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  {
    scrollDown();
    return false;
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
  {
    json data;
    data["phase"] = "NANI?!";
    emitSceneEvent("NextPhase", data);
    return false;
  }

  return true;
}

void MapScene::scrollUp()
{
  float y_pos = getPosition().y;

  if(y_pos >= 0)
    return;

  const int window_height = engine::Window::height();
  float camera_move = window_height * CAMERA_MOVE;
  float final_pos = y_pos + camera_move;

  if(final_pos > 0)
    final_pos = camera_move - final_pos;

  move(0, camera_move);
}

void MapScene::scrollDown()
{
  const int window_height = engine::Window::height();
  float camera_move = window_height * CAMERA_MOVE;
  float final_pos = -getPosition().y + window_height + camera_move;
  float movement = final_pos > _background_height ? _background_height - final_pos : camera_move;

  if(movement > 0)
    move(0, -movement);
}

}
