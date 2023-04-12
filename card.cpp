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
#include "card.h"

Card::Card(int _rank, int _suit){
    this->rank = _rank;
    this->suit = _suit;
}

std::string Card::getRank(){
    switch(rank){
        case 1:
            return "A";
        case 11:
            return "J";
        case 12:
            return "Q";
        case 13:
            return "K";
        default:
            return (std::to_string(rank));
    }
}

std::string Card::getSuit(){
    switch(suit){
        case 1:
            return "Hearts";
        case 2:
            return "Diamonds";
        case 3:
            return "Spades";
        case 4:
            return "Clubs";
        default:
            return "Error";
    }
}

int Card::getVal(){
    return rank;
}

void Card::printCard(){
    std::cout << this->getRank() << " of " << this->getSuit();
}