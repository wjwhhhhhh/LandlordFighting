#include "ui/include/screen.h"
#include <QIcon>
#include <QPainter>
namespace ui
{
void screen::init()
{

    this->setFixedSize(960, 640);
    background_.setPixmap(layout::ImageManage::defaultImageManage()->getBackground());
    start_.setFixedSize(90, 45);
    start_.move(480, 320);
    start_.setObjectName("start");
    start_.setStyleSheet(R"(
        QPushButton#start {
            background-image: url(:/res/images/start-1.png);
                    border: none;
        padding: 0;
        }
        QPushButton#start:hover {
            background-image: url(:/res/images/start-3.png);
                    border: none;
        padding: 0;
        }
        QPushButton#start:pressed {
            background-image: url(:/res/images/start-2.png);
                    border: none;
        padding: 0;
        }
    )");
    background_.setParent(this);
    start_.setParent(this);
    connect(&start_, &QPushButton::clicked, this, &ui::screen::start);
}

void screen::screen::start(bool checked)
{
    std::cout << "点击开始按键" << std::endl;

    start_.setParent(nullptr);
    /// TODO(动画模块(发牌模块))
}

void start(bool checked = false);
bool checkEnd();
void End();
void setPlayer(int index, const layout::Player &player);
void playerSendCards(int32_t id, std::vector<layout::Card>);

} // namespace ui
