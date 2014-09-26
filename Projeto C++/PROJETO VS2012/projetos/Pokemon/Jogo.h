#pragma once
#include "personagem.h"
#include "TelaMenu.h"
#include "TelaCenario.h"
#include "libUnicornio.h"

#define INICIAL 1000
#define MENU 50
#define JOGANDO 60
#define CASAANDAR2 1
#define CASAANDAR1 2
#define CASAINIMIGO 3
#define LABORATORIO 4
#define PALLET 5
#define ROTA01 6
#define VIRIDIAN 7
#define LOJA 100
#define CENTRO 200
#define GINASIO 8

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



