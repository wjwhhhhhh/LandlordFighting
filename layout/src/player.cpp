#include "layout/include/player.h"
namespace layout
{
std::vector<Card> Player::robotSend()
{
    sort();
    std::vector<Card> cards = {*cards_.rbegin()};
    removeCard({*cards_.rbegin()});
    return cards;
}
std::vector<Card> Player::gptSend()
{
    return {};
}
std::vector<Card> Player::peopleSend()
{
    return {};
}
void Player::removeCard(std::vector<Card> cards)
{
    std::vector<Card> new_card;
    for (auto &c : cards_)
    {
        if (std::find(cards.begin(), cards.end(), c) == cards.end())
            new_card.push_back(c);
    }
    cards_ = new_card;
}
void Player::addCard(std::vector<Card> cards)
{
    cards_.insert(cards_.end(), cards.begin(), cards.end());
}
void Player::sort()
{
    std::sort(cards_.begin(), cards_.end());
}
std::vector<Card> Player::getCards() const
{
    return cards_;
}
}; // namespace layout