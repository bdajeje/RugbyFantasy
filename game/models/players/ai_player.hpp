#ifndef AI_PLAYER_HPP
#define AI_PLAYER_HPP

#include <game/models/players/player.hpp>

namespace game {

class AIPlayer : public Player
{
  public:

    AIPlayer(const std::string& team_name);
};

}

#endif // AI_PLAYER_HPP
