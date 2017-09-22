#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <memory>

#include <engine/updatable.hpp>

namespace engine {

class Animation : public Updatable
{
  public:

    Animation() = default;
    virtual ~Animation() = default;

    bool isFinished() const { return _finished; }
    virtual void finish() { _finished = true; }

  protected:

    bool _finished {false};
};

using AnimationSP = std::shared_ptr<Animation>;
using AnimationUP = std::unique_ptr<Animation>;

}

#endif // ANIMATION_HPP
