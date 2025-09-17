/*
#include <stdio.h>
#include <windows.h>
#include <math.h>

#define PI 3.14159265358979323846

void drawPoint(int x, int y, char ch) {
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    printf("%c", ch);
    fflush(stdout);
}

int main() {
    int cx = 30, cy = 5; // 회오리 사각형 시작 좌표
    int layers = 3;       // 회오리 겹 수
    int i, j;

    // 1. 회오리 사각형 그리기
    char frame[9][12] = {
        "+---------+",
        "|         |",
        "|  +---+  |",
        "|  | - |  |",
        "|  | - |  |",
        "|  +---+  |",
        "|         |",
        "+---------+",
        "           "
    };

    for (i = 0;i < 8;i++)
        for (j = 0;j < 11;j++)
            drawPoint(cx + j, cy + i, frame[i][j]);

    Sleep(500);

    // 2. 심지 좌표를 cos/sin으로 계산
    int totalPoints = 30;
    double startX = cx + 5.0; // 안쪽 중심
    double startY = cy + 3.0;
    double endX = cx + 10.0;  // 바깥쪽
    double endY = cy + 0.0;

    for (i = 0;i < totalPoints;i++) {
        double t = (double)i / totalPoints;
        double x = startX + (endX - startX) * t + cos(t * PI * 4) * 0.5; // 회오리 효과
        double y = startY + (endY - startY) * t + sin(t * PI * 4) * 0.5;

        drawPoint((int)round(x), (int)round(y), ' ');
        Sleep(100);
    }

    // 3. 바깥 사각형 제거
    for (i = 0;i < 8;i++)
        for (j = 0;j < 11;j++)
            drawPoint(cx + j, cy + i, ' ');

    // 4. 폭발 표시
    COORD pos = { (SHORT)(cx - 6),(SHORT)(cy + 4) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    printf("(BooM)");
    fflush(stdout);

    return 0;
}
*/
#include <stdio.h>
#include <math.h>
#include <Windows.h>

#define PI 3.14159265358979323846


void gotoxy(int x, int y) {
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main() {
    int startX = 5, startY = 5;
    gotoxy(startX, startY);
    printf("(Bomb)");

    int posX = startX + 5, posY = startY;
    int dx, dy;
    double angle = 0.0;
    int length = 5;

   
    while (length > 0) {
        dx = cos(angle * PI / 180.0);
        dy = sin(angle * PI / 180.0);
        int count = 0;
        while (count < length) {
            posX += dx;
            posY += dy;
            gotoxy(posX, posY);
            if (count == length - 1) printf("+");
            else printf("-");
            count++;
        }
        angle += 90.0;
        dx = cos(angle * PI / 180.0);
        dy = sin(angle * PI / 180.0);
        count = 0;
        length--;
        while (count < length) {
            posX += dx;
            posY += dy;
            gotoxy(posX, posY);
            if (count == length - 1) printf("+");
            else printf("|");
            count++;
        }
        angle += 90.0;
    }

   
    gotoxy(posX, posY);
    printf("*");

    angle -= 180.0;

 
    while (length < 5) {
        angle -= 90.0;
        dx = cos(angle * PI / 180.0);
        dy = sin(angle * PI / 180.0);
        int count = 0;
        while (count < length) {
            Sleep(100);
            gotoxy(posX, posY);
            printf(" ");
            posX += dx;
            posY += dy;
            gotoxy(posX, posY);
            printf("*");
            count++;
        }
        angle -= 90.0;
        dx = cos(angle * PI / 180.0);
        dy = sin(angle * PI / 180.0);
        length++;
        count = 0;
        while (count < length) {
            Sleep(100);
            gotoxy(posX, posY);
            printf(" ");
            posX += dx;
            posY += dy;
            gotoxy(posX, posY);
            if (length != 5) printf("*");
            count++;
        }
    }

  
    gotoxy(startX, startY - 1);
    printf("^^^^^^");
    gotoxy(startX, startY);
    printf("!BOOM!");
    gotoxy(startX, startY + 1);
    printf("^^^^^^");

    gotoxy(0, startY + 10);
    return 0;
}