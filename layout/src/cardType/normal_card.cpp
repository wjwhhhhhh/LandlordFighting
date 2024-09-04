#include "layout/include/cardType/normal_card.h"
#include "layout/include/config.h"
#include <unordered_map>
namespace layout
{
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
    if (count.size() > 2)
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
    if (!std::get<0>(ans))
        return nullptr;
    std::shared_ptr<NormalGroup> group = std::make_shared<NormalGroup>();
    for (auto c : cards)
    {
        if (c.getValue() != std::get<1>(ans))
            group->slave_.push_back(c);
        else
            group->master_.push_back(c);
    }
    return group;
}

} // namespace layout
