#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include <views/player_view.hpp>

class MainWindow : public QMainWindow
{
  Q_OBJECT

  public:

    MainWindow(QWidget *parent = 0);
    ~MainWindow();

  private:

    PlayerView* _player_view;
};

#endif // MAINWINDOW_HPP
