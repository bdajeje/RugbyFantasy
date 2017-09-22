#ifndef ANIMATED_SPRITE_HPP
#define ANIMATED_SPRITE_HPP

#include <memory>

#include <engine/updatable.hpp>
#include <engine/graphics/animation.hpp>
#include <engine/graphics/sprite.hpp>
#include <engine/graphics/animations/sprite_animation.hpp>

#include <utils/json.hpp>

namespace engine {

class AnimatedSprite : public Sprite
                     , public Updatable                     

{
  public:

    AnimatedSprite(const std::string& name, float width, float height);
    virtual ~AnimatedSprite() = default;

    virtual void update(const sf::Time& time) override;
    void start();

  protected:

    AnimationUP _animation;
    AnimatedSpriteDataSP _data;
};

using AnimatedSpriteSP = std::shared_ptr<AnimatedSprite>;

}

#endif // ANIMATED_SPRITE_HPP
