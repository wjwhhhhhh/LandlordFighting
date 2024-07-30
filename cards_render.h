#ifndef CARDS_RENDER_H
#define CARDS_RENDER_H

#include <QWidget>
namespace Eula
{

class CardPanel : public QWidget
{
    Q_OBJECT
public:
    explicit CardPanel(QWidget *parent = nullptr);

   void setImage(QPixmap &front,QPixmap &back);
    QPixmap getImage();
   void setIsFront();
    bool getIsFront();
signals:
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    QPixmap m_front,m_back;
    bool m_isFront; //是不是正面
};

}
#endif // CARDS_RENDER_H
