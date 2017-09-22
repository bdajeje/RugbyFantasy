#ifndef SPRITE_ANIMATION_HPP
#define SPRITE_ANIMATION_HPP

#include <engine/graphics/sprite.hpp>
#include <engine/graphics/animation.hpp>
#include <utils/json.hpp>

namespace engine {

struct AnimatedSpriteData
{
  AnimatedSpriteData(const json& data)
    : _nbr_elements {data["steps"]}
    , _refresh_rate_ms {data["refresh_rate"]}
    , _repeat {data["repeat"] == 1}
  {
    if(_nbr_elements == 0)
      _nbr_elements = 1;

    _texture_file = data["sprite"];
  }

  std::string _texture_file;
  size_t _nbr_elements;
  unsigned int _refresh_rate_ms;
  bool _repeat;
};

using AnimatedSpriteDataSP = std::shared_ptr<AnimatedSpriteData>;

class SpriteAnimation final : public Animation
{
  public:

    SpriteAnimation(SpriteSP sprite, const AnimatedSpriteDataSP& data);

    void setFrameRate(uint value) noexcept { _data->_refresh_rate_ms = value; }
    size_t steps() const noexcept { return _data->_nbr_elements; }

    void restart();

    virtual void update(const sf::Time& time) override;

  protected:

    void updateSprite();

  private:

    SpriteSP _sprite;
    AnimatedSpriteDataSP _data;
    unsigned int _elapsed_time {0};
    unsigned int _texture_step_width;
};

using SpriteAnimationSP = std::shared_ptr<SpriteAnimation>;

}

#endif // SPRITE_ANIMATION_HPP
