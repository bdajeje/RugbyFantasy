#ifndef PLAYER_TEAM_HPP
#define PLAYER_TEAM_HPP

#include <memory>

namespace game {

class PlayerTeam final
{
  public:

    PlayerTeam(const std::string& team_name);

    const std::string& name() const noexcept { return _name; }

  private:

    std::string _name;
};

using PlayerTeamSP = std::shared_ptr<PlayerTeam>;

}

#endif // PLAYER_TEAM_HPP
