/*
Part 1 of Day 2: Tally up the total score for the given input, following the rules:
Per single round: Score equals the shape you select (1 for Rock or 'X', 2 for Paper or 'Y', 3 for Scissors or 'Z')
plus the outcome of the round (0 for a loss, 3 for a draw, 6 for a win)

Day 2 prompt found at: https://adventofcode.com/2022/day/2
For my input file, D2Input.txt, an output of 13052 is expected
*/

#include <iostream>
#include <fstream> 
#include <map>
#include <algorithm>
#include <filesystem> 

std::map<char, char> rpsMap = {{'X', 'Z'}, {'Y', 'X'}, {'Z', 'Y'}}; //Keys are what input beats their Value
std::string txtPath = "D2Input.txt"; 

int tallyRound(char playerIn, char enemyIn){ //compares player and opponent inputs, returning the value of the result plus the player's input
    if (playerIn == enemyIn){ //Draw
        return 3 + int(playerIn - 'W'); 
    }
    else if (enemyIn == rpsMap[playerIn]){ //Player Win
        return 6 + int(playerIn - 'W'); 
    }
    else{
        return 0 + int(playerIn - 'W'); //Player Loss
    }
}

int main(){
    std::cout << txtPath; 
    int grandTotal = 0; 
    std::ifstream inFile;
    inFile.open(txtPath);  
    std::string line; 
    if (inFile.is_open()){ 
        while (std::getline(inFile, line)){
            switch(line[0]){
                case('A'):
                    grandTotal += tallyRound(line[2], 'X'); 
                    break; 
                case('B'):
                    grandTotal += tallyRound(line[2], 'Y'); 
                    break; 
                case('C'):
                    grandTotal += tallyRound(line[2], 'Z');
                    break;  
            }
        }
        inFile.close(); 
    }

    else{
        std::cout << "File not open" << std::endl; 
    }
    std::cout << "Total from all rounds: " << grandTotal; 
    return 0; 
}