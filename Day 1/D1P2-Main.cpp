/* Code for part 2 of Day 1, Advent of Code 2022
Given a text file of numbers, determines which 3 sections of 
numbers have the highest number of "calories", return their
values in order

Prompt from: https://adventofcode.com/2022/day/1
For my given text file (Day1Input.txt), output of "203002" expected
*/  

#include <iostream>
#include <fstream> 
using namespace std; 

void calCompare(int& first, int& second, int& third, int& current){
  int temp = 0; 
  if(current > third){
    third = current; 
    
    if(third > second){
      temp = second; 
      second = third; 
      third = temp; 
      
      if(second > first){
        temp = first; 
        first = second; 
        second = temp; 
      }
    }
  } 
  return;  
}

int main() { 
  int curCal = 0, firstCal = 0, secondCal = 0, thirdCal = 0; 
  string line; 

  ifstream inFile; 
  inFile.open("Day1Input.txt"); 

  //Checks each group of numbers, linewise; compares totals in order, records the highest amount & its index
  while(getline(inFile, line)){
    if(line.empty()){ 
      calCompare(firstCal, secondCal, thirdCal, curCal); 
      curCal = 0; 
    }
    else{
      curCal += stoi(line); 
    }
  }

  //Checks final group of numbers if text file ends with a number rather than a blank space
  calCompare(firstCal, secondCal, thirdCal, curCal); 

  inFile.close(); 

  cout << "Sum of top 3 calorie counts = " << firstCal + secondCal + thirdCal; 

  return 0;
}