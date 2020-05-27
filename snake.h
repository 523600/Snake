///////////////////////////////////
///control snake
////////////////////////////////// 
#include "food.h"
#include "monster.h"

class Snake
{
	public:	
		int speed;
		int direction;
		Food food[MAXFOODNUM];
		Monster monster;
		Link* head=NULL;
		Link* tail=NULL;
			
		void init();
		void move(int);
		void show();
		bool IsEat();
		void GameRun(void);
		bool IsDead();
		void addbody(int,int);
		Snake(int s=INIT_SPEED):speed(s){};
};
