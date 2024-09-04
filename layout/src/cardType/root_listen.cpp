#include "layout/include/cardType/root_listen.h"
#include "bomb_card.h"
#include "normal_card.h"
#include "sequences_card.h"

namespace layout
{
void RootListen::init()
{
    addListener(std::make_shared<BombCard>());
    addListener(std::make_shared<SequencesCard>());
    addListener(std::make_shared<NormalCard>());
}

void RootListen::addListener(const std::shared_ptr<Listener> &listener)
{
    listeners.push_back(listener);
}

std::shared_ptr<CardGroup> RootListen::deal(std::vector<Card> cards)
{
    for (auto &c : listeners)
    {
        if (c->shouldResponse(cards))
        {
            return c->deal(cards);
            break;
        }
    }
    return nullptr;
}
} // namespace layout
