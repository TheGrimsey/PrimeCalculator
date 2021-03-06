// PrimeCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <chrono>

bool isPrime(unsigned int number, std::vector<int> existingPrimes = std::vector<int>()) {
	for (int i : existingPrimes) {
		if (number % i == 0) return false;
	}
	return true;
}

int main()
{
    std::cout << "How many primes would you like to calculate?!" << std::endl;
	unsigned int amountToCalculate;
	std::cin >> amountToCalculate;
	if (std::cin.fail()){
		std::cout << "Not a valid integer. Must be a number and positivt.";
		return 1;
	}

	std::vector<int> primes;
	primes.reserve(amountToCalculate);
	for (int i = 2; primes.size() < amountToCalculate; i++) {
		if (isPrime(i, primes))primes.emplace_back(i);
	}

	std::stringstream primesString;
	for (int i : primes) {
		primesString << i << ", ";
	}

	std::cout << primesString.str();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
