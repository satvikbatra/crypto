#include <iostream>
#include "default-inclusions.hpp"
#include "./encrypt-text.hpp"
#include "./decrypt-text.hpp"
#include "set-text.hpp"
#include "show-text.hpp"
using namespace std;

int main() {
    int option;
    do {
        system("cls");
        cout << "Cryptography with Geometric Transposition\n\n";
        cout << "1 - Encrypt Text\n";
        cout << "2 - Decrypt Text\n";
        cout << "3 - Set texts\n";
        cout << "4 - Show Texts in the files\n";
        cout << "0 - Exit\n\n";
        cout << "OPTION: ";
        cin >> option;
        cin.ignore();
        switch(option) {
            case 1:
                encryptText();
                break;
            case 2:
                decryptText();
                break;
            case 3:
                setTexts();
                break;
            case 4:
                showTexts();
                break;
            case 0:
                cout << "\n\nExiting...\n\n";
                system("pause");
                break;
            default:
                cout << "\n\nInvalid option!\n\n";
                system("pause");
                break;
        }
    } while(option < 0 || option > 3 || option != 0);
    return 0;
}

