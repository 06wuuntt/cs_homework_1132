#include <stdio.h>
#include <string.h>

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

void contest(basePlayer_t players[], int stop_outs) {
    int outs = 0, score = 0, playerindex = 0, hitindex[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0}, bases[4] = {0, 0, 0, 0};
    while (outs < stop_outs) {
        basePlayer_t *current_player = &players[playerindex];
        // printf("outs:%d %d\n", outs, stop_outs);
        // printf("playerindex:%d, hitindex:%d\n", playerindex, hitindex);
        // printf("type:%d\n", current_hit->type);
        if (hitindex[playerindex] >= current_player->no) {
            playerindex = (playerindex + 1) % 9;
            continue;
        }
        play_t *current_hit = &current_player->data[hitindex[playerindex]];
        if (current_hit->type == BASE_HIT) {
            // printf("hit:%d\n", current_hit->result.base_hit);
            if (current_hit->result.base_hit == 4) {
                // printf("homerun\n");
                score++;
                for (int i = 1; i < 4; i++) {
                    if (bases[i] > 0) {
                        score++;
                        bases[i] = 0;
                    }
                }
            } else {
                for (int i = 3; i > 0; i--) {
                    if (bases[i] > 0) {
                        if (i + current_hit->result.base_hit > 3) {
                            score++;
                            bases[i] = 0;
                        } else {
                            bases[i + current_hit->result.base_hit] = bases[i];
                            bases[i] = 0;
                        }
                    }
                }
                bases[current_hit->result.base_hit] = 1;
            }
        } else if (current_hit->type == OUT) {
            outs++;
            if (outs == stop_outs) {
                break;
            }
            if (outs % 3 == 0) {
                bases[1] = bases[2] = bases[3] = 0;
            }
        }
        hitindex[playerindex]++;
        playerindex = (playerindex + 1) % 9;
    }
    printf("%d\n", score);
}

int main() {
    basePlayer_t players[9];
    int stop_outs;
    for (int i = 0; i < 9; i++) {
        int a;
        scanf("%d", &a);
        players[i].no = a;
        for (int j = 0; j < a; j++) {
            char hit[3];
            scanf("%s", hit);
            if (hit[1] == 'B' || hit[1] == 'R') {
                players[i].data[j].type = BASE_HIT;
                if (hit[0] == 'H') {
                    players[i].data[j].result.base_hit = 4;
                } else {
                    players[i].data[j].result.base_hit = hit[0] - '0';
                }
            } else {
                players[i].data[j].type = OUT;
                players[i].data[j].result.out_kind = hit[0];
            }
        }
    }
    scanf("%d", &stop_outs);
    contest(players, stop_outs);
    return 0;
}