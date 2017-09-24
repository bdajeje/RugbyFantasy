#include "map_ui_scene.hpp"

#include <game/game.hpp>
#include <engine/window.hpp>
#include <engine/events/event_types.hpp>

namespace game {

namespace {
  constexpr float TEAM_UI_BLOCK_WIDTH   = 0.25;
  constexpr float TEAM_UI_BLOCK_PADDING = 0.01;  
  constexpr float STATE_TEXT_PADDING = 0.01;
}

MapUIScene::MapUIScene()
  : Scene {"MapUI"}
{
  createUI();
  eventsRegistration();
}

void MapUIScene::createUI()
{
   _team_1_ui_block = createTeamUIBLock(Game::player1(), UIBlockPosition::Left);
   addDrawable(_team_1_ui_block);

   _team_2_ui_block = createTeamUIBLock(Game::player2(), UIBlockPosition::Right);
   addDrawable(_team_2_ui_block);

   _state_text = engine::getText("", {"conversation.ttf", 25, sf::Color::White});
   _state_text->setPosition({0, engine::Window::height() * STATE_TEXT_PADDING});
   addDrawable(_state_text);

   updateStateText("Place your players");
}

void MapUIScene::updateStateText(const std::string& new_text)
{
  _state_text->setString(new_text);
  auto pos = _state_text->getPosition();
  pos.x = (engine::Window::width() - _state_text->getSize().x) / 2;
  _state_text->setPosition(pos);
}

MapUITeamBlockSP MapUIScene::createTeamUIBLock(PlayerSP player, UIBlockPosition position)
{
  auto result = std::make_shared<MapUITeamBlock>(player, engine::Window::width() * TEAM_UI_BLOCK_WIDTH, engine::Window::height());

  float x = engine::Window::width() * TEAM_UI_BLOCK_PADDING;
  float y = engine::Window::height() * TEAM_UI_BLOCK_PADDING;

  if(position == UIBlockPosition::Right)
    x = engine::Window::width() - x - result->getSize().x;

  result->setPosition(sf::Vector2f{x, y});

  return result;
}

void MapUIScene::eventsRegistration()
{
  using namespace std::placeholders;
  registerSceneEvent("Map", "NextPhase", std::bind(&MapUIScene::gamePhaseChanged, this, _1));
}

void MapUIScene::gamePhaseChanged(const json& data)
{
  updateStateText(data["phase"]);
}

}
