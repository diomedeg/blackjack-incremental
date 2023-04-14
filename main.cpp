/********************************************************************************
    Blackjack_incremental is based on blackjack with a point system rather than against a dealer
    Copyright (C) 2023  Giovanni Diomede

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*******************************************************************************/
#include "game.h"

unsigned long long int goal = 10000000000000000000ull;

int main(){
    std::cout << "Welcome to Blackjack Incremental, an incremental game with the goal of reaching 10 quintillion points. Unlike typical Blackjack, there is no dealer here: " <<
                    "you earn points based on your hand's total score compared to Blackjack, with upgrades to increase the amount of points you get and what number Blackjack " <<
                    "actually is. Jacks, Queens, and Kings are also worth 11, 12, and 13 points respectively, and Aces are always worth 1 point." << std::endl;
    
    char c = ' ';
    while (c != 'N' && c != 'n' && getScore() < goal){
        std::cout << "\nPress S to begin a round, U to view upgrades, or N to quit the game." << std::endl;
        std::cin >> c;

        if(c == 'S' || c == 's'){
            start();
            analyze();
        } else if (c == 'U' || c == 'u'){
            upgradeMenu();
        } else if (c == 'N' || c == 'n'){
            std::cout << "Game has been quit." << std::endl;
        } else {
            std::cout << "Invalid input, try again." << std::endl;
        }
    }

    if (getScore() >= goal){
        std::cout << "Congratulations! You've won!" << std::endl;
    }

    return 0;
}