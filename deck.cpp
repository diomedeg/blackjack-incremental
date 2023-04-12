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
#include "deck.h"

std::vector<Card> deck;

void makeDeck() {
    for (int i = 1; i <= 4; i++){
        for (int j = 1; j <= 13; j++){
            Card c(j, i);
            deck.push_back(c);
        }
    }
}

void shuffle(){
    srand((unsigned)time(0));
    for(int i = 0; i < 52; i++)
        std::swap(deck[i], deck[rand() % 52]);
    std::cout << "Deck Shuffled!" << std::endl;
}

void print_deck() {
    std::cout << "Deck:" << std::endl;
    int t=0;
    for (Card i : deck) {
        i.printCard();
        t++;
        if (t % 13 == 0){
            std::cout << std::endl;
        } else std::cout << ", ";
    }
}

Card draw() {
    Card card = deck.front();
    deck.erase(deck.begin());
    return card;
}

bool is_empty(){
    return deck.empty();
}