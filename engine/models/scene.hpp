#ifndef SCENE_HPP
#define SCENE_HPP

#include <list>
#include <string>

#include <engine/drawable.hpp>
#include <engine/updatable.hpp>

namespace engine {
namespace model {

class Scene : public engine::Drawable
{
  public:

    Scene(std::string name);
    virtual ~Scene() = default;

    void addDrawable(DrawableSP drawable);
    void addUpdatable(engine::UpdatableSP updatable);

    virtual const sf::Vector2f& getSize() const noexcept override { return _size; }
    virtual void setPosition(sf::Vector2f pos) override;
    virtual void move(float x, float y) override;
    virtual void update(const sf::Time& time);
    virtual void start() {}

  protected:

    virtual void internalDraw(sf::RenderTarget& target, sf::RenderStates states) const noexcept;

  private:

    std::string _name;
    std::list<engine::DrawableSP> _drawables;
    std::list<engine::UpdatableSP> _updatables;
    sf::Vector2f _size;
    sf::Vector2f _base_pos;
};

using SceneSP = std::shared_ptr<Scene>;

}
}

#endif // SCENE_HPP
