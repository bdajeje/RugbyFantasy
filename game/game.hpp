#ifndef GAME_HPP
#define GAME_HPP

#include <memory>

#include <game/models/players/player.hpp>

namespace game {

class Game final
{
  public:

    static void startNewGame(PlayerSP player_1, PlayerSP player_2);

    static PlayerSP player1() { return _instance->_player_1; }
    static PlayerSP player2() { return _instance->_player_2; }

  private:

    Game(PlayerSP player_1, PlayerSP player_2);

  private:

    static std::unique_ptr<Game> _instance;

  private:

    PlayerSP _player_1;
    PlayerSP _player_2;
};

}

#endif // GAME_HPP
