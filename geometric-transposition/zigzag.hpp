#ifndef ZIGZAG_HPP_INCLUDED
#define ZIGZAG_HPP_INCLUDED

#include <string>
#include <cmath>
#include <vector>
using namespace std;

void zigzag(string& text) {
    int lengthText = text.length();
    string auxiliaryText(lengthText, ' ');

    int linesCount, columnsCount;

    int squareRootLengthText = static_cast<int>(sqrt(lengthText));

    linesCount = columnsCount = squareRootLengthText;
    while (columnsCount * linesCount < lengthText) {
        linesCount++;
    }

    vector<vector<char > > matrix(linesCount, vector<char>(columnsCount, '-'));

    char state = 'r';
    int k = 0;
    for (int i = 0; i < linesCount; i++) {
        if (state == 'r') {
            for (int j = 0; j < columnsCount; j++) {
                if (k < lengthText) {
                    matrix[i][j] = text[k++];
                } else {
                    matrix[i][j] = '-';
                }
            }

            state = 'l';
        } else {
            for (int j = columnsCount - 1; j >= 0; j--) {
                if (k < lengthText) {
                    matrix[i][j] = text[k++];
                } else {
                    matrix[i][j] = '-';
                }
            }

            state = 'r';
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