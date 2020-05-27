#include "monster.h"

void Monster::minit()
{
	srand((unsigned int)time(NULL));
	double rx=rand()%640;
	double ry=rand()%640;
	pos.x=rx;
	pos.y=ry;
	
}//create a monster

void Monster::mshow()
{
	setfillcolor(EGERGB(0x80, 0x0, 0xFF));
	bar(pos.x-10,pos.y-10,pos.x+10,pos.y+10);
}//show a monster

void Monster::mmove(double a,double b)
{
	setfillcolor(WHITE);
	bar(pos.x-10,pos.y-10,pos.x+10,pos.y+10);
	pos.x+=((a-pos.x)/50);
	pos.y+=((b-pos.y)/50);
	mshow();
}//control the monster
