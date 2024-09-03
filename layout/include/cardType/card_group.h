#ifndef CARD_GROUP_H
#define CARD_GROUP_H
#include <vector>
#include "card.h"
namespace  layout
{
    class CardGroup
    {
    public:
        enum type
        {
            normal,//正常
            sequences,// 顺子
            bomb,//炸弹
        };
    private:
    protected:
        type group_card_;

    };

    class NormalGroup:public CardGroup
    {
    public:
        NormalGroup(){
            group_card_=type::normal;
        }
        ~NormalGroup(){};
    private:
        std::vector<Card> master_;// 主牌
        std::vector<Card>slave_;//带的
    };

    class SequencesGroup: public CardGroup
    {
    public:
        SequencesGroup(){
            group_card_=type::sequences;
        }
        ~SequencesGroup(){};
    private:
        std::vector<NormalGroup> master_;
    };


    class Bomb:public CardGroup
    {
    public:
        Bomb(){
            group_card_=type::bomb;
        }
        ~Bomb(){};
    private:
        std::vector<Card>cards_;
    };
}
#endif // CARD_GROUP_H
