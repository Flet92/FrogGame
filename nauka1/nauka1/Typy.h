#pragma once
#include <SFML/Graphics.hpp>				//plik nag³ówkowy zawieraj¹cy potrzebne funkcje
#include <iostream>
#include <windows.h>

using namespace std;


struct Point {								//struktura definiuj¹ca punkt
	int x;
	int y;
};
enum TypeOfCell								//definicja typów komórki
{
    grass = 0,
    road = 1,
	water = 2,
	frogongrass = 3,
	frogonasphalt = 4

};
enum Direction							//definicja typów komórki
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
TypeOfCell changeType( TypeOfCell argument ); //funkcja zwracaj¹ca podany argument typu komórki
