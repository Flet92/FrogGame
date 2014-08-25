#include "C_Map.h"
#include "Typy.h"
#include "C_Cell.h"


void C_Map::createMap( C_Cell Tmap[numberOfCellsV][numberOfCellsH])
{
	for(int i=0;i<numberOfCellsV;i++){
		for(int j=0;j<numberOfCellsH;j++){
			Tmap[i][j].cellSize.x=mapSizeH/numberOfCellsH;
			Tmap[i][j].cellSize.y=mapSizeV/numberOfCellsV;
			Tmap[i][j].position.x=(j+1)*(Tmap[i][j].cellSize.x / 2);
			Tmap[i][j].position.y=(i+1)*(Tmap[i][j].cellSize.y / 2);
			Tmap[i][j].kierunek=gora;
			if (i==0) Tmap[i][j].cellType=grass;
			if ((i>=1)&&(i<=4)) Tmap[i][j].cellType=road;	
			if (i==5) Tmap[i][j].cellType=water;
			}
	}
}
C_Map::C_Map(void)
	
{
	createMap(Mapa);
}


C_Map::~C_Map(void)
{
}
