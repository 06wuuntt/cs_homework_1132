#include <stdio.h>

int main(){
    int outnum = 0, n = 0, score= 0, newbase;
    int base[3] = {0, 0, 0};
    for (int i=0; i<5; i++){
        scanf("%d", &n);
        if (n == 0){
            outnum++;
            if (outnum == 3){
                base[0] = base[1] = base[2] = 0;
                outnum = 0;
            }
        }
        else if (n == 4){
            score += 1 + base[0] + base[1] + base[2];
            base[0] = base[1] = base[2] = 0;
        }
        else{
            for (int j=2; j>=0; j--){
                if (base[j] == 1){
                    newbase = n+j;
                    if (newbase >= 3) score++;
                    else{
                        base[newbase] = 1;
                    }
                    base[j] = 0; 
                }
            }
            base[n - 1] = 1;
        }
    }        
    printf("%d\n%d %d %d\n", score, base[0], base[1], base[2]);
    return 0;       
}