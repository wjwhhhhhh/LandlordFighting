#ifndef CARD_H
#define CARD_H
#include <cstdint>
namespace layout
{
class Card
{
  public:
    // 花色
    enum CardSuit
    {
        Hearts,     // 红心
        Diamond,    // 方块
        Club,       // 梅花
        Spade,      // 黑桃
        Small_Kind, // 小王
        Big_Kind
    };

    CardSuit getCardSuitByInt(int val)
    {
        return static_cast<CardSuit>(val);
    }
    enum CardPoint
    {
        Card_3,
        Card_4,
        Card_5,
        Card_6,
        Card_7,
        Card_8,
        Card_9,
        Card_10,
        Card_J,
        Card_Q,
        Card_K,
        Card_A,
        Card_2,
    };
    CardPoint getCardPointByInt(int val)
    {
        return static_cast<CardPoint>(val);
    }
    Card(int32_t point)
    {
        setPoint(point);
        setShow(false);
    }
    void setPoint(int32_t point)
    {
        point_ = point;
    }
    int32_t getPoint() const
    {
        return point_;
    }
    bool operator<(const Card &other) const
    {
        if (point_ >= 52 || other.point_ >= 52)
            return point_ < other.point_;
        return point_ / 4 < other.point_ / 4;
    }
    bool operator==(const Card &other) const
    {
        if (*this < other)
            return false;
        return point_ / 4 == other.point_ / 4;
    }
    bool operator!=(const Card &other) const
    {
        return !(*this == other);
    }
    bool operator>(const Card &other)
    {
        return !(*this < other || *this == other);
    }
    static bool UsedBy(const Card &a, const Card &b)
    {
        return a.point_ < b.point_;
    }
    operator bool()
    {
        return is_show_;
    }
    int32_t getValue() const
    {
        if (point_ >= 52)
            return point_;
        return point_ / 4;
    }

    void setShow(bool value)
    {
        is_show_ = value;
    }
    bool getShow()
    {
        return is_show_;
    }

  private:
    int32_t point_;
    bool is_show_;
};
} // namespace layout
#endif // CARD_H
