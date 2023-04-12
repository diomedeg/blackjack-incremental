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

unsigned long long int totalPoints = 0;
int blackjack = 21;
unsigned long long int blackjackPrice = 100;
int normMult = 0;
unsigned long long int normPrice = 10;
int jackpotMult = 1;
unsigned long long int jackpotPrice = 10;
int bustMult = 0;
unsigned long long int bustPrice = 10;

void start() {
    std::cout << "\nGame Start!" << std::endl;
    makeDeck();
    shuffle();
    resetHand();
    hit();
    hit();
}

unsigned long long int intPow(int base, int pow){
    if(pow == 0) return 1;
    
    for (int i = 0; i < pow; i++){
        base *= base;
    }
    return base;
}

void analyze(){
    std::cout << "\nComparing to Blackjack" << std::endl;
    int roundScore = checkHand();
    if (roundScore == blackjack){
        roundScore *= intPow(10, jackpotMult);
        totalPoints += roundScore;
        std::cout << "You've hit Blackjack for " << roundScore << " points." << std::endl;
    } else if (roundScore > blackjack) {
        roundScore *= intPow(2, bustMult);
        totalPoints += roundScore;
        std::cout << "You've busted for " << roundScore << " points." << std::endl;
    } else turn(roundScore);
}

void turn(int roundScore){
    char c = ' ';
    while(c != 'H' && c != 'h' && c != 'S' && c != 's')
        c = choice();
        if (c == 'H' || c == 'h'){
            hit();
            analyze();
        } else if (c == 'S' || c == 's'){
            roundScore *= intPow(3, normMult);
            totalPoints += roundScore;
            std::cout << "You've stood for " << roundScore << " points." << std::endl;
        } else if (c == 'U' || c == 'u'){
            upgradeMenu();
        } else {
            std::cout << "Invalid input, try again." << std::endl;
        }
}

void upgradeMenu(){
    char c = ' ';
    while (c != 'P' && c != 'p'){
        std::cout << "\nYou currently have " << totalPoints << " points." << std::endl;
        std::cout << "Press 1 to triple the reward for standing below Blackjack, costs " << normPrice <<
                        " points. Bought " << normMult << " times." << std::endl;
        std::cout << "Press 2 to double the reward for busting, costs " << bustPrice <<
                        " points. Bought " << bustMult << " times." << std::endl;
        std::cout << "Press 3 to multiply the reward for Blackjack by ten, costs " << jackpotPrice <<
                        " points. Bought " << jackpotMult - 1 << " times." << std::endl;
        std::cout << "Press 4 to increase the threshold for Blackjack by one, costs " << blackjackPrice <<
                        " points. Currently " << blackjack << std::endl;
        std::cout << "Press P to return to the game." << std::endl;
        
        std::cin >> c;
        switch(c){
            case '1':
                normUpg();
                break;
            case '2':
                bustUpg();
                break;
            case '3':
                jackpotUpg();
                break;
            case '4':
                blackjackUpg();
                break;
            case 'P': case 'p':
                break;
            default:
                std::cout << "Invalid input, try again." << std::endl;
                break;
        }
    }
}

void normUpg(){
    if(totalPoints >= normPrice){
        totalPoints -= normPrice;
        normMult += 1;
        normPrice *= 3;
        std::cout << "Upgrade successful! Returning to upgrade menu." << std::endl;
    } else {
        std::cout << "Insufficient points, upgrade failed. Returning to upgrade menu." << std::endl;
    }
}

void bustUpg(){
    if(totalPoints >= bustPrice){
        totalPoints -= bustPrice;
        bustMult += 1;
        bustPrice *= 2;
        std::cout << "Upgrade successful! Returning to upgrade menu." << std::endl;
    } else {
        std::cout << "Insufficient points, upgrade failed. Returning to upgrade menu." << std::endl;
    }
}

void jackpotUpg(){
    if(totalPoints >= jackpotPrice){
        totalPoints -= jackpotPrice;
        jackpotMult += 1;
        jackpotPrice *= 10;
        std::cout << "Upgrade successful! Returning to upgrade menu." << std::endl;
    } else {
        std::cout << "Insufficient points, upgrade failed. Returning to upgrade menu." << std::endl;
    }
}

void blackjackUpg(){
    if(totalPoints >= blackjackPrice){
        totalPoints -= blackjackPrice;
        blackjack += 1;
        blackjackPrice *= 5;
        std::cout << "Upgrade successful! Returning to upgrade menu." << std::endl;
    } else {
        std::cout << "Insufficient points, upgrade failed. Returning to upgrade menu." << std::endl;
    }
}

unsigned long long int getScore(){
    return totalPoints;
}