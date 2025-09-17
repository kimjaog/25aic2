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


void printBomb(int stage, int x, int y) {
    if (stage == 1) {
        gotoxy(x, y - 1);
        printf("^^^^^^");
        gotoxy(x, y);
        printf("!BOOM!");
        gotoxy(x, y + 1);
        printf("^^^^^^");
    }
}

int main() {
    int startX = 6, startY = 6;
    gotoxy(startX, startY);
    printf("( b )");

    int posX = startX + 5, posY = startY;
    int dx, dy;
    double angle = 0.0;
    int length = 6;

   
    while (length > 0) {
        dx = cos(angle * PI / 180.0);
        dy = sin(angle * PI / 180.0);
        int count = 0;
        while (count < length) {
            posX += dx;
            posY += dy;
            gotoxy(posX, posY);
            printf("#");  
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
            printf("#"); 
            count++;
        }
        angle += 90.0;
    }

    
    gotoxy(14, 9);
    printf("*");

    angle -= 180.0;

    
    while (length < 6) {
        angle -= 90.0;
        dx = cos(angle * PI / 180.0);
        dy = sin(angle * PI / 180.0);
        int count = 0;
        while (count < length) {
            Sleep(200);
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
            Sleep(200);
            gotoxy(posX, posY);
            printf(" ");  
            posX += dx;
            posY += dy;
            gotoxy(posX, posY);
            if (length != 6) printf("*"); 
            count++;
        }
    }

  
    printBomb(1, startX, startY);

    gotoxy(0, startY + 10);
    return 0;
}