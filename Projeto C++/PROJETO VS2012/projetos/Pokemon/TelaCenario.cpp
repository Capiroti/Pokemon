#include "TelaCenario.h"


TelaCenario::TelaCenario()
{
}

TelaCenario::~TelaCenario()
{
}

string TelaCenario::getJson(){return this->json;}
string TelaCenario::getNomeTileSet(){return this->nomeTileSet;}
string TelaCenario::getCaminhoTileSet(){return this->caminhoTileSet;}
vector<int> TelaCenario::getPortas(){return this->portas;}
vector<int> TelaCenario::getEntradas(){return this->entradas;}

void TelaCenario::setJson(string json){this->json = json;}
void TelaCenario::setNomeTileSet(string nomeTileSet){this->nomeTileSet = nomeTileSet;}
void TelaCenario::setCaminhoTileSet(string caminhoTileSet){this->caminhoTileSet = caminhoTileSet;}
void TelaCenario::setPorta(int porta){this->portas.push_back(porta);}
void TelaCenario::setEntrada(int entrada){this->entradas.push_back(entrada);}


void TelaCenario::carregaMapa(TileMap &mapa)
{
	mapa.carregar(this->json);
	mapa.carregarConfigTileSet(this->nomeTileSet, this->caminhoTileSet);
}

void TelaCenario::carregaMapa(string json, string nomeTileSet, string caminhoTileSet, TileMap &mapa)
{
	mapa.carregar(json);
	mapa.carregarConfigTileSet(nomeTileSet, caminhoTileSet);

	this->json = json;
	this->nomeTileSet = nomeTileSet;
	this->caminhoTileSet = caminhoTileSet;
}

void TelaCenario::desenhaInterface(Personagem &player, string nomeObjeto, int addXCentral, int addYCentral, TileMap &mapa)
{
	player.carregarAnimacao(mapa.getObjeto(nomeObjeto));
	mapa.setPosCentro((player.getXcentral() + addXCentral), (player.getYcentral() + addYCentral));
}

int TelaCenario::verificarMudancaMapa(TileMap &mapa, Personagem &player)
{
	if(mapa.existeObjetoDoTipoNaPos("SaidaPallet",player.getX(),player.getY()))
		return 5;
	else if(mapa.existeObjetoDoTipoNaPos("SaidaRota01",player.getX(),player.getY()))
		return 6;
	else if(mapa.existeObjetoDoTipoNaPos("SaidaViridian",player.getX(),player.getY()))
		return 7;
	else
		return 0;
}