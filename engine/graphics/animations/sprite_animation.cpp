#include "sprite_animation.hpp"

#include <engine/resources/textures_cache.hpp>

namespace engine {

SpriteAnimation::SpriteAnimation(SpriteSP sprite, const AnimatedSpriteDataSP& data)
  : _sprite {sprite}    
  , _data {data}
  , _texture_step_width {_sprite->getTextureSize().x / _data->_nbr_elements}
{}

void SpriteAnimation::restart()
{
  _finished = false;
  _elapsed_time = 0;
}

void SpriteAnimation::update(const sf::Time& elapsed_time)
{
  if(isFinished() || _data->_nbr_elements <= 1)
    return;

  // Do we need a sprite update
  bool need_update = false;
  if( elapsed_time.asMilliseconds() - _elapsed_time >= _data->_refresh_rate_ms )
    need_update = true;

  _elapsed_time += elapsed_time.asMilliseconds();

  if(need_update)
    updateSprite();
}

void SpriteAnimation::updateSprite()
{
  const unsigned int step_nbr = ceil(_elapsed_time / _data->_refresh_rate_ms);
  int x_offset;

  if(step_nbr == 0)
    x_offset = 0;
  else if(step_nbr < _data->_nbr_elements)
    x_offset = _texture_step_width * step_nbr;
  else
  {
    if(_data->_repeat)
    {
      restart();
      x_offset = 0;
    }
    else
    {
      _finished = true;
      return;
    }
  }

  const auto& bounds = _sprite->getSize();
  _sprite->setTextureRect(sf::IntRect(x_offset, 0, bounds.x, bounds.y));
}

}
