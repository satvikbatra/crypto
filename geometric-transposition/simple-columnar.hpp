#ifndef SIMPLE_COLUMNAR_HPP_INCLUDED
#define SIMPLE_COLUMNAR_HPP_INCLUDED

#include <string>
#include <vector>
using namespace std;

void simpleColumnar(string& text, int linesCount) {
    int lengthText = text.length();
    string auxiliaryText(lengthText, ' ');
    int columnsCount;

    if (lengthText % linesCount == 0) {
        columnsCount = lengthText / linesCount;
    } else {
        columnsCount = lengthText / linesCount + 1;
    }

    vector<vector<char>> matrix(linesCount, vector<char>(columnsCount, '-'));

    int k = 0;
    for (int i = 0; i < linesCount; i++) {
        for (int j = 0; j < columnsCount; j++) {
            if (k < lengthText) {
                matrix[i][j] = text[k++];
            } else {
                matrix[i][j] = '-';
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
