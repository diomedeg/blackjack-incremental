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
#include "player.h"

std::vector<Card> hand;

void hit(){
    hand.push_back(draw());
}

void stand(){
}

int checkHand(){
    int sum = 0;
    std::cout << "Your Hand:" << std::endl;
    for (Card i: hand) {
        i.printCard();
        std::cout << std::endl;
        sum += i.getVal();
    }
    return sum;
}

char choice() {
    std::cout << "Non Blackjack, Hit, Stand, or Upgrade?" << std::endl;
    std::cout << "Press H to hit, S to stand, or U to access upgrades." << std::endl;
    char c = ' ';
    std::cin >> c;
    return c;
}

void resetHand(){
    hand.clear();
}