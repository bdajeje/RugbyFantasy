#ifndef MAP_UI_TEAM_BLOCK_HPP
#define MAP_UI_TEAM_BLOCK_HPP

#include <engine/models/scene.hpp>
#include <engine/graphics/sprite.hpp>
#include <game/models/players/player.hpp>

namespace game {

class MapUITeamBlock final : public engine::model::Scene
{
  public:

    MapUITeamBlock(const PlayerSP& player, int width, int height);

  private:

    engine::SpriteSP createIcon(const PlayerSP& player);
    void createName(const PlayerSP& player, const engine::SpriteSP& icon);
};

using MapUITeamBlockSP = std::shared_ptr<MapUITeamBlock>;

}

#endif // MAP_UI_TEAM_BLOCK_HPP
