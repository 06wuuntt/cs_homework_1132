#include <stdio.h>

int roundBMI(double bmi){
    int intpart = (int)bmi;
    double decimalpart = bmi - intpart;
    int finalbmi = 0;
    if (decimalpart >= 0.6){
        finalbmi = intpart + 1;
    }
    else if (decimalpart <= 0.4){
        finalbmi = intpart;
    }
    else{
        if (intpart%2 == 0){
            finalbmi = intpart + 1;
        }
        else{
            finalbmi = intpart;
        }
    }
    return finalbmi;
}

double computeBMI(int weight, double height){
    double bmi;
    int finalbmi;
    height /= 100;
    bmi = weight/(height*height);
    finalbmi = roundBMI(bmi);
    printf("%d\n", finalbmi);
    if (finalbmi> 24){
        printf("too high");
    }
    else if (finalbmi < 18){
        printf("too low");
    }
}

void check(int weight, int height){
    if (weight < 20 || weight > 100){
        printf("ERROR");
    }
    else if (height < 100 || height > 200){
        printf("ERROR");
    }
    else computeBMI(weight, height);
}

int main(){
    int w, h;
    scanf("%d %d", &w, &h);
    check(w, h);
    return 0;
}