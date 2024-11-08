/*
Part 1 of Day 3

Day 3 prompt found at: https://adventofcode.com/2022/day/3
For my input file, D3Input.txt, an output of 
*/

#include <iostream> 
#include <fstream>
#include <algorithm>
#include <vector>

std::string alphabet = "abcdefghijklmnopqrstuvwxyz"; //it the alphabet, silly :) 
std::vector<char> firstHalf; 
std::vector<char> secondHalf; 
std::string txtPath = "D3Input.txt"; 

int compareHalves(std::string line){
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
        if (count(secondHalf.begin(), secondHalf.end(), currentChar) == 1){
            for(int j = 0; j < alphabet.length(); j++){
                if (alphabet[j] == currentChar){
                    std::cout << alphabet[j] << " "; 
                    std::cout << "Matching character: " << currentChar << std::endl; 
                    ruckID = j+1; 
                    break; 
                }

                else if (toupper(alphabet[j]) == currentChar){
                    std::cout << toupper(alphabet[j]) << std::endl; 
                    std::cout << "Matching character: " << currentChar << std::endl;
                    ruckID = j+1 + alphabet.length(); 
                    break; 
                }
            }
        }

        else{
            while(firstHalf[i] == firstHalf[i+1]){ //progresses index i to the next unique character to prevent redundancy
                i += 1; 
            }
        }
    }
    firstHalf.clear(); 
    secondHalf.clear(); 
    std::cout << ruckID << std::endl; 
    return (ruckID); 
}

int main(){
    std::ifstream inFile;
    inFile.open(txtPath);  
    std::string line; 
    int ruckTotal = 0; 
    if (inFile.is_open()){ 
        while (std::getline(inFile, line)){
            ruckTotal += compareHalves(line); 
        }
        inFile.close(); 
        std::cout << "Total amount: " << ruckTotal << std::endl; 
    }
    
    else{
        std::cout << "File is not open" << std::endl; 
    }

    return 0; 
}