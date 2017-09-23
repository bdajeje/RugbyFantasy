#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <memory>

#include <game/models/player_team.hpp>

namespace game {

class Player
{
  public:

    Player(const std::string& team_name);
    virtual ~Player() = default;

    PlayerTeamSP team() const noexcept { return _team; }

  protected:

    PlayerTeamSP _team;
};

using PlayerSP = std::shared_ptr<Player>;

}

#endif // PLAYER_HPP
