#ifndef DECRYPT_TRIANGULAR_H_INCLUDED
#define DECRYPT_TRIANGULAR_H_INCLUDED

#include <string>
using namespace std;

void decryptTriangular(string& encryptedText) {
    int lengthText = encryptedText.length();
    string auxiliaryText;

    int linesCount = 1, columnsCount;

    int maxCharMatrix = 1;
    int maxCharLastLine = 1;

    while (maxCharMatrix < lengthText) {
        maxCharLastLine += 2;
        maxCharMatrix += maxCharLastLine;
        linesCount++;
    }

    columnsCount = maxCharLastLine;

    vector<vector<char > > matrix(linesCount, vector<char>(columnsCount, '-'));

    int maxCharCurrentLine = 1;
    int k = 0;

    for (int i = 0; i < linesCount; i++, maxCharCurrentLine += 2) {
        for (int j = (columnsCount / 2) - i, l = 0, quant = 0; l < columnsCount; l++) {
            if (l != j || k >= lengthText) {
                matrix[i][l] = '-';
            } else {
                matrix[i][j++] = '@';
                quant++;
                if (quant >= maxCharCurrentLine) {
                    j = -1;
                }
                k++;
            }
        }
    }

    k = 0;

    for (int j = 0; j < columnsCount; j++) {
        for (int i = 0; i < linesCount; i++) {
            if (matrix[i][j] != '-') {
                matrix[i][j] = encryptedText[k++];
            }
        }
    }

    maxCharCurrentLine = 1;
    k = 0;

    for (int i = 0; i < linesCount; i++, maxCharCurrentLine += 2) {
        for (int j = (columnsCount / 2) - i, l = 0, quant = 0; l < columnsCount; l++) {
            if (!(l != j || k >= lengthText)) {
                auxiliaryText.push_back(matrix[i][j++]);
                quant++;
                if (quant >= maxCharCurrentLine) {
                    j = -1;
                }
                k++;
            }
        }
    }

    encryptedText = auxiliaryText;
}

#endif
