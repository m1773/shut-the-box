#include <cstdlib>

#include "box.h"

Box::Box()
{
    for (int i = 0; i < 9; ++i)
    {
        tiles[i] = i + 1;
    }
}

bool Box::close(int a, int b, int c)
{
    if (a < 0 || a > 9) return false;
    if (b < 0 || b > 9) return false;
    if (c < 0 || c > 9) return false;

    if (a == b && a != 0) return false;
    if (b == c && b != 0) return false;
    if (c == a && c != 0) return false;

    if (a != 0)
    {
        if (tiles[a-1] == 0) return false;
        else tiles[a-1] = 0;
    }
    if (b != 0)
    {
        if (tiles[b-1] == 0) return false;
        else tiles[b-1] = 0;
    }
    if (c != 0)
    {
        if (tiles[c-1] == 0) return false;
        else tiles[c-1] = 0;
    }
    return true;
}

int Box::score() const
{
    int score = 0;
    for (int i = 0; i < 9; ++i)
    {
        if (tiles[i] > 0)
        {
            score += tiles[i];
        }
    }
    return score;
}

std::string Box::str() const
{
    std::string result;
    for (int i = 0; i < 9; ++i)
    {
        result += (tiles[i] > 0) ? std::to_string(tiles[i]) : "*";
        result += " ";
    }
    return result;
}
