#ifndef DECRYPT_SIMPLE_COLUMNAR_HPP_INCLUDED
#define DECRYPT_SIMPLE_COLUMNAR_HPP_INCLUDED

#include <string>
#include <vector>
using namespace std;

void decryptSimpleColumnar(string& encryptedText, int columnsCount) {
    string auxiliaryText = encryptedText;
    int lengthText = encryptedText.size();
    int linesCount;

    if (lengthText % columnsCount == 0) {
        linesCount = lengthText / columnsCount;
    } else {
        linesCount = lengthText / columnsCount + 1;
    }

    vector<vector<char > > matrix(linesCount, vector<char>(columnsCount, '-'));

    int k = 0;
    for (int i = 0; i < linesCount; i++) {
        for (int j = 0; j < columnsCount; j++) {
            if (k < lengthText) {
                matrix[i][j] = '@';
                k++;
            }
        }
    }

    k = 0;
    for (int i = 0; i < linesCount; i++) {
        for (int j = 0; j < columnsCount; j++) {
            if (k < lengthText && matrix[i][j] != '-') {
                matrix[i][j] = encryptedText[k];
                k++;
            }
        }
    }

    k = 0;
    for (int j = 0; j < columnsCount; j++) {
        for (int i = 0; i < linesCount; i++) {
            if (matrix[i][j] != '-') {
                auxiliaryText[k] = matrix[i][j];
                k++;
            }
        }
    }

    auxiliaryText.resize(k);
    encryptedText = auxiliaryText;
}

#endif
