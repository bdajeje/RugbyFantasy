#include "map_ui_scene.hpp"

#include <game/game.hpp>
#include <engine/window.hpp>

namespace game {

namespace {
  constexpr float TEAM_UI_BLOCK_WIDTH   = 0.25;
  constexpr float TEAM_UI_BLOCK_PADDING = 0.01;
}

MapUIScene::MapUIScene()
  : Scene {"MapUI"}
{
  createUI();
}

void MapUIScene::createUI()
{
   _team_1_ui_block = createTeamUIBLock(Game::player1(), UIBlockPosition::Left);
   addDrawable(_team_1_ui_block);

   _team_2_ui_block = createTeamUIBLock(Game::player2(), UIBlockPosition::Right);
   addDrawable(_team_2_ui_block);
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

}
