'''
Python code for part 1 of Day 1, Advent of Code '22; transcribed from C++ file

Given a text file of numbers, determines which section of 
numbers has the highest number of "calories"

Prompt from: https://adventofcode.com/2022/day/1
For my given text file (Day1Input.txt), output of "69883" expected
'''

def main(): 
  curElf, topElf, curCal, topCal = 1,0,0,0
  f = open("Day1Input.txt", "r")
  for line in f:  
    
    if (line == '\n'): 
      if (curCal > topCal):
        topCal = curCal
        topElf = curElf
      curElf += 1
      curCal = 0

    else: 
      curCal += int(line)

  #final check if text file ends with content rather than blank line
  if (curCal > topCal):
    topCal = curCal
    topElf = curElf
  print("Elf", +topElf, "is carrying", +topCal, "calories.")

main()
