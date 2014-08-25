#pragma once
#include "Typy.h"
class C_MobileObject
{
public:
	C_MobileObject(Point, Direction);
	~C_MobileObject(void);
protected:
	Point position;					//pozycja obiektu ruchomego
	Point size;						//rozmiar obiektu ruchomego
	const Point startPosition;		//pozycja startowa obiektu ruchomego
	Direction direction;			//kierunek w ktory jest zwrocony obiekt ruchomy
};

