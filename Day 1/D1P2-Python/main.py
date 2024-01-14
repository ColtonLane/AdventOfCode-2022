'''
Transcribed Python code for part 2 of Day 1, Advent of Code '22

Given a text file of numbers, determines which 3 sections of 
numbers have the highest number of "calories", return their
values in order

Prompt from: https://adventofcode.com/2022/day/1
For my given text file (Day1Input.txt), output of "207576" expected
'''

def calCompare(current, list):
  temp = 0
  if(current > list[2]): 
    list[2] = current

    if (list[2] > list[1]): 
      temp = list[1]
      list[1] = list[2]
      list[2] = temp

      if(list[1] > list[0]): 
        temp = list[0]
        list[0] = list[1]
        list[1] = temp
  return list

def main(): 
  curCal = 0
  topThreeCal = [0,0,0]
  f = open("Day1Input.txt", "r")
  for line in f:  
    
    if (line == '\n'): 
      calCompare(curCal, topThreeCal)
      curCal = 0

    else: 
      curCal += int(line)

  #final check if text file ends with content rather than blank line
  calCompare(curCal, topThreeCal)
  print("Sum of the top three calorie counts:", sum(topThreeCal))

main()
