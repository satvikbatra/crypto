#ifndef SHOW_TEXTS_HPP_INCLUDED
#define SHOW_TEXTS_HPP_INCLUDED

#include "default-inclusions.hpp"

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

void showTexts() {
    ifstream f_OriginalText("original-text.txt");
    ifstream f_EncryptedText("encrypted-text.txt");
    ifstream f_ResultText("result-text.txt");

    string originalText;
    string encryptedText;
    string resultText;

    if (f_OriginalText.is_open()) {
        getline(f_OriginalText, originalText);
    } else {
        originalText = "file not found";
    }

    if (f_EncryptedText.is_open()) {
        getline(f_EncryptedText, encryptedText);
    } else {
        encryptedText = "file not found";
    }

    if (f_ResultText.is_open()) {
        getline(f_ResultText, resultText);
    } else {
        resultText = "file not found";
    }

    system("cls");

    cout << "Cryptography with Geometric Transposition\n\n";
    cout << "[SHOWING ALL TEXTS FROM THE FILES]\n\n";
    cout << "'original-text.txt'  = " << originalText << "\n";
    cout << "'encrypted-text.txt' = " << encryptedText << "\n";
    cout << "'result-text.txt'    = " << resultText << "\n\n";
    system("pause");
}

#endif
