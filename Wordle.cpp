#include <iostream>
#include <random>
#include <algorithm>
#include "Wordle.h"
using namespace std;

Wordle::Wordle() {
    words = {
        "salt", "doubt", "bag", "organization", "mother", "now",
        "silver", "animal", "impulse", "sign", "harmony", "stage",
        "fight", "cough", "comfort", "theory", "net", "liquid",
        "roof", "pin", "sugar", "fish", "hand", "receipt",
        "agreement", "sneeze", "mass", "attention"
    };
    score = 0;
    attempt = 0;
    index = 0;
    randIndex = 0;
    correct = false;
    correctLength = false;
}

void Wordle::PlayWordle() {
    system("cls");
    random_device rd;
    uniform_int_distribution<int> dist(0, words.size() - 1);
    randIndex = dist(rd);
    secretWord = words[randIndex];
    hint = string(secretWord.length(), '_');
	words.erase(words.begin() + randIndex);

    cout << "Your initial hint is a " << secretWord.length() << " letter word!" << endl;
    cout << "Type 'quit' to exit the game" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempt++;
        if (guess == "quit") {
            cout << "That's okay! The word was " << secretWord << "!" << endl;
            clearConsole();
        }

        if (guess.length() != secretWord.length()) {
            cout << "You used the wrong number of letters, try again." << endl;
            correctLength = false;
        }
        else {
            correctLength = true;
        }

        if (guess == secretWord) {
            score++;
            cout << "Congratulations! You guessed the word!\nThe word was "
                << secretWord << "! \nIt took you " << attempt
                << " attempts. Your score is now " << score << endl;
            cout << "Would you like to play again?(y/n) ";
            cin >> playAgain;
            if (playAgain == "y") {
                attempt = 0;
                clearConsole();
                PlayWordle();
            }
            else {
                cout << "Thanks for playing!" << endl;
                clearConsole();
                break;
            }
            correct = true;
        }

        if (correctLength) {
            GiveHint();
            cout << "Your hint is " << hint << endl;
        }
    } while (!correct && guess != "quit");
}

void Wordle::GiveHint() {
    string lowercaseSecretWord = secretWord;
    transform(lowercaseSecretWord.begin(), lowercaseSecretWord.end(), lowercaseSecretWord.begin(), ::tolower);

    for (int i = 0; i < secretWord.size(); ++i) {
        if (guess[i] == secretWord[i]) {
            hint[i] = toupper(guess[i]);
        }
        else if (lowercaseSecretWord.find(tolower(guess[i])) != string::npos) {
            hint[i] = tolower(guess[i]);
        }
        else {
            hint[i] = '_';
        }
    }
}
