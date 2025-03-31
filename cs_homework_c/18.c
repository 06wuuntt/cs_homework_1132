#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool duplicate(int array[], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = i+1; j < length; j++) {
            if (array[i] == array[j]) {
                return true;
            }
        }
    }
    return false;
}

bool duplicate_array(int m, int array1[], int array2[]) {
    for (int i = 0; i < m; i++) {
        if (array1[i] != array2[i]) {
            return false;
        }
    }
    return true;
}

void sort_array(int m, int array[][m], int result_count) {
    int temp[m];
    for (int i = 0; i < result_count-1; i++) {
        for (int j = i; j < result_count; j++) {
            if (array[i][0] > array[j][0]) {
                for (int k = 0; k < m; k++) {
                    temp[k] = array[i][k];
                    array[i][k] = array[j][k];
                    array[j][k] = temp[k];
                }
            } else if(array[i][0] == array[j][0]) {
                if (array[i][1] > array[j][1]) {
                    for (int k = 0; k < m; k++) {
                        temp[k] = array[i][k];
                        array[i][k] = array[j][k];
                        array[j][k] = temp[k];
                    }
                }
            }
        }
    }
    for (int i = 0; i < result_count; i++) {
        if (duplicate_array(m, array[i], array[i+1])) {
            continue;
        }
        for (int j = 0; j < m; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }    
}

void seperate(int numarray[], int length, int m) {
    int temp[m];
    int result[20][m];
    int result_count = 0;
    for (int i = 0; i < length-m+1; i++) {
        for (int j = 0; j < m; j++) {
            temp[j] = numarray[i+j];
        }
        if (duplicate(temp, m) == false) {
            for (int j = 0; j < m; j++) {
                result[result_count][j] = temp[j];
            }
            result_count++;
        }
    }
    printf("%d\n", result_count);
    sort_array(m, result, result_count);
}

int main() {
    int m, index = 0;
    char array[40];
    int numarray[20];
    scanf("%d", &m);
    getchar();
    fgets(array, sizeof(array), stdin);
    for (int i = 0; i < strlen(array); i++) {
        if (isdigit(array[i])) {
            numarray[index] = array[i] - '0';
            index++;
        }
    }
    seperate(numarray, index, m);
}