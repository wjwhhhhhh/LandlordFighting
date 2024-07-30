#include "gamepanel.h"
#include "ui_gamepanel.h"

GamePanel::GamePanel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GamePanel)
{
    ui->setupUi(this);
}

GamePanel::~GamePanel()
{
    delete ui;
}
