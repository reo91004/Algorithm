#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 편리성을 위해 전역변수 선언
char board[3][3];  // 보드판 선언
int flag = 0;

// 보드판 초기화 함수
void init() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) board[i][j] = ' ';
}

// 보드판 표시 함수
void show_board() {
    for (int i = 0; i < 3; ++i) {
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
    }

    printf("---|---|---\n");
}

// 승패를 확인하는 함수
int check(char b[3][3], char ch) {
    int i;
    for (i = 0; i < 3; ++i) {
        // 행으로 한 줄이 완성되었을 경우
        if (b[i][0] == ch && b[i][1] == ch && b[i][2] == ch) return 1;
    }
    for (i = 0; i < 3; ++i) {  // 열로 한 줄이 완성 되었을 경우
        if (b[0][i] == ch && b[1][i] == ch && b[2][i] == ch) return 1;
    }

    if (b[1][1] == ch)  // 대각선으로 한 줄이 완성 되었을 경우
        if ((b[0][0] == ch && b[2][2] == ch) || (b[0][2] == ch && b[2][0] == ch)) return 1;

    return 0;
}

// 우승자 출력 함수
void print_win(char val) {
    if (val == 'X')
        printf("\nX가 승리했습니다!\n");
    else if (val == 'O')
        printf("\nO가 승리했습니다!\n");
}

// --------------------------------------------------------------------------------
// 인공지능 함수
char play_AI(int cnt, char val) {
    system("CLS");
    printf("AI 차례입니다.\n");
    show_board();
    
    char val_oppos;

    if (val == 'X')
        val_oppos = 'O';
    else
        val_oppos = 'X';

    // AI가 선공이 아니면 가운데 놓는게 승률이 제일 높음
    if (cnt == 1) {
        if (board[1][1] == ' ') {
            board[1][1] = val;
            return val;
        }
        else {
            while (1) {
                srand(time(NULL));
                int tmpx = rand() % 3;
                int tmpy = rand() % 3;
                if (board[tmpx][tmpy] == ' ') {
                    board[tmpx][tmpy] = val;
                    return val;
                }
            }
        }
    }

    for (int pos = 0; pos < 3; ++pos) {
        // ---------- 대각선 분야 판별
        if ((board[0][0] == board[1][1]) && (board[1][1] == val_oppos) && (board[2][2] == ' ')) {
            board[2][2] = val;
            break;
        } 
        else if ((board[0][2] == board[1][1]) && (board[1][1] == val_oppos) && (board[2][0] == ' ')) {
            board[2][0] = val;
            break;
        } 
        else if ((board[2][0] == board[1][1]) && (board[1][1] == val_oppos) && (board[0][2] == ' ')) {
            board[0][2] = val;
            break;
        }
        else if ((board[2][0] == board[0][2]) && (board[0][2] == val_oppos) && (board[1][1] == ' ')) {
            board[1][1] = val;
            break;
        } 
        else if ((board[2][2] == board[1][1]) && (board[1][1] == val_oppos) && (board[0][0] == ' ')) {
            board[0][0] = val;
            break;
        }
        else if ((board[2][2] == board[0][0]) && (board[0][0] == val_oppos) && (board[1][1] == ' ')) {
            board[1][1] = val;
            break;
        }

        // ---------- 가로, 세로 판별
        else if (pos < 2) {
            if ((board[pos][0] == board[pos][1]) && (board[pos][1] == val_oppos) && (board[pos][2] == ' ')) {
                board[pos][2] = val;
                break;
            }
            else if ((board[pos][0] == board[pos][2]) && (board[pos][0] == val_oppos) && (board[pos][1] == ' ')) {
                board[pos][1] = val;
                break;
            }
            else if ((board[0][pos] == board[1][pos]) && (board[1][pos] == val_oppos) && (board[2][pos] == ' ')) {
                board[2][pos] = val;
                break;
            } 
            else if ((board[0][pos] == board[2][pos]) && (board[0][pos] == val_oppos) && (board[1][pos] == ' ')) {
                board[1][pos] = val;
                break;
            }
            else if ((board[1][pos] == board[2][pos]) && (board[1][pos] == val_oppos) && (board[0][pos] == ' ')) {
                board[0][pos] = val;
                break;
            } 
            else if ((board[pos][1] == board[pos][2]) && (board[pos][1] == val_oppos) && (board[pos][0] == ' ')) {
                board[pos][0] = val;
                break;
            }
        }
        // 모든 경우를 돌았는데도 채워질 칸이 정해지지 않으면 랜덤으로 채움
        else {
            while (1) {
                srand(time(NULL));
                int tmpx = rand() % 3;
                int tmpy = rand() % 3;
                if (board[tmpx][tmpy] == ' ') {
                    board[tmpx][tmpy] = val;
                    break;
                }
            }
        }
    }

    return val;
}

// 플레이어 함수
char play_player(int cnt, char val) {
    system("CLS");
    printf("플레이어 차례입니다.\n");
    show_board(); 
    
    while (1) {
        int x, y;
        printf("(x, y) 좌표(종료 -1, -1) : ");
        scanf("%d %d", &x, &y);

        // -1, -1이 입력되면 종료
        if (x == -1 && y == -1) {
            printf("게임을 종료합니다.\n");
            exit(0);
        }
        if (board[x][y] != ' ') {
            printf("잘못된 위치입니다.\n");
            continue;
        }
        else {
            board[x][y] = val;
            break;
        }
    }

    return val;
}

int main(void) {
    init();  // 보드판 초기화

    char val = 'X';  // X, O 저장
    int x, y, cnt = 0, winner, game = 0;

    printf("틱택토 게임입니다. 선을 둘 사람을 고르세요.\n0. 플레이어 / 1. AI\n입력 : ");
    scanf("%d", &flag); // flag가 0이면 사람 시작, 1이면 AI 시작
    
    // 본 게임 진입
    do {
        game++;

        // 처음에는 그대로 가지만 2번째 턴부터는 val이 계속 바뀌어야 함
        if (val == 'X' && cnt != 0)
            val = 'O';
        else if (val == 'O' && cnt != 0)
            val = 'X';

        if (flag == 0) {
            val = play_player(cnt++, val);
            flag = 1;
        } else {
            val = play_AI(cnt++, val);
            flag = 0;
        }

    } while ((winner = !check(board, val)) && game < 9);

    // 우승자 출력
    if (winner && game == 9)
        printf("\n비겼습니다!\n");
    else
        print_win(val);

    return 0;
}