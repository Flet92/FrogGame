#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include "C_Cell.h"
#include "C_Map.h"
#include "C_Frog.h"
#include "C_Painter.h"

using namespace std;

int main()
{
	Point start;
	start.x=5;
	start.y=0;
 //   sf::RenderWindow gameWindow( sf::VideoMode( 900, 600, 32 ), "Zaba" );
//	sf::Event zdarzenie;
	C_Map *mapa;
	mapa = new C_Map;
	C_Frog zaba (start, gora, mapa);
	C_Painter *malarz;
	malarz = new C_Painter();
	malarz->renderujOkno();
//	zaba = new C_Frog(start, gora);
	
/*	while( gameWindow.isOpen() )
    {
   
		while( gameWindow.pollEvent( zdarzenie ) )
        {
            if( zdarzenie.type == sf::Event::Closed )
                 gameWindow.close();
            
        } //while
        
        gameWindow.clear( sf::Color::White );
	
	
        gameWindow.display();
    } //while */
	delete mapa;
    return 0;
}
/*using namespace sf;

	float przyspiesz(float &j){
				Sleep(100);
				j++;
				if (j==700) j=-100;
			return j;
	}
int main()
{
	int i=0;
	float j=1;
	int k=0;
	Texture tekstura,teksturac,teksturaj;
	Sprite zabcia, autko, ulica,ulica1;

	
    RenderWindow oknoAplikacji( sf::VideoMode( 800, 600, 32 ), "Projekt ZABA" );
    Frog Zaba(tekstura,zabcia);
	Car Samochod(teksturac,autko);
	jezdnia Ulica(teksturaj,ulica);
	jezdnia Ulica1(teksturaj,ulica1);
	
	Event zdarzenie;
    while( oknoAplikacji.isOpen() )
    {
        
        while( oknoAplikacji.pollEvent( zdarzenie ) )
        {
            if( zdarzenie.type == Event::Closed )
                 oknoAplikacji.close();
            
            if( zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape )
                 oknoAplikacji.close();
            
            if( zdarzenie.type == Event::MouseButtonPressed && zdarzenie.mouseButton.button == Mouse::Middle )
                 oknoAplikacji.close();
			if( zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Up )
                 i++;
			if( zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Down )
                 i--;
			
		
            
        }
        oknoAplikacji.clear( sf::Color::Black );
			float a;
		a=200+przyspiesz(j);
		float b;
			b=477;
		float az;
			az=387;
			float bz;
				bz=575-i*Zaba.skok;
    
  //      zabcia.setOrigin(0, 0 ); 
	
		ulica.setPosition(0, 475);
		ulica1.setPosition(0, 400);
		zabcia.setPosition(az, bz);
		autko.setPosition(a, b);
//		 if(((az<(a+320))&&(az>a))&&((bz<b)&&(bz>(b-140))))  break;
		oknoAplikacji.draw( ulica);
		oknoAplikacji.draw( ulica1);
		oknoAplikacji.draw( zabcia );
		oknoAplikacji.draw( autko);
        oknoAplikacji.display();
    }
    return 0;
}
		
	/*	sf::Font font;
if (!font.loadFromFile("arial.ttf"))
{
    std::cout<<"error...";
}
		
        
		 if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Down )
               obrazek.move( 0, 0.2 );
		 if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Up )
               obrazek.move( 0, -0.2 );
		 if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Right )
               obrazek.move( 0.2, 0 );
		 if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Left )
               obrazek.move( -0.2, 0 );
       // obrazek.setRotation( 30 ); //INFO: dopisane w tym rozdziale
        obrazek.setScale( 0.5, 0.5 ); //INFO: dopisane w tym rozdziale
        
        
#include <SFML/Graphics.hpp>

struct RObiekt
{
    double x;
    double y;
    double fPredkosc;
    
    RObiekt( double f_x = 0.0, double f_y = 0.0, double f_fPredkosc = 1.0 )
        : x( f_x )
        , y( f_y )
        , fPredkosc( f_fPredkosc )
    { }
    
    void PrzesunObiekt( double idzDoX, double idzDoY )
    {
        if( x < idzDoX )
        {
            x += fPredkosc;
            if( x > idzDoX )
                 x = idzDoX;
            
        } else
        if( x > idzDoX )
        {
            x -= fPredkosc;
            if( x < idzDoX )
                 x = idzDoX;
            
        }
        
        if( y < idzDoY )
        {
            y += fPredkosc;
            if( y > idzDoY )
                 y = idzDoY;
            
        } else
        if( y > idzDoY )
        {
            y -= fPredkosc;
            if( y < idzDoY )
                 y = idzDoY;
            
        }
    }
}; //struct RObiekt
using namespace sf;
int main()
{
    sf::RenderWindow oknoAplikacji( sf::VideoMode( 800, 600, 32 ), "Wytwarzanie Gier 2D, C++ " );
    oknoAplikacji.setVerticalSyncEnabled( true ); //W³¹czenie synchronizacji pionowej - sta³a liczba FPS (zazwyczaj 60) - zadzia³a pod warunkiem, ¿e system nie wymusza na aplikacji wy³¹czenia tego trybu
     CircleShape circle( 10 );
	 circle.setFillColor(Color::Red);
    typedef std::vector < RObiekt > VObiektyT;
    VObiektyT vObiekty;
    
    vObiekty.push_back( RObiekt( 50, 50, 1.0 ) );
    vObiekty.push_back( RObiekt( 100, 250, 3.5 ) );
    vObiekty.push_back( RObiekt( 300, 100, 5.0 ) );
    vObiekty.push_back( RObiekt( 500, 500, 2.5 ) );
    
    while( oknoAplikacji.isOpen() )
    {
          sf::Event zdarzenie;
        while( oknoAplikacji.pollEvent( zdarzenie ) )
        {
            if( zdarzenie.type == sf::Event::Closed )
                 oknoAplikacji.close();
            
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape )
                 oknoAplikacji.close();
            
            if( zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Middle )
                 oknoAplikacji.close();
            
        } //while
        
        //Przemieszczanie obiektów:
        vObiekty[ 0 ].PrzesunObiekt( 300, 300 );
        vObiekty[ 1 ].PrzesunObiekt( 500, 500 );
        vObiekty[ 2 ].PrzesunObiekt( 100, 100 );
        vObiekty[ 3 ].PrzesunObiekt( 300, 40 );
        
        
        oknoAplikacji.clear();
        for( VObiektyT::const_iterator i = vObiekty.begin(); i != vObiekty.end(); ++i ){
           
			circle.setPosition( i->x, i->y );
	//	circle.setFillColor( sf::Color::red);
	}		oknoAplikacji.draw(circle);
        
        oknoAplikacji.display();
    }
    return 0;
} */