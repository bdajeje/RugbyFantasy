#include "map_ui_team_block.hpp"

#include <engine/graphics/sprite.hpp>
#include <engine/graphics/text.hpp>
#include <engine/window.hpp>
#include <utils/file.hpp>

namespace game {

namespace {
  constexpr float ICON_WIDTH = 0.05;
  constexpr float ICON_HEIGHT = 0.05;
  constexpr float ICON_MARGIN = 0.01;
  constexpr float NAME_Y_MARGIN = 0.01;
  constexpr int NAME_TEXT_SIZE = 20;
}

MapUITeamBlock::MapUITeamBlock(const PlayerSP& player, int width, int height)
  : Scene {"MapUIBlock", width, height}
{
  auto icon = createIcon(player);
  createName(player, icon);
}

engine::SpriteSP MapUITeamBlock::createIcon(const PlayerSP& player)
{
  auto icon = engine::getSprite("team_icons/" + utils::files::sanitize(player->team()->name()) + ".png", engine::Window::width() * ICON_WIDTH, engine::Window::height() * ICON_HEIGHT);
  icon->setPosition({engine::Window::width() * ICON_MARGIN, engine::Window::height() * ICON_MARGIN});
  addDrawable(icon);

  return icon;
}

void MapUITeamBlock::createName(const PlayerSP& player, const engine::SpriteSP& icon)
{
  auto name = engine::getText(player->team()->name(), {"conversation.ttf", NAME_TEXT_SIZE, sf::Color::White});
  const auto& icon_size = icon->getSize();
  const auto& icon_pos  = icon->getPosition();

  name->setPosition({icon_pos.x + icon_size.x + ICON_MARGIN,
                     icon_pos.y + engine::Window::height() * NAME_Y_MARGIN});
  addDrawable(name);
}

}
