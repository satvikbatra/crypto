#ifndef TRIANGULAR_HPP_INCLUDED
#define TRIANGULAR_HPP_INCLUDED

#include <string>
#include <vector>
using namespace std;

void triangular(string& text) {
    int lengthText = text.length();
    string auxiliaryText(lengthText, ' ');

    int linesCount = 1;
    int columnsCount;

    int maxCharPyramid = 1;
    int maxCharLastLine = 1;

    while (maxCharPyramid < lengthText) {
        maxCharLastLine += 2;
        maxCharPyramid += maxCharLastLine;
        linesCount++;
    }

    columnsCount = maxCharLastLine;

    vector<vector<char>> matrix(linesCount, vector<char>(columnsCount, '-'));

    int maxCharCurrentLine = 1;
    int k = 0;
    for (int i = 0; i < linesCount; i++, maxCharCurrentLine += 2) {
        for (int j = (columnsCount / 2) - i, l = 0, quant = 0; l < columnsCount; l++) {
            if (l != j || k >= lengthText) {
                matrix[i][l] = '-';
            } else {
                matrix[i][j++] = text[k++];
                quant++;
                if (quant >= maxCharCurrentLine) {
                    j = -1;
                }
            }
        }
    }

    k = 0;
    for (int j = 0; j < columnsCount; j++) {
        for (int i = 0; i < linesCount; i++) {
            if (matrix[i][j] != '-') {
                auxiliaryText[k++] = matrix[i][j];
            }
        }
    }

    auxiliaryText.resize(k);

    text = auxiliaryText;
}

#endif
