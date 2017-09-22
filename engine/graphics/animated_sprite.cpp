#include "animated_sprite.hpp"

#include <engine/resources/textures_cache.hpp>
#include <utils/file.hpp>

namespace engine {

AnimatedSprite::AnimatedSprite(const std::string& name, float width, float height)
  : Sprite {width, height}
{  
  const json animation_data = json::parse(utils::files::read("./assets/animated_sprites/" + name + ".json"));
  _data = std::make_shared<AnimatedSpriteData>(animation_data["animation"]);

  const sf::Texture& texture = textures::TexturesCache::get(_data->_texture_file);
  const sf::Vector2u texture_size = texture.getSize();

  setTexture(texture);
  const float texture_element_width = texture_size.x / _data->_nbr_elements;
  const auto _size = getSize();
  _sprite->setScale(sf::Vector2f{_size.x / texture_element_width,
                                 _size.y / texture_size.y});
}

void AnimatedSprite::update(const sf::Time& time)
{
  if(_animation && !_animation->isFinished())
    _animation->update(time);
}

void AnimatedSprite::start()
{
  if(_animation)
    return;

  _animation.reset(new SpriteAnimation(shared_from_this(), _data));
}

}
