#ifndef INTERNAL_SPIRAL_HPP_INCLUDED
#define INTERNAL_SPIRAL_HPP_INCLUDED

#include <string>
#include <cmath>
#include <vector>
using namespace std;

void internalSpiral(string& text) {
    int lengthText = text.length();
    string auxiliaryText(lengthText, ' ');

    int linesCount, columnsCount;

    int squareRootLengthText = static_cast<int>(sqrt(lengthText));

    linesCount = columnsCount = squareRootLengthText;
    while (columnsCount * linesCount < lengthText) {
        linesCount++;
    }

    if (linesCount < columnsCount) {
        linesCount = columnsCount;
    } else if (columnsCount < linesCount) {
        columnsCount = linesCount;
    }

    if (linesCount % 2 == 0) {
        linesCount++;
        columnsCount++;
    }

    if ((linesCount - 2) * (columnsCount - 2) >= lengthText) {
        linesCount -= 2;
        columnsCount -= 2;
    }

    vector<vector<char>> matrix(linesCount, vector<char>(columnsCount, '-'));

    int verticalMiddle = (linesCount - 1) / 2;
    int horizontalMiddle = (columnsCount - 1) / 2;

    int i = verticalMiddle, j = horizontalMiddle, k = 0;
    char state = 'r';

    vector<int> verticalLimit = { verticalMiddle - 1, verticalMiddle + 1 };
    vector<int> horizontalLimit = { horizontalMiddle - 1, horizontalMiddle + 1 };

    while (k < lengthText) {
        switch (state) {
            case 'r':
                while (j <= horizontalLimit[1] && k < lengthText) {
                    matrix[i][j++] = text[k++];
                }

                i++;
                j--;
                horizontalLimit[1]++;
                state = 'd';
                break;

            case 'd':
                while (i <= verticalLimit[1] && k < lengthText) {
                    matrix[i++][j] = text[k++];
                }

                i--;
                j--;
                verticalLimit[1]++;
                state = 'l';
                break;

            case 'l':
                while (j >= horizontalLimit[0] && k < lengthText) {
                    matrix[i][j--] = text[k++];
                }

                j++;
                i--;
                horizontalLimit[0]--;
                state = 'u';
                break;

            case 'u':
                while (i >= verticalLimit[0] && k < lengthText) {
                    matrix[i--][j] = text[k++];
                }

                i++;
                j++;
                verticalLimit[0]--;
                state = 'r';
                break;
        }
    }

    k = 0;
    int currentLine = linesCount - 1, currentColumn = 1;

    while (k < lengthText) {
        if (currentLine >= 0) {
            for (i = currentLine, j = 0; i < linesCount && j < columnsCount; i++, j++) {
                if (matrix[i][j] != '-') {
                    auxiliaryText[k++] = matrix[i][j];
                }
            }
            currentLine--;
        } else {
            for (i = 0, j = currentColumn; j < columnsCount; i++, j++) {
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
