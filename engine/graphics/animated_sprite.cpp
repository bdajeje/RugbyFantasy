#include "animated_sprite.hpp"

#include <engine/resources/textures_cache.hpp>
#include <engine/graphics/animations/sprite_animation.hpp>
#include <utils/file.hpp>

namespace engine {

AnimatedSprite::AnimatedSprite(const std::string& name, float width, float height)
  : Sprite {width, height}
  , _data {json::parse(utils::files::read("./assets/animated_sprites/" + name + ".json"))}
{
  std::string sprite_name = _data[0]["sprite"];
  _sprite->setTexture(textures::TexturesCache::get(sprite_name));
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

  _animation = std::make_shared<SpriteAnimation>(shared_from_this(), _data[0]["animation"]);
}

}
