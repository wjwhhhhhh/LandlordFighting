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

  private:
    void init();
    QLabel background_;
    QLabel player_[3];
    std::map<int32_t, QLabel> player_card[3];
    QPushButton start_;
};
} // namespace ui
#endif // SCREEN_H
