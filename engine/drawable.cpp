#include "drawable.hpp"

namespace engine {

void Drawable::draw(sf::RenderTarget& target, sf::RenderStates states) const noexcept
{
  if(_visible)
    internalDraw(target, states);
}

}
