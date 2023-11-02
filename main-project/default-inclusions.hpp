#ifndef DEFAULT_INCLUSIONS_HPP_INCLUDED
#define DEFAULT_INCLUSIONS_HPP_INCLUDED

#include <iostream>
#include <cstdlib>
#include <limits>
#include "D:\Crypto\string-processings\remove-invalid-characters.hpp"
#include "D:\Crypto\string-processings\replace-equivalent-characters.hpp"
using namespace std;
#define MAX_LENGTH_TEXT 99999

int showOptions() {
    int option;

    cout << "Choose an option:\n\n";

    cout << "1 - Simple Columnar\n";
    cout << "2 - Triangular\n";
    cout << "3 - External Spiral\n";
    cout << "4 - Internal Spiral\n";
    cout << "5 - Zigzag\n";
    cout << "6 - 'L' Pattern\n";
    cout << "0 - Exit\n";

    cout << "OPTION: ";
    cin >> option;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return option;
}

void showCurrentText(string currentText) {
    cout << "Original Text: " << currentText << "\n\n";
}

#endif