#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  

void drawHangman(int attempts) {
    std::cout << "--------" << std::endl;
    std::cout << "|      |" << std::endl;

    if (attempts < 6)
        std::cout << "|      O" << std::endl;
    else
        std::cout << "|" << std::endl;

    if (attempts < 5)
        std::cout << "|      |" << std::endl;
    else
        std::cout << "|" << std::endl;

    if (attempts < 4)
        std::cout << "|     /";
    else
        std::cout << "|";

    if (attempts < 3)
        std::cout << "|\\";
    else
        std::cout << " ";

    if (attempts < 3)
        std::cout << "\\";
    else
        std::cout << " ";

    if (attempts < 4)
        std::cout << "/" << std::endl;
    else
        std::cout << std::endl;

    if (attempts < 2)
        std::cout << "|     /";
    else
        std::cout << "|";

    if (attempts < 1)
        std::cout << " \\";
    else
        std::cout << " ";

    if (attempts < 1)
        std::cout << " /";
    else
        std::cout << " ";

    std::cout << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "========" << std::endl;
}

bool contains(const std::string& word, char letter) {
    return word.find(letter) != std::string::npos;
}

void displayWord(const std::string& secretWord, const std::vector<char>& guessedLetters) {
    for (char letter : secretWord) {
        if (std::find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end()) {
            std::cout << letter << " ";
        } else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

int main() {
    const int maxAttempts = 6;
    std::string secretWord = "kristal";
    std::vector<char> guessedLetters;
    int attempts = 0; // Deklarera och initialisera variabeln attempts

    std::cout << "Welcome to Hangman!" << std::endl;

    bool won = false; // Skapa en variabel för att hålla koll på om spelaren har vunnit
    while (attempts < maxAttempts) {
        drawHangman(attempts);
        std::cout << "Guessed letters: ";
        for (char letter : guessedLetters) {
            std::cout << letter << " ";
        }
        std::cout << std::endl;

        displayWord(secretWord, guessedLetters);

        bool allGuessed = true; // Skapa en variabel för att hålla koll på om alla bokstäver har gissats
        for (char letter : secretWord) {
            if (std::find(guessedLetters.begin(), guessedLetters.end(), letter) == guessedLetters.end()) {
                allGuessed = false;
                break;
            }
        }

        if (allGuessed) { // Kolla om alla bokstäver har gissats korrekt
            won = true;
            break; // Bryt ur loopen om spelaren har vunnit
        }

        std::cout << "Guess a letter: ";
        char guess;
        std::cin >> guess;

        if (contains(secretWord, guess)) {
            std::cout << "Correct guess!" << std::endl;
            guessedLetters.push_back(guess);
        } else {
            std::cout << "Incorrect guess!" << std::endl;
            attempts++;
        }
    }

    if (won) {
        std::cout << "Congratulations! You won and good luck for the future!" << std::endl;
    } else {
        std::cout << "Sorry, you lost. The word was: " << secretWord << std::endl;
        drawHangman(maxAttempts);
    }

    return 0;
}
