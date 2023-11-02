#ifndef DECRYPT_EXTERNAL_SPIRAL_HPP_INCLUDED
#define DECRYPT_EXTERNAL_SPIRAL_HPP_INCLUDED

#include <cstring>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

void decryptExternalSpiral(string& encryptedText) {
    int lengthText = encryptedText.length();
    string auxiliaryText(lengthText, ' ');

    int linesCount, columnsCount;
    int squareRootLengthText = static_cast<int>(sqrt(lengthText));

    linesCount = columnsCount = squareRootLengthText;
    while (columnsCount * linesCount < lengthText) {
        linesCount++;
    }

    vector<vector<char>> matrix(linesCount, vector<char>(columnsCount, '-'));

    for (int i = 0; i < linesCount; i++) {
        for (int j = 0; j < columnsCount; j++) {
            matrix[i][j] = '-';
        }
    }

    int i = 0, j = 0, k = 0;
    char state = 'r';

    vector<int> verticalLimit = {1, linesCount - 1};
    vector<int> horizontalLimit = {0, columnsCount - 1};

    while (k < lengthText) {
        switch (state) {
            case 'r':
                while (j <= horizontalLimit[1] && k++ < lengthText) {
                    matrix[i][j++] = '@';
                }
                j--;
                i++;
                horizontalLimit[1]--;
                state = 'd';
                break;

            case 'd':
                while (i <= verticalLimit[1] && k++ < lengthText) {
                    matrix[i++][j] = '@';
                }
                i--;
                j--;
                verticalLimit[1]--;
                state = 'l';
                break;

            case 'l':
                while (j >= horizontalLimit[0] && k++ < lengthText) {
                    matrix[i][j--] = '@';
                }
                j++;
                i--;
                horizontalLimit[0]++;
                state = 'u';
                break;

            case 'u':
                while (i >= verticalLimit[0] && k++ < lengthText) {
                    matrix[i--][j] = '@';
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
                    matrix[i][j] = encryptedText[k++];
                }
            }
            currentLine++;
        } else {
            for (i = currentLine - 1, j = currentColumn; j < columnsCount; i--, j++) {
                if (matrix[i][j] != '-') {
                    matrix[i][j] = encryptedText[k++];
                }
            }
            currentColumn++;
        }
    }

    i = 0, j = 0, k = 0;
    state = 'r';

    verticalLimit[0] = 1;
    verticalLimit[1] = linesCount - 1;

    horizontalLimit[0] = 0;
    horizontalLimit[1] = columnsCount - 1;

    while (k < lengthText) {
        switch (state) {
            case 'r':
                while (j <= horizontalLimit[1] && k < lengthText) {
                    if (matrix[i][j] != '-') {
                        auxiliaryText[k++] = matrix[i][j++];
                    }
                }
                j--;
                i++;
                horizontalLimit[1]--;
                state = 'd';
                break;

            case 'd':
                while (i <= verticalLimit[1] && k < lengthText) {
                    if (matrix[i][j] != '-') {
                        auxiliaryText[k++] = matrix[i++][j];
                    }
                }
                i--;
                j--;
                verticalLimit[1]--;
                state = 'l';
                break;

            case 'l':
                while (j >= horizontalLimit[0] && k < lengthText) {
                    if (matrix[i][j] != '-') {
                        auxiliaryText[k++] = matrix[i][j--];
                    }
                }
                j++;
                i--;
                horizontalLimit[0]++;
                state = 'u';
                break;

            case 'u':
                while (i >= verticalLimit[0] && k < lengthText) {
                    if (matrix[i][j] != '-') {
                        auxiliaryText[k++] = matrix[i--][j];
                    }
                }
                i++;
                j++;
                verticalLimit[0]++;
                state = 'r';
                break;
        }
    }

    auxiliaryText[k] = '\0';

    encryptedText = auxiliaryText;
}

#endif
