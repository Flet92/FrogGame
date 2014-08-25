#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include "C_Map.h"
using namespace std;

class C_Painter
{
public:
	sf::RenderWindow gameWindow;
	sf::Event zdarzenie;
	void renderujOkno();
	C_Painter(void);
	~C_Painter(void);
};

