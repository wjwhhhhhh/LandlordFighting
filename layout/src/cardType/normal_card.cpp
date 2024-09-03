#include "layout/include/cardType/normal_card.h"
#include <unordered_map>
namespace layout
{
bool NormalCard::checkOne(const std::vector<Card>&cards)
{

}
bool NormalCard::checkTwo(const std::vector<Card>&cards)
{

}
bool NormalCard::checkThree(const std::vector<Card>&cards)
{

}
bool NormalCard::checkFour(const std::vector<Card>&cards)
{

}
std::shared_ptr<CardGroup>NormalCard::dealOne(const std::vector<Card>&cards)
{

}
std::shared_ptr<CardGroup>NormalCard::dealTwo(const std::vector<Card>&cards)
{

}
std::shared_ptr<CardGroup>NormalCard::dealThree(const std::vector<Card>&cards)
{

}
std::shared_ptr<CardGroup>NormalCard::dealFour(const std::vector<Card>&cards)
{

}
bool NormalCard::shouldResponse(const std::vector<int32_t>& cards)
{
    std::vector<Card>value;
    for( auto &c:cards)
    {
        value.emplace_back(c);
    }
    return shouldResponse(value);
}
bool NormalCard::shouldResponse(const std::vector<Card>&cards)
{
    if(checkOne(cards))return true;
    if(checkTwo(cards))return true;
    if(checkThree(cards))return true;
    if(checkFour(cards))return true;
    return false;

}

}
