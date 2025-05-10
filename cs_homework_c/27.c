#include <stdio.h>
#include <string.h>

void splitWord(char *sentence, char word[][500], int *wordcount) {
    int wordlen = 0, len = strlen(sentence), i = 0;
    while (i != len) {
        if (sentence[i] == ' ' || sentence[i] == '\n') {
            (*wordcount)++;
            wordlen  = 0;
        } else {
            word[*wordcount][wordlen] = sentence[i];
            wordlen++;
        }
        i++;
    }
}

int matchWord(char *word, char *compareword) {
    int i = 0;
    if (strlen(word) == strlen(compareword) || strlen(word) + 1 == strlen(compareword)) {
        for (i = 0; i < strlen(word); i++) {
            if (word[i] != compareword[i]) return 0;
        }
        char c = compareword[i];
        if (c == '.' || c == ',' || c == '!' || c == '?', c == ';', c == ':') return 1;
    } else {
        return 0;
    }
    return 1;
}

void replaceWord(char word[][500], int wordcount, char *str1, char *str2) {
    for (int i = 0; i < wordcount; i++) {
        int wordlen = strlen(word[i]);
        if (matchWord(str1, word[i])) {
            if (wordlen != strlen(str1)) printf("%s%c ", str2, word[i][wordlen - 1]);
            else printf("%s ", str2);
        }
        else printf("%s ", word[i]);
    }
    printf("\n");    
}

void insert(char word[][500], int wordcount, char *str1, char *str2) {
    for (int i = 0; i < wordcount; i++) {
        if (matchWord(str1, word[i])) {
            printf("%s %s ", str2, word[i]);
        } else printf("%s ", word[i]);
    }
    printf("\n");
    for (int i = 0; i < wordcount; i++) {
        if (matchWord(str1, word[i])) {
            printf("%s %s ", word[i], str2);
        } else printf("%s ", word[i]);
    }
    printf("\n");
}

void removeword(char word[][500], int wordcount, char *str1) {
    for (int i = 0; i < wordcount; i++) {
        if (matchWord(str1, word[i])) {
            continue;
        }
        printf("%s ", word[i]);
    }
    printf("\n");
}

void reverse(char word[][500], int wordcount) {
    for (int i = wordcount - 1; i >= 0; i--) {
        printf("%s ", word[i]);
    }
    printf("\n");
}

int main() {
    char sentence[1000], word[500][500];
    char str1[100], str2[100];
    int wordcount = 0;
    fgets(sentence, sizeof(sentence), stdin);
    scanf("%s %s", str1, str2);   
    splitWord(sentence, word, &wordcount);
    replaceWord(word, wordcount, str1, str2);
    insert(word, wordcount, str1, str2);
    removeword(word, wordcount, str1);
    reverse(word, wordcount);
    return 0;
}