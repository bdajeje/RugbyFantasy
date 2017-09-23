#include "game.hpp"

namespace game {

std::unique_ptr<Game> Game::_instance;

void Game::startNewGame(PlayerSP player_1, PlayerSP player_2)
{
  _instance.reset(new Game(player_1, player_2));
}

Game::Game(PlayerSP player_1, PlayerSP player_2)
  : _player_1 {player_1}
  , _player_2 {player_2}
{

}

}
