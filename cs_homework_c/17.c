#include <stdio.h>

int main() {
    int n;
    int allscore[3] = {0, 0, 0}, winnum[3] = {0, 0, 0};
    char teams[3] = {'A', 'B', 'C'};
    scanf("%d", &n);
    while (n--) {
        char player1, player2;
        int score1 = 0, score2 = 0;
        scanf(" %c %c", &player1, &player2);
        for (int i = 0; i < 4; i++) {
            int s1, s2;
            scanf("%d %d", &s1, &s2);
            score1 += s1;
            score2 += s2;
        }
        allscore[player1 - 'A'] += score1;
        allscore[player2 - 'A'] += score2;
        if (score1 > score2) {
            winnum[player1 - 'A']++;
        } else if (score1 < score2) {
            winnum[player2 - 'A']++;
        }
    }
    // for (int i = 0; i < 3; i++) {
    //     printf("%c %d %d\n", teams[i], allscore[i], winnum[i]);
    // }
    int maxwin = 0, maxindex = 0;
    for (int i = 0; i < 3; i++) {
        if (winnum[i] > maxwin) {
            maxwin = winnum[i];
            maxindex = i;
        }
    }
    printf("%c %d\n", teams[maxindex], allscore[maxindex]);
    return 0;
}