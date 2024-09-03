#ifndef NORMAL_CARD_H
#define NORMAL_CARD_H
#include "listen.h"
#include "card_group.h"
#include <memory>
namespace layout
{
    class NormalCard:public Listener
    {
    public:
        NormalCard(){}
        ~NormalCard(){}
    private:
        std::shared_ptr<CardGroup>dealOne(const std::vector<Card>&cards);
        std::shared_ptr<CardGroup>dealTwo(const std::vector<Card>&cards);
        std::shared_ptr<CardGroup>dealThree(const std::vector<Card>&cards);
        std::shared_ptr<CardGroup>dealFour(const std::vector<Card>&cards);
        bool checkOne(const std::vector<Card>&cards);
        bool checkTwo(const std::vector<Card>&cards);
        bool checkThree(const std::vector<Card>&cards);
        bool checkFour(const std::vector<Card>&cards);
        bool shouldResponse(const std::vector<int32_t>& cards) override;
        bool shouldResponse(const std::vector<Card>&cards)override;
    };
}
#endif // NORMAL_CARD_H
