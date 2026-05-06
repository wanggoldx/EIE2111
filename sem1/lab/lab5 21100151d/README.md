# Lab 5: Recursion

## Overview

This lab introduces recursive functions:
- Prime number checking
- Recursive power calculation
- Functions calling themselves

## How to Set Up

1. Open `lab5.sln` in Visual Studio
2. Build the solution

## How to Run

1. Open the solution in Visual Studio
2. Press `F5` or click Debug > Start Debugging

## Questions (Programs)

### Question 1: Prime Number Generator
- Input: two integers (range)
- Output: all prime numbers in the range
- Counts total primes found

### Question 2: Recursive Power
- Input: base and exponent
- Output: base^exponent calculated recursively

## Key Functions

| Function | Description |
|----------|------------|
| checkprime(int) | Checks if a number is prime (divisible only by 1 and itself) |
| calpowerrecus(int, int) | Calculates power using recursion |

## Recursion Explanation

### Prime Check
- Count divisors from 1 to n
- If exactly 2 divisors found, n is prime

### Power Calculation
- Uses static variable to accumulate result
- Multiplies base by itself (exponent-1) times
- Base case: when exponent reaches 0, return 1

## Student

Lau Wang Chun (ID: 21100151d)