#include <stdio.h>
#include <string.h>

double getCardpoint(char card[]){
    double point;
    if (strcmp(card, "A") == 0) point = 1;
    else if (strcmp(card, "10") == 0) point = 10;
    else if (strcmp(card, "J") == 0 || strcmp(card, "Q") == 0 || strcmp(card, "K") == 0) point = 0.5;
    else point = (int)card[0]-48;
    return point;
}

int main(){
    char card[2];
    double a_point, b_point;
    for (int i=0; i<3; i++){
        scanf("%s", card);
        a_point += getCardpoint(card);
    }
    for (int i=0; i<3; i++){
        scanf("%s", card);
        b_point += getCardpoint(card);
    }
    if (a_point > 10.5) a_point = 0;
    if (b_point > 10.5) b_point = 0;
    printf("%g\n%g\n", a_point, b_point);
    if (a_point > b_point) printf("X Win");
    else if (a_point < b_point) printf("Y Win");
    else printf("Tie");

    return 0;
}