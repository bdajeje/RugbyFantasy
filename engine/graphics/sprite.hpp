#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <memory>

#include <SFML/Graphics/Sprite.hpp>

#include <engine/drawable.hpp>

namespace engine {

class Sprite : public Drawable
             , public std::enable_shared_from_this<Sprite>
{
  public:

    Sprite(float width, float height);
    virtual ~Sprite() = default;

    /*! Replace sprite current texture
     *  \param texture - to set
     *  \param width - ovewrite scaling with given value
     *  \param height - ovewrite scaling with given value
     */
    void setTexture(const sf::Texture& texture, bool resetRect = false);
    void setTextureRect(const sf::IntRect& rectangle);

    void verticalFlip();
    void horizontalFlip();

    virtual const sf::Vector2f& getSize() const noexcept override { return _size; }
    virtual void setPosition(sf::Vector2f pos) override { _sprite->setPosition(pos); }
    virtual void move(float x, float y) override { _sprite->move(x, y); }

  protected:

    virtual void internalDraw(sf::RenderTarget& target, sf::RenderStates states) const noexcept override;

  protected:

    std::shared_ptr<sf::Sprite> _sprite;
    sf::Vector2f _size;
};

using SpriteSP = std::shared_ptr<Sprite>;

SpriteSP getSprite(const std::string& texture_file_path, float width, float height);
SpriteSP getSprite(const sf::Texture& texture, float width, float height);

}

#endif // SPRITE_HPP
