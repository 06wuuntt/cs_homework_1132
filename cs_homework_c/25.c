#include <stdio.h>
#define Board_size 10

void getData(int board[Board_size][Board_size]) {
    for (int i = 0; i < Board_size*Board_size; i++) {
        int n; 
        scanf("%d", &n);
        board[i / 10][i % 10] = n; 
    }
}

void sort(int resultpos[][2], int resultline[], int poscount) {
    int sortresult[poscount][3];
    int maxline = 4;
    while (maxline) {
        for (int i = 0; i < poscount; i++) {
            if (resultline[i] == maxline) printf("%d%d %d\n", resultpos[i][0], resultpos[i][1], resultline[i]);
        }
        maxline--;
    }
}

int checkLine(int x, int y, int dx, int dy, int board[Board_size][Board_size]) {
    int count = 1;
    int i = x + dx, j = y + dy;
    while (i >= 0 && i < 10 && j >= 0 && j < 10 && board[i][j] == 1) {
        count += 1;
        i += dx;
        j += dy;
    }
    i = x - dx;
    j = y - dy;
    while (i >= 0 && i < 10 && j >= 0 && j < 10 && board[i][j] == 1) {
        count += 1;
        i -= dx;
        j -= dy;
    }
    if (count == 5) return 1;
    return 0;
}

void findSpace(int board[Board_size][Board_size], int resultpos[][2], int resultline[]) {
    int poscount = 0;
    for (int i = 0; i < Board_size; i++) {
        for (int j = 0; j < Board_size; j++) {
            int linecount = 0;
            if (board[i][j] == 0) {
                linecount += checkLine(i, j, 1, 0, board);
                linecount += checkLine(i, j, 0, 1, board);
                linecount += checkLine(i, j, 1, 1, board);
                linecount += checkLine(i, j, 1, -1, board);
            }
            if (linecount) {
                resultpos[poscount][0] = i;
                resultpos[poscount][1] = j;
                resultline[poscount] = linecount;
                poscount += 1;
            }
        }
    }
    sort(resultpos, resultline, poscount);
    // for (int i = 0; i < poscount; i++) {
    //     printf("%d%d %d\n", resultpos[i][0], resultpos[i][1], resultline[i]);
    // }
}

int main() {
    int board[Board_size][Board_size];
    getData(board);
    int resultpos[100][2], resultline[100]; 
    findSpace(board, resultpos, resultline);       
    return 0;
}