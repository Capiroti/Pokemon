#pragma once
#include "personagem.h"
#include "TelaMenu.h"
#include "TelaCenario.h"
#include "libUnicornio.h"

#define INICIAL 0
#define MENU 1
#define JOGANDO 2
#define PALLET 3
#define ROTA01 4
#define VERIDIAN 5
#define CASAANDAR1 6
#define CASAANDAR2 7
#define LABORATORIO 8
#define LOJA 9
#define CENTRO 10
#define GINASIO 11
#define CASAINIMIGO 12

#define GAROTO 0
#define GAROTA 1 

class Jogo
{
protected:
	int indiceTela;
	Personagem player;
	TelaMenu *telaMenu;
	TelaCenario *telaCenario;

	
	TileMap mapa;
	
	Sprite fundo;
	GerenciadorDeRecursos recursos;
	
	bool entrouCenario;

public:
	Jogo();
	~Jogo();

	void controladorTelas();
	void carregarCenario(string json,string nomeTileSet, string caminhoTileSet, int addPosXcentral, int addPosYcentral);
	void testPlayerMapa();
	void inicializar();
	void executar();
	void finalizar();
};



