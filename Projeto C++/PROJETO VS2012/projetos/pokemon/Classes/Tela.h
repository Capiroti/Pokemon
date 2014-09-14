#pragma once
#include "libUnicornio.h"

class Tela
{
protected:
	TileMap mapa;
	AStar astar;

public:

	void setMapa(TileMap pmapa);
	TileMap getMapa();

	Tela();
	~Tela();
};

