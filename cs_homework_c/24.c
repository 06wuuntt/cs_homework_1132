#include <stdio.h>
#include <string.h>

void rotate_anticlockwise(int cube[6][3][3], int color) {
    int copy_cube[6][3][3];
    memcpy(copy_cube, cube, sizeof(copy_cube));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cube[color][i][j] = copy_cube[color][j][2 - i];
        }
    }
}

void rotate_clockwise(int cube[6][3][3], int color) {
    int copy_cube[6][3][3];
    memcpy(copy_cube, cube, sizeof(copy_cube));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cube[color][i][j] = copy_cube[color][2 - j][i];
        }
    }
}

void rotate_column(int index, int cube[6][3][3]) {
    int temp[3];
    for (int i = 0; i < 3; i++) temp[i] = cube[0][i][index];
    for (int i = 0; i < 3; i++) cube[0][i][index] = cube[3][i][index];
    for (int i = 0; i < 3; i++) cube[3][i][index] = cube[5][i][index];
    for (int i = 0; i < 3; i++) cube[5][i][index] = cube[2][2-i][2-index];
    for (int i = 0; i < 3; i++) cube[2][2-i][2-index] = temp[i];
    if (index == 0) rotate_anticlockwise(cube, 4);
    else if (index == 2) rotate_clockwise(cube, 1);
}

void rotate_row(int index, int cube[6][3][3]) {
    int temp[3];
    for (int i = 0; i < 3; i++) temp[i] = cube[4][index][i];
    for (int i = 0; i < 3; i++) cube[4][index][i] = cube[3][index][i];
    for (int i = 0; i < 3; i++) cube[3][index][i] = cube[1][index][i];
    for (int i = 0; i < 3; i++) cube[1][index][i] = cube[2][index][i];
    for (int i = 0; i < 3; i++) cube[2][index][i] = temp[i];
    if (index == 0) rotate_clockwise(cube, 0);
    else if (index == 2) rotate_anticlockwise(cube, 5);
}

int main() {
    int n, rotate;
    scanf("%d", &n);
    int cube[6][3][3];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cube[i][j][k] = i + 1;
            }
        }
    }
    while (n--) {
        scanf("%d", &rotate);
        int type = rotate / 10;
        int index = rotate % 10;
        if (type == 1) rotate_column(index, cube);
        else if (type == 2) rotate_row(index, cube);
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            printf("%d ", cube[3][i][j]);
        }
        printf("\n");
    }
}