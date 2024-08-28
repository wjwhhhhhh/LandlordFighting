#ifndef SCREEN_H
#define SCREEN_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include "layout/include/image_manage.h"

namespace ui
{
class screen:public QWidget
{
public:
    screen()
    {
        init();
    }
    void paintEvent(QPaintEvent*)override;
private:
    void init();
    void resizeEvent(QResizeEvent * )override;
    void setBackground(const QPixmap& background);

    QLabel background_;
};
}
#endif // SCREEN_H
