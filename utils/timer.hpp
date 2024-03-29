#ifndef UTILS_TIME_TIMER_HPP
#define UTILS_TIME_TIMER_HPP

#include <SFML/System/Clock.hpp>

namespace utils {
namespace time {

class Timer final
{
  public:

    Timer() = default;

    /*! Start the timer */
    void start();

    /*! Restart the timer
     *  \returns time since started
     */
    ::sf::Time restart();

    /*! Pause the timer
     *  \returns current elapsed time
     */
    ::sf::Time pause();

    /*! Returns time since started */
    ::sf::Time getElapsedTime() const;

    /*! Is the timer paused ? */
    bool isPaused() const { return _paused; }

  private:

    sf::Clock _clock;
    ::sf::Time _elapsed_time {::sf::Time::Zero};
    bool _paused {true};
};

} // time
} // utils

#endif // TIMER_HPP
