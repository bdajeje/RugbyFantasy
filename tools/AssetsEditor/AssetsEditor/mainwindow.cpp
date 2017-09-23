#include "mainwindow.hpp"

#include <QTabWidget>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  auto central_widget = new QWidget(this);
  auto main_layout    = new QVBoxLayout();

  // Create tab widget
  auto widget_tab = new QTabWidget;

  // First tab
  _player_view = new PlayerView();
  widget_tab->addTab(_player_view, tr("Player"));

  main_layout->addWidget(widget_tab);
  central_widget->setLayout(main_layout);
  setCentralWidget(central_widget);
}

MainWindow::~MainWindow()
{}
