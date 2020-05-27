#ifndef _STRUCT_H      
#define _STRUCT_H
#include <graphics.h>
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
#include <mmsystem.h>
#pragma comment (lib, "Winmm.lib")
#define SCR_WIDTH      640
#define SCR_HEIGHT     640
#define N  3
#define MAXFOODNUM 9
#define INIT_SPEED 10 
struct Position
{
	double x;
	double y;
};//Coordinate structure 

struct Link
{
	double x;
	double y;
	color_t s_color;
	Link* prev;
	Link* next;
};// snake¡®s body 
using namespace std;
#endif
