#include <stdio.h>

int checkconnect(int n, int road[n][n], int *visited, int stopstep, int stopr1, int stopr2) {
    // 確定路徑是否連通
    int copy[n][n];
    // 複製路徑
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            copy[i][j] = road[i][j];
        }
    }
    // 將斷掉的路徑設為-1
    for (int i = 0; i < n - 1; i++) {
        if (i == stopstep - 1) {
            
            copy[stopr1 - 1][stopr2 - 1] = -1;
            copy[stopr2 - 1][stopr1 - 1] = -1;
        }
        if (copy[visited[i]][visited[i + 1]] == -1) {
            return 0;
        }
    }
    return 1;
}

void comparelength(int *minlength, int *visited, int n, int road[n][n], int *final_path, int stopstep, int stopr1, int stopr2) {
    // 比較長度
    int length = 0;
    for (int i = 0; i < n - 1; i++) {
        if (visited[i] == stopr2 - 1 && i < stopstep - 1) return;
        length += road[visited[i]][visited[i + 1]];
    }
    if (length < *minlength && stopr1 - 1 == visited[stopstep - 1]) {
        *minlength = length;
        for (int i = 0; i < n; i++) {
            final_path[i] = visited[i];
        }
    }
}

void dfs(int n, int *visited, int road[n][n], int *step, int *used, int stopstep, int stopr1, int stopr2, int *minlength, int *final_path) {
    if (*step == n) {
        if (checkconnect(n, road, visited, stopstep, stopr1, stopr2)) {
            comparelength(minlength, visited, n, road, final_path, stopstep, stopr1, stopr2);
        }
        return;
    }

    for (int next = 0; next < n; next++) {
        if (!used[next]) {
            visited[(*step)++] = next;
            used[next] = 1;
            dfs(n, visited, road, step, used, stopstep, stopr1, stopr2, minlength, final_path);
            used[next] = 0;
            (*step)--;
        }
    }
}

int main() {
    int n, stopstep, stopr1, stopr2;
    scanf("%d", &n);
    int road[n][n], visited[10] = {0}, used[10] = {0}, final_path[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int length;
            scanf("%d", &length);
            road[i][j] = length;
        }
    }
    scanf("%d %d %d", &stopstep, &stopr1, &stopr2);
    int step = 1, minlength = 100;
    visited[0] = 0;
    used[0] = 1;
    dfs(n, visited, road, &step, used, stopstep, stopr1, stopr2, &minlength, final_path);
    for (int i = 0; i < n; i++) {
        printf("%d ", final_path[i] + 1);
    }
    printf("\n");
    printf("%d\n", minlength);
    return 0;
}