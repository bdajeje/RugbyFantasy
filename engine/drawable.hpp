#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <memory>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>

namespace engine {

class Drawable : public sf::Drawable
{
  public:

    Drawable() = default;
    virtual ~Drawable() = default;

    void hide() noexcept { _visible = false; }
    void show() noexcept { _visible = true; }
    bool isVisible() const noexcept { return _visible == true; }

    void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const noexcept;

    virtual sf::Vector2f getSize() const noexcept = 0;
    virtual const sf::Vector2f& getPosition() const noexcept = 0;

    virtual void setPosition(sf::Vector2f pos) = 0;
    virtual void move(float x, float y) = 0;

    protected:

      virtual void internalDraw(sf::RenderTarget& target, sf::RenderStates states) const noexcept = 0;

  private:

    bool _visible {true};
};

using DrawableSP = std::shared_ptr<Drawable>;

}

#endif // DRAWABLE_HPP
