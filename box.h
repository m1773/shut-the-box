#pragma once

#include <string>

class Box
{
public:
    Box();

    bool close(int a, int b, int c);

    int score() const;

    std::string str() const;

private:
    int tiles[9];
};
