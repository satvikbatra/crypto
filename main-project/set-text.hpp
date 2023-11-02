#ifndef SET_TEXTS_HPP_INCLUDED
#define SET_TEXTS_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#include "default-inclusions.hpp"

void setTexts() {
    int option;
    char originalText[MAX_LENGTH_TEXT];

    do {
        system("cls");

        cout << "Cryptography with Geometric Transposition\n\n";
        cout << "[SET TEXTS]\n\n";
        cout << "Choose a file\n\n";
        cout << "1 - Original Text ('original-text.txt')\n";
        cout << "2 - Encrypted Text ('encrypted-text.txt')\n";
        cout << "3 - Result Text ('result-text.txt')\n";
        cout << "0 - Back\n\n";
        cout << "OPTION: ";
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (option) {
            case 1: {
                ofstream f_OriginalText("original-text.txt");
                char originalText[MAX_LENGTH_TEXT];

                cout << "\nEnter the Original Text: ";
                cin.getline(originalText, MAX_LENGTH_TEXT);

                removeInvalidCharacters(originalText);
                replaceEquivalentCharacters(originalText);

                f_OriginalText << originalText;

                cout << "\nSaved successfully!\n\n";
                break;
            }

            case 2: {
                ofstream f_EncryptedText("encrypted-text.txt");
                char encryptedText[MAX_LENGTH_TEXT];

                cout << "\nEnter the Encrypted Text: ";
                cin.getline(encryptedText, MAX_LENGTH_TEXT);

                removeInvalidCharacters(encryptedText);
                replaceEquivalentCharacters(encryptedText);

                f_EncryptedText << encryptedText;

                cout << "\nSaved successfully!\n\n";
                break;
            }

            case 3: {
                ofstream f_ResultText("result-text.txt");
                char resultText[MAX_LENGTH_TEXT];

                cout << "\nEnter the Result Text: ";
                cin.getline(resultText, MAX_LENGTH_TEXT);

                removeInvalidCharacters(resultText);
                replaceEquivalentCharacters(resultText);

                f_ResultText << resultText;

                cout << "\nSaved successfully!\n\n";
                break;
            }

            case 0:
                break;

            default:
                cout << "\n\nInvalid option!\n\n";
                break;
        }

    } while (option < 0 || option > 3);

    if (option != 0) {
        system("pause");
    }
}

#endif
