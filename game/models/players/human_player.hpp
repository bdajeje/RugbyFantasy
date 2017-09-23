#ifndef HUMAN_PLAYER_HPP
#define HUMAN_PLAYER_HPP

#include <game/models/players/player.hpp>

namespace game {

class HumanPlayer : public Player
{
  public:

    HumanPlayer(const std::string& team_name);
};

}

#endif // HUMAN_PLAYER_HPP
