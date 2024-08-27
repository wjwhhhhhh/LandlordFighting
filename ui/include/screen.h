#ifndef SCREEN_H
#define SCREEN_H

#include <QWidget>

namespace ui
{
class screen:public QWidget
{
public:
    screen();
    void paintEvent(QPaintEvent*)override;
};
}
#endif // SCREEN_H
