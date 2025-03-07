// 撰寫一個main function
// 設定矩形的高與寬兩個整數變數值分別為15, 12,
// 計算面積和周長並輸出
#include <stdio.h>

int main(){
    int height = 15, width = 12;
    int area, length;
    area = height*width;
    length = 2*height + 2*width;
    printf("area = %d, length = %d", area, length);
    return 0;
}