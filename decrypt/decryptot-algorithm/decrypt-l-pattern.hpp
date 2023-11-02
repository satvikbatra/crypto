#ifndef DECRYPT_L_PATTERN_HPP_INCLUDED
#define DECRYPT_L_PATTERN_HPP_INCLUDED

#include <string>
#include <cmath>
#include <vector>
using namespace std;

void decryptLPattern(string& encryptedText) {
    int lengthText = encryptedText.length();
    string auxiliaryText(lengthText, ' ');

    int linesCount, columnsCount;
    int squareRootLengthText = static_cast<int>(sqrt(lengthText));

    linesCount = columnsCount = squareRootLengthText;
    while (columnsCount * linesCount < lengthText) {
        columnsCount++;
    }

    vector<vector<char>> matrix(linesCount, vector<char>(columnsCount, '-'));

    int i = 0, j = 0, k = 0;
    char state = 'd';

    int inputVerticalLimit = linesCount - 1;
    int inputHorizontalLimit = 0;

    while (k < lengthText) {
        switch (state) {
            case 'd':
                while (i <= inputVerticalLimit && k < lengthText) {
                    matrix[i++][j] = '@';
                    k++;
                }

                i--;
                j++;
                state = 'R';
                inputHorizontalLimit++;
                break;

            case 'R':
                while (j <= columnsCount - 1 && k < lengthText) {
                    matrix[i][j++] = '@';
                    k++;
                }

                j--;
                i--;
                state = 'u';
                inputVerticalLimit--;
                break;

            case 'u':
                matrix[i][j--] = '@';
                state = 'l';
                k++;
                break;

            case 'l':
                while (j >= inputHorizontalLimit && k < lengthText) {
                    matrix[i][j--] = '@';
                    k++;
                }

                j++;
                i--;
                state = 'U';
                inputVerticalLimit--;
                break;

            case 'U':
                while (i >= 0 && k < lengthText) {
                    matrix[i--][j] = '@';
                    k++;
                }

                i++;
                j++;
                state = 'r';
                inputHorizontalLimit++;
                break;

            case 'r':
                matrix[i++][j] = '@';
                state = 'd';
                k++;
                break;
        }
    }

    i = 0;
    j = 0;
    k = 0;
    int currentLine = linesCount - 1;
    int currentColumn = 1;
    while (k < lengthText) {
        if (currentLine >= 0) {
            for (i = currentLine, j = 0; i < linesCount && j < columnsCount; i++, j++) {
                if (matrix[i][j] != '-') {
                    matrix[i][j] = encryptedText[k++];
                }
            }
            currentLine--;
        } else {
            for (i = 0, j = currentColumn; j < columnsCount; i++, j++) {
                if (matrix[i][j] != '-') {
                    matrix[i][j] = encryptedText[k++];
                }
            }
            currentColumn++;
        }
    }

    i = 0;
    j = 0;
    k = 0;
    state = 'd';

    inputVerticalLimit = linesCount - 1;
    inputHorizontalLimit = 0;

    while (k < lengthText) {
        switch (state) {
            case 'd':
                while (i <= inputVerticalLimit && k < lengthText) {
                    auxiliaryText[k++] = matrix[i++][j];
                }

                i--;
                j++;
                state = 'R';
                inputHorizontalLimit++;
                break;

            case 'R':
                while (j <= columnsCount - 1 && k < lengthText) {
                    auxiliaryText[k++] = matrix[i][j++];
                }

                j--;
                i--;
                state = 'u';
                inputVerticalLimit--;
                break;

            case 'u':
                auxiliaryText[k++] = matrix[i][j--];
                state = 'l';
                break;

            case 'l':
                while (j >= inputHorizontalLimit && k < lengthText) {
                    auxiliaryText[k++] = matrix[i][j--];
                }

                j++;
                i--;
                state = 'U';
                inputVerticalLimit--;
                break;

            case 'U':
                while (i >= 0 && k < lengthText) {
                    auxiliaryText[k++] = matrix[i--][j];
                }

                i++;
                j++;
                state = 'r';
                inputHorizontalLimit++;
                break;

            case 'r':
                auxiliaryText[k++] = matrix[i++][j];
                state = 'd';
                break;
        }
    }

    auxiliaryText[k] = '\0';

    encryptedText = auxiliaryText;
}

#endif
