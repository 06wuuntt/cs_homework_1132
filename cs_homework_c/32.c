#include <stdio.h>
#include <string.h>

typedef struct student_s {
    char name[50];
    int score;
} student_t;

void input(student_t s[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%s %d", s[i].name, &s[i].score);
    }
}

char *getHigh(student_t s[], int n, char name[], int *highScore) {
    for (int i = 0; i < n; i++) {
        if (s[i].score > *highScore) {
            *highScore = s[i].score;
            strcpy(name, s[i].name);
        }
    }
    return name;
}

char *getLow(student_t s[], int n, char name[], int *lowScore) {
    for (int i = 0; i < n; i++) {
        if (s[i].score < *lowScore) {
            *lowScore = s[i].score;
            strcpy(name, s[i].name);
        }
    }
    return name;
}

int getAverage(student_t s[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += s[i].score;
    }
    return sum / n;
}

int getMedian(student_t s[], int n) {
    int scores[n];
    for (int i = 0; i < n; i++) {
        scores[i] = s[i].score;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (scores[j] > scores[j + 1]) {
                int temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }
    if (n % 2 == 0) {
        return (scores[n / 2 - 1] + scores[n / 2]) / 2;
    } else {
        return scores[n / 2];
    }
}

int main() {
    int n;
    char highname[50], lowname[50];
    int highScore = 0, lowScore = 100;
    scanf("%d", &n);
    student_t students[n];
    input(students, n);
    strcpy(highname, getHigh(students, n, highname, &highScore));
    strcpy(lowname, getLow(students, n, lowname, &lowScore));
    printf("%s %d\n%s %d\n", highname, highScore, lowname, lowScore);
    printf("%d\n", getAverage(students, n));
    printf("%d\n", getMedian(students, n));
    return 0;
}