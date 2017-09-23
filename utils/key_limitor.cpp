#include "key_limitor.hpp"

namespace utils {

KeyLimitor::KeyLimitor(sf::Int32 min_elapsed_time)
  : _min_elapsed_time { min_elapsed_time }
{
  _timer.start();
}

bool KeyLimitor::isAllowed()
{
  if(_min_elapsed_time <= _timer.getElapsedTime().asMilliseconds())
  {
    _timer.restart();
    return true;
  }

  return false;
}

}
