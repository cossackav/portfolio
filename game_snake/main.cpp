#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection{STOP=0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

// настройка параметров
void Setup()
{
    gameOver = false;
    dir = STOP;
    x= width/2 - 1;
    y = height/2 - 1;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

// вывод карты
void Draw()
{
    system("cls");
    for(int i = 0; i < width + 1; i++)
        cout << "#";
    cout << endl;

    for(int i=0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(j == 0 or j == width-1){
                cout << "#";
            }
            if(i == y and j == x)
                cout << "0";
            else if(i == fruitY and j == fruitX)
                cout << "F";
            else
                cout << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < width + 1; i++)
        cout << "#";
    cout << endl;
    cout << "Score: " << score << endl;
}
// отслеживание клвиатуры
void Input()
{
    if(_kbhit()){
        switch(_getch()){
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }

    }
}

// логика игры
void Logic()
{
    switch(dir){
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }

    if(x < 0 or x > width or y < 0 or y > height)
        gameOver = true;
    if(x == fruitX and y == fruitY){
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }

}

int main()
{
    Setup();
    while(!gameOver)
    {
        Draw();
        Input();
        Logic();
    }
    return NULL;
}

