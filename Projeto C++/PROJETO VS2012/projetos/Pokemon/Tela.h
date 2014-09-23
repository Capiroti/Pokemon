#pragma once
#include "libunicornio.h"

class Tela
{
protected:
	Sprite fundo;
	GerenciadorDeRecursos recurso;
	TileMap mapa;
	vector<int> tilePorta;
	vector<int> tileMudaCenario;

public:

	void setMapa(TileMap mapa);
	TileMap getMapa();

	virtual int desenhaInterface() = 0;

	Tela();
	~Tela();
};

