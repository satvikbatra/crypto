#ifndef EXTERNAL_SPIRAL_HPP_INCLUDED
#define EXTERNAL_SPIRAL_HPP_INCLUDED

#include <string>
#include <cmath>
#include <vector>
using namespace std;

void externalSpiral(string& text) {
    int lengthText = text.length();
    string auxiliaryText(lengthText, ' ');

    int linesCount, columnsCount;

    int squareRootLengthText = static_cast<int>(sqrt(lengthText));

    linesCount = columnsCount = squareRootLengthText;
    while (columnsCount * linesCount < lengthText) {
        linesCount++;
    }

    vector<vector<char>> matrix(linesCount, vector<char>(columnsCount, '-'));

    int i = 0, j = 0, k = 0;
    char state = 'r';

    vector<int> verticalLimit = { 1, linesCount - 1 };
    vector<int> horizontalLimit = { 0, columnsCount - 1 };

    while (k < lengthText) {
        switch (state) {
            case 'r':
                while (j <= horizontalLimit[1] && k < lengthText) {
                    matrix[i][j++] = text[k++];
                }
                j--;
                i++;
                horizontalLimit[1]--;
                state = 'd';
                break;

            case 'd':
                while (i <= verticalLimit[1] && k < lengthText) {
                    matrix[i++][j] = text[k++];
                }
                i--;
                j--;
                verticalLimit[1]--;
                state = 'l';
                break;

            case 'l':
                while (j >= horizontalLimit[0] && k < lengthText) {
                    matrix[i][j--] = text[k++];
                }
                j++;
                i--;
                horizontalLimit[0]++;
                state = 'u';
                break;

            case 'u':
                while (i >= verticalLimit[0] && k < lengthText) {
                    matrix[i--][j] = text[k++];
                }
                i++;
                j++;
                verticalLimit[0]++;
                state = 'r';
                break;
        }
    }

    k = 0;
    int currentLine = 0, currentColumn = 1;

    while (k < lengthText) {
        if (currentLine < linesCount) {
            for (i = currentLine, j = 0; i >= 0 && j < columnsCount; i--, j++) {
                if (matrix[i][j] != '-') {
                    auxiliaryText[k++] = matrix[i][j];
                }
            }
            currentLine++;
        } else {
            for (i = currentLine - 1, j = currentColumn; j < columnsCount; i--, j++) {
                if (matrix[i][j] != '-') {
                    auxiliaryText[k++] = matrix[i][j];
                }
            }
            currentColumn++;
        }
    }

    text = auxiliaryText;
}

#endif
