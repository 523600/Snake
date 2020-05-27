#include "food.h"

Food Food::finit(int p)
{
	int rx=rand()%400+100;
	int ry=rand()%400+100;
	this->data=p;
	this->pos.x=rx;
	this->pos.y=ry;
	return *this;
}//create a food on a point 

void Food::fshow()
{
	if(data!=0){
		char c=data+'0';
		setcolor(GREEN);
		setfont(12, 0, "??");
		outtextxy(pos.x, pos.y, c);
	}
}//show a food
