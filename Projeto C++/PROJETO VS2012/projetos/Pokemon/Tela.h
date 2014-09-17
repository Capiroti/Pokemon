#pragma once
#include "libunicornio.h"

class Tela
{
protected:
	Sprite fundo;
	GerenciadorDeRecursos recurso;
	TileMap mapa;

public:

	void setMapa(TileMap pmapa);
	TileMap getMapa();

	virtual void desenha();

	Tela();
	~Tela();
};

