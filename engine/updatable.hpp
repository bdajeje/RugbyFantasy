#ifndef UPDATABLE_HPP
#define UPDATABLE_HPP

#include <memory>

#include <SFML/System/Time.hpp>

namespace engine {

class Updatable
{
  public:

    Updatable();
    virtual ~Updatable() = default;

    virtual void update(const sf::Time& time) = 0;
};

using UpdatableSP = std::shared_ptr<Updatable>;

}

#endif // UPDATABLE_HPP
