#pragma once
#include "personagem.h"
#include "TelaMenu.h"
#include "libUnicornio.h"

#define INICIAL 2
#define MENU 0
#define JOGANDO 1


#define GAROTO 0
#define GAROTA 1 

class Jogo
{
protected:
	int tela;
	Personagem player;
	TileMap *mapa;
	Sprite fundo;
	GerenciadorDeRecursos recursos;
	TelaMenu menu1;
	

public:
	Jogo();
	~Jogo();


	void controladorTelas();
	void testPlayerMapa();
	void inicializar();
	void executar();
	void finalizar();
};

