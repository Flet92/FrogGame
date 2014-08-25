#include "C_Frog.h"
using namespace std;

int C_Frog::lifes=3;														//nadanie zabie trzech zyc		
C_Frog::C_Frog(Point a, Direction b, C_Map *orient)										//konstruktor klasy podrzêdnej
	:C_MobileObject(a,b),													//konstruktor klasy nadrzêdnej z argumentami pozycji i kierunku
	jumpDist(1),																//dlugosc skoku rowna sie "1"																															
	rozkaz(silent),
	orientation(orient)
	
{	
	position=startPosition;
	lifes--;																//uzycie jednego z trzech zyc zaby
	if (lifes>=0)
	{
		orientation->Mapa[a.x][a.y].changeCellType(frogongrass);				//zaba ustawia sie na mapie na pozycji poczatkowej
		orientation->Mapa[a.x][a.y].kierunek=gora;								//zaba ustawia sie na mapie tak by byc skierowana w gore
		lifeCycle(rozkaz, jumpDist, position, orientation);
	}
	else
	{}
}


C_Frog::~C_Frog(void)
{
}
void C_Frog::lifeCycle(Order order, int skok, Point &pozycja, C_Map *orientation)	//zycie zaby
{
	if (order!=silent)															//jeœli nadano rozkaz
	{
		listenOrder(order);															//wysluchaj rozkaz
		jump(listenOrder(order), skok, pozycja, orientation);						//skacz w odpowiednim kierunku
		checkWinAndGoOn(pozycja, orientation);
	}
}
void C_Frog::checkWinAndGoOn(Point &pozycja, C_Map *orientation)
{
	if(orientation->Mapa[pozycja.x][pozycja.y].cellType==water)
	{
		pozycja.x=((orientation->numberOfCellsH)/2);
		pozycja.y=0;
	}
}
void C_Frog::jump(Direction kierunek, int skok, Point &pozycja, C_Map *orientation)
{
	if (kierunek==gora)
		if(pozycja.y!=orientation->numberOfCellsV)
		{
			if(orientation->Mapa[pozycja.x][pozycja.y].cellType==frogongrass)
				orientation->Mapa[pozycja.x][pozycja.y].changeCellType(grass);
			if(orientation->Mapa[pozycja.x][pozycja.y].cellType==frogonasphalt)
				orientation->Mapa[pozycja.x][pozycja.y].changeCellType(road);
			pozycja.y=+skok;
			if(orientation->Mapa[pozycja.x][pozycja.y].cellType==grass)
				orientation->Mapa[pozycja.x][pozycja.y].changeCellType(frogongrass);
			if(orientation->Mapa[pozycja.x][pozycja.y].cellType==road)
				orientation->Mapa[pozycja.x][pozycja.y].changeCellType(frogonasphalt);
		}
	if (kierunek==dol)
		if(pozycja.y!=0)
		{
			if(orientation->Mapa[pozycja.x][pozycja.y].cellType==frogongrass)
				orientation->Mapa[pozycja.x][pozycja.y].changeCellType(grass);
			if(orientation->Mapa[pozycja.x][pozycja.y].cellType==frogonasphalt)
				orientation->Mapa[pozycja.x][pozycja.y].changeCellType(road);
			pozycja.y-=skok;
			if(orientation->Mapa[pozycja.x][pozycja.y].cellType==grass)
				orientation->Mapa[pozycja.x][pozycja.y].changeCellType(frogongrass);
			if(orientation->Mapa[pozycja.x][pozycja.y].cellType==road)
				orientation->Mapa[pozycja.x][pozycja.y].changeCellType(frogonasphalt);
		}
	if (kierunek==prawo)
		if(pozycja.x!=orientation->numberOfCellsH)
		{
			if(orientation->Mapa[pozycja.x][pozycja.y].cellType==frogongrass)
				orientation->Mapa[pozycja.x][pozycja.y].changeCellType(grass);
			if(orientation->Mapa[pozycja.x][pozycja.y].cellType==frogonasphalt)
				orientation->Mapa[pozycja.x][pozycja.y].changeCellType(road);
			pozycja.x=+skok;
			if(orientation->Mapa[pozycja.x][pozycja.y].cellType==grass)
				orientation->Mapa[pozycja.x][pozycja.y].changeCellType(frogongrass);
			if(orientation->Mapa[pozycja.x][pozycja.y].cellType==road)
				orientation->Mapa[pozycja.x][pozycja.y].changeCellType(frogonasphalt);
		}
	if (kierunek==lewo)
		if (pozycja.x!=0)
		{
			if(orientation->Mapa[pozycja.x][pozycja.y].cellType==frogongrass)
				orientation->Mapa[pozycja.x][pozycja.y].changeCellType(grass);
			if(orientation->Mapa[pozycja.x][pozycja.y].cellType==frogonasphalt)
				orientation->Mapa[pozycja.x][pozycja.y].changeCellType(road);
			pozycja.x=-skok;
			if(orientation->Mapa[pozycja.x][pozycja.y].cellType==grass)
				orientation->Mapa[pozycja.x][pozycja.y].changeCellType(frogongrass);
			if(orientation->Mapa[pozycja.x][pozycja.y].cellType==road)
				orientation->Mapa[pozycja.x][pozycja.y].changeCellType(frogonasphalt);
		}
	orientation->Mapa[pozycja.x][pozycja.y].kierunek=kierunek;
}
Direction C_Frog::listenOrder(Order order)
{
	if (order==goAhead)
	{
		direction=gora;
		order=silent;
	}
	if (order==goBack)
	{
		direction=dol;
		order=silent;
	}
	if (order==turnRight)
	{
		direction=prawo;
		order=silent;
	}
	if (order==turnLeft)
	{	
		direction=lewo;
		order=silent;
	}
	return direction;
}