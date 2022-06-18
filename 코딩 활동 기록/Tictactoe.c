#include <stdio.h>
#include <stdlib.h>

// 편리성을 위해 전역변수 선언
char board[3][3]; // 보드판 선언

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
    else
        printf("\nO가 승리했습니다!\n");
}

int main(void) {
    init();  // 보드판 초기화

    int flag = 0;
    char val; // X, O 저장
    int x, y, winner, game = 0;

    // 본 게임 진입
    do {
        game++;
        show_board();
        printf("(x, y) 좌표(종료 -1, -1) : ");
        scanf("%d %d", &x, &y);

        // -1, -1이 입력되면 종료
        if (x == -1 && y == -1) {
            printf("게임을 종료합니다.\n");
            exit(0);
        }

        // 이미 있는 곳에 입력하면 다시 입력하도록 함
        if (board[x][y] != ' ') {
            printf("잘못된 위치입니다.\n");
            continue;
        }

        // 순번에 따라 X, O 그리기 (flag 변수를 활용해 좀 더 직관적으로 표시했다.)
        if (flag == 0) {
            board[x][y] = 'X';
            flag = 1;
            val = 'X';
        }
        else {
            board[x][y] = 'O';
            flag = 0;
            val = 'O';
        }
    } while ((winner = !check(board, val)) && game < 9);

    // 우승자 출력
    if (winner && game == 9)
        printf("\n비겼습니다!\n");
    else
        print_win(val);

    return 0;
}