#!/bin/bash

# SIT111 - 2.5C Scripting
# Calc the square of a stored number
# shellcheck disable=SC1066
INT=3
SQUARE=$((INT * INT))
echo $SQUARE

# Ask the user for their age
read -p "Please enter your age: " USER_AGE
echo "You are $USER_AGE years old"

# Conditional Branching

# IF ELSE
CURRENT_HOUR=$(date "+%H")

if [ $CURRENT_HOUR -lt 12 ]; then
  echo "Good morning $USER"
  else
    echo "Good evening $USER"
fi

# CASE
read -p "Please choose an option: (1) Start, (2) Stop, (3) Status: " OPTION

case $OPTION in
  1)
    echo "$USER chose the Starting option."
    ;;
  2)
    echo "$USER chose Stopping option."
    ;;
  3)
    echo "$USER chose the Status option."
    ;;
  *) # Default case
    echo "Invalid option"
    ;;
esac

# FOR LOOP - sets an iterator to the value of the COUNTDOWN_SECS
read -p "Please enter the number of seconds to countdown: " COUNTDOWN_SECS

for ((i = COUNTDOWN_SECS; i > 0; i--)); do
  echo "$i"
  sleep 1 # Without this the script will appear to echo COUNTDOWN_SECS for the current iteration almost instantly
done
echo "Time's up!"

# WHILE LOOP - find a valid age for the user
LEGAL_DRINKING_AGE=18
read -p "Please enter your age: " USER_AGE

while [ $USER_AGE -lt $LEGAL_DRINKING_AGE ]; do
  echo "You are too young to drink alcohol"1
  read -p "Please enter your age: " USER_AGE
done

# EXTENDED CASE STATEMENT - user to choose option until choosing to `exit`.
read -p "Please choose an option: (1) Start, (2) Stop, (3) Status, (4) Exit: " OPTION

while [ $OPTION -ne 4 ]; do
  case $OPTION in
    1)
      echo "$USER chose the Starting option."
      read -p "Please choose an option: (1) Start, (2) Stop, (3) Status, (4) Exit: " OPTION
      ;;
    2)
      echo "$USER chose Stopping option."
      read -p "Please choose an option: (1) Start, (2) Stop, (3) Status, (4) Exit: " OPTION
      ;;
    3)
      echo "$USER chose the Status option."
      read -p "Please choose an option: (1) Start, (2) Stop, (3) Status, (4) Exit: " OPTION
      ;;
    4)
      echo "$USER chose the Exit option. Bye!!."
      read -p "Please choose an option: (1) Start, (2) Stop, (3) Status, (4) Exit: " OPTION
      ;;
    *) # Default case
      echo "Invalid option"
      ;;
  esac
done