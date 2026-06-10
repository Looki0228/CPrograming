#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#define sleep(n) Sleep((n) * 1000)
#else
#include <unistd.h>
#endif
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

//게임 스테이지 이동
int floor_change = 0;
//(4층 게임 입장 / 맵 이동)
int key_floor4 = 0;

//화면 제거
void clearscreen_floor4() {
    printf("[\033[2J\033[1;1f");
}

//엔터 입력
void pressenter_floor4() {
    while (getchar() != '\n');
}

//게임 오프닝
void showOpening() {
    clearscreen_floor4();
    printf("===================================================================\n");
    printf("  ______   ______   ______   ______    ______   ______     ______  \n");
    printf(" |  ____| /  ____| /  ____| /  __  \\  |  ___ \\ |  ____|   |  ____| \n");
    printf(" | |__    | (____  | |     /  /__\\  \\ | |___)| | |__      | |  __  \n");
    printf(" |  __|   \\____  \\ | |     |  ____  | |  ____/ |  __|     | | |_ | \n");
    printf(" | |____   ____) | | |____ | |    | | | |      | |____    | |__| | \n");
    printf(" |______| |______/ \\______||_|    |_| |_|      |______|    \\_____| \n");
    printf("===================================================================\n");
    printf("                   PRESS ENTER TO START GAME...                  \n");
    printf("===================================================================\n");
    printf("\033[11;1f");
}

