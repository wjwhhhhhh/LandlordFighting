#ifndef CARD_H
#define CARD_H
namespace collab
{
class Card
{
public:
    //花色
    enum CardSuit
    {
        Hearts,//红心
        Diamond,//方块
        Club,//梅花
        Spade,//黑桃
    };

    CardSuit getCardSuitByInt(int val);
    enum CardPoint
    {
        Card_3,
        Card_4,
        Card_5,
        Card_6,
        Card_7,
        Card_8,
        Card_9,
        Card_10,
        Card_J,
        Card_Q,
        Card_K,
        Card_A,
        Card_2,
        Card_Sj,
        Card_BJ,
    };
    CardPoint getCardPontByInt(int val);
    Card();
    CardPoint getPoint();
    CardSuit getSuit();
    void setPoint(CardPoint point);
    void setSuit( CardSuit suit);
    void setPointAndSuit(int val);
private:
    CardPoint m_point;
    CardSuit m_suit;
};
}
#endif // CARD_H
