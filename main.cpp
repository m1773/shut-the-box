#include <iostream>
#include "dice.h"
#include "box.h"

int main()
{
    Box box;
    Dice dice(2);

    std::cout << "Let's play Shut The Box\n" << std::endl;

    while (box.score() != 0)
    {
        std::cout << "Box: " << box.str() << std::endl;

        dice.roll();
        if (dice.count() == 1)
        {
            std::cout << "Dice: " << dice.die(0) << std::endl;
        }
        else
        {
            std::cout << "Dice: " << dice.die(0) << "-" << dice.die(1) << std::endl;
        }

        int a, b, c;
        std::cout << "Tiles: ";
        std::cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 0)
        {
            std::cout << std::endl;
            break;
        }
        while (a + b + c != dice.total() || !box.close(a, b, c))
        {
            std::cout << "Tile selection is not valid. Try again." << std::endl;
            std::cout << "Tiles: ";
            std::cin >> a >> b >> c;

            if (a == 0 && b == 0 && c == 0)
            {
                std::cout << std::endl;
                break;
            }
        }

        if (box.score() <= 6)
        {
            dice = Dice(1);
        }

        std::cout << std::endl;
    }

    std::cout << "Box: " << box.str() << std::endl;
    std::cout << "Score: " << box.score() << std::endl;
    return 0;
}