//오프닝 스토리
void opening_story() {
    clearscreen_floor4();
    printf("\n\n\n\n");
    printf("                         ㅡㅡㅡㅡㅡㅡㅡㅡ                          \n");
    printf("                         |              |                          \n");
    printf("                         |   \033[33m23 : 05    \033[0m|                          \n");
    printf("         ㅡㅡㅡㅡㅡㅡㅡㅡ|              |ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
    printf("        /                |              |                   / |\n");
    printf("       /                 ㅡㅡㅡㅡㅡㅡㅡㅡ                  /  /\n");
    printf("      /                / ㅁㅁㅁㅁㅁㅁㅁ /                 /  /| \n");
    printf("     /                / ㅁㅁㅁㅁㅁㅁㅁ /                 /  /  \n");
    printf("    /                / ㅁㅁㅁㅁㅁㅁㅁ /                 /  /   \n");
    printf("   /                 ㅡㅡㅡㅡㅡㅡㅡㅡ                  /  /    \n");
    printf("  /                                                   /  /     \n");
    printf(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ/  /      \n");
    printf(" |                                                   | /       \n");
    printf(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ| |       \n");
    printf("  |   | |                                        |   | |       \n");
    printf("  |   | |                                        |   | |       \n");
    printf("  |   | |                                        |   | |       \n");
    printf("===============================================================\n\n");
    printf("   과제를 하다가 과방에서 잠깐 엎드려 잤다.                   \n");
    printf("   깨보니 과방에는 아무도 없고 시간은 11시가 넘었다.          \n");
    printf("   막차가 끊기기 전에 건물에서 나가야 한다!                   \n\n");
    printf("===============================================================\n\n");
    printf("게임을 시작하려면 'ENTER'를 누르세요");
}

//인트로 - 게임 시작
void game_start() {
    showOpening();
    pressenter_floor4();
    opening_story();
    pressenter_floor4();
    floor_change = 4;
    return;
}

//4층 - 과방 맵 출력
char map1symbol_floor4[20][1024] = {
    "  ",
    "\033[48;2;169;169;169m  \033[0m",
    "\033[38;2;160;82;45m문\033[0m",
    "\033[38;2;160;82;45mㅡ\033[0m",
    "\033[38;2;160;82;45m |\033[0m",
    "\033[38;2;160;82;45m__\033[0m",
    "\033[38;2;160;82;45m \\\033[0m",
    "\033[38;2;160;82;45m\\ \033[0m",
    "\033[38;2;160;82;45m| \033[0m",
    "\033[38;2;160;82;45m/ \033[0m",
    "\033[38;2;160;82;45m /\033[0m",
    "\033[31m* \033[0m"
};
void printmap1_floor4(int map1_floor4[12][17]) {
    printf("\033[2K\033[1;1f");
    for (int row = 0; row < 12; row++) {
        for (int column = 0; column < 17; column++) {
            printf("%s", map1symbol_floor4[map1_floor4[row][column]]);
        }
        printf("\n");
    }
}

//4층 - 과방 캐릭터 이동
void map1move_floor4(char direction, int* row, int* column, int map1_floor4[12][17]) {
    if (((direction == 'w') || (direction == 'W')) &&
        (0 < *row) &&
        (map1_floor4[*row - 1][*column] != 1) &&
        (map1_floor4[*row - 1][*column] != 3) &&
        (map1_floor4[*row - 1][*column] != 4) &&
        (map1_floor4[*row - 1][*column] != 5) &&
        (map1_floor4[*row - 1][*column] != 6) &&
        (map1_floor4[*row - 1][*column] != 7) &&
        (map1_floor4[*row - 1][*column] != 8) &&
        (map1_floor4[*row - 1][*column] != 9) &&
        (map1_floor4[*row - 1][*column] != 10))
        (*row)--;
    else if (((direction == 'a') || (direction == 'A')) &&
        (0 < *column) &&
        (map1_floor4[*row][*column - 1] != 1) &&
        (map1_floor4[*row][*column - 1] != 3) &&
        (map1_floor4[*row][*column - 1] != 4) &&
        (map1_floor4[*row][*column - 1] != 5) &&
        (map1_floor4[*row][*column - 1] != 6) &&
        (map1_floor4[*row][*column - 1] != 7) &&
        (map1_floor4[*row][*column - 1] != 8) &&
        (map1_floor4[*row][*column - 1] != 9) &&
        (map1_floor4[*row][*column - 1] != 10))
        (*column)--;
    else if (((direction == 's') || (direction == 'S')) &&
        (*row < 11) &&
        (map1_floor4[*row + 1][*column] != 1) &&
        (map1_floor4[*row + 1][*column] != 3) &&
        (map1_floor4[*row + 1][*column] != 4) &&
        (map1_floor4[*row + 1][*column] != 5) &&
        (map1_floor4[*row + 1][*column] != 6) &&
        (map1_floor4[*row + 1][*column] != 7) &&
        (map1_floor4[*row + 1][*column] != 8) &&
        (map1_floor4[*row + 1][*column] != 9) &&
        (map1_floor4[*row + 1][*column] != 10))
        (*row)++;
    else if (((direction == 'd') || (direction == 'D')) &&
        (*column < 16) &&
        (map1_floor4[*row][*column + 1] != 1) &&
        (map1_floor4[*row][*column + 1] != 3) &&
        (map1_floor4[*row][*column + 1] != 4) &&
        (map1_floor4[*row][*column + 1] != 5) &&
        (map1_floor4[*row][*column + 1] != 6) &&
        (map1_floor4[*row][*column + 1] != 7) &&
        (map1_floor4[*row][*column + 1] != 8) &&
        (map1_floor4[*row][*column + 1] != 9) &&
        (map1_floor4[*row][*column + 1] != 10))
        (*column)++;
}

//4층 - 과방 맵
int map1_floor4[12][17] = {
        { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1 },
        { 1,4,4,0,1,0,0,11,1,0,0,0,1,0,0,0,1 },
        { 1,4,0,3,1,0,5,5,1,0,5,5,1,0,0,0,1 },
        { 1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
        { 1,4,0,0,0,3,3,3,3,3,3,0,0,0,1,1,1 },
        { 1,4,0,0,9,0,0,0,0,0,0,6,0,0,4,0,1 },
        { 1,4,0,0,8,1,0,0,0,0,0,4,0,0,4,0,1 },
        { 1,4,0,0,7,0,0,0,0,0,0,10,0,0,1,1,1 },
        { 1,4,0,0,0,3,3,3,3,3,3,0,0,0,4,0,1 },
        { 1,4,0,0,0,0,0,0,0,0,0,0,0,0,4,0,1 },
        { 1,4,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1 },
        { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};

//4층 - 미로 맵 출력
void printmazemap_floor4(int mazemaps_floor4[7][7]) {
    char symbol[10][1024] = {
        "  ",//투명 배경 (0) 바닥
        "\033[48;2;169;169;169m  \033[0m",//회색 배경 (1) 벽
        "\033[41m  \033[0m",//빨간색 배경 (2) return
        "\033[44m  \033[0m",//파란색 배경 (3) True
        "\033[44m  \033[0m",//파란색 배경 (4) False
        "\033[44m  \033[0m",//파란색 배경 (5) False
        "\033[48;5;54m  \033[0m",//보라색 배경 (6) Clear
        "\033[47m  \033[0m",//흰색 배경 (7) 정답
        "\033[43m  \033[0m",//노란색 배경 (8) 시작지점으로 돌아오기
        "\033[42m  \033[0m"//초록색 배경 (9) 미로 게임 시작
    };
    printf("\033[2K\033[1;1f");
    for (int row = 0; row < 7; row++) {
        for (int column = 0; column < 7; column++)
            printf("%s", symbol[mazemaps_floor4[row][column]]);
        printf("\n");
    }
    printf("\033[1;16f게임 설명: 이 게임은 TP미로입니다. 색깔 발판을 밟으면 다른 맵으로 이동하는 미로 게임입니다.");
    printf("\033[2;16f*\033[32m초록색 발판\033[0m은 미로 게임 시작 발판입니다.");
    printf("\033[3;16f*\033[33m노란색 발판\033[0m은 시작 지점으로 돌아가는 발판입니다.");
    printf("\033[4;16f*\033[31m빨간색 발판\033[0m은 미로 시작 지점으로 되돌아오는 발판입니다.");
    printf("\033[5;16f*\033[34m파란색 발판\033[0m은 다음 맵으로 TP하는 발판입니다.");
    printf("\033[6;16f*\033[38;5;54m보라색 발판\033[0m은 클리어 발판입니다.");
    printf("\033[7;16f*\033[37m흰색 발판\033[0m은 정답 발판입니다.");
}

//4층 - 미로 캐릭터 이동
void mazemove_floor4(char direction, int* row, int* column, int mazemaps_floor4[7][7]) {
    if (((direction == 'w') || (direction == 'W')) && (0 < *row) && (mazemaps_floor4[*row - 1][*column] != 1)) {
        (*row)--;
        (*row)--;
    }
    else if (((direction == 'a') || (direction == 'A')) && (0 < *column) && (mazemaps_floor4[*row][*column - 1] != 1)) {
        (*column)--;
        (*column)--;
    }
    else if (((direction == 's') || (direction == 'S')) && (*row < 6) && (mazemaps_floor4[*row + 1][*column] != 1)) {
        (*row)++;
        (*row)++;
    }
    else if (((direction == 'd') || (direction == 'D')) && (*column < 6) && (mazemaps_floor4[*row][*column + 1] != 1)) {
        (*column)++;
        (*column)++;
    }
}

//4층 - 미로 맵 변경
void changemazemap_floor4(int* currentmazemap_floor4, int newmazemap_floor4, int* row, int* column, int mazemaps_floor4[27][7][7]) {
    *currentmazemap_floor4 = newmazemap_floor4;
    *row = 3;
    *column = 3;

    printmazemap_floor4(mazemaps_floor4[*currentmazemap_floor4]);
    printf("\033[%d;%df옷", *row + 1, *column * 2 + 1);
}

//4층 - 미로 맵
int mazemaps_floor4[27][7][7] = {
    {//START
        { 1,1,1,1,1,1,1 },
        { 1,0,0,7,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,9,0,0,1 },
        { 1,1,1,1,1,1,1 }, },
    {//A
        { 1,1,1,1,1,1,1 },
        { 1,0,0,8,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,3,0,0,1 },
        { 1,1,1,1,1,1,1 }, },
    {//B
        { 1,1,1,1,1,1,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,3,0,0,1 },
        { 1,1,1,1,1,1,1 }, },
    {//C
        { 1,1,1,1,1,1,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,3,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,1,1,1,1,1,1 }, },
    {//D
        { 1,1,1,1,1,1,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,3,0,0,0,5,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,4,0,0,1 },
        { 1,1,1,1,1,1,1 }, },
    {//E
        { 1,1,1,1,1,1,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,4,0,0,1 },
        { 1,1,1,1,1,1,1 }, },
    {//F
        { 1,1,1,1,1,1,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,3,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,1,1,1,1,1,1 }, },
    {//G
        { 1,1,1,1,1,1,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,4,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,3,0,0,1 },
        { 1,1,1,1,1,1,1 }, },
    {//H
        { 1,1,1,1,1,1,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,4,0,0,1 },
        { 1,1,1,1,1,1,1 }, },
    {//I
        { 1,1,1,1,1,1,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,4,0,0,0,5,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,1,1,1,1,1,1 }, },
    {//J
        { 1,1,1,1,1,1,1 },
        { 1,0,0,4,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,5,0,0,1 },
        { 1,1,1,1,1,1,1 }, },
    {//K
        { 1,1,1,1,1,1,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,4,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,1,1,1,1,1,1 }, },
    {//L
        { 1,1,1,1,1,1,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,4,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,3,0,0,1 },
        { 1,1,1,1,1,1,1 }, },
    {//M
        { 1,1,1,1,1,1,1 },
        { 1,2,2,2,2,2,1 },
        { 1,2,0,0,0,2,1 },
        { 1,2,0,0,0,2,1 },
        { 1,2,0,0,0,2,1 },
        { 1,2,2,2,2,2,1 },
        { 1,1,1,1,1,1,1 }, },
    {//N
        { 1,1,1,1,1,1,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,4,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,1,1,1,1,1,1 }, },
    {//O
        { 1,1,1,1,1,1,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,4,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,1,1,1,1,1,1 }, },
    {//P
        { 1,1,1,1,1,1,1 },
        { 1,0,0,4,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,5,0,0,1 },
        { 1,1,1,1,1,1,1 }, },
    {//Q
        { 1,1,1,1,1,1,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,4,0,0,0,3,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,1,1,1,1,1,1 }, },
    {//R
        { 1,1,1,1,1,1,1 },
        { 1,0,0,4,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,3,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,1,1,1,1,1,1 }, },
    {//S
        { 1,1,1,1,1,1,1 },
        { 1,0,0,4,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,5,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,3,0,0,1 },
        { 1,1,1,1,1,1,1 }, },
    {//T
        { 1,1,1,1,1,1,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,4,0,0,1 },
        { 1,1,1,1,1,1,1 }, },
    {//U
        { 1,1,1,1,1,1,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,4,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,1,1,1,1,1,1 }, },
    {//V
        { 1,1,1,1,1,1,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,4,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,3,0,0,1 },
        { 1,1,1,1,1,1,1 }, },
    {//W
        { 1,1,1,1,1,1,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,3,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,1,1,1,1,1,1 }, },
    {//X
        { 1,1,1,1,1,1,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,2,0,0,0,2,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,3,0,0,1 },
        { 1,1,1,1,1,1,1 }, },
    {//Y
        { 1,1,1,1,1,1,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,6,0,0,1 },
        { 1,1,1,1,1,1,1 }, },
    {//Z
        { 1,1,1,1,1,1,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,2,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,1 },
        { 1,1,1,1,1,1,1 }, }
};

//4층 - 미로 게임
void mazegame_floor4() {
    int currentMap_floor4 = 0;
    int row = 3, column = 3;
    char direction = ' ';
    printf("\033[2J");
    printf("\033[10;1f");
    printmazemap_floor4(mazemaps_floor4[currentMap_floor4]);
    printf("\033[10;1f");
    for (int mazeexit_floor4 = 0; mazeexit_floor4 == 0; ) {
        printf("\033[%d;%df  ", row + 1, column * 2 + 1);
        mazemove_floor4(direction, &row, &column, mazemaps_floor4[currentMap_floor4]);
        printf("\033[%d;%df옷", row + 1, column * 2 + 1);
        if (currentMap_floor4 == 0) {
            if (mazemaps_floor4[currentMap_floor4][row][column] == 9) {
                changemazemap_floor4(&currentMap_floor4, 1, &row, &column, mazemaps_floor4);
            }
            else if (mazemaps_floor4[currentMap_floor4][row][column] == 7) {
                changemazemap_floor4(&currentMap_floor4, 0, &row, &column, mazemaps_floor4);
                printf("\033[10;1f정답은 게임 시작 후 '아래 -> 왼쪽 -> 왼쪽 -> 아래 -> 오른쪽 -> 아래 \n-> 아래 -> 오른쪽 -> 오른쪽 -> 아래 -> 왼쪽 -> 아래 -> 아래'입니다.");
            }
        }
        if (currentMap_floor4 == 1) {
            if (mazemaps_floor4[currentMap_floor4][row][column] == 3) {
                changemazemap_floor4(&currentMap_floor4, 4, &row, &column, mazemaps_floor4);
            }
            else if (mazemaps_floor4[currentMap_floor4][row][column] == 8) {
                changemazemap_floor4(&currentMap_floor4, 0, &row, &column, mazemaps_floor4);
            }
        }
        if ((currentMap_floor4 == 2) && (mazemaps_floor4[currentMap_floor4][row][column] == 3)) {
            changemazemap_floor4(&currentMap_floor4, 6, &row, &column, mazemaps_floor4);
        }
        if ((currentMap_floor4 == 3) && (mazemaps_floor4[currentMap_floor4][row][column] == 3)) {
            changemazemap_floor4(&currentMap_floor4, 2, &row, &column, mazemaps_floor4);
        }
        if (currentMap_floor4 == 4) {
            if (mazemaps_floor4[currentMap_floor4][row][column] == 3) {
                changemazemap_floor4(&currentMap_floor4, 3, &row, &column, mazemaps_floor4);
            }
            else if (mazemaps_floor4[currentMap_floor4][row][column] == 4) {
                changemazemap_floor4(&currentMap_floor4, 8, &row, &column, mazemaps_floor4);
            }
            else if (mazemaps_floor4[currentMap_floor4][row][column] == 5) {
                changemazemap_floor4(&currentMap_floor4, 5, &row, &column, mazemaps_floor4);
            }
        }
        if ((currentMap_floor4 == 5) && (mazemaps_floor4[currentMap_floor4][row][column] == 4)) {
            changemazemap_floor4(&currentMap_floor4, 9, &row, &column, mazemaps_floor4);
        }
        if ((currentMap_floor4 == 6) && (mazemaps_floor4[currentMap_floor4][row][column] == 3)) {
            changemazemap_floor4(&currentMap_floor4, 7, &row, &column, mazemaps_floor4);
        }
        if (currentMap_floor4 == 7) {
            if (mazemaps_floor4[currentMap_floor4][row][column] == 3) {
                changemazemap_floor4(&currentMap_floor4, 12, &row, &column, mazemaps_floor4);
            }
            else if (mazemaps_floor4[currentMap_floor4][row][column] == 4) {
                changemazemap_floor4(&currentMap_floor4, 8, &row, &column, mazemaps_floor4);
            }
        }
        if ((currentMap_floor4 == 8) && (mazemaps_floor4[currentMap_floor4][row][column] == 4)) {
            changemazemap_floor4(&currentMap_floor4, 13, &row, &column, mazemaps_floor4);
        }
        if (currentMap_floor4 == 9) {
            if (mazemaps_floor4[currentMap_floor4][row][column] == 4) {
                changemazemap_floor4(&currentMap_floor4, 8, &row, &column, mazemaps_floor4);
            }
            else if (mazemaps_floor4[currentMap_floor4][row][column] == 5) {
                changemazemap_floor4(&currentMap_floor4, 10, &row, &column, mazemaps_floor4);
            }
        }
        if (currentMap_floor4 == 10) {
            if (mazemaps_floor4[currentMap_floor4][row][column] == 4) {
                currentMap_floor4 = 26;
                row = 5, column = 3;
                printmazemap_floor4(mazemaps_floor4[currentMap_floor4]);
                printf("\033[%d;%df옷", row + 1, column * 2 + 1);
            }
            else if (mazemaps_floor4[currentMap_floor4][row][column] == 5) {
                changemazemap_floor4(&currentMap_floor4, 15, &row, &column, mazemaps_floor4);
            }
        }
        if ((currentMap_floor4 == 11) && (mazemaps_floor4[currentMap_floor4][row][column] == 4)) {
            currentMap_floor4 = 26;
            row = 3, column = 5;
            printmazemap_floor4(mazemaps_floor4[currentMap_floor4]);
            printf("\033[%d;%df옷", row + 1, column * 2 + 1);
        }
        if (currentMap_floor4 == 12) {
            if (mazemaps_floor4[currentMap_floor4][row][column] == 3) {
                changemazemap_floor4(&currentMap_floor4, 17, &row, &column, mazemaps_floor4);
            }
            else if (mazemaps_floor4[currentMap_floor4][row][column] == 4) {
                changemazemap_floor4(&currentMap_floor4, 13, &row, &column, mazemaps_floor4);
            }
        }
        if ((currentMap_floor4 == 13) && (mazemaps_floor4[currentMap_floor4][row][column] == 2)) {
            changemazemap_floor4(&currentMap_floor4, 1, &row, &column, mazemaps_floor4);
            printf("\033[9;1f여기 아니지롱 ㅋㅋ");
            fflush(stdout);
            sleep(1.5);
            printf("\033[9;1f                    ");
        }
        if ((currentMap_floor4 == 14) && (mazemaps_floor4[currentMap_floor4][row][column] == 4)) {
            changemazemap_floor4(&currentMap_floor4, 13, &row, &column, mazemaps_floor4);
        }
        if ((currentMap_floor4 == 15) && (mazemaps_floor4[currentMap_floor4][row][column] == 4)) {
            currentMap_floor4 = 26;
            row = 3, column = 1;
            printmazemap_floor4(mazemaps_floor4[currentMap_floor4]);
            printf("\033[%d;%df옷", row + 1, column * 2 + 1);
        }
        if (currentMap_floor4 == 16) {
            if (mazemaps_floor4[currentMap_floor4][row][column] == 4) {
                changemazemap_floor4(&currentMap_floor4, 11, &row, &column, mazemaps_floor4);
            }
            else if (mazemaps_floor4[currentMap_floor4][row][column] == 5) {
                currentMap_floor4 = 26;
                row = 1, column = 3;
                printmazemap_floor4(mazemaps_floor4[currentMap_floor4]);
                printf("\033[%d;%df옷", row + 1, column * 2 + 1);
            }
        }
        if (currentMap_floor4 == 17) {
            if (mazemaps_floor4[currentMap_floor4][row][column] == 3) {
                changemazemap_floor4(&currentMap_floor4, 18, &row, &column, mazemaps_floor4);
            }
            else if (mazemaps_floor4[currentMap_floor4][row][column] == 4) {
                changemazemap_floor4(&currentMap_floor4, 16, &row, &column, mazemaps_floor4);
            }
        }
        if (currentMap_floor4 == 18) {
            if (mazemaps_floor4[currentMap_floor4][row][column] == 3) {
                changemazemap_floor4(&currentMap_floor4, 19, &row, &column, mazemaps_floor4);
            }
            else if (mazemaps_floor4[currentMap_floor4][row][column] == 4) {
                changemazemap_floor4(&currentMap_floor4, 13, &row, &column, mazemaps_floor4);
            }
        }
        if (currentMap_floor4 == 19) {
            if (mazemaps_floor4[currentMap_floor4][row][column] == 3) {
                changemazemap_floor4(&currentMap_floor4, 23, &row, &column, mazemaps_floor4);
            }
            else if (mazemaps_floor4[currentMap_floor4][row][column] == 4) {
                changemazemap_floor4(&currentMap_floor4, 14, &row, &column, mazemaps_floor4);
            }
            else if (mazemaps_floor4[currentMap_floor4][row][column] == 5) {
                changemazemap_floor4(&currentMap_floor4, 20, &row, &column, mazemaps_floor4);
            }
        }
        if ((currentMap_floor4 == 20) && (mazemaps_floor4[currentMap_floor4][row][column] == 4)) {
            currentMap_floor4 = 26;
            row = 5, column = 3;
            printmazemap_floor4(mazemaps_floor4[currentMap_floor4]);
            printf("\033[%d;%df옷", row + 1, column * 2 + 1);
        }
        if ((currentMap_floor4 == 21) && (mazemaps_floor4[currentMap_floor4][row][column] == 4)) {
            currentMap_floor4 = 26;
            row = 3, column = 5;
            printmazemap_floor4(mazemaps_floor4[currentMap_floor4]);
            printf("\033[%d;%df옷", row + 1, column * 2 + 1);
        }
        if (currentMap_floor4 == 22) {
            if (mazemaps_floor4[currentMap_floor4][row][column] == 3) {
                changemazemap_floor4(&currentMap_floor4, 24, &row, &column, mazemaps_floor4);
            }
            else if (mazemaps_floor4[currentMap_floor4][row][column] == 4) {
                changemazemap_floor4(&currentMap_floor4, 21, &row, &column, mazemaps_floor4);
            }
        }
        if ((currentMap_floor4 == 23) && (mazemaps_floor4[currentMap_floor4][row][column] == 3)) {
            printmazemap_floor4(mazemaps_floor4[currentMap_floor4]);
            changemazemap_floor4(&currentMap_floor4, 22, &row, &column, mazemaps_floor4);
        }
        if (currentMap_floor4 == 24) {
            if (mazemaps_floor4[currentMap_floor4][row][column] == 3) {
                changemazemap_floor4(&currentMap_floor4, 25, &row, &column, mazemaps_floor4);
            }
            else if (mazemaps_floor4[currentMap_floor4][row][column] == 2) {
                changemazemap_floor4(&currentMap_floor4, 1, &row, &column, mazemaps_floor4);
                printf("\033[9;1f여기 아니지롱 ㅋㅋ");
                fflush(stdout);
                sleep(1.5);
                printf("\033[9;1f                    ");
            }
        }
        if ((currentMap_floor4 == 25) && (mazemaps_floor4[currentMap_floor4][row][column] == 6)) {
            clearscreen_floor4();
            printf("\033[10;1f열쇠를 얻었다! 이제 과방에서 나가자!");
            printf("\033[11;1f\033[2K돌아가려면 'A' 또는 'a'를 입력하세요: ");
            mazeexit_floor4 = 1;
            key_floor4 = 1;
        }
        if ((currentMap_floor4 == 26) && (mazemaps_floor4[currentMap_floor4][row][column] == 2)) {
            changemazemap_floor4(&currentMap_floor4, 1, &row, &column, mazemaps_floor4);
            printf("\033[9;1f여기 아니지롱 ㅋㅋ");
            fflush(stdout);
            sleep(1.5);
            printf("\033[9;1f                    ");
        }
        printf("\033[8;1f\033[2K방향키(WASD)를 입력하세요: ");
        scanf("\n%c", &direction);
        printf("\033[9;1f                       ");
        if ((direction != 'w') && (direction != 'W') &&
            (direction != 'a') && (direction != 'A') &&
            (direction != 's') && (direction != 'S') &&
            (direction != 'd') && (direction != 'D')) {
            printf("\033[8;1f\033[2K잘못된 입력입니다. 방향키(WASD)를 입력하세요: ");
            scanf("\n%c", &direction);
        }
    }
    clearscreen_floor4();
    printmap1_floor4(map1_floor4);
    row = 2, column = 6;
    printf("\033[2;15f옷");
}

//4층 - 워들 게임
int wordle_floor4(int count, char you[6], char wordle[30], char words[200][6], int num) {
    char again;
    while (1) {
        count = 6;
        printf("=============\n");
        printf("| ? ? ? ? ? |\n");
        printf("=============\n");
        while (count > 0) {
            printf("기회 %d번 남았습니다.\n단어를 입력하세요: ", count);
            scanf("%s", you);
            printf("\n");
            // 대문자 -> 소문자
            for (int i = 0; you[i] != '\0'; i++) {
                if (you[i] >= 'A' && you[i] <= 'Z') {
                    you[i] += 32;
                }
            }
            printf("=============\n");
            printf("|   ");
            int letter_floor4 = 0;
            if (!strcmp(wordle, you)) {
                printf("\033[32m%s\033[0m", you);
                printf("    |\n=============\n");
                printf("정답입니다!\n");
                printf("계단 비밀번호 : 71409");
                sleep(2);
                clearscreen_floor4();
                key_floor4 = 10;
                return 0;
            }
            while (letter_floor4 < 5) {
                if (words[num][letter_floor4] == you[letter_floor4]) {
                    printf("\033[32m%c\033[0m", you[letter_floor4]);
                }
                else if (words[num][0] == you[letter_floor4] ||
                    words[num][1] == you[letter_floor4] ||
                    words[num][2] == you[letter_floor4] ||
                    words[num][3] == you[letter_floor4] ||
                    words[num][4] == you[letter_floor4]) {
                    printf("\033[33m%c\033[0m", you[letter_floor4]);
                }
                else {
                    printf("%c", you[letter_floor4]);
                }
                letter_floor4++;
            }
            printf("    |\n=============\n");
            count--;
        }
        printf("기회를 모두 소진했습니다!\n");
        printf("정답: %s\n", wordle);
        printf("나가려면 ENTER를 누르세요.");
        getchar();
        pressenter_floor4();
        return 0;
    }
}
void wordle_start_floor4() {
    char words[200][6] = {
        "apple", "beach", "bread", "cloud", "dance", "earth", "flame", "glass",
        "heart", "ivory", "juice", "knife", "lemon", "music", "night", "ocean",
        "piano", "queen", "river", "stone", "table", "uncle", "voice", "water",
        "young", "zebra", "break", "birth", "candy", "dream", "early", "fruit",
        "grape", "house", "index", "joker", "light", "maple", "novel", "olive",
        "party", "quiet", "radio", "smile", "tiger", "urban", "vivid", "world",
        "yield", "array", "alarm", "brick", "cabin", "camel", "chain", "chest",
        "clock", "crown", "dairy", "daisy", "eagle", "entry", "field", "flute",
        "frost", "giant", "glory", "grass", "green", "honey", "image", "irony",
        "jelly", "koala", "layer", "lucky", "match", "medal", "metal", "money",
        "north", "organ", "paint", "paper", "pearl", "phone", "pilot", "plant",
        "plate", "proud", "razor", "route", "scale", "sheep", "shirt", "snack",
        "train", "truck", "whale", "debug"
    };
    srand(time(NULL));
    int num = rand() % 100;
    char wordle[30];
    strcpy(wordle, words[num]);
    char you[6];
    int count = 6;
    int play;
    clearscreen_floor4();
    do {
        printf("\033[1;1f=======PLAY WORDLE========\n");
        printf("|                        |\n");
        printf("| 1. 규칙   2. 게임 시작 |\n");
        printf("|                        |\n");
        printf("==========================\n");
        scanf("%d", &play);
        if (play == 1) {
            printf("글자와 위치가 모두 일치하면 \033[32m초록색\033[0m, ");
            printf("글씨는 맞지만 위치가 틀리면 \033[33m노란색\033[0m,");
            printf(" 둘 다 틀리면 흰색으로 표시됩니다.\n기회는 총 6번, ");
            printf("5글자 영어 단어를 추측하세요!\n\n");
            wordle_floor4(count, you, wordle, words, num);
        }
        if (play == 2) {
            wordle_floor4(count, you, wordle, words, num);
        }
    } while (play != 1 && play != 2);
}

//4층 - 4층 맵 출력
char map2symbol_floor4[20][1024] = {
    "  ",
    "\033[48;2;169;169;169m  \033[0m",//1
    "\033[38;2;160;82;45m문\033[0m",//2
    "\033[32m계\033[0m",//3
    "\033[32m단\033[0m",//4
    "\033[31mXX\033[0m",//5
    "\033[32m계\033[0m",//6
    "\033[32m단\033[0m",//7
    "  ",//8
    "\033[38;2;160;82;45m문\033[0m",//9
    "\033[38;2;160;82;45m문\033[0m",//10
    "\033[38;2;160;82;45m엘\033[0m",//11
    "\033[38;2;160;82;45m베\033[0m"//12
};
void printmap2_floor4(int map2_floor4[35][65]) {
    clearscreen_floor4();
    printf("\033[2K\033[2;1f");
    for (int row = 0; row < 35; row++) {
        for (int column = 0; column < 65; column++) {
            printf("%s", map2symbol_floor4[map2_floor4[row][column]]);
        }
        printf("\n");
    }
    printf("\033[1;1f\033[32m소문자(wasd)\033[0m로 1칸, \033[34m대문자(WASD)\033[0m로 2칸 이동할 수 있습니다.");
}

//4층 - 4층 캐릭터 이동
void map2move_floor4(char direction, int* row, int* column, int map2_floor4[35][65]) {
    //소문자 입력
    if ((direction == 'w') && (0 < *row) &&
        (map2_floor4[*row - 1][*column] != 1) &&
        (map2_floor4[*row - 1][*column] != 5) &&
        (map2_floor4[*row - 1][*column] != 8))
        (*row)--;
    else if ((direction == 'a') && (0 < *column) &&
        (map2_floor4[*row][*column - 1] != 1) &&
        (map2_floor4[*row][*column - 1] != 5) &&
        (map2_floor4[*row][*column - 1] != 8))
        (*column)--;
    else if ((direction == 's') && (*row < 34) &&
        (map2_floor4[*row + 1][*column] != 1) &&
        (map2_floor4[*row + 1][*column] != 5) &&
        (map2_floor4[*row + 1][*column] != 8))
        (*row)++;
    else if ((direction == 'd') && (*column < 64) &&
        (map2_floor4[*row][*column + 1] != 1) &&
        (map2_floor4[*row][*column + 1] != 5) &&
        (map2_floor4[*row][*column + 1] != 8))
        (*column)++;
    //대문자 입력
    else if ((direction == 'W') && (0 < *row) &&
        (map2_floor4[*row - 1][*column] != 1) &&
        (map2_floor4[*row - 1][*column] != 5) &&
        (map2_floor4[*row - 1][*column] != 8)) {
        (*row)--;
        if ((map2_floor4[*row - 1][*column] != 1) &&
            (map2_floor4[*row - 1][*column] != 5) &&
            (map2_floor4[*row - 1][*column] != 8)) {
            (*row)--;
        }
    }
    else if ((direction == 'A') && (0 < *column) &&
        (map2_floor4[*row][*column - 1] != 1) &&
        (map2_floor4[*row][*column - 1] != 5) &&
        (map2_floor4[*row][*column - 1] != 8)) {
        (*column)--;
        if ((map2_floor4[*row][*column - 1] != 1) &&
            (map2_floor4[*row][*column - 1] != 5) &&
            (map2_floor4[*row][*column - 1] != 8)) {
            (*column)--;
        }
    }
    else if ((direction == 'S') && (*row < 34) &&
        (map2_floor4[*row + 1][*column] != 1) &&
        (map2_floor4[*row + 1][*column] != 5) &&
        (map2_floor4[*row + 1][*column] != 8)) {
        (*row)++;
        if ((map2_floor4[*row + 1][*column] != 1) &&
            (map2_floor4[*row + 1][*column] != 5) &&
            (map2_floor4[*row + 1][*column] != 8)) {
            (*row)++;
        }
    }
    else if ((direction == 'D') && (*column < 64) &&
        (map2_floor4[*row][*column + 1] != 1) &&
        (map2_floor4[*row][*column + 1] != 5) &&
        (map2_floor4[*row][*column + 1] != 8)) {
        (*column)++;
        if ((map2_floor4[*row][*column + 1] != 1) &&
            (map2_floor4[*row][*column + 1] != 5) &&
            (map2_floor4[*row][*column + 1] != 8)) {
            (*column)++;
        }
    }
}

//4층 - 4층 맵
int map2_floor4[35][65] = {
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,1,1,5,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,8,2,0,0,1,1,1,1,5,1,1,1,1,5,1,1,1,5,1,1,1,1,5,1,1,1,5,1,1,1,5,1,1,1,5,1,1,1,5,1,1,1,5,1,1,1,1,5,1,1,1,5,1,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,5,1,5,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,9,8,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,9,8,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1 },
{ 1,5,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1 },
{ 1,5,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,1,1,1,1,1,1,1,1 },
{ 1,0,0,0,0,1,0,0,0,0,5,0,0,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,1,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,1,0,0,0,0,1,3,4,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,1,0,0,0,0,1,8,8,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,11,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,5,1,1,0,0,0,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,12,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,5,0,0,0,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,1,1,1,1,1 },
{ 1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,8,0,0,1 },
{ 1,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,8,0,1 },
{ 1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,8,0,1 },
{ 1,0,0,0,0,0,0,0,1,5,1,1,1,1,1,1,1,1,1,1,5,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,10,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,10,1,5,1,1,1,1,1,1 },
{ 1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,1,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};

//4층 - 4층 게임 진행
void game_map2_floor4() {
    clearscreen_floor4();
    printmap2_floor4(map2_floor4);
    int row = 5, column = 9;
    char direction = ' ';
    int code_floor4 = 0;
    do {
        printf("\033[%d;%df%s", row + 2, column * 2 + 1, map2symbol_floor4[map2_floor4[row][column]]);
        map2move_floor4(direction, &row, &column, map2_floor4);
        printf("\033[%d;%df옷", row + 2, column * 2 + 1);
        if (map2_floor4[row][column] == 2) { //과방
            printf("\033[38;1f도어락이 자동으로 잠겨버렸다. 다시 돌아갈 수는 없을 것 같다.");
        }
        if (map2_floor4[row][column] == 3 || map2_floor4[row][column] == 4) { // 4층 탈출
            if (key_floor4 == 10) {
                while (1) {
                    printf("\033[2J");
                    printf("\033[1;1f _____________________________________________________ \n");
                    printf("|                                                     |\n");
                    printf("|        문을 열려면 관리자 코드가 필요합니다         |\n");
                    printf("|            _____ _____ _____ _____ _____            |\n");
                    printf("|           |     |     |     |     |     |           |\n");
                    printf("|           |     |     |     |     |     |           |\n");
                    printf("|           |     |     |     |     |     |           |\n");
                    printf("|           |_____|_____|_____|_____|_____|           |\n");
                    printf("|_____________________________________________________|\n");
                    printf("관리자 코드 입력 : ");
                    scanf("%d", &code_floor4);
                    if (code_floor4 == 71409) {
                        floor_change = 3;
                        return;
                    }
                    printf("틀렸습니다. 다시 입력하겠습니까? (y/n): ");
                    char again;
                    scanf(" %c", &again);
                    if (again != 'y' && again != 'Y') {
                        printmap2_floor4(map2_floor4);
                        printf("\033[%d;%df옷", row + 2, column * 2 + 1);
                        break;
                    }
                }
            }
            else if (key_floor4 != 10) {
                while (1) {
                    printf("\033[2J");
                    printf("\033[1;1f _____________________________________________________ \n");
                    printf("|                                                     |\n");
                    printf("|        문을 열려면 관리자 코드가 필요합니다         |\n");
                    printf("|            _____ _____ _____ _____ _____            |\n");
                    printf("|           |     |     |     |     |     |           |\n");
                    printf("|           |     |     |     |     |     |           |\n");
                    printf("|           |     |     |     |     |     |           |\n");
                    printf("|           |_____|_____|_____|_____|_____|           |\n");
                    printf("|                                                     |\n");
                    printf("|_____________________________________________________|\n");
                    printf("3층으로 내려가려면 관리자 코드가 필요하다.\n");
                    printf("ENTER를 눌러 뒤로가기");
                    getchar();
                    pressenter_floor4();
                    printmap2_floor4(map2_floor4);
                    printf("\033[%d;%df옷", row + 2, column * 2 + 1);
                    break;
                }
            }
        }

        if (map2_floor4[row][column] == 9) { //G418
            if (key_floor4 == 10) {
                printf("\033[38;1f계단 비밀번호는 71409입니다.");
            }
            if (key_floor4 != 10) {
                printf("\033[38;1f강의용 컴퓨터가 켜져있어 가보니 wordle이 켜져있다. 게임을 해보자.");
                sleep(2);
                wordle_start_floor4();
                printmap2_floor4(map2_floor4);
                printf("\033[%d;%df옷", row + 2, column * 2 + 1);
            }
        }

        if (map2_floor4[row][column] == 10) { //G420
            printf("\033[38;1f강의실을 샅샅이 살펴보았지만 아무것도 발견하지 못했다. 다른 강의실을 가봐야할 것 같다.");
        }

        if (map2_floor4[row][column] == 6 || map2_floor4[row][column] == 7) {
            printf("\033[38;1f이 계단은 이용할 수 없다. 다른 계단을 이용해보자.");
        }

        if (map2_floor4[row][column] == 11 || map2_floor4[row][column] == 12) { //엘베
            printf("\033[38;1f작동하지 않는 것 같다");
        }

        printf("\033[37;1f\033[2K방향키(WASD)를 입력하세요: ");
        scanf("\n%c", &direction);
        printf("\033[38;1f\033[2K       ");
        printf("\033[39;1f\033[2K       ");
        if ((direction != 'w') && (direction != 'W') &&
            (direction != 'a') && (direction != 'A') &&
            (direction != 's') && (direction != 'S') &&
            (direction != 'd') && (direction != 'D')) {
            printf("\033[37;1f\033[2K잘못된 입력입니다. 방향키(WASD)를 입력하세요: ");
            scanf(" %c", &direction);
        }
    } while ((direction == 'W') || (direction == 'A') || (direction == 'S') || (direction == 'D') ||
        (direction == 'w') || (direction == 'a') || (direction == 's') || (direction == 'd'));
}

//4층 - 과방 게임 진행
void start_floor4() {
    clearscreen_floor4();
    printf("\033[10;1f");
    printmap1_floor4(map1_floor4);
    int row = 9, column = 13;
    char direction = ' ';
    do {
        printf("\033[%d;%df%s", row + 1, column * 2 + 1, map1symbol_floor4[map1_floor4[row][column]]);
        map1move_floor4(direction, &row, &column, map1_floor4);
        printf("\033[%d;%df옷", row + 1, column * 2 + 1);
        if (map1_floor4[row][column] == 2 && key_floor4 == 1) {
            game_map2_floor4();
            return;
        }
        else if (map1_floor4[row][column] == 2 && key_floor4 == 0) {
            printf("\033[2;38f문이 잠겨있다. 나가려면 열쇠가 필요할 것 같다.");
            printf("\033[3;38f열쇠를 찾아보자.");
        }
        else if (map1_floor4[row][column] == 11 && key_floor4 == 1) {
            printf("\033[2;38f열쇠를 얻었으니 문을 열고 나가보자.");
        }
        else if (map1_floor4[row][column] == 11 && key_floor4 == 0) {
            mazegame_floor4();
        }

        printf("\033[14;1f\033[2K방향키(WASD)를 입력하세요: ");
        scanf("\n%c", &direction);
        printf("\033[15;1f\033[2K       ");
        printf("\033[16;1f\033[2K       ");
        if ((direction != 'w') && (direction != 'W') &&
            (direction != 'a') && (direction != 'A') &&
            (direction != 's') && (direction != 'S') &&
            (direction != 'd') && (direction != 'D')) {
            printf("\033[14;1f\033[2K잘못된 입력입니다. 방향키(WASD)를 입력하세요: ");
            scanf(" %c", &direction);
            printf("\033[15;1f\033[2K       ");
            printf("\033[16;1f\033[2K       ");
        }
    } while ((direction == 'W') || (direction == 'A') || (direction == 'S') || (direction == 'D') ||
        (direction == 'w') || (direction == 'a') || (direction == 's') || (direction == 'd'));
}

//3층 - 엘베 방문 여부- 1 == 방문함, 0 == 방문하지 않음.
int visitedElevator_floor3 = 0;

//3층 - 화면 지우기 함수
void clearScreen_floor3() {
    printf("\033[2J\033[1;1f");
}

//3층 - 엔터 함수
void pressEnter_floor3() {
    int c;
    printf("\n  [ Enter 키를 눌러 계속... ]\n");
    while (getchar() != '\n' && c != EOF);
    getchar();
}

//3층 - 301호 전경
void show_301_floor3() {

    clearScreen_floor3();

    printf("\n     \033[36m[ 301호 강의실 ]\033[0m\n\n");

    printf("  +-----------------------------------------------+\n");
    printf("  |  _________________________________________    |\n");
    printf("  | |                     O                   |   |\n");
    printf("  | |                 < 칠  판 >              |   |\n");
    printf("  | |_________________________________________|   |\n");
    printf("  |                                  [교수님 자리]|\n");
    printf("  |   ____   ____   ____   ____   ____            |\n");
    printf("  |  |    | |    | |    | |    | |    |           |\n");
    printf("  |  |책상| |책상| |책상| |책상| |책상|           |\n");
    printf("  |  |____| |____| |____| |____| |____|           |\n");
    printf("  |   ____   ____   ____   ____   ____            |\n");
    printf("  |  |    | |    | |    | |    | |    |           |\n");
    printf("  |  |책상| |책상| |책상| |책상| |책상|           |\n");
    printf("  |  |____| |____| |____| |____| |____|           |\n");
    printf("  |                                               |\n");
    printf("  |                                               |\n");
    printf("  +-----------------------------------------------+\n\n");

    printf("  텅 빈 강의실이다. 어디를 조사할까?\n\n");

    printf("  1. 칠판을 살펴본다.\n\n");
    printf("  2. 시계를 살펴본다.\n\n");
    printf("  3. 책상을 살펴본다.\n\n");
    printf("  0. 돌아간다\n\n");

    printf("  선택 >> ");
}

//3층 - 301호 시계
void show_clock_ascii_floor3() {
    clearScreen_floor3();

    printf("\n");
    printf("          \033[33m      12        \033[0m\n");
    printf("          \033[33m   .─────.     \033[0m\n");
    printf("          \033[33m  /        \\   \033[0m\n");
    printf("          \033[33m |          |  \033[0m\n");
    printf("          \033[33m9 ????╋     3  \033[0m\n");
    printf("          \033[33m |          |  \033[0m\n");
    printf("          \033[33m  \\        /  \033[0m\n");
    printf("          \033[33m   '─────'     \033[0m\n");
    printf("          \033[33m       6        \033[0m\n\n");

    printf("  \033[37m!!... 시계가 이상하다.\033[0m\n\n");
    printf("  시침, 분침, 초침... 세 바늘이 모두 \033[33m9\033[0m를 향해 멈춰 있다.\n\n");
}

//3층 - 301호 퍼즐
void puzzle_301_floor3() {

    if (visitedElevator_floor3 == 0) {      //엘베 먼저 확인 후 퍼즐 풀 수 있도록
        clearScreen_floor3();
        printf("\n  엘레베이터가 작동하는지 먼저 확인해보자.\n");
        pressEnter_floor3();
        return;
    }

    int choice_floor3;      //선택지
    int staying_floor3 = 1; //1,2,3 선택 후 돌아가기 누르면 301호로 돌아가도록

    while (staying_floor3) {

        show_301_floor3();

        do {
            scanf("%d", &choice_floor3);
        } while (choice_floor3 < 0 || choice_floor3 > 3);

        while (getchar() != '\n');

        switch (choice_floor3) {

        case 1: //칠판을 살펴본다.

            clearScreen_floor3();

            printf("\n");
            printf("  \033[90m+─────────────────────────────────────────+\033[0m\n");
            printf("  \033[90m|\033[0m  \033[37m< 2진수 -> 10진수 변환 >               \033[90m|\033[0m\n");
            printf("  \033[90m|\033[0m                                         \033[90m|\033[0m\n");
            printf("  \033[90m|\033[0m  \033[37m  각 자릿수에 아래 값을 곱한 뒤 합산   \033[90m|\033[0m\n");
            printf("  \033[90m|\033[0m                                         \033[90m|\033[0m\n");
            printf("  \033[90m|\033[0m  \033[37m  자릿수:  8   4   2   1               \033[90m|\033[0m\n");
            printf("  \033[90m|\033[0m  \033[37m  값   :   ?   ?   ?   ?               \033[90m|\033[0m\n");
            printf("  \033[90m|\033[0m                                         \033[90m|\033[0m\n");
            printf("  \033[90m|\033[0m  \033[37m  = (?x8) + (?x4) + (?x2) + (?x1)      \033[90m|\033[0m\n");
            printf("  \033[90m|\033[0m                                         \033[90m|\033[0m\n");
            printf("  \033[90m+─────────────────────────────────────────+\033[0m\n\n");

            printf("  누군가 수업 내용을 판서해둔 것 같다.\n");

            pressEnter_floor3();

            break;

        case 2: //시계를 살펴본다.

            show_clock_ascii_floor3();

            pressEnter_floor3();

            break;

        case 3: //책상을 살펴본다.

            clearScreen_floor3();

            printf("\n");
            printf("    \033[33m ___________  \033[0m\n");
            printf("    \033[33m|  '        | \033[0m\n");
            printf("    \033[33m|           | \033[0m\n");
            printf("    \033[33m|___________| \033[0m\n");
            printf("    \033[33m  |       |   \033[0m\n");
            printf("    \033[33m  |       |   \033[0m\n\n");

            printf("  이 자리에 앉았던 학생이 \033[90m'집에 가고 싶다...'\033[0m 라고 낙서해놨다. 나도... \n");

            pressEnter_floor3();

            break;

        case 0: //돌아간다.(함수종료)

            staying_floor3 = 0;

            break;
        }
    }
}

//3층 - 징검다리 퍼즐
void puzzle_locker_floor3() {

    if (visitedElevator_floor3 == 0) {  //엘베 먼저 확인 후 퍼즐 풀 수 있도록
        clearScreen_floor3();
        printf("\n  엘레베이터가 작동하는지 먼저 확인해보자.\n");
        pressEnter_floor3();
        return;
    }

    int choice_floor3 = -1; //선택지

    while (choice_floor3 != 0) {
        clearScreen_floor3();

        printf("\n     \033[36m[ 징검다리 구역 ]\033[0m\n\n");

        printf("  자하관으로 넘어갈 수 있는 징검다리 구역.\n\n");
        printf("  하지만 유리문은 잠겨있다. 근처를 둘러볼까?\n\n");
        printf("  한쪽 벽에 사물함들이 줄지어 있다.\n\n");
        printf("  1. 사물함을 살펴본다\n\n");
        printf("  2. 사물함을 열어본다\n\n");
        printf("  0. 돌아간다.\n\n");

        printf("  선택 >> ");
        scanf("%d", &choice_floor3);

        while (getchar() != '\n');

        switch (choice_floor3) {

        case 1: //사물함을 살펴본다.

            clearScreen_floor3();

            printf("\n");
            printf("  \033[33m ┌─────┬─────┬─────┬─────┐\033[0m\n");
            printf("  \033[33m │  0  │  1  │  1  │  0  │\033[0m\n");
            printf("  \033[33m └─────┴─────┴─────┴─────┘\033[0m\n\n");

            printf("  사물함 위에 '0 1 1 0' 이라는 숫자가 써져 있다.\n\n");

            pressEnter_floor3();
            break;

        case 2: //사물함을 열어본다.

            printf("\n  사물함은 모두 잠겨있다.\n");

            pressEnter_floor3();
            break;

        case 0: //돌아간다.(함수종료)

            break;

        }

    }
}

//3층 - 화장실 퍼즐
void puzzle_toilet_floor3() {

    if (visitedElevator_floor3 == 0) {  //엘베 먼저 확인 후 퍼즐 풀 수 있도록
        clearScreen_floor3();
        printf("\n  엘레베이터가 작동하는지 먼저 확인해보자.\n");
        pressEnter_floor3();
        return;
    }

    int choice_floor3 = -1; //선택지

    while (choice_floor3 != 0) { //0 == 돌아간다.(함수종료)
        clearScreen_floor3();

        printf("\n");
        printf("  \033[36m[ 3층 화장실 ]\033[0m\n\n");
        printf("  화장실 문 앞에 뜯어질 것 같은 종이 한 장이 붙어 있다.\n\n");

        printf("  1. 뜯어본다\n\n");
        printf("  0. 돌아간다\n\n");

        printf("  선택 >> ");
        scanf("%d", &choice_floor3);
        while (getchar() != '\n');

        if (choice_floor3 == 1) { //뜯어본다.
            clearScreen_floor3();
            printf("  뜯어보니 안쪽에 글씨가 적혀 있다.\n\n");

            printf("  \033[33m+-------------------------------------+\033[0m\n");
            printf("  \033[33m|   ※ 거짓말쟁이는 단 한 명          |\033[0m\n");
            printf("  \033[33m|                                     |\033[0m\n");
            printf("  \033[33m|  A: \"B는 진실을 말하고 있어\"        |\033[0m\n");
            printf("  \033[33m|  B: \"나는 거짓말쟁이가 아니야\"      |\033[0m\n");
            printf("  \033[33m|  C: \"A는 거짓말쟁이야\"              |\033[0m\n");
            printf("  \033[33m|  D: \"C는 진실을 말하고 있어\"        |\033[0m\n");
            printf("  \033[33m|                                     |\033[0m\n");
            printf("  \033[33m|  거짓말쟁이는 누구인가?             |\033[0m\n");
            printf("  \033[33m+-------------------------------------+\033[0m\n\n");

            pressEnter_floor3();
            choice_floor3 = 0;
        }
    }
}

//3층 - 교수님연구실 퍼즐
void puzzle_lab_floor3() {

    if (visitedElevator_floor3 == 0) {  //엘베 먼저 확인 후 퍼즐 풀 수 있도록
        clearScreen_floor3();
        printf("\n  엘레베이터가 작동하는지 먼저 확인해보자.\n");
        pressEnter_floor3();
        return;
    }

    int choice_floor3 = -1; //선택지

    while (choice_floor3 != 0) { //0 == 돌아간다.(함수종료)

        clearScreen_floor3();

        printf("\n  \033[36m[ 교수님 연구실 ]\033[0m\n\n");
        printf("\033[33m _________________\033[0m                                        \n");
        printf("\033[33m|  ______________ |\033[0m                                        \n");
        printf("\033[33m| |_\\_\\_\\_\\_\\_\\_| |\033[0m                                        \n");
        printf("\033[33m| |=|=|=|=|=|=|=| |\033[0m                                        \n");
        printf("\033[33m| | | | | | | | | |\033[0m                                        \n");
        printf("\033[33m| |_|_|_|_|_|_|_| |\033[0m                                        \n");
        printf("\033[33m|  _______________|\033[0m   \033[36m.───────────────.\033[0m                  \n");
        printf("\033[33m| |_\\_\\_\\_\\_\\_\\_| |\033[0m   \033[36m|  ___________  |\033[0m                  \n");
        printf("\033[33m| |=|=|=|=|||=|=| |\033[0m   \033[36m| |           | |\033[0m                  \n");
        printf("\033[33m| | | | | ||| | | |\033[0m   \033[36m| |           | |\033[0m                  \n");
        printf("\033[33m| |_|_|_|_|||_|_| |\033[0m   \033[36m| |           | |\033[0m              \n");
        printf("\033[33m|  ______________ |\033[0m   \033[36m| |___________| |\033[0m  \033[33m  (   )\033[0m          \n");
        printf("\033[33m| |_\\_\\_\\_\\_\\_\\_| |\033[0m   \033[36m`───────────────'\033[0m    \033[33m|   |\033[0m          \n");
        printf("\033[33m| |=|=|=|=|=|=|=| |\033[0m        \033[36m||||||\033[0m          \033[33m`───'\033[0m          \n");
        printf("\033[33m| | | | | | | | | |\033[0m   \033[36m──────────────────────────────\033[0m\n");
        printf("\033[33m| |_|_|_|_|_|_|_| |\033[0m   \033[36m  [   ] [   ]  ????????????\033[0m\n");
        printf("\033[33m|_________________|\033[0m  \033[36m──────────────────────────────\033[0m\n");
        printf("                            \033[36m|          |\033[0m                    \n");
        printf(" \033[90m───────────────────────────────────────────────────\033[0m\n\n");
        printf("  연구실 문이 조금 열려있다. 조심스럽게 들어간다.\n\n");
        printf("  책이 잔뜩 꽂혀있는 책장, 교수님의 컴퓨터 책상, 쓰레기통이 보인다.\n\n");

        printf("  1. 책상을 살펴본다\n\n");
        printf("  2. 쓰레기통을 살펴본다\n\n");
        printf("  3. 책장을 살펴본다\n\n");
        printf("  0. 돌아간다\n\n");

        printf("  선택 >> ");
        scanf("%d", &choice_floor3);
        while (getchar() != '\n');

        if (choice_floor3 == 1) {   //책상을 살펴본다.
            int Choice2_floor3 = -1;  //두번째 선택지
            while (Choice2_floor3 != 0) { //0 == 돌아간다.(함수종료)
                clearScreen_floor3();
                printf("  책상 앞에 섰다.\n\n");
                printf("  1. 컴퓨터를 살펴본다\n\n");
                printf("  2. 책상을 살펴본다\n\n");
                printf("  0. 돌아간다\n\n");
                printf("  선택 >> ");
                scanf("%d", &Choice2_floor3);
                while (getchar() != '\n');

                if (Choice2_floor3 == 1) { //컴퓨터를 살펴본다.
                    printf("\n");
                    printf("         \033[36m.─────────────────────────────.\033[0m\n");
                    printf("         \033[36m|  ┌─────────────────────────┐ |\033[0m\n");
                    printf("         \033[36m|  │                         │ |\033[0m\n");
                    printf("         \033[36m|  │                         │ |\033[0m\n");
                    printf("         \033[36m|  │                         │ |\033[0m\n");
                    printf("         \033[36m|  │                         │ |\033[0m\n");
                    printf("         \033[36m|  │                         │ |\033[0m\n");
                    printf("         \033[36m|  │                         │ |\033[0m\n");
                    printf("         \033[36m|  └─────────────────────────┘ |\033[0m\n");
                    printf("         \033[36m`─────────────────────────────'\033[0m\n");
                    printf("                    \033[36m||||||||||||\033[0m\n");
                    printf("         \033[36m────────────────────────────────\033[0m\n\n");
                    printf("  컴퓨터는 켜지지 않는다...\n");
                    pressEnter_floor3();
                }
                else if (Choice2_floor3 == 2) { //책상을 살펴본다.

                    printf("\n");
                    printf("  책상 위에는 논문 더미와 빈 커피잔뿐이다.\n");
                    pressEnter_floor3();
                }
            }
        }

        if (choice_floor3 == 2) {   //쓰레기통을 살펴본다.

            printf("\n");
            printf("  쓰레기통을 뒤져봤지만... 으음, 건질 건 없는 것 같다.\n");
            pressEnter_floor3();
        }

        if (choice_floor3 == 3) {   //책장을 살펴본다.
            int Choice2_floor3 = -1;
            while (Choice2_floor3 != 0) { //0 == 돌아간다.(함수종료)
                clearScreen_floor3();
                printf("  \033[33m _____________________\033[0m\n");
                printf("  \033[33m |                     \\ \033[0m\n");
                printf("  \033[33m | |=====================|\033[0m\n");
                printf("  \033[33m | | ||| ||| || |||  ||| |\033[0m\n");
                printf("  \033[33m | |=====================|\033[0m\n");
                printf("  \033[33m | | ||| ||| || \033[31m|||\033[33m  ||| |\033[0m\n");
                printf("  \033[33m | |=====================|\033[0m\n");
                printf("  \033[33m | | ||| ||| || |||  ||| |\033[0m\n");
                printf("  \033[33m | |_____________________|\033[0m\n\n");

                printf("  책장을 살펴보니, 한 권만 \033[31m거꾸로\033[0m 되어있다.\n\n");
                printf("  1. 뒤집힌 책을 꺼내 살펴본다\n\n");
                printf("  0. 돌아간다\n\n");
                printf("  선택 >> ");
                scanf("%d", &Choice2_floor3);
                while (getchar() != '\n');

                if (Choice2_floor3 == 1) { //뒤집힌 책을 꺼내 살펴본다.
                    clearScreen_floor3();
                    printf("\n");
                    printf("  책을 꺼내 뒤집어보니 등에 이렇게 적혀 있다:\n\n");
                    printf("  \033[33m  Escape Series ? Part. T\033[0m\n\n");
                    printf("  시리즈 번호... \033[33mT\033[0m.\n");
                    pressEnter_floor3();
                }
            }
        }
    }
}

//3층 - 엘베 코드입력 장
int elevator_floor3() {


    visitedElevator_floor3 = 1; //엘베 방문함

    int choice_floor3; //선택지
    char input_floor3[10]; //코드입력

    while (1) { //코드 입력 실패해도 반복해서 띄움

        clearScreen_floor3();
        printf("\n     \033[36m[ 엘레베이터 ]\033[0m\n\n");
        printf("  엘레베이터 패널에 빨간 경고문이 떠 있다.\n\n");
        printf("  \033[31m  !! 관리자 코드를 입력하세요: [ _ ] [ _ ] [ _ ] [ _ ]  !!\033[0m\n\n");
        printf("  \033[90m  힌트 : 순서는 301호 - 징검다리 - 교수님 연구실 - 화장실\033[0m\n\n");
        printf("        \033[33m+---------------------+\033[0m\n");
        printf("        \033[33m|  ELEVATOR  SYSTEM   |\033[0m\n");
        printf("        \033[33m|---------------------|\033[0m\n");
        printf("        \033[33m|   관리자 코드 입력  |\033[0m\n");
        printf("        \033[33m|                     |\033[0m\n");
        printf("        \033[33m|  [  ] [  ] [  ] [  ]|\033[0m\n");
        printf("        \033[33m|                     |\033[0m\n");
        printf("        \033[33m+---------------------+\033[0m\n\n");
        printf("  1. 관리자 코드를 입력한다.\n\n");
        printf("  0. 돌아간다.\n\n");
        printf("  선택 >> ");
        scanf("%d", &choice_floor3);
        while (getchar() != '\n');

        if (choice_floor3 == 0) { //뒤로가기(함수종료)
            return 0;
        }

        if (choice_floor3 != 1) {
            continue;
        }

        printf("\n");
        printf("  코드를 입력하세요 >> ");
        scanf("%9s", input_floor3);
        while (getchar() != '\n');

        char answer_floor3[] = "96CT";  //정답 코드
        int correct_floor3 = 1; //정답이 맞는지 여부

        if (strlen(input_floor3) != 4) { //코드가 4글자가 아니면 오답처리
            correct_floor3 = 0;
        }
        else {  //소문자를 대문자로 변환,코드가 하나라도 다르면 오답처리
            for (int i_floor3 = 0; i_floor3 < 4; i_floor3++) {
                char a_floor3 = input_floor3[i_floor3];
                if (a_floor3 >= 'a' && a_floor3 <= 'z')
                    a_floor3 -= 32;
                if (a_floor3 != answer_floor3[i_floor3]) {
                    correct_floor3 = 0;
                    break;
                }
            }
        }

        if (correct_floor3) { //정답일 때 성공 메시지 출력
            floor_change = 2;
            clearScreen_floor3();
            printf("\033[32m\n\n");
            printf("     +-----------------------------------------+\n");
            printf("     |                                         |\n");
            printf("     |       코드 [ 9 - 6 - C - T ] 일치!      |\n");
            printf("     |                                         |\n");
            printf("     |  \033[0m    엘레베이터가 작동을 시작한다...   \033[32m |\n");
            printf("     |                                         |\n");
            printf("     |  \033[0m    2층 외의 버튼은 눌리지 않는다.   \033[32m  |\n");
            printf("     |                                         |\n");
            printf("     |                                         |\n");
            printf("     |         v  2층으로 이동합니다  v        |\n");
            printf("     +-----------------------------------------+\n");
            printf("\033[0m\n\n");

            fflush(stdout);
            sleep(5); //5초 대기

            return 1; //함수 반환
        }
        else { //오답일 때 오답 메시지 출력
            printf("\n  \033[31m틀린 것 같다.. \033[0m 엘레베이터가 반응하지 않는다.\n");
            pressEnter_floor3();
        }
    }
}

//3층 - 맵 크기 정의
#define ROWS 19
#define COLS 21

//3층 - 맵 출력 함수
int map_floor3[19][21] = {
   { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,1,1,1,1 },
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
   { 1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,0,0,0,8 },
   { 0,0,0,1,0,0,1,1,0,0,1,1,1,1,1,1,1,0,0,0,9 },
   { 0,0,0,1,4,5,1,1,0,0,1,1,1,1,1,1,1,0,0,0,10 },
   { 0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,0,0,0,11 },
   { 0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,0,0,0,1 },
   { 0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,0,0,0,1 },
   { 1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,0,1 },
   { 6,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,1 },
   { 7,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,1 },
   { 1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,0,1 },
   { 0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,0,0,0,12 },
   { 0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,13 },
   { 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14 },
   { 0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
   { 0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};

//3층 - 플레이어 위치를 받아서 맵을 출력
void printmap_floor3(int playerRow_floor3, int playerCol_floor3) {

    const char* sym_floor3[] = {
        "  ",
        "\033[48;2;169;169;169m  \033[0m",   // 회색 벽
        "\033[31m문\033[0m",                 // 첫번째 문 - 빨강
        "\033[32m문\033[0m",                 // 두번째 문 - 초록
        "\033[92m계\033[0m",                 // 계단 - 밝은 초록
        "\033[92m단\033[0m",
        "\033[91m엘\033[0m",                 // 엘베 - 밝은 빨강
        "\033[91m베\033[0m",
        "\033[38;5;208m징\033[0m",           // 징검다리 - 주황
        "\033[38;5;208m검\033[0m",
        "\033[38;5;208m다\033[0m",
        "\033[38;5;208m리\033[0m",
        "\033[33m화\033[0m",                 // 화장실 - 노랑
        "\033[33m장\033[0m",
        "\033[33m실\033[0m",

    };

    printf("\033[2J\033[1;1f"); //커서 이동

    printf("\n");
    printf("  \033[33m--- 3층 복도 ---\033[0m  WASD: 이동 | E: 상호작용\n\n"); //조작법 안내

    for (int r_floor3 = 0; r_floor3 < ROWS; r_floor3++) {

        printf("  ");

        for (int c_floor3 = 0; c_floor3 < COLS; c_floor3++) {

            if (r_floor3 == playerRow_floor3 && c_floor3 == playerCol_floor3)
                printf("옷"); //플레이어 위치에 출력
            else
                printf("%s", sym_floor3[map_floor3[r_floor3][c_floor3]]); //아니면 값에 맞는 심볼 출력

        }

        printf("\n");
    }

    printf("\n");
}

//3층 - 시작
void floor3() {
    clearScreen_floor3();
    printf("\033[33m\n\n");
    printf("     +====================================+\n");
    printf("     |           3 F L O O R              |\n");
    printf("     |      상명대학교 제1공학관 3층      |\n");
    printf("     +====================================+\n");
    printf("\033[0m\n\n");
    printf("           4층에서 계단을 내려왔다.\n\n");
    printf("      하지만 아래로 가는 계단이 \033[31m막혀 있다!\033[0m\n\n");
    printf("           엘레베이터를 확인해볼까?\n\n");
    pressEnter_floor3();
    int row = 5;
    int col = 4;    //플레이어 시작 좌표
    char dir; //입력 방향
    int running_floor3 = 1; //게임 실행 상태

    while (running_floor3) {
        printmap_floor3(row, col);
        printf("  방향(WASD) 또는 E(상호작용) >> ");
        scanf(" %c", &dir);

        while (getchar() != '\n');
        int nr_floor3 = row;
        int nc_floor3 = col;    //입력방향에 따라 좌표 계산 -> 이동

        if (dir == 'w' || dir == 'W')
            nr_floor3--;
        else if (dir == 's' || dir == 'S')
            nr_floor3++;
        else if (dir == 'a' || dir == 'A')
            nc_floor3--;
        else if (dir == 'd' || dir == 'D') //wasd 입력시 이동
            nc_floor3++;
        else if (dir == 'e' || dir == 'E') { //e 입력시 상호작용
            int cell_floor3 = map_floor3[row][col]; //현재 위치
            int adj_floor3[4][2] = { //또는 인접한 4칸 확인.
                {row - 1, col},
                {row + 1, col},
                {row, col - 1},
                {row, col + 1}
            };

            for (int i_floor3 = 0; i_floor3 < 4; i_floor3++) {
                int ar_floor3 = adj_floor3[i_floor3][0];
                int ac_floor3 = adj_floor3[i_floor3][1];
                if (ar_floor3 >= 0 && ar_floor3 < ROWS && ac_floor3 >= 0 && ac_floor3 < COLS) {
                    if (map_floor3[ar_floor3][ac_floor3] >= 2 && map_floor3[ar_floor3][ac_floor3] <= 20) //값이 2~20이면 상호작용 가능한 오브젝트
                        cell_floor3 = map_floor3[ar_floor3][ac_floor3];
                }
            }

            switch (cell_floor3) {
            case 2: puzzle_301_floor3(); break; //301호 퍼즐
            case 3: puzzle_lab_floor3(); break; //교수님연구실 퍼즐
            case 4: case 5: //계단
                printf("\n  아래로 가는 계단은 막혀 있다. 엘레베이터를 타야 한다.\n");
                pressEnter_floor3();
                break;
            case 6: case 7: //엘베 -> 성공 시 루프 종료
                if (elevator_floor3())
                    running_floor3 = 0;
                break;
            case 8: case 9: case 10: case 11: //징검다리 퍼즐
                puzzle_locker_floor3();
                break;
            case 12: case 13: case 14:  //화장실 퍼즐
                puzzle_toilet_floor3();
                break;
            default: //그 외
                printf("  주변에 상호작용 할 것이 없다.\n");
            }
            continue;
        }

        if (nr_floor3 >= 0 && nr_floor3 < ROWS && nc_floor3 >= 0 && nc_floor3 < COLS) { //벽에서는 이동 X
            int t_floor3 = map_floor3[nr_floor3][nc_floor3];

            if (t_floor3 == 0) {
                row = nr_floor3;
                col = nc_floor3;
            }
        }
    }
}

//2층 - 
int vision_floor2 = 2;

//2층 - 
int map1_floor2[19][21] = {
   { 1,2,1,1,1,2,1,2,1,1,2,1,1,1,2,1,1,2,1,2,1 },
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
   { 1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,0,0,0,1 },
   { 0,0,0,1,0,0,1,1,0,0,1,0,0,0,1,7,1,0,0,0,2 },
   { 0,0,0,1,3,4,1,1,0,0,1,0,1,0,1,0,1,0,0,0,1 },
   { 0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,0,0,1 },
   { 0,0,0,0,0,0,0,1,0,0,1,0,1,1,1,0,1,0,0,0,1 },
   { 0,0,0,0,0,0,0,1,0,0,1,0,1,0,1,0,1,0,0,0,1 },
   { 1,1,1,1,1,1,1,1,0,0,1,0,1,0,1,1,1,0,0,0,1 },
   { 5,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1 },
   { 6,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,1 },
   { 1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,1,0,0,0,1 },
   { 0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,0,1,0,0,0,1 },
   { 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1 },
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
   { 1,1,1,1,1,2,1,1,2,1,1,2,1,1,1,2,1,1,2,1,1 }
};

//2층 - 
char motga_floor2[7][128] = {
   {"  ┏┓     "},
   {"  ┣┫     "},
   {"  ???? ∧    ∧  ??"},
   {"  ┃┏━┫(´?ω ' ?)  ??"},
   {"  ┃┃?┫/    ⌒?"},
   {"  ┃┣┻┫人＿__つ_つ(_()?:?*??"},
   {"  ?━━?"}
};
char flashlight_floor2[8][64] = {
   {"    \\  |  /   "},
   {"     \\ | /    "},
   {"      \\|/     "},
   {"   .------.   "},
   {" .-|======|   "},
   {" | |======|   "},
   {" '-'------'   "},
   {"     ||||     "}
};

//2층 - 
void printMap_floor2(int map_floor2[19][21], int playerRow_floor2, int playerCol_floor2) {
    char symbol_floor2[10][1024] = {
       "  ",
       "\033[48;2;169;169;169m  \033[0m",
       "\033[38;5;94m문\033[0m",
       "\033[38;5;94m계\033[0m",
       "\033[38;5;94m단\033[0m",
       "\033[38;5;94m엘\033[0m",
       "\033[38;5;94m베\033[0m",
       "\033[33m* \033[0m"
    };

    printf("\033[2J\033[1;1f");
    for (int row_floor2 = 0; row_floor2 < 19; row_floor2++) {
        for (int column_floor2 = 0; column_floor2 < 21; column_floor2++) {
            int rowGap_floor2 = row_floor2 - playerRow_floor2;
            int colGap_floor2 = column_floor2 - playerCol_floor2;
            if (rowGap_floor2 < 0) rowGap_floor2 = -rowGap_floor2;
            if (colGap_floor2 < 0) colGap_floor2 = -colGap_floor2;
            if (rowGap_floor2 + colGap_floor2 <= vision_floor2)
                printf("%s", symbol_floor2[map_floor2[row_floor2][column_floor2]]);
            else
                printf("  ");
        }
        printf("\n");
    }
}

//2층 - 
void printPlayer_floor2(int row_floor2, int column_floor2) {
    printf("\033[%d;%df옷", row_floor2 + 1, column_floor2 * 2 + 1);
}

//2층 - 
void rendering_floor2(int map_floor2[19][21], int row_floor2, int column_floor2) {
    printMap_floor2(map_floor2, row_floor2, column_floor2);
    printPlayer_floor2(row_floor2, column_floor2);
}

//2층 - 
void back_floor2(char direction_floor2, int* row_floor2, int* column_floor2) {
    if ((direction_floor2 == 'w') || (direction_floor2 == 'W')) (*row_floor2)++;
    else if ((direction_floor2 == 's') || (direction_floor2 == 'S')) (*row_floor2)--;
    else if ((direction_floor2 == 'a') || (direction_floor2 == 'A')) (*column_floor2)++;
    else if ((direction_floor2 == 'd') || (direction_floor2 == 'D')) (*column_floor2)--;
}

//2층 - 
void M_floor2(int line_floor2, const char* msg_floor2) {
    printf("\033[%d;1f%s", line_floor2, msg_floor2);
    fflush(stdout);
    sleep(2);
    printf("\033[%d;1f\033[2K", line_floor2);
    fflush(stdout);
}

//2층 - 
void move_floor2(char direction_floor2, int* row_floor2, int* column_floor2, int map_floor2[19][21]) {
    if (((direction_floor2 == 'w') || (direction_floor2 == 'W')) && (0 < *row_floor2) && (map_floor2[*row_floor2 - 1][*column_floor2] != 1))
        (*row_floor2)--;
    else if (((direction_floor2 == 'a') || (direction_floor2 == 'A')) && (0 < *column_floor2) && (map_floor2[*row_floor2][*column_floor2 - 1] != 1))
        (*column_floor2)--;
    else if (((direction_floor2 == 's') || (direction_floor2 == 'S')) && (*row_floor2 < 18) && (map_floor2[*row_floor2 + 1][*column_floor2] != 1))
        (*row_floor2)++;
    else if (((direction_floor2 == 'd') || (direction_floor2 == 'D')) && (*column_floor2 < 20) && (map_floor2[*row_floor2][*column_floor2 + 1] != 1))
        (*column_floor2)++;
}

//2층 - 
void motgaevent_floor2(char direction_floor2, int* row_floor2, int* column_floor2) {
    for (int i_floor2 = 0; i_floor2 < 7; i_floor2++)
        printf("\033[%d;25f%s", i_floor2 + 7, motga_floor2[i_floor2]);
    printf("\033[22;1f어두워서 못가겠어.. 손전등좀 찾아줘.. 이 층 어딘가에 있어 찾아줄때 까지 못지나가!");
    printf("\033[%d;%df옷", *row_floor2 + 1, *column_floor2 * 2 + 1);
    fflush(stdout);
    back_floor2(direction_floor2, row_floor2, column_floor2);
}

//2층 - 
void flEvent_floor2(int map_floor2[19][21], int* row_floor2, int* column_floor2, int* hasFlashlight_floor2) {
    printf("\033[2J\033[1;1f");
    for (int i_floor2 = 0; i_floor2 < 3; i_floor2++)
        printf("\033[%d;28f\033[33m%s\033[0m\n", i_floor2 + 6, flashlight_floor2[i_floor2]);
    for (int i_floor2 = 3; i_floor2 < 8; i_floor2++)
        printf("\033[%d;28f\033[37m%s\033[0m\n", i_floor2 + 6, flashlight_floor2[i_floor2]);
    printf("\033[22;1f손전등을 획득했습니다!");
    fflush(stdout);
    sleep(2);
    map_floor2[*row_floor2][*column_floor2] = 0;
    *hasFlashlight_floor2 = 1;

    vision_floor2 = 8;
    rendering_floor2(map_floor2, *row_floor2, *column_floor2);
}

//2층 - 
void startprint_floor2() {
    printf("\033[2J\033[1;1f");
    printf("\033[9;6f\033[31m정전됐습니다. 맵이 어두워집니다.\033[0m");
    fflush(stdout);
    sleep(2);
    printf("\033[9;6f\033[2K");
    fflush(stdout);
}

//1층 - 맵 정의
#define EMPTY 0
#define WALL 1
#define ATTACK 2
#define MONSTER 3
#define CURE 4

//1층 - 엔터 입력 받기 함수
void enter() {
    printf("\n[Enter를 누르면 계속 진행합니다]");
    while (getchar() != '\n');
    getchar();
}

// 1층 - 슈팅게임 화면 그리기
void shooting_floor1(int shootingmap[9][17], int player_row, int player_column) {
    char symbol[5][1024] = { "  ", "\033[48;2;169;169;169m  \033[0m", "\033[31m !\033[0m", "\033[34m모\033[0m", "\033[31m +\033[0m" };

    for (int row = 0; row < 9; row++) {
        for (int column = 0; column < 17; column++) {
            if (row == player_row && column == player_column) {
                printf("옷");
            }
            else {
                printf("%s", symbol[shootingmap[row][column]]);
            }
        }
        printf("\n");
    }
}

// 1층 - 슈팅게임 캐릭터 이동
void shootingcharacter_floor1(char direction, int* row, int* column, int shootingmap[9][17]) {
    if (((direction == 'w') || (direction == 'W')) && (0 < *row) && (shootingmap[*row - 1][*column] != 1))
        (*row)--;
    else if (((direction == 'a') || (direction == 'A')) && (0 < *column) && (shootingmap[*row][*column - 1] != 1))
        (*column)--;
    else if (((direction == 's') || (direction == 'S')) && (*row < 8) && (shootingmap[*row + 1][*column] != 1))
        (*row)++;
    else if (((direction == 'd') || (direction == 'D')) && (*column < 16) && (shootingmap[*row][*column + 1] != 1))
        (*column)++;
}

//1층 - 슈팅게임
int shoot(int bat) {

    int shootingmap[9][17] = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    int row = 7, column = 7;
    char direction = 'w';
    srand(time(NULL));

    //문을 부숴서 열었을 경우 HP 20, 문을 카드키로 열었을 경우 HP 50
    int HP = 50;
    int A_HP = 100;
    int heart = 3;
    int rx, ry;

    printf("\033[2J\033[1;1f");
    printf("=====================================\n\n");
    printf("           <슈팅 게임 규칙>          \n\n");
    printf(" '!'와 닿으면 A의 체력이 20 깎입니다.\n\n");
    printf(" '모'와 닿으면 체력이 10 깎입니다.   \n\n");
    printf(" '+'와 닿으면 체력이 5 오릅니다.     \n\n ");
    printf("=====================================\n\n");
    enter();

    if (bat == 1) {
        printf("================================================================\n\n");
        printf("\n앗! 문을 부수다 다쳤는지 손에서 피가 납니다. 체력이 깎입니다.\n\n");
        printf("================================================================\n\n");
        HP -= 20;
        enter();
    }





    while (HP > 0 && A_HP > 0) {
        printf("\033[2J\033[1;1f");

        shooting_floor1(shootingmap, row, column);
        printf("\n=============================\n A의 체력: %d | 나의 체력: %d\n=============================\n", A_HP, HP);

        printf("방향키(WASD) 입력: ");
        scanf(" %c", &direction);
        shootingcharacter_floor1(direction, &row, &column, shootingmap);


        for (int r = 1; r < 8; r++) {
            for (int c = 1; c < 16; c++) {
                if (shootingmap[r][c] == MONSTER || shootingmap[r][c] == CURE)
                    shootingmap[r][c] = EMPTY;
            }
        }

        for (int i = 0; i < 3; i++) {
            do {
                rx = rand() % 7 + 1;
                ry = rand() % 15 + 1;
            } while (shootingmap[rx][ry] != EMPTY);
            shootingmap[rx][ry] = MONSTER;
        }

        if (heart >= 3) {
            do {
                rx = rand() % 7 + 1;
                ry = rand() % 15 + 1;
            } while (shootingmap[rx][ry] != EMPTY);
            shootingmap[rx][ry] = ATTACK;
            heart = 0;
        }
        else {
            heart++;
        }

        do {
            rx = rand() % 7 + 1;
            ry = rand() % 15 + 1;
        } while (shootingmap[rx][ry] != EMPTY);
        shootingmap[rx][ry] = CURE;



        // 5. 충돌 판정
        if (shootingmap[row][column] == MONSTER) {
            printf("아야!\n");
            HP -= 10;
        }
        else if (shootingmap[row][column] == ATTACK) {
            printf("공격!\n");
            A_HP -= 20;
            shootingmap[row][column] = EMPTY;

        }
        else if (shootingmap[row][column] == CURE) {
            printf("체력 회복!\n");
            HP += 5;
        }

        if (A_HP <= 0) {
            A_HP = 0;
            printf("\033[2J\033[1;1f");
            shooting_floor1(shootingmap, row, column);
            printf("\n=============================\n A의 체력: %d | 나의 체력: %d\n=============================\n", A_HP, HP);

            printf("\n===================================================\n");
            printf("A의 체력이 바닥났습니다.\n");
            printf("===================================================\n");
            break;
        }



        // 플레이어 사망
        else if (HP <= 0) {
            printf("\033[2J\033[1;1f");
            printf("===================================================\n\n");
            printf("체력이 바닥났습니다.\n\n");
            printf("===================================================\n");
            printf("");

            enter();

            printf("\033[2J\033[1;1f");
            printf("===================================================\n\n");
            printf("하지만 여기서 포기할 수는 없습니다.\n\n");
            printf("===================================================\n");
            printf("");

            enter();


            shoot(bat);

        }





    }

    enter();

    printf("\033[2J\033[1;1f\n\n");
    printf("          ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ    \n");
    printf("         |                          |   \n");
    printf("         |                          |   \n");
    printf("         |  \033[31mStop deleting files...  \033[37m|   \n");
    printf("         |        (중간고사)        |   \n");
    printf("         |                          |   \n");
    printf("         |                          |   \n");
    printf("         |                          |   \n");
    printf("          ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ    \n");
    printf("                     |  |               \n");
    printf("                     |  |               \n");
    printf("       ㅡㅡㅡㅡㅡㅡㅡ    ㅡㅡㅡㅡㅡㅡㅡ \n\n");
    printf("                     < 게 임 전 공 >    \n\n");
    enter();
    printf("\033[2J\033[1;1f \n\n");
    printf("          ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ    \n");
    printf("         |                          |   \n");
    printf("         |                          |   \n");
    printf("         |    \033[31mrecovering files...   \033[37m|   \n");
    printf("         |        (중간고사)        |   \n");
    printf("         |                          |   \n");
    printf("         |                          |   \n");
    printf("         |                          |   \n");
    printf("          ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ    \n");
    printf("                     |  |               \n");
    printf("                     |  |               \n");
    printf("       ㅡㅡㅡㅡㅡㅡㅡ    ㅡㅡㅡㅡㅡㅡㅡ \n\n");
    printf("                     < 게 임 전 공 >    \n\n");
    enter();
    printf("\033[2J\033[1;1f \n\n");
    printf("          ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ    \n");
    printf("         |                          |   \n");
    printf("         |                          |   \n");
    printf("         |         \033[31mcomplete!        \033[37m|   \n");
    printf("         |        (중간고사)        |   \n");
    printf("         |                          |   \n");
    printf("         |                          |   \n");
    printf("         |                          |   \n");
    printf("          ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ    \n");
    printf("                     |  |               \n");
    printf("                     |  |               \n");
    printf("       ㅡㅡㅡㅡㅡㅡㅡ    ㅡㅡㅡㅡㅡㅡㅡ \n\n");
    printf("                     < 게 임 전 공 >    \n\n");

    enter();
    printf("\033[2J\033[1;1f \n\n");
    printf("===================================================\n\n");
    printf(" 정문이 열리자 경비원분께서 다급히 달려오셨다.     \n");
    printf(" 나는 더 늦기 전에 막차를 타고 집으로 갈 수 있었고,\n");
    printf(" 그날 이후로 다시는 그 친구를 만날 수 없었다.      \n\n");
    printf("===================================================\n");
    enter();

    printf("\033[2J\033[1;1f");
    printf("=========================================================================\n");
    printf("  ______  ______  ______   ______  ______  ______ \n");
    printf(" |  ____|/  ____|/  ____| /  __  \\|  ___ \\|  ____|\n");
    printf(" | |__   | (___  | |     /  /__\\  \\ |___) | |__   \n");
    printf(" |  __|   \\___ \\ | |    |  ____  ||  ____/|  __|  \n");
    printf(" | |____ _____) || |____| |    | || |     | |____ \n");
    printf(" |______|______/  \\______|_|    |_|_|     |______|\n\n");
    printf("  ______  _     _  ______  ______  ______  ______  ______   _ \n");
    printf(" /  ____|| |   | |/  ____|/  ____||  ____|/  ____|/  ____| | |\n");
    printf(" | (___  | |   | || |     | |     | |__   | (___  | (___   | |\n");
    printf("  \\___ \\ | |   | || |     | |     |  __|   \\___ \\  \\___ \\  | |\n");
    printf(" _____) || |___| || |____ | |____ | |____ _____) |_____) | |_|\n");
    printf(" |______/ \\_____/  \\______|______||______|______/|______/  (_)\n");
    printf("=========================================================================\n");
    printf("                        CONGRATULATIONS !!!                      \n");
    printf("=========================================================================\n");

    exit(0);

}

//1층 - 중앙맵 
void printMap_floor1(int map1[9][9], int player_row, int player_column) {
    char symbol[30][1024] = { "  ", "\033[48;2;169;169;169m  \033[0m", "\033[34m >\033[0m", "\033[34m< \033[0m" };
    printf("\033[2J\033[1;1f");
    for (int row = 0; row < 9; row++) {
        for (int column = 0; column < 9; column++) {

            if (row == player_row && column == player_column) {
                printf("옷");
            }
            else {
                printf("%s", symbol[map1[row][column]]);
            }
        }
        printf("\n");
    }
}

//1층 - 중앙맵 이동
void move_floor1(char direction, int* row, int* column, int map1[9][9]) {
    if (((direction == 'w') || (direction == 'W')) && (0 < *row) && (map1[*row - 1][*column] != 1))
        (*row)--;
    else if (((direction == 'a') || (direction == 'A')) && (0 < *column) && (map1[*row][*column - 1] != 1))
        (*column)--;
    else if (((direction == 's') || (direction == 'S')) && (*row < 8) && (map1[*row + 1][*column] != 1))
        (*row)++;
    else if (((direction == 'd') || (direction == 'D')) && (*column < 8) && (map1[*row][*column + 1] != 1))
        (*column)++;
}

//1층 - 로비맵
void lobby_floor1(int map_lobby[7][9], int player_row, int player_column) {
    char symbol[20][1024] = { "  ", "\033[48;2;169;169;169m  \033[0m", "\033[34m문\033[0m", "\033[34m못\033[0m" };
    printf("\033[2J\033[1;1f");
    for (int row = 0; row < 7; row++) {
        for (int column = 0; column < 9; column++) {

            if (row == player_row && column == player_column) {
                printf("옷");
            }
            else {
                printf("%s", symbol[map_lobby[row][column]]);
            }
        }
        printf("\n");
    }
}

//1층 - 로비 이동
void lobbymove_floor1(char direction, int* row, int* column, int map[7][9]) {
    if (((direction == 'w') || (direction == 'W')) && (0 < *row) && (map[*row - 1][*column] != 1))
        (*row)--;
    else if (((direction == 'a') || (direction == 'A')) && (0 < *column) && (map[*row][*column - 1] != 1))
        (*column)--;
    else if (((direction == 's') || (direction == 'S')) && (*row < 6) && (map[*row + 1][*column] != 1))
        (*row)++;
    else if (((direction == 'd') || (direction == 'D')) && (*column < 8) && (map[*row][*column + 1] != 1))
        (*column)++;
}

//1층 - 과사무실
void office_floor1(int map_office[10][15], int player_row, int player_column) {
    char symbol[30][1024] = { "  ", "\033[48;2;169;169;169m  \033[0m", "\033[34m모\033[0m", "\033[34m>\033[0m", "\033[34m홋\033[0m" };
    printf("\033[2J\033[1;1f");
    for (int row = 0; row < 10; row++) {
        for (int column = 0; column < 15; column++) {

            if (row == player_row && column == player_column) {
                printf("옷");
            }
            else {
                printf("%s", symbol[map_office[row][column]]);
            }
        }
        printf("\n");
    }
}

//1층 - 과사무실 이동
void officemove_floor1(char direction, int* row, int* column, int map[10][15]) {
    if (((direction == 'w') || (direction == 'W')) && (0 < *row) && (map[*row - 1][*column] != 1))
        (*row)--;
    else if (((direction == 'a') || (direction == 'A')) && (0 < *column) && (map[*row][*column - 1] != 1))
        (*column)--;
    else if (((direction == 's') || (direction == 'S')) && (*row < 9) && (map[*row + 1][*column] != 1))
        (*row)++;
    else if (((direction == 'd') || (direction == 'D')) && (*column < 14) && (map[*row][*column + 1] != 1))
        (*column)++;
}

//게임 시작
int main() {
    game_start();
    while (1) {
        switch (floor_change) {
        case 4: {
            start_floor4();
            break;
        }
        case 3: {
            floor3();
            break;
        }
        case 2: {
            int row_floor2 = 12, column_floor2 = 1;
            int hasFlashlight_floor2 = 0;
            startprint_floor2();
            rendering_floor2(map1_floor2, row_floor2, column_floor2);
            for (char direction_floor2 = 'w';
                (direction_floor2 == 'W') || (direction_floor2 == 'A') || (direction_floor2 == 'S') || (direction_floor2 == 'D')
                || (direction_floor2 == 'w') || (direction_floor2 == 'a') || (direction_floor2 == 's') || (direction_floor2 == 'd'); ) {
                move_floor2(direction_floor2, &row_floor2, &column_floor2, map1_floor2);
                rendering_floor2(map1_floor2, row_floor2, column_floor2);
                if (map1_floor2[row_floor2][column_floor2] == 2)
                    M_floor2(22, "문이 잠겨있다.");
                if ((map1_floor2[row_floor2][column_floor2] == 5) || (map1_floor2[row_floor2][column_floor2] == 6)) {
                    M_floor2(22, "엘리베이터가 작동하지 않는다.");
                    back_floor2(direction_floor2, &row_floor2, &column_floor2);
                    rendering_floor2(map1_floor2, row_floor2, column_floor2);
                }
                if ((map1_floor2[row_floor2][column_floor2] == 3) || (map1_floor2[row_floor2][column_floor2] == 4)) {
                    if (hasFlashlight_floor2 == 0)
                        motgaevent_floor2(direction_floor2, &row_floor2, &column_floor2);
                    else if (hasFlashlight_floor2 == 1) {
                        floor_change = 1;
                        break;
                    }
                }
                if (map1_floor2[row_floor2][column_floor2] == 7)
                    flEvent_floor2(map1_floor2, &row_floor2, &column_floor2, &hasFlashlight_floor2);

                if ((map1_floor2[row_floor2][column_floor2] == 3) || (map1_floor2[row_floor2][column_floor2] == 4)) {
                    if (hasFlashlight_floor2 == 1)
                        floor_change = 1;
                    break;
                }

                printf("\033[21;1f\033[2K방향키(WASD)를 입력하세요: ");
                scanf(" %c", &direction_floor2);
            }
            break;
        }
        case 1: {
            int map1[9][9] = {
            {1,1,1,1,1,1,1,1,1},
            {1,0,0,0,0,0,0,0,1},
            {3,0,0,0,0,0,0,0,2},
            {1,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,1},
            {1,1,1,1,1,1,1,1,1}
            };

            int map_lobby[7][9] = {
                { 1,1,1,1,1,1,1,1,1 },
                { 2,0,0,0,0,0,0,0,1 },
                { 1,0,0,0,0,0,0,0,1 },
                { 1,0,0,0,0,0,0,3,1 },
                { 1,0,0,0,0,0,0,0,1 },
                { 1,0,0,0,0,0,0,0,1 },
                { 1,1,1,1,1,1,1,1,1 }
            };

            int map_office[10][15] = {
                { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
                { 1,0,2,0,1,0,2,0,1,0,0,0,0,0,3 },
                { 1,0,4,0,1,0,0,0,1,0,0,0,0,0,1 },
                { 1,1,0,1,1,1,0,1,1,0,0,0,0,0,1 },
                { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
                { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
                { 1,1,0,1,1,1,0,1,1,0,0,0,0,0,1 },
                { 1,0,0,0,1,0,0,0,1,0,0,0,0,0,1 },
                { 1,0,2,0,1,0,2,0,1,0,0,0,0,0,1 },
                { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
            };


            int row = 1, column = 3;
            char direction = 'w';
            int stage = 0;
            char talk_menu;
            int password = 0;
            int office = 0;
            int lobby = 0;
            int lobby2 = 0;
            int bat = 0;
            int skip = 0;

            printMap_floor1(map1, row, column);

            while (1) {

                if ((direction == 'W') || (direction == 'A') || (direction == 'S') || (direction == 'D') ||
                    (direction == 'w') || (direction == 'a') || (direction == 's') || (direction == 'd')) {

                    if (stage == 0) {
                        move_floor1(direction, &row, &column, map1);

                        if (map1[row][column] == 2) {
                            stage = 1;
                            row = 1;
                            column = 1;
                        }

                        else if (map1[row][column] == 3) {
                            if (skip > 0) {
                                stage = 2;
                                row = 1;
                                column = 14;
                            }

                            else {
                                printf("\033[2J\033[1;1f");
                                printf("\033[37m                  ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ  \n");
                                printf("\033[37m                 ㅣ                     ㅣ\n");
                                printf("\033[37m                 ㅣ                     ㅣ\n");
                                printf("\033[37m                 ㅣ         ㅡㅡ        ㅣ\n");
                                printf("\033[37m                 ㅣ        ㅣ  ㅣ       ㅣ\n");
                                printf("\033[31m   ㅡㅡㅡㅡㅡㅡ  \033[37mㅣ        ㅣ  ㅣ       ㅣ\n");
                                printf("\033[31m  ㅣ password ㅣ \033[37mㅣ        ㅣ  ㅣ       ㅣ\n");
                                printf("\033[31m  ㅣ          ㅣ \033[37mㅣ        ㅣ  ㅣ       ㅣ\n");
                                printf("\033[31m  ㅣ          ㅣ \033[37mㅣ         ㅡㅡ        ㅣ\n");
                                printf("\033[31m  ㅣ          ㅣ \033[37mㅣ                  ㅇ ㅣ\n");
                                printf("\033[31m   ㅡㅡㅡㅡㅡㅡ  \033[37mㅣ                     ㅣ\n");
                                printf("\033[37m                 ㅣ                     ㅣ\n");
                                printf("\033[37m                 ㅣ                     ㅣ\n");
                                printf("\033[37m                 ㅣ                     ㅣ\n");
                                printf("\033[37m                 ㅣ                     ㅣ\n");
                                printf("\033[37m                 ㅣ                     ㅣ\n");
                                printf("\033[37m                 ㅣ                     ㅣ\n");
                                printf("=====================================================\n");
                                printf("|                      잠겨있다.                     |\n");
                                printf("=====================================================\n\n");
                                printf("1. 부순다.\n");
                                printf("2. 비밀번호를 입력한다.\n");
                                scanf("%d", &office);

                                if (office == 1) {
                                    printf("\033[2J\033[1;1f");

                                    if (bat == 1) {
                                        skip++;
                                        printf("부수자!");
                                        printf("\033[2J\033[1;1f");
                                        printf("\033[37m                  ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ  \n");
                                        printf("\033[37m                 ㅣ                     ㅣ\n");
                                        printf("\033[37m                 ㅣ                     ㅣ\n");
                                        printf("\033[37m                 ㅣ         ㅡㅡ        ㅣ\n");
                                        printf("\033[37m                 ㅣ        ㅣ  ㅣ  ㅡㅡㅡ \n");
                                        printf("\033[31m   ㅡㅡㅡㅡㅡㅡ  \033[37mㅣ       /             \n");
                                        printf("\033[31m  ㅣ password ㅣ \033[37mㅣ   /ㅡ               \n");
                                        printf("\033[31m  ㅣ          ㅣ \033[37mㅣ  /                  \n");
                                        printf("\033[31m  ㅣ          ㅣ \033[37mㅣ /                   \n");
                                        printf("\033[31m  ㅣ          ㅣ \033[37mㅣ/                    \n");
                                        printf("\033[31m   ㅡㅡㅡㅡㅡㅡ  \033[37m /                     \n");
                                        printf("\033[37m                 ㅣ   ㅡ /               ㅣ\n");
                                        printf("\033[37m                 ㅣ      |               ㅣ\n");
                                        printf("\033[37m                 ㅣ       |              ㅣ\n");
                                        printf("\033[37m                 ㅣ        ㅡㅡ          ㅣ\n");
                                        printf("\033[37m                 ㅣ            |         ㅣ\n");
                                        printf("\033[37m                 ㅣ             |ㅡㅡㅡㅡㅣ\n");
                                        enter();
                                        stage = 2;
                                        row = 1;
                                        column = 14;
                                    }

                                    else if (bat == 0) {
                                        printf("=====================================\n\n");
                                        printf(" 도구가 필요할 것 같다. \n\n");
                                        printf("=====================================\n\n");
                                        enter();
                                        row = 2; column = 1;
                                    }
                                }

                                else if (office == 2) {
                                    printf("\033[2J\033[1;1f");
                                    printf("=====================================\n\n");
                                    printf("              ㅡㅡㅡㅡㅡㅡ  \n");
                                    printf("             ㅣ password ㅣ \n");
                                    printf("             ㅣ          ㅣ \n");
                                    printf("             ㅣ          ㅣ \n");
                                    printf("             ㅣ 1  2  3  ㅣ \n");
                                    printf("             ㅣ          ㅣ \n");
                                    printf("             ㅣ 4  5  6  ㅣ \n");
                                    printf("             ㅣ          ㅣ \n");
                                    printf("             ㅣ 7  8  9  ㅣ \n");
                                    printf("             ㅣ          ㅣ \n");
                                    printf("              ㅡㅡㅡㅡㅡㅡ  \n");
                                    printf("=====================================\n\n");
                                    printf("비밀번호를 입력하세요. ");
                                    scanf("%d", &password);

                                    if (password == 5114) {
                                        printf("\033[2J\033[1;1f");
                                        printf("=====================================\n\n");
                                        printf("              ㅡㅡㅡㅡㅡㅡ  \n");
                                        printf("             ㅣ password ㅣ \n");
                                        printf("             ㅣ          ㅣ \n");
                                        printf("             ㅣ          ㅣ \n");
                                        printf("             ㅣ          ㅣ \n");
                                        printf("             ㅣ  UNLOCK  ㅣ \n");
                                        printf("             ㅣ          ㅣ \n");
                                        printf("             ㅣ          ㅣ \n");
                                        printf("             ㅣ          ㅣ \n");
                                        printf("             ㅣ          ㅣ \n");
                                        printf("              ㅡㅡㅡㅡㅡㅡ  \n");
                                        printf("=====================================\n\n");
                                        printf("보안이 해제됩니다.");
                                        skip++;
                                        enter();
                                        stage = 2;
                                        row = 1;
                                        column = 14;
                                    }
                                }
                            }
                        }
                    }

                    else if (stage == 1) {
                        lobbymove_floor1(direction, &row, &column, map_lobby);

                        if (map_lobby[row][column] == 3) {
                            printf("\033[2J\033[1;1f");
                            printf("=====================================\n\n");
                            printf(" '이 분은 왜 아직 안 나가신 걸까?'   \n\n");
                            printf("=====================================\n");
                            enter();

                            printf("\033[2J\033[1;1f");
                            printf("=====================================\n\n");
                            printf(" 과사무실 가보셨어요?\n");
                            printf(" 거기서 뭔가... 이상한 일이 벌어지고 있어요.\n");
                            printf(" 저희를 가둔 사람도 아마...\n\n");
                            printf("=====================================\n");
                            printf(" 과사무실을 들렸다면 > 1\n");
                            printf(" 들리지 않았다면 > 2\n선택: ");
                            scanf("%d", &lobby);

                            if (lobby == 1) {
                                printf("\033[2J\033[1;1f");
                                printf("=====================================\n\n");
                                printf("1. 문을 부술 도구에 대해 질문하기    \n");
                                printf("2. 비밀번호에 대해 질문하기          \n\n");
                                printf("=====================================\n");
                                printf("선택: ");
                                scanf("%d", &lobby2);

                                if (lobby2 == 1) {
                                    printf("\033[2J\033[1;1f");
                                    printf("=====================================\n\n");
                                    printf(" 무기요? 아, 야구 동아리가           \n");
                                    printf(" 저기 야구 배트를 두고 갔던데...     \n");
                                    printf(" ... 여기, 이걸 써보세요.            \n\n");
                                    printf("=====================================\n");
                                    printf("야구 배트 획득!");

                                    bat++;
                                    enter();
                                }

                                else if (lobby2 == 2) {
                                    printf("\033[2J\033[1;1f");
                                    printf("=====================================\n\n");
                                    printf(" 아, 저도 자세히는 모르는데          \n");
                                    printf(" 학교 전화번호 맨 뒷자리 4개일 걸요? \n");
                                    printf(" 홈페이지에 있을 거예요.             \n\n");
                                    printf("=====================================\n");
                                    enter();
                                }
                            }
                            row = 4;
                            column = 7;
                        }

                        else if (map_lobby[row][column] == 2) {
                            stage = 0;
                            row = 2;
                            column = 7;
                        }
                    }

                    else if (stage == 2) {
                        officemove_floor1(direction, &row, &column, map_office);

                        if (map_office[row][column] == 4) {
                            printf("\033[2J\033[1;1f");
                            printf("\n");
                            printf("          ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ    \n");
                            printf("         |                          |   \n");
                            printf("         |                          |   \n");
                            printf("         | files are deleting...10% |   \n");
                            printf("         |        (중간고사)        |   \n");
                            printf("         |                          |   \n");
                            printf("         |                          |   \n");
                            printf("         |                          |   \n");
                            printf("          ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ    \n");
                            printf("                     |  |               \n");
                            printf("                     |  |               \n");
                            printf("       ㅡㅡㅡㅡㅡㅡㅡ    ㅡㅡㅡㅡㅡㅡㅡ \n\n");
                            printf("                     < 게 임 전 공 >    \n\n");
                            printf("=============================================\n\n");
                            printf(" 과 동기 A: 안돼! 방해하지마!                \n\n");
                            printf(" 나: 지금 뭐하는 거야? 파일 삭제 중?         \n\n");
                            printf(" A : 이 성적으로 학점이 나와서는 안돼...     \n");
                            printf("     다시 기회를 얻을 수만 있다면          \n");
                            printf("   : 난 무엇이든 할 수 있어.                 \n\n");
                            printf("=============================================\n");
                            enter();
                            shoot(bat);
                            row = 2;
                            column = 3;
                        }

                        if (map_office[row][column] == 3) {
                            stage = 0;
                            row = 1;
                            column = 1;
                        }
                    }

                    if (stage == 0) {
                        printMap_floor1(map1, row, column);
                    }

                    else if (stage == 1) {
                        lobby_floor1(map_lobby, row, column);
                    }

                    else {
                        office_floor1(map_office, row, column);
                    }

                    printf("\033[12;1f\033[2K방향키(WASD)를 입력하세요: ");
                    scanf("\n%c", &direction);
                }

                else {
                    printf("WASD를 눌러주세요!");
                    printf("\033[12;1f\033[2K방향키(WASD)를 입력하세요: ");
                    scanf("\n%c", &direction);
                }
            }
            break;
        }
        }
    }
}
