#ifndef L_PATTERN_HPP_INCLUDED
#define L_PATTERN_HPP_INCLUDED

#include <string>
#include <cmath>
#include <vector>
using namespace std;

void lPattern(string& text) {
    int lengthText = text.length();
    string auxiliaryText(lengthText, ' ');

    int linesCount, columnsCount;

    int squareRootLengthText = static_cast<int>(sqrt(lengthText));

    linesCount = columnsCount = squareRootLengthText;
    while (columnsCount * linesCount < lengthText) {
        columnsCount++;
    }

    vector<vector<char > > matrix(linesCount, vector<char>(columnsCount, '-'));

    int i = 0, j = 0, k = 0;
    char state = 'd';

    int inputVerticalLimit = linesCount - 1;
    int inputHorizontalLimit = 0;

    while (k < lengthText) {
        switch (state) {
            case 'd':
                while (i <= inputVerticalLimit && k < lengthText) {
                    matrix[i++][j] = text[k++];
                }

                i--;
                j++;
                state = 'R';
                inputHorizontalLimit++;
                break;

            case 'R':
                while (j <= columnsCount - 1 && k < lengthText) {
                    matrix[i][j++] = text[k++];
                }

                j--;
                i--;
                state = 'u';
                inputVerticalLimit--;
                break;

            case 'u':
                matrix[i][j--] = text[k++];
                state = 'l';
                break;

            case 'l':
                while (j >= inputHorizontalLimit && k < lengthText) {
                    matrix[i][j--] = text[k++];
                }

                j++;
                i--;
                state = 'U';
                inputVerticalLimit--;
                break;

            case 'U':
                while (i >= 0 && k < lengthText) {
                    matrix[i--][j] = text[k++];
                }

                i++;
                j++;
                state = 'r';
                inputHorizontalLimit++;
                break;

            case 'r':
                matrix[i++][j] = text[k++];
                state = 'd';
                break;
        }
    }

    i = 0;
    j = 0;
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
        }
        else {
            for (i = 0, j = currentColumn; j < columnsCount; i++, j++) {
                if (matrix[i][j] != '-') {
                    auxiliaryText[k++] = matrix[i][j];
                }
            }
            currentColumn++;
        }
    }

    auxiliaryText[k] = '\0';

    text = auxiliaryText;
}

#endif
