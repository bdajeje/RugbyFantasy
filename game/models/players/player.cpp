#include "player.hpp"

namespace game {

Player::Player(const std::string& team_name)
  : _team {std::make_shared<PlayerTeam>(team_name)}
{

}

}
