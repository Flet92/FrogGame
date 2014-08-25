#pragma once												
#include "C_Cell.h"												//klasa Mapa Gry zawiera tablic� dwuwymiarow� wszystkich kom�rek gry
#include <SFML/Graphics.hpp>									//wraz z ich pozycjami i typem, na jej podstawie klasa C_Painter rysuje grafik�
#include <SFML/Graphics.hpp>				
#include <iostream>

using namespace std;
class C_Map														
{
public:
	static const int mapSizeH=900;
	static const int mapSizeV=600;
	static const int numberOfCellsH = 9;								//liczba kom�rek poziomych
	static const int numberOfCellsV = 6;								//liczba kom�rek pionowych
	C_Cell Mapa[numberOfCellsV][numberOfCellsH];	//wirtualna mapa w postaci tablicy dwuwymiarowej
	void createMap( C_Cell Tmap[][numberOfCellsH] );
	C_Map(void);
	~C_Map(void);
};

/*+numberofcellsH: int
+numberofcellsV: int
+grass: *C_Grass
+water: *C_Water
+road: *C_Road
+immoblieobject *C_ImmobileObject
+mobileobject *C_MobileObject
--
+makemap(): void */