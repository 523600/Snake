#include "snake.h"
#define SHOW_CONSOLE
int foodnum=9;
int flag=0;
int t=0;
bool Snake::IsDead()// Judge if snake is dead
{
	if(head->x<20||head->y<20||head->x>620||head->y>620)//Whether to hit the wall if it is returned true
	{
		flag=1;
		cleardevice();
		setfont(48, 0, "??");
		setcaption("failed" );
		outtextxy(250, 250, "YOU LOSE!");
		PlaySound("Various Artists - Happy Tree Friends.wav", NULL, SND_FILENAME | SND_ASYNC|SND_LOOP|SND_NODEFAULT);//Happy Tree Friends
		getch();
		return true;
	}else if(abs(monster.pos.y-head->y)<10&&abs(monster.pos.x-head->x)<10){//Whether to encounter monsters if it is returned correctly
		flag=1;
		cleardevice();
		setfont(48, 0, "??");
		setcaption("failed" );
		outtextxy(250, 250, "YOU LOSE!");
		PlaySound("Various Artists - Happy Tree Friends.wav", NULL, SND_FILENAME | SND_ASYNC|SND_LOOP|SND_NODEFAULT);//Happy Tree Friends
		getch();
		return true;
	}else{//return false 
		return false;
	}
}

bool Snake::IsEat()//Judge if snake is eating food
{
	int num;
	for(int j=0;j<9;j++)//Walk through the food array to see if the snake has eaten anything
	{
		if(food[j].data!=0)
		{
			if(abs(food[j].pos.x-head->x)<10&&abs(food[j].pos.y-head->y)<10)
			{
				switch(direction)
				{
					case 1:
						for(num=0;num<food[j].data;num++)
						{
							addbody(head->x,head->y-10);//The snake body growth
						}
						break; 
					case 2:
						for(num=0;num<food[j].data;num++)
						{
							addbody(head->x,head->y+10);//The snake body growth
						}
						break;
					case 3:
						for(num=0;num<food[j].data;num++)
						{
							addbody(head->x-10,head->y);//The snake body growth
						}
						break;
					case 4:
						for(num=0;num<food[j].data;num++)
						{
							addbody(head->x+10,head->y);//The snake body growth
						}
						break;
				}
				speed+=3*food[j].data;//Slow speed	
				food[j].data=0;//Zero the food data
				foodnum--;//Reduce the amount of food by one 
				return true;
			}
		}
	}
	return false;
}

void Snake::addbody(int x_,int y_)//Glue the new head onto the old one 
{
	Link* p=new Link;//Create a new snakehead
	p->x=x_;
	p->y=y_;
	if(head){
		p->next=head;
		head->s_color=BLACK	;
		head->prev=p;
		p->s_color=RED;
		head=p;
	}else {
		head=tail=p;
		head->s_color=BLACK;
	}
	setfillcolor(head->s_color);
	bar(head->x-5,head->y-5,head->x+5,head->y+5);//Draw the new snake head 
}

void Snake::init()
{
	monster.minit();//Create a monster 
		
	int k=1;
	for(int i=0;i<9;i++)
	{
		food[i]=food[i].finit(k);
		k++;
	}
	
	for(int i=0;i<5;i++)
	{
		addbody(100,200-10*i);
	} 
	
	Link* p_color=head->next;
	while(p_color!=tail)
	{
		setfillcolor(BLACK);
		bar(p_color->x-5,p_color->y-5,p_color->x+5,p_color->y+5);
		p_color=p_color->next;
	}//Initializes the snake
	direction=1;
}

void Snake::move(int direction_)
{
	Link* p=(Link*)malloc(sizeof(Link*));
	float x_=head->x;
	float y_=head->y;
	switch(direction_)
	{
		case 1:
			y_-=10;
			break; 
		case 2:
			y_+=10; 
			break;
		case 3:
			x_-= 10;
			break;
		case 4:
			x_ += 10;
			break;
	}
	addbody(x_,y_);//Draw the new snake head 
	p=tail;
	tail=tail->prev;
	if(tail)
		tail->next = NULL;//Move the tail forward one square
	
	Link* p_color=head->next;
	while(p_color!=tail->next)
	{
		setfillcolor(BLACK);
		bar(p_color->x-5,p_color->y-5,p_color->x+5,p_color->y+5);
		p_color=p_color->next;
	} //Draw the black body
	
	setfillcolor(WHITE);
	bar(p->x-5,p->y-5,p->x+5,p->y+5);//Erase the original snake tail
	delete p; 
		                       
}

void Snake::show()
{
	char k;
	while(IsDead()==false )
	{
		t++;
		stringstream ss1,ss2,ss3,ss4;
        ss1 << foodnum;
        string s1 = ss1.str();
        ss2 << t;
        string s2 = ss2.str();
        string s = "Snake - Food:" + s1 + ",Time:" + s2;
        char* pszMultiByte = &s[0];  
		int iSize; 
		wchar_t* pwszUnicode; 
		iSize = MultiByteToWideChar(CP_ACP, 0, pszMultiByte , -1, NULL, 0);
		pwszUnicode = (wchar_t *)malloc(iSize*sizeof(wchar_t)); 
		MultiByteToWideChar(CP_ACP, 0, pszMultiByte , -1, pwszUnicode , iSize);
		setcaption(pwszUnicode );//Show the title
		
		k = getch();//Identify the key

		for(int i=0;i<9;i++)
		{
			food[i].fshow();
		}//Show the food
		monster.mshow();//Show the monster
		switch(k)
		{
			case 'w':
				if(direction == 2)
					continue;
				direction = 1;
				break;
			case 's':
				if(direction== 1)
					continue;
				direction = 2;
				break;
			case 'a':
				if(direction == 4)
					continue;
				direction = 3;
				break;
			case 'd':
				if(direction == 3)
					continue;
				direction= 4;
				break;
		}
		move(direction);
		monster.mmove(head->x,head->y);
		if(IsEat()==true){
			t++;
			continue;
		}
		delay(speed);
		if(foodnum==0){
			setcaption("YOU WIN");
			break;
		}
		
	}
	cleardevice();
	if(flag==0){
		setcaption("YOU WIN");
		outtextxy(250, 250, "YOU WIN");
		PlaySound("music.wav",NULL,SND_FILENAME|SND_ASYNC|SND_LOOP|SND_NODEFAULT);//Let's meet in 1998
	}
	getch();
	closegraph();
}

void Snake::GameRun()
{
	initgraph(SCR_WIDTH, SCR_HEIGHT, 0);
	PlaySound("music1.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);//The third set of national broadcast gymnastics for middle school students
	PIMAGE pimg = newimage(640, 640);
	PIMAGE temp = newimage();
	getimage(temp, "u=3151353086,3354584439&fm=26&gp=0.jpg");
	int tempWidth = getwidth(temp), tempHeight = getheight(temp);
	putimage(pimg, 0, 0, 640, 640, temp, 0, 0, tempWidth, tempHeight);
	delimage(temp);
	temp = NULL;
	putimage(0, 0, pimg);
	setbkmode(TRANSPARENT);
	setfontbkcolor(RED);
	setfont(48, 0, "Ó×Ô²");
	outtextxy(220, 150, "THE SNAKE");
	setfont(24, 0, "Ó×Ô²");
	outtextxy(230, 550, "Çë°´ÈÎÒâ¼ü¼ÌÐø");
	getch();
	cleardevice();
	setbkcolor(WHITE);
	init();
	show();
}
