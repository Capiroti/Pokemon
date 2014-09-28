#pragma once
#include <fstream>
#include "personagem.h"
#include "TelaMenu.h"
#include "TelaCenario.h"
#include "libUnicornio.h"

#define INICIAL 1000
#define MENU 50
#define JOGANDO 60

#define GAROTO 0
#define GAROTA 1 

using namespace std;

class Jogo
{
protected:
	int indiceTela, indiceTelaAtual;
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
	void criaPokemon(int idPokemon);
	void inicializar();
	void executar();
	void finalizar();
};



