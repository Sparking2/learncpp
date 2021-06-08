//Question #1
//
//Pretend you’re writing a game where the player can hold 3 types of items : health potions, torches, and arrows.
//Create an enum to identify the different types of items, and an std::array to store the number of each item the player is carrying
//(The enumerators are used as indexes of the array).
//The player should start with 2 health potions, 5 torches, and 10 arrows.
//Write a function called countTotalItems() that returns how many items the player has in total.
//Have your main() function print the output of countTotalItems() as well as the number of torches.

#include <iostream>
#include <array>
#include <numeric>

enum ItemTypes
{
    item_health_potions,
    item_torches,
    item_arrows,
    max_items
};

using inventory_type = std::array<int, ItemTypes::max_items>;

int countTotalItems(const inventory_type& items) {
    return std::reduce(items.begin(), items.end());
}

int Ch_9_X_Question1()
{
    inventory_type items{ 2,5,10 };

    std::cout << "The player has " << countTotalItems(items) << " Item(s) in total.\n";

    std::cout << "The player has " << items[ItemTypes::item_arrows] << " Arrow(s).";

    return 0;
}