#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    string startPos, endPos;
    cin >> startPos >> endPos;

    int totalMoves = 0;
    int movesRightUp = 0, movesRight = 0, movesUp = 0, movesDown = 0;
    int movesLeft = 0, movesDownUp = 0, movesRightDown = 0, movesLeftUp = 0, movesLeftDown = 0;

    int horizontalDist = endPos[0] - startPos[0];
    int verticalDist = endPos[1] - startPos[1];

    if (horizontalDist > 0) {
        // Moving right
        if (verticalDist > 0) {
            int diagonalMoves = min(verticalDist, horizontalDist);
            movesRightUp = diagonalMoves;
            totalMoves += diagonalMoves;

            if (verticalDist > horizontalDist) {
                movesUp = verticalDist - diagonalMoves;
                totalMoves += movesUp;
            } else {
                movesRight = horizontalDist - diagonalMoves;
                totalMoves += movesRight;
            }
        } else {
            // Moving down
            int diagonalMoves = min(abs(verticalDist), horizontalDist);
            movesRightDown = diagonalMoves;
            totalMoves += diagonalMoves;

            if (abs(verticalDist) > horizontalDist) {
                movesDown = abs(verticalDist) - diagonalMoves;
                totalMoves += movesDown;
            } else {
                movesRight = horizontalDist - diagonalMoves;
                totalMoves += movesRight;
            }
        }
    } else {
        // Moving left
        if (verticalDist > 0) {
            int diagonalMoves = min(abs(verticalDist), abs(horizontalDist));
            movesLeftUp = diagonalMoves;
            totalMoves += diagonalMoves;

            if (abs(verticalDist) > abs(horizontalDist)) {
                movesUp = abs(verticalDist) - diagonalMoves;
                totalMoves += movesUp;
            } else {
                movesLeft = abs(horizontalDist) - diagonalMoves;
                totalMoves += movesLeft;
            }
        } else {
            // Moving down
            int diagonalMoves = min(abs(verticalDist), abs(horizontalDist));
            movesLeftDown = diagonalMoves;
            totalMoves += diagonalMoves;

            if (abs(verticalDist) > abs(horizontalDist)) {
                movesDown = abs(verticalDist) - diagonalMoves;
                totalMoves += movesDown;
            } else {
                movesLeft = abs(horizontalDist) - diagonalMoves;
                totalMoves += movesLeft;
            }
        }
    }

    cout << totalMoves << endl;
    for (int i = 0; i < movesRightUp; ++i) cout << "RU" << endl;
    for (int i = 0; i < movesRight; ++i) cout << "R" << endl;
    for (int i = 0; i < movesUp; ++i) cout << "U" << endl;
    for (int i = 0; i < movesDown; ++i) cout << "D" << endl;
    for (int i = 0; i < movesLeft; ++i) cout << "L" << endl;
    for (int i = 0; i < movesDownUp; ++i) cout << "DU" << endl;
    for (int i = 0; i < movesRightDown; ++i) cout << "RD" << endl;
    for (int i = 0; i < movesLeftUp; ++i) cout << "LU" << endl;
    for (int i = 0; i < movesLeftDown; ++i) cout << "LD" << endl;

    return 0;
}
