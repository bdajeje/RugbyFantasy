#include "sprite.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

#include <engine/resources/textures_cache.hpp>

namespace engine {

Sprite::Sprite(float width, float height)
  : _sprite {std::make_shared<sf::Sprite>()}
  , _size {width, height}
{

}

void Sprite::internalDraw(sf::RenderTarget& target, sf::RenderStates states) const noexcept
{
  target.draw(*_sprite, states);
}

void Sprite::setTexture(const sf::Texture& texture, bool resetRect)
{
  _sprite->setTexture(texture, resetRect);

  if(!resetRect)
  {
    const auto texture_size = texture.getSize();
    _sprite->setScale( _size.x / texture_size.x, _size.y / texture_size.y );
  }
}

void Sprite::setTextureRect(const sf::IntRect& rectangle)
{
  _sprite->setTextureRect(rectangle);
}

void Sprite::verticalFlip()
{
  const auto& bounds = _sprite->getLocalBounds();
  _sprite->setTextureRect(sf::IntRect(0, bounds.height, bounds.width, -bounds.height));
}

void Sprite::horizontalFlip()
{
  const auto& bounds = _sprite->getLocalBounds();
  _sprite->setTextureRect(sf::IntRect(bounds.width, 0, -bounds.width, bounds.height));
}

SpriteSP getSprite(const std::string& texture_file_path, float width, float height)
{
  return getSprite(textures::TexturesCache::get(texture_file_path), width, height);
}

SpriteSP getSprite(const sf::Texture& texture, float width, float height)
{
  auto sprite = std::make_shared<Sprite>(width, height);
  sprite->setTexture(texture, false);
  return sprite;
}

}
