#include "scene.hpp"

#include <engine/window.hpp>

namespace engine {
namespace model {

std::map<EmittingSceneAction, std::map<ReceivingScene, SceneEventCallback>> Scene::s_scene_events;
std::map<ReceivingScene, std::set<EmittingSceneAction>> Scene::s_registered_scenes;

Scene::Scene(std::string name, float width, float height)
  : _name {name}
  , _base_pos {0, 0}
{
  if(width == 0 && height == 0)
    _size = sf::Vector2f{static_cast<float>(Window::width()), static_cast<float>(Window::height())};
  else
    _size = sf::Vector2f{width, height};
}

Scene::~Scene()
{
  unregisterSceneEvents();
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

void Scene::unregisterSceneEvents()
{
  auto found = s_registered_scenes.find(_name);
  if(found == s_registered_scenes.end())
    return;

  const auto& scene_actions = found->second;
  for(const auto& emitting_scene_action : scene_actions)
  {
    auto scene_event_it = s_scene_events.find(emitting_scene_action);
    if(scene_event_it == s_scene_events.end())
      continue;

    std::map<ReceivingScene, SceneEventCallback>& nani = scene_event_it->second;
    nani.erase(nani.find(_name));
  }
}

void Scene::registerSceneEvent(EmittingScene from, SceneAction action, SceneEventCallback func)
{
  EmittingSceneAction scene_action = from + action;
  s_registered_scenes[_name].insert(scene_action);
  s_scene_events[scene_action].emplace(_name, func);
}

void Scene::emitSceneEvent(SceneAction action, const json& data)
{
  // Try to find if other scenes have subscribed to this action
  auto found = s_scene_events.find(_name + action);
  if(found == s_scene_events.end())
    return;

  // Execute registered callbacks for this action
  const auto& registrations = found->second;
  for(const auto& registration : registrations)
    registration.second(data);
}

}
}
