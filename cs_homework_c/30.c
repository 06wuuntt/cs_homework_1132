#include <stdio.h>

typedef enum { OUT, BASE_HIT } play_type_t;

typedef union {
    int base_hit; // 1~4: number of bases
    char out_kind; // 'F', 'S', 'G'
} play_result_t;

typedef struct {
    play_type_t type;
    play_result_t result;
} play_t;

typedef struct {
    int no; // 擊球員的打擊次數
    play_t data[5]; // 擊球員的打擊結果
} basePlayer_t;

int main() {
    
    return 0;
}