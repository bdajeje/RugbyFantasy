#ifndef PLAYER_VIEW_HPP
#define PLAYER_VIEW_HPP

#include <map>

#include <QComboBox>
#include <QSpinBox>
#include <QLineEdit>

class PlayerView final : public QWidget
{
  Q_OBJECT

  public:

    PlayerView();

  public slots:

    void loadTeams();
    void loadPlayers(int team_index);
    void loadPlayer(int player_index);
    void clearPlayer();

  private:

    QComboBox* _teams_scroll_down;
    QComboBox* _players_scroll_down;
    QLineEdit* _name;
    std::map<std::string, QSpinBox*> _attributes;
};

#endif // PLAYER_VIEW_HPP
