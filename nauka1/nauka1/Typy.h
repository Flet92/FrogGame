#pragma once
#include <SFML/Graphics.hpp>				//plik nag��wkowy zawieraj�cy potrzebne funkcje
#include <iostream>
#include <windows.h>

using namespace std;


struct Point {								//struktura definiuj�ca punkt
	int x;
	int y;
};
enum TypeOfCell								//definicja typ�w kom�rki
{
    grass = 0,
    road = 1,
	water = 2,
	frogongrass = 3,
	frogonasphalt = 4

};
enum Direction							//definicja typ�w kom�rki
{
    prawo = 0,
	lewo = 1,
	gora = 2,
	dol = 3
};
enum Order
{
	goAhead = 0,
	goBack = 1,
	turnRight = 2,
	turnLeft = 3,
	silent = 4
};
TypeOfCell changeType( TypeOfCell argument ); //funkcja zwracaj�ca podany argument typu kom�rki
