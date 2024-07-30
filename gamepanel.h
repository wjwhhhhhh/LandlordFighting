#ifndef GAMEPANEL_H
#define GAMEPANEL_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class GamePanel;
}
QT_END_NAMESPACE

class GamePanel : public QWidget
{
    Q_OBJECT

public:
    GamePanel(QWidget *parent = nullptr);
    ~GamePanel();

private:
    Ui::GamePanel *ui;
};
#endif // GAMEPANEL_H
