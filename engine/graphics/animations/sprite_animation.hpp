#ifndef SPRITE_ANIMATION_HPP
#define SPRITE_ANIMATION_HPP

#include <engine/graphics/sprite.hpp>
#include <engine/graphics/animation.hpp>
#include <utils/json.hpp>

namespace engine {

class SpriteAnimation final : public Animation
{
  public:

    SpriteAnimation(SpriteSP sprite, const json& data);

    void setFrameRate(uint value) noexcept { _refresh_rate_ms = value; }
    size_t steps() const noexcept { return _nbr_elements; }

    void restart();

    virtual void update(const sf::Time& time) override;

  protected:

    void updateSprite();

  private:

    SpriteSP _sprite;
    size_t _nbr_elements;
    unsigned int _refresh_rate_ms;
    unsigned int _total_width;
    unsigned int _elapsed_time {0};
    bool _repeat;
};

using SpriteAnimationSP = std::shared_ptr<SpriteAnimation>;

}

#endif // SPRITE_ANIMATION_HPP
