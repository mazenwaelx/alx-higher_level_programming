#!/usr/bin/python3
def fizzbuzz():
    if num % 3 == 0:
        print("Fizz", end=" ")
    elif num % 5 == 0:
        print("Buzz", end=" ")
    elif num % 5 == 0 and num % 3 == 0:
        print("FizzBuzz", end=" ")
    else:
        print(f"{num:d}");
