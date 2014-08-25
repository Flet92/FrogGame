#pragma once
#include <SFML/Graphics.hpp>
#include "Typy.h"

using namespace std;
class C_Cell												//Klasa definiuje kom�rk� gry
{
public:
	Point position;											//pozycja kom�rki
	Direction kierunek;										//orientacja kom�rki
	Point cellSize;											//rozmiar kom�rki
	TypeOfCell cellType;									//typ kom�rki(woda, trawa, asfalt)
	TypeOfCell changeCellType(TypeOfCell ncellType)			//funkcja zmieniaj�ca typ kom�rki i go zwracaj�ca
	{		
		cellType = changeType(ncellType);
		return cellType;
	}
	
	C_Cell(void);
	~C_Cell(void);
};

