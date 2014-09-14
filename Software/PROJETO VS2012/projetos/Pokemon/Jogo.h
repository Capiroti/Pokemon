#pragma once
#include "personagem.h"
#include "libUnicornio.h"

#define MENU 0
#define JOGANDO 1

#define GAROTO 0
#define GAROTA 1 

class Jogo
{
protected:
	int tela;
	Personagem player;

public:
	Jogo();
	~Jogo();


	void controladorTelas();
	void inicializar();
	void executar();
	void finalizar();
};

