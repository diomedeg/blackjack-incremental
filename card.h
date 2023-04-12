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

#pragma once

#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>

class Card {
private:
    int rank;
    int suit;
public:
    Card(int _rank, int _suit);
    std::string getRank();
    std::string getSuit();
    int getVal();
    void printCard();
};