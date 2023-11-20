/* Code for part 1 of Day 1, Advent of Code 2022
Given a text file of numbers, determines which section of 
numbers has the highest number of "calories"

Prompt from: https://adventofcode.com/2022/day/1
For my given text file (Day1Input.txt), output of "70369" expected
*/  

#include <iostream>
#include <fstream> 
using namespace std; 

void checkTop (int& topC, int& topE, int& curC, int& curE){
  if (curC > topC){
    topC = curC; 
    topE = curE;
  } 
  return; 
}

int main() {
  int curElf = 0, topElf = 0, topCal = 0; 
  string line; 
  
  ifstream inFile; 
  inFile.open("Day1Input.txt"); 

  //Total of current elf being counted; resets at each blank space
  int curCal = 0; 

  //Checks each group of numbers, linewise; compares totals in order, records the highest amount & its index
  while(getline(inFile, line)){
    if(line.empty()){ 
      if(curCal > topCal){
        checkTop(topCal, topElf, curCal, curElf); 
      }
      curElf++; 
      curCal = 0; 
    }
    else{
      curCal += stoi(line); 
    }
  }
  //Does final check if text file ends with content rather than empty line
  checkTop(topCal, topElf, curCal, curElf); 
  
  inFile.close(); 

  cout << "Elf " << topElf+1 << " is carrying " << topCal << " calories."; 
  
  return 0;
}