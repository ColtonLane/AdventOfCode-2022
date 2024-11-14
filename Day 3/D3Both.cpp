/*
Day 3 prompt found at: https://adventofcode.com/2022/day/3
Part 1 of Day 3
For each line of the input file, either half of the line will share a case-sensitive letter. 
Only one letter will be shared across each half. This letter determines the value for that line (1-26 = a-z; 27-52 = A-Z). 
Find the total combined value for every line. 
For my input file, D3Input.txt, an output of 7821 is expected

Part 2 of Day 3
For each group of 3 lines (line 0 - line 2, line 3 - line 5, etc.), there will be only one shared, case-sensitive letter
across each line. This character determines the value of the group (1-26 = a-z; 27-52 = A-Z). 
Find the total combined value of each 3-line group. 
For my input file, D3Input.txt, an output of 2752 is expected
*/

#include <iostream> 
#include <fstream>
#include <algorithm>
#include <vector>

std::string alphabet = "abcdefghijklmnopqrstuvwxyz"; //it the alphabet, silly :) 
std::string upperAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //BIG ALPHABET, OH SHIT
std::string txtPath = "D3Input.txt"; 

int returnLetterValue(char c){ //returns the value of the character in relation to the alphabet (a-z = 1-26, A-Z = 27-52)
    int value; 
    for(int j = 0; j < alphabet.length(); j++){
        if (alphabet[j] == c){ 
            value = j+1; 
            break; 
        }

        else if (upperAlphabet[j] == c){
            value = j+1 + alphabet.length(); 
            break; 
        }
    }
    return value; 
}

int compareHalves(std::string line){
    std::vector<char> firstHalf; 
    std::vector<char> secondHalf; 
    int startSecond = line.length()/2; 
    //populates firstHalf vector with the first half of the string
    for(int i = startSecond-1; i >= 0; i--){
        firstHalf.push_back(line[i]); 
    }
    //populates secondHalf vector with the second half of the string
    for (int i = startSecond*2; i >= startSecond; i--){
        secondHalf.push_back(line[i]); 
    }

    //Alphabetically sorts both vectors
    std::sort (firstHalf.begin(), firstHalf.end()); 
    std::sort (secondHalf.begin(), secondHalf.end()); 
    
    int ruckID = 0; //value of the rucksack to be returned; determined in the following 'for' loop
    
    //compares each unique letter in firstHalf to secondHalf
    for (int i = 0; i < firstHalf.size(); i++){
        char currentChar = firstHalf[i]; 
        if (count(secondHalf.begin(), secondHalf.end(), currentChar) > 0){
            ruckID = returnLetterValue(currentChar); 
        }

        else{
            while(firstHalf[i] == firstHalf[i+1]){ //progresses index i to the next unique character to prevent redundancy
                i += 1; 
            }
        }
    }
    firstHalf.clear(); 
    secondHalf.clear(); 
    return (ruckID); 
}

int compareGroups(){
    std::ifstream inFile;
    inFile.open(txtPath);  
    std::string line, first, second; 
    int index, groupsTotal = 0; 

    if(inFile.is_open()){
        while(std::getline(inFile, line)){
            switch(index){
                case 0:
                    first = line; 
                    index = 1; 
                    break; 
                case 1:
                    second = line; 
                    index = 2; 
                    break; 
                case 2:
                    for (int i = 0; i < line.length(); i++){
                        //checks if the current character is found in both the first and second line of the group
                        if (count(first.begin(), first.end(), line[i]) > 0 && count(second.begin(), second.end(), line[i]) > 0){ 
                            groupsTotal += returnLetterValue(line[i]); 
                            break; 
                        }
                    }
                    index = 0; 
                    break; 
            }
        }
    }
    else{
        std::cout << "File is not open" << std::endl; 
    }

    return groupsTotal; 
}

int main(){
    //Part 1
    std::ifstream inFile;
    inFile.open(txtPath);  
    std::string line; 
    int ruckTotal = 0; 

    if (inFile.is_open()){ 
        while (std::getline(inFile, line)){
            ruckTotal += compareHalves(line); 
        }
        inFile.close(); 
        std::cout << "Total amount for Part 1: " << ruckTotal << std::endl; 
    }
    
    else{
        std::cout << "File is not open" << std::endl; 
    }

    //Part 2
    std::cout << "Total amount for Part 2: " << compareGroups() << std::endl; 

    return 0; 
}