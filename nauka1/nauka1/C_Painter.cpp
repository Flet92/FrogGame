#include "C_Painter.h"


C_Painter::C_Painter(void)
{
	sf::RenderWindow gameWindow( sf::VideoMode( 900, 600, 32 ), "Zaba" );
	renderujOkno();
}


C_Painter::~C_Painter(void)
{
}


void C_Painter::renderujOkno()
{
	while( gameWindow.isOpen() )
    {
		while( gameWindow.pollEvent( zdarzenie ) )
        {
			if( zdarzenie.type == sf::Event::Closed )
            gameWindow.close();    
       }
        gameWindow.clear( sf::Color::White );
		gameWindow.display();
	} 
}