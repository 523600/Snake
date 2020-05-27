#include <graphics.h>
#include <iostream>


#define SCR_WIDTH      640
#define SCR_HEIGHT     640
#define N  3

using namespace std;

struct Link
{
	double x;
	double y;
	color_t s_color;
	Link* prev;
	Link* next;
};

struct Position
{
	double x;
	double y;
};

int t=0;
int flag=0;

void Gamerun(void)
{
	initgraph(SCR_WIDTH, SCR_HEIGHT,0);
	setbkcolor(WHITE);

	PlaySound("music.wav", NULL, SND_FILENAME | SND_ASYNC|SND_LOOP|SND_NODEFAULT);
    Snake snake;
    snake.init();
    
    snake.show();
    
}



