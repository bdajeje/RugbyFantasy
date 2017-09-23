#include "player_view.hpp"

#include <boost/algorithm/string.hpp>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QGroupBox>

#include <utils/directory.hpp>
#include <utils/file.hpp>
#include <utils/json.hpp>

namespace {
  std::array<std::string, 4> Attributes {"Strength", "Agility", "Speed", "Armor"};
}

PlayerView::PlayerView()
{
  auto layout = new QVBoxLayout(this);

  // List of teams
  auto teams_label = new QLabel("Choose a team");
  _teams_scroll_down = new QComboBox;
  _teams_scroll_down->setToolTip("Choose a team to change the list of players");
  loadTeams();
  layout->addWidget(teams_label);
  layout->addWidget(_teams_scroll_down);

  // List of players
  auto players_label = new QLabel("Choose a player");
  _players_scroll_down = new QComboBox;
  _players_scroll_down->setToolTip("Choose a player to edit here");
  layout->addWidget(players_label);
  layout->addWidget(_players_scroll_down);

  // Player name
  _name = new QLineEdit;
  _name->setToolTip("Enter player's name here");
  _name->setPlaceholderText("Player's name");
  layout->addWidget(_name);

  layout->addSpacing(15);

  auto attributes_layout = new QVBoxLayout;
  auto attributes_group = new QGroupBox("Player's attributes");
  attributes_group->setLayout(attributes_layout);
  layout->addWidget(attributes_group);

  // Player attributes
  for(const auto& attribute : Attributes)
  {
    auto attribute_layout = new QHBoxLayout;
    auto label            = new QLabel(attribute.c_str());
    auto line_edit        = new QSpinBox;
    line_edit->setRange(0, 100);
    _attributes[attribute] = line_edit;

    attribute_layout->addWidget(label);
    attribute_layout->addWidget(line_edit);
    attributes_layout->addLayout(attribute_layout);
  }

  connect(_teams_scroll_down, SIGNAL(currentIndexChanged(int)), this, SLOT(loadPlayers(int)));
  connect(_players_scroll_down, SIGNAL(currentIndexChanged(int)), this, SLOT(loadPlayer(int)));
}

void PlayerView::loadTeams()
{
  _teams_scroll_down->clear();
  _teams_scroll_down->addItem("");

  static const std::string target_dir = "./assets/teams/";
  std::vector<std::string> dirs = utils::listDirs(target_dir, ".*", true);
  for(const auto& dir : dirs)
    _teams_scroll_down->addItem(dir.c_str(), QVariant{QString{utils::files::read(target_dir + dir).c_str()}});
}

void PlayerView::loadPlayers(int team_index)
{
  clearPlayer();

  _players_scroll_down->clear();
  _players_scroll_down->addItem("");

  auto team_name = _teams_scroll_down->itemText(team_index);

  static const std::string target_dir = "./assets/teams/" + team_name.toStdString() + "/players/";
  std::vector<std::string> files = utils::listFiles(target_dir, ".*\.json", true);
  for(const auto& file : files)
  {
    std::string player_name = file.substr(0, file.length() - 5);
    _players_scroll_down->addItem(player_name.c_str(), QVariant{QString{utils::files::read(target_dir + file).c_str()}});
  }
}

void PlayerView::clearPlayer()
{
  _name->clear();
  for(const auto& attribute : _attributes)
    attribute.second->setValue(0);
}

void PlayerView::loadPlayer(int player_index)
{
  if(player_index == 0)
    return;

  json data = json::parse(_players_scroll_down->itemData(player_index).toString().toStdString());

  for(const auto& attribute : Attributes)
  {
    int value = data[boost::algorithm::to_lower_copy(attribute)];
    _attributes[attribute]->setValue(value);
  }
}

