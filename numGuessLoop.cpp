// Copyright Carolyn
// Created by: Carolyn Webster Pless
// Created on: 22/11/08
// Generates a random number from 0 to 9 then
// uses a Do..While loop to keep getting user inputs
// Until it is the same as the random number.
// Then, the loop breaks.

#include <iostream>
#include <random>
#include <string>

int main() {
    // Variables
    std::string userGuessString;
    int userGuessInt;
    float userGuessFloat;
    int correctNumber;

    // Title
    std::cout << "Guess The Number \n";

    // generating a random number
    std::random_device rseed;

    std::mt19937 rgen(rseed());

    std::uniform_int_distribution<int> idist(0, 9);

    // random number variable
    correctNumber = idist(rgen);

    do {
        // User Input
        std::cout << "Guess a number between 0 and 9:";
        std::cin >> userGuessString;

        // Try catch statement to check errors
        try {
            userGuessInt = std::stoi(userGuessString);
            float userGuessFloat = stof(userGuessString);

            // To make sure the user guess is not a decimal
            if (userGuessFloat != static_cast<int>(userGuessFloat)
            || userGuessFloat < 0) {
                std::cout << "Please enter a whole number!\n";
            } else {
                // To make sure the guess is between 0 and 9
                if (userGuessInt >= 0 && userGuessInt <= 9) {
                    // If the guess is the same as the random number
                    if (userGuessInt == correctNumber) {
                        std::cout << "You've guessed the number correctly! \n";
                        break;
                    } else {
                        std::cout <<
                        "You've guessed the number incorrectly. Try again! \n";
                    }
                } else {
                    std::cout << "Please enter a number between 0 and 9! \n";
                }
            }
        } catch (std::invalid_argument) {
            std::cout << "Please enter an integer! (whole number) \n";
        }
    } while (true);
}
