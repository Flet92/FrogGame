#pragma once
#include <SFML/Graphics.hpp>
#include "Typy.h"

using namespace std;
class C_Cell												//Klasa definiuje komórkê gry
{
public:
	Point position;											//pozycja komórki
	Direction kierunek;										//orientacja komórki
	Point cellSize;											//rozmiar komórki
	TypeOfCell cellType;									//typ komórki(woda, trawa, asfalt)
	TypeOfCell changeCellType(TypeOfCell ncellType)			//funkcja zmieniaj¹ca typ komórki i go zwracaj¹ca
	{		
		cellType = changeType(ncellType);
		return cellType;
	}
	
	C_Cell(void);
	~C_Cell(void);
};

