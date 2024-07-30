#include "cards_render.h"
#include<QPainter>
Eula::CardPanel::CardPanel(QWidget *parent)
    : QWidget{parent}
{}
void Eula::CardPanel::setImage(QPixmap &front,QPixmap &back)
{
    m_front=front;
    m_back=back;

    setFixedSize(m_back.size());
    update();
}
QPixmap Eula::CardPanel::getImage()
{
    return m_front;
}
void Eula::CardPanel::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    if(m_isFront)
    {
        p.drawPixmap(rect(),m_front);
    }else
    {
        p.drawPixmap(rect(),m_back);
    }
}
void Eula::CardPanel::setIsFront(bool value)
{
    m_isFront=value;
}
bool Eula::CardPanel::getIsFront()
{
    return m_isFront;
}
