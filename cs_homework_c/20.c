#include <stdio.h>

typedef struct {
    int up, front, back, left, right, bottom;
} Dice;

Dice diceroll(int *dice, int roll, int dicenum, Dice d) {
    int temp = d.up;
    switch (roll) {
        case 1:
            d.up = d.back;
            d.back = d.bottom;
            d.bottom = d.front;
            d.front = temp;
            break;
        case 2:
            d.up = d.front; 
            d.front = d.bottom;
            d.bottom = d.back;
            d.back = temp;
            break;
        case 3:
            d.up = d.left;
            d.left = d.bottom;
            d.bottom = d.right;
            d.right = temp;
            break;
        case 4:
            d.up = d.right;
            d.right = d.bottom;
            d.bottom = d.left;
            d.left = temp;
            break;
    }
    dice[dicenum - 1] = d.up;
    return d;
}

int score(int *dice) {
    int same_two = 0, same_four = 0, result = 0;
    int point[6] = {0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 4; i++) {
        point[dice[i] - 1]++;
    }
    for (int i = 0; i < 6; i++) {
        if (point[i] == 2) same_two++;
        else if (point[i] == 4) same_four++;
    }
    if (same_four) result = 18;
    else if (same_two == 2) {
        for (int i = 5; i >= 0; i--) {
            if (point[i] == 2) {
                result = (i + 1) * 2;
                break;
            }
        }
    } else if (same_two == 1) {
        for (int i = 0; i < 6; i++) {
            if (point[i] == 1) {
                result += i + 1;
            }
        }
    } 
    // printf("times = %d %d %d %d %d %d\n", point[0], point[1], point[2], point[3], point[4], point[5]);
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    int dice[4] = {1, 1, 1, 1};
    Dice d1 = {1, 4, 3, 5, 2, 6}, d2 = {1, 4, 3, 5, 2, 6}, d3 = {1, 4, 3, 5, 2, 6}, d4 = {1, 4, 3, 5, 2, 6};
    while (n--) {
        int roll1, roll2, roll3, roll4;
        scanf("%d %d %d %d", &roll1, &roll2, &roll3, &roll4);
        d1 = diceroll(dice, roll1, 1, d1);
        d2 = diceroll(dice, roll2, 2, d2);
        d3 = diceroll(dice, roll3, 3, d3);
        d4 = diceroll(dice, roll4, 4, d4);
        // printf("dice = %d %d %d %d\n", dice[0], dice[1], dice[2], dice[3]);
    }
    int result = score(dice);
    printf("%d", result);
    // printf("%d %d %d %d", dice[0], dice[1], dice[2], dice[3]);
    return 0;
}