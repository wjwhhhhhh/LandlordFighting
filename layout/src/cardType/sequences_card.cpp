#include "layout/include/cardType/sequences_card.h"
#include "config.h"
#include <map>
namespace layout
{
std::shared_ptr<CardGroup> dealOne(const std::vector<Card> &cards)
{
    return nullptr;
}
std::shared_ptr<CardGroup> dealTwo(const std::vector<Card> &cards)
{
    return nullptr;
}
std::shared_ptr<CardGroup> dealThree(const std::vector<Card> &cards)
{
    return nullptr;
}
std::tuple<bool, int32_t> check(const std::vector<Card> &cards)
{
    std::map<int32_t, int32_t> counts;
    for (auto &c : cards)
        counts[c.getValue()]++;
    std::vector<int32_t> first, second;
    for (auto [x, y] : counts)
    {
        if (x == 12)
            return {false, -1}; // 2不能是顺子
        first.push_back(x);
        second.push_back(y);
    }
    if (first.size() == 1)
        return {false, -1};
    for (int32_t i = 1; i < first.size(); i++)
    {
        if (second[i] != second[i - 1] || first[i] != first[i - 1] + 1)
            return {false, -1};
    }
    if (second[0] > config.min_sequences.size())
        return {false, -1};
    if (first.size() < config.min_sequences[second[0] - 1])
        return {false, -1};
    return {true, first[0]}; // TODO  bug
}
bool SequencesCard::shouldResponse(const std::vector<int32_t> &cards)
{
    std::vector<Card> value;
    for (auto &c : cards)
    {
        value.emplace_back(c);
    }
    return shouldResponse(value);
}
bool SequencesCard::shouldResponse(const std::vector<Card> &cards)
{
    auto ans = check(cards);
    return std::get<0>(ans);
}
std::shared_ptr<CardGroup> SequencesCard::deal(const std::vector<Card> &cards)
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
    default:
        break;
    };
    return nullptr;
}

} // namespace layout