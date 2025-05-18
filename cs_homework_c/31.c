#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum scoreType_s {G, GPA, S} scoreType_t;

typedef enum G_s {Aplus, A, Aduce, Bplus, B, Bduce, Cplus, C, Cduce, F, X} G_t;

typedef enum GPA_s {
    b4dot3, b4dot0, b3dot7, b3dot3, b3dot0, b2dot7, b2dot3, b2dot0, b1dot7, b1, b0
} GPA_t;

typedef enum S_s {
    b90to100, b85to89, b80to84, b77to79, b73to76, b70to72, b67to69, b63to66, b60to62, b1to59, b0to0
} S_t;

typedef union student_s {
    int score;
    G_t G;
    GPA_t GPA;
    S_t S;
} student_t;

typedef struct {
    int id;
    student_t scores[10];
    int avg;
} studentInfo;

int turn_G(char *s, int *scores) {
    if (strcmp(s, "A+") == 0) return scores[Aplus];
    if (strcmp(s, "A") == 0) return scores[A];
    if (strcmp(s, "A-") == 0) return scores[Aduce];
    if (strcmp(s, "B+") == 0) return scores[Bplus];
    if (strcmp(s, "B") == 0) return scores[B]; 
    if (strcmp(s, "B-") == 0) return scores[Bduce];
    if (strcmp(s, "C+") == 0) return scores[Cplus];
    if (strcmp(s, "C") == 0) return scores[C];
    if (strcmp(s, "C-") == 0) return scores[Cduce];
    if (strcmp(s, "F") == 0) return scores[F];
    if (strcmp(s, "X") == 0) return scores[X];
}

int turn_GPA(char *s, int *scores) {
    float gpascore[11] = {4.3, 4.0, 3.7, 3.3, 3.0, 2.7, 2.3, 2.0, 1.7, 1, 0};
    float val = atof(s);
    for (int i = 0; i < 11; i++) {
        if (val == gpascore[i]) return scores[i];
    }
}

int turn_S(char *s, int *scores) {
    if (strcmp(s, "90-100") == 0) return scores[b90to100];
    if (strcmp(s, "85-89") == 0) return scores[b85to89];
    if (strcmp(s, "80-84") == 0) return scores[b80to84];
    if (strcmp(s, "77-79") == 0) return scores[b77to79];
    if (strcmp(s, "73-76") == 0) return scores[b73to76];
    if (strcmp(s, "70-72") == 0) return scores[b70to72];
    if (strcmp(s, "67-69") == 0) return scores[b67to69];
    if (strcmp(s, "63-66") == 0) return scores[b63to66];
    if (strcmp(s, "60-62") == 0) return scores[b60to62];
    if (strcmp(s, "1-59") == 0) return scores[b1to59];
    if (strcmp(s, "0") == 0) return scores[b0to0];
}

int main() {
    int m, n;
    scanf("%d", &m);
    int scores_table[11] = {95, 87, 82, 78, 75, 70, 68, 65, 60, 50, 0};
    scoreType_t courseType[m];
    for (int i = 0; i < m; i++) {
        char type[10];
        scanf("%s", type);
        if (strcmp(type, "G") == 0) courseType[i] = G;
        else if (strcmp(type, "GPA") == 0) courseType[i] = GPA;
        else courseType[i] = S;
    }
    scanf("%d", &n);
    studentInfo students[n];
    for (int i = 0; i < n; i++) {
        int total = 0, score = 0;
        scanf("%d", &students[i].id);
        for (int j = 0; j < m; j++) {
            char temp[20];
            scanf("%s", temp);
            if (courseType[j] == G) {
                students[i].scores[j].G = turn_G(temp, scores_table);
                score = students[i].scores[j].G;
            } else if (courseType[j] == GPA) {
                students[i].scores[j].GPA = turn_GPA(temp, scores_table);
                score = students[i].scores[j].GPA;
            } else {
                students[i].scores[j].S = turn_S(temp, scores_table);
                score = students[i].scores[j].S;
            }
            // printf("%d %d\n", students[i].id, score);
            total += score;
        }
        students[i].avg = total / m;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].avg < students[j].avg) {
                studentInfo temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        printf("%d %d\n", students[i].id, students[i].avg);
    } 
}