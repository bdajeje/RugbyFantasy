#include "sprite_animation.hpp"

#include <engine/resources/textures_cache.hpp>

namespace engine {

SpriteAnimation::SpriteAnimation(SpriteSP sprite, const json& data)
  : _sprite {sprite}
  , _nbr_elements {data["steps"]}
  , _refresh_rate_ms {data["refresh_rate"]}
  , _repeat {data["repeat"] == 1}
{
  if(_nbr_elements == 0)
    _nbr_elements = 1;

  restart();
}

void SpriteAnimation::restart()
{
  _finished = false;
  _elapsed_time = 0;

//  const sf::Texture& texture = textures::TexturesCache::get(_texture_file);

//  // Set first sprite before even updating
//  _sprite->setTexture(texture, true);
//  const auto bounds = _sprite->getLocalBounds();
//  _total_width = bounds.width;

//  _sprite->setTextureRect(sf::IntRect(0, 0, bounds.width / _nbr_elements, bounds.height));
}

void SpriteAnimation::update(const sf::Time& elapsed_time)
{
  if(isFinished() || _nbr_elements <= 1)
    return;

  // Do we need a sprite update
  bool need_update = false;
  if( elapsed_time.asMilliseconds() - _elapsed_time >= _refresh_rate_ms )
    need_update = true;

  _elapsed_time += elapsed_time.asMilliseconds();

  if(need_update)
    updateSprite();
}

void SpriteAnimation::updateSprite()
{
  const unsigned int step_nbr = ceil(_elapsed_time / _refresh_rate_ms);
  const auto& bounds = _sprite->getSize();
  uint x_offset = step_nbr * bounds.x+ (1 * step_nbr);

  if(x_offset >= _total_width)
  {
    if(_repeat)
    {
      _elapsed_time = 0;
      x_offset = 0;
    }
    else
    {
      _finished = true;
      return;
    }
  }

  _sprite->setTextureRect(sf::IntRect(x_offset, 0, bounds.x, bounds.y));
}

}
