#include "layout/include/card.h"

namespace layout
{
Card::CardPoint Card::getPoint()
{
    return m_point;
}

Card::CardSuit Card::getSuit()
{
    return m_suit;
}

void Card::setPoint(Card::CardPoint point)
{
    m_point = point;
}

void Card::setSuit(Card::CardSuit suit)
{
    m_suit = suit;
}

void Card::setPointAndSuit(int val)
{
    m_suit = getCardSuitByInt(val % 4);
    m_point = getCardPointByInt(val / 4);
}

Card::CardSuit Card::getCardSuitByInt(int val)
{
    return static_cast<CardSuit>(val);
}

Card::CardPoint Card::getCardPointByInt(int val)
{
    return static_cast<CardPoint>(val);
}

int Card::getIntByPointAndSuit()
{
    return m_point * 4 + m_suit;
}

} // namespace layout
