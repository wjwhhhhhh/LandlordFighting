#include "layout/include/cardType/normal_card.h"
#include <config.h>
#include <unordered_map>
namespace layout
{
std::shared_ptr<CardGroup> NormalCard::dealOne(const std::vector<Card> &cards)
{
    return nullptr;
}
std::shared_ptr<CardGroup> NormalCard::dealTwo(const std::vector<Card> &cards)
{
    return nullptr;
}
std::shared_ptr<CardGroup> NormalCard::dealThree(const std::vector<Card> &cards)
{
    return nullptr;
}
std::shared_ptr<CardGroup> NormalCard::dealFour(const std::vector<Card> &cards)
{
    return nullptr;
}
bool NormalCard::shouldResponse(const std::vector<int32_t> &cards)
{
    std::vector<Card> value;
    for (auto &c : cards)
    {
        value.emplace_back(c);
    }
    return shouldResponse(value);
}
bool NormalCard::shouldResponse(const std::vector<Card> &cards)
{
    auto ans = check(cards);
    return std::get<0>(ans);
}

std::tuple<bool, int32_t> NormalCard::check(const std::vector<Card> &cards)
{
    std::unordered_map<int32_t, int32_t> count;
    for (auto &c : cards)
        count[c.getValue()]++;
    if (count.size() != 2)
        return {false, -1};
    int32_t master = count.begin()->first, slave = (++count.begin())->first;
    if (count[master] < count[slave])
        std::swap(master, slave);
    if (master > config.min_with.size())
        return {false, -1};
    if (slave > config.min_with[master - 1])
        return {false, -1};
    return {true, master};
}
std::shared_ptr<CardGroup> NormalCard::deal(const std::vector<Card> &cards)
{
    auto ans = check(cards);

    switch (std::get<1>(ans))
    {
    case 1:
        return dealOne(cards);
        break;
    case 2:
        return dealTwo(cards);
        break;
    case 3:
        return dealThree(cards);
        break;
    case 4:
        return dealFour(cards);
        break;
    default:
        break;
    };
}

} // namespace layout
