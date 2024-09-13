#ifndef SCREEN_H
#define SCREEN_H

#include "collab/include/stdc++.h"
#include "layout/include/game_manager.h"
#include "layout/include/image_manage.h"
#include "layout/include/player.h"
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QWidget>
namespace ui
{
class screen : public QWidget
{
  public:
    screen()
    {
        init();
    }
    void start(bool checked = false);
    bool checkEnd();
    void End();
    void setPlayer(int index, const layout::Player &player);
    void playerSendCards(int32_t id, std::vector<layout::Card>);
    void showCards(); // 展示所有玩家的图片
    void showsendCards();
    void grabThelandlords(); // 抢地主阶段
  private:
    void init();
    QLabel background_;
    QLabel player_avatar_[3];
    std::vector<QLabel> player_card[3];
    std::vector<QLabel> player_send_card;
    QPushButton start_;
    QPushButton qiangdizhu;
    QPushButton buqiangdizhu;
};

} // namespace ui
#endif // SCREEN_H
