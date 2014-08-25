#pragma once
#include "Typy.h"
#include "C_MobileObject.h"
#include <iostream>
#include "C_Map.h"

using namespace std;

class C_Frog 
	:public C_MobileObject								//dziedziczenie pod klasie Obiekt ruchomy
{
public:
	void jump(Direction  , int, Point &, C_Map *);		//Funkcja skoku zaby korzystaj¹ca z argumentow: kierunku skoku, dlugosci skoku i aktualnej pozycji
	void checkWinAndGoOn (Point &, C_Map *);
	void lifeCycle(Order , int, Point &, C_Map *);		//Zycie zaby
	C_Map *orientation;									//wskaznik na mape
	Order rozkaz;
	Direction listenOrder(Order);						//Funkcja sluchania rozkazow przez zabe
	C_Frog(Point, Direction, C_Map *);							//konstruktor zawierajacy pozycje startu i kierunek patrzenia zaby
	~C_Frog(void);
private:
	int jumpDist;										//zasieg skoku
	static int lifes;									//ilosc zyc
};

