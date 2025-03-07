#include <stdio.h>

void calculateMoney(int incall, int outcall, int homecall, int inmes, int outmes){
    int allmoney[3];
    int plan[3][6] = {{500, 400, 300, 10, 15, 183},
                      {600, 500, 400, 20, 25, 383},
                       {700, 600, 500, 30, 35, 983}};
    double rate[3][5] = {{0.08, 0.1393, 0.1349, 1.1287, 1.4803}, 
                         {0.07, 0.1304, 0.1217, 1.1127, 1.2458},
                         {0.06, 0.1087, 0.1018, 0.9572, 1.1243}};
    for (int i=0; i<3; i++){
        double money = 0;
        money += (incall > plan[i][0]) ? (incall - plan[i][0]) * rate[i][0] : 0;
        money += (outcall > plan[i][1]) ? (outcall - plan[i][1]) * rate[i][1] : 0;
        money += (homecall > plan[i][2]) ? (homecall - plan[i][2]) * rate[i][2] : 0;
        money += (inmes > plan[i][3]) ? (inmes - plan[i][3]) * rate[i][3] : 0;
        money += (outmes > plan[i][4]) ? (outmes - plan[i][4]) * rate[i][4] : 0;
        
        if (money < plan[i][5]){
            money = plan[i][5];
        }
        allmoney[i] = (int)money;
    }

    int bestmoney = allmoney[0], bestplan = plan[0][5];
    for (int i=0; i<3; i++){
        if (allmoney[i] <= bestmoney){
            bestmoney = (int)allmoney[i];
            bestplan = plan[i][5];
        }
    }
    printf("%d\n%d", bestmoney, bestplan);
}

int main(){
    int incall, outcall, homecall, inmes, outmes;
    scanf("%d %d %d %d %d", &incall, &outcall, &homecall, &inmes, &outmes);
    calculateMoney(incall, outcall, homecall, inmes, outmes);

    return 0;
}