#ifndef SCENE_HPP
#define SCENE_HPP

#include <list>
#include <map>
#include <string>
#include <functional>
#include <set>

#include <engine/drawable.hpp>
#include <engine/updatable.hpp>
#include <utils/json.hpp>

namespace engine {
namespace model {

using SceneEventCallback = std::function<void(const json& data)>;

namespace {

  // Some aliases to better understand following code
  using EmittingScene       = std::string;
  using EmittingSceneAction = std::string;
  using SceneAction         = std::string;
  using ReceivingScene      = std::string;

  struct SceneEventRegistration
  {
    SceneEventRegistration(EmittingScene emitter, SceneAction action)
      : emitter {emitter}
      , action {action}
    {}

    EmittingScene emitter;
    SceneAction action;
  };

}

class Scene : public engine::Drawable
{
  public:

    Scene(std::string name, float width = 0.f, float height = 0.f);
    virtual ~Scene();

    void addDrawable(DrawableSP drawable);
    void addUpdatable(engine::UpdatableSP updatable);

    virtual sf::Vector2f getSize() const noexcept override { return _size; }
    virtual const sf::Vector2f& getPosition() const noexcept override { return _base_pos; }

    virtual void setPosition(sf::Vector2f pos) override;
    virtual void move(float x, float y) override;
    virtual void update(const sf::Time& time);
    virtual void start() {}

  private:

    void unregisterSceneEvents();

  protected:

    virtual void internalDraw(sf::RenderTarget& target, sf::RenderStates states) const noexcept;        
    void registerSceneEvent(EmittingScene from, SceneAction action, SceneEventCallback func);
    void emitSceneEvent(SceneAction action, const json& data);

  private:

    std::string _name;
    std::list<engine::DrawableSP> _drawables;
    std::list<engine::UpdatableSP> _updatables;
    sf::Vector2f _size;
    sf::Vector2f _base_pos;

    /*!
     * First map of scene name to map of scene action to triggers callbacks
     */
    static std::map<EmittingSceneAction, std::map<ReceivingScene, SceneEventCallback>> s_scene_events;

    static std::map<ReceivingScene, std::set<EmittingSceneAction>> s_registered_scenes;
};

using SceneSP = std::shared_ptr<Scene>;

}
}

#endif // SCENE_HPP
