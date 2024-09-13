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
    qiangdizhu.setFixedSize(90, 45);
    qiangdizhu.move(480, 320);
    qiangdizhu.setObjectName("qiangdizhu");
    qiangdizhu.setStyleSheet(R"(
        QPushButton#qiangdizhu {
            background-image: url(:/res/images/buqiang-1.png);
                    border: none;
        padding: 0;
        }
        QPushButton#qiangdizhu:hover {
            background-image: url(:/res/images/buqiang-3.png);
                    border: none;
        padding: 0;
        }
        QPushButton#qiangdizhu:pressed {
            background-image: url(:/res/images/buqiang-2.png);
                    border: none;
        padding: 0;
        }
    )");
    buqiangdizhu.setFixedSize(90, 45);
    buqiangdizhu.move(580, 320);
    buqiangdizhu.setObjectName("buqiangdizhu");
    buqiangdizhu.setStyleSheet(R"(
        QPushButton#buqiangdizhu {
            background-image: url(:/res/images/buqiang-1.png);
                    border: none;
        padding: 0;
        }
        QPushButton#buqiangdizhu:hover {
            background-image: url(:/res/images/buqiang-3.png);
                    border: none;
        padding: 0;
        }
        QPushButton#buqiangdizhu:pressed {
            background-image: url(:/res/images/buqiang-2.png);
                    border: none;
        padding: 0;
        }
    )");
    /// 中下
    player_card[0].resize(layout::config.max_cards);
    for (u32 i = 0; i < layout::config.max_cards; i++)
    {
        player_card[0][i].setParent(this);
        player_card[0][i].move(200 + i * 40, 100);
    }
    /// 左上
    player_card[1].resize(layout::config.max_cards);
    for (u32 i = 0; i < layout::config.max_cards; i++)
    {
        player_card[1][i].setParent(this);
        if (i < layout::config.max_cards / 2)
            player_card[1][i].move(100 + i * 40, 100);
        else
            player_card[1][i].move(100 + i * 40, 200);
    }
    /// 右上
    player_card[2].resize(layout::config.max_cards);
    for (u32 i = 0; i < layout::config.max_cards; i++)
    {
        player_card[2][i].setParent(this);
        if (i < layout::config.max_cards / 2)
            player_card[2][i].move(500 + i * 20, 100);
        else
            player_card[2][i].move(500 + i * 20, 200);
    }
    // TODO (加载模块)
    background_.setParent(this);
    start_.setParent(this);
    connect(&start_, &QPushButton::clicked, this, &ui::screen::start);
}

void screen::start(bool checked)
{
    std::cout << "点击开始按键" << std::endl;

    start_.setParent(nullptr);

    /// TODO(发牌模块)
    layout::gameManager->startGame();
    /// 抢地主阶段

    std::cout << "抢地主结束" << std::endl;
    /// 设置头像环节
    setPlayer(0, layout::gameManager->getPlayer(0));
    setPlayer(1, layout::gameManager->getPlayer(1));
    setPlayer(2, layout::gameManager->getPlayer(2));
    std::cout << "设置头像结束" << std::endl;
}
void screen::End()
{
    /// TODO (结束模块)
}
void screen::setPlayer(int32_t index, const layout::Player &player)
{
    // 设置头像
}
void screen::playerSendCards(int32_t id, std::vector<layout::Card>)
{
}

void screen::showCards()
{
    for (u32 id = 0; id < 3; id)
    {
        const std::vector<layout::Card> &cards_one = layout::gameManager->getPlayer(0).getCards();
        for (u32 i = 0; i < cards_one.size(); i++)
        {
            player_card[id][i].setPixmap(layout::ImageManage::defaultImageManage()->getCardByCard(cards_one[i]));
            player_card[id][i].setVisible(true);
        }
        for (u32 i = cards_one.size() + 1; i < layout::config.max_cards; i++)
        {
            player_card[id][i].setVisible(false);
        }
    }
}

} // namespace ui
