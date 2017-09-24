#ifndef MAP_UI_SCENE_HPP
#define MAP_UI_SCENE_HPP

#include <engine/models/scene.hpp>
#include <engine/events/event.hpp>
#include <engine/graphics/text.hpp>
#include <game/models/players/player.hpp>
#include <game/graphics/models/map_ui_team_block.hpp>

namespace game {

class MapUIScene final : public engine::model::Scene                       
{
  public:

    MapUIScene();

  private:

    enum class UIBlockPosition {Left, Right};

    void createUI();
    MapUITeamBlockSP createTeamUIBLock(PlayerSP player, UIBlockPosition position);    
    void eventsRegistration();
    void gamePhaseChanged(const json& data);
    void updateStateText(const std::string& new_text);

  private:

    MapUITeamBlockSP _team_1_ui_block;
    MapUITeamBlockSP _team_2_ui_block;
    engine::TextSP _state_text;
};

}

#endif // MAP_UI_SCENE_HPP
