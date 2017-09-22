#include "scene.hpp"

#include <engine/window.hpp>

namespace engine {
namespace model {

Scene::Scene(std::string name)
  : _name {name}
  , _size {static_cast<float>(Window::width()), static_cast<float>(Window::height())}
  , _base_pos {0, 0}
{

}

void Scene::internalDraw(sf::RenderTarget& target, sf::RenderStates states) const noexcept
{
  for(const auto& drawable : _drawables)
    drawable->draw(target, states);
}

void Scene::addUpdatable(engine::UpdatableSP updatable)
{
  _updatables.push_back(updatable);
}

void Scene::addDrawable(engine::DrawableSP drawable)
{
  _drawables.push_back(drawable);
}

void Scene::setPosition(sf::Vector2f pos)
{
  float x_diff = pos.x - _base_pos.x;
  float y_diff = pos.y - _base_pos.y;
  _base_pos = pos;

  for(auto& drawable : _drawables)
    drawable->move(x_diff, y_diff);
}

void Scene::move(float x, float y)
{
  sf::Vector2f next_pos = _base_pos;
  next_pos.x += x;
  next_pos.y += y;

  setPosition(next_pos);
}

void Scene::update(const sf::Time& time)
{
  for(auto& updatable : _updatables)
    updatable->update(time);
}

}
}
