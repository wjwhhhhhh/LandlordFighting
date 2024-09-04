#include "layout/include/cardType/bomb_card.h"
namespace layout
{

bool BombCard::shouldResponse(const std::vector<int32_t> &cards)
{
    std::vector<Card> value;
    for (auto &c : cards)
    {
        value.emplace_back(c);
    }
    return shouldResponse(value);
}
bool BombCard::shouldResponse(const std::vector<Card> &cards)
{
    if (cards.size() != 4)
        return false;
    for (int32_t i = 1; i < cards.size(); i++)
    {
        if (cards[i] != cards[i - 1])
            return false;
    }
}
std::shared_ptr<CardGroup> BombCard::deal(const std::vector<Card> &cards)
{
    std::shared_ptr<BombGroup> group = std::make_shared<BombGroup>();
    group->cards_.insert(group->cards_.end(), cards.begin(), cards.end());
}
}; // namespace layout