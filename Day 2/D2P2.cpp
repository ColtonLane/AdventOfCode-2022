/*
Part 2 of Day 2: Tally up the total score for the given input, following the rules:
Per single round: Score equals the shape you select (1 for Rock, 2 for Paper, 3 for Scissors)
plus the outcome of the round (0 for a loss, 3 for a draw, 6 for a win). The input now indicates what the 
opponent selects (A for Rock, B for Scissors, C for Paper) and what the outcome should be (X for lose, Y for draw, Z for win).
The program needs to select what input it should play to get the desired outcome, with the final score being tabulated the same as
in part 1. 

Day 2 prompt found at: https://adventofcode.com/2022/day/2
For my input file, D2Input.txt, an output of 13693 is expected
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
            char oppIn = ' '; 
            switch(line[0]){
                case('A'):
                    oppIn = 'X'; 
                    break; 
                case('B'):
                    oppIn = 'Y'; 
                    break; 
                case('C'):
                    oppIn = 'Z'; 
                    break;  
            }

            switch(line[2]){
                case('X'): //player must lose
                   grandTotal += tallyRound(rpsMap[oppIn], oppIn); 
                    break; 
                case('Y'): //player must draw
                    grandTotal += tallyRound(oppIn, oppIn); 
                    break; 
                case('Z'): //player must win
                    for (const auto& [key, value] : rpsMap){ //searches for a key via its value
                        if (value == oppIn){
                            grandTotal += tallyRound(key, oppIn); 
                        }
                    }
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