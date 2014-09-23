#include "TelaCenario.h"


TelaCenario::TelaCenario()
{
}

TelaCenario::~TelaCenario()
{
}

TileMap TelaCenario::getMapa(){return this->mapa;}
string TelaCenario::getJson(){return this->json;}
string TelaCenario::getNomeTileSet(){return this->nomeTileSet;}
string TelaCenario::getCaminhoTileSet(){return this->caminhoTileSet;}
vector<int> TelaCenario::getPortas(){return this->portas;}
vector<int> TelaCenario::getEntradas(){return this->entradas;}

void TelaCenario::setMapa(TileMap mapa){this->mapa = mapa;}
void TelaCenario::setJson(string json){this->json = json;}
void TelaCenario::setNomeTileSet(string nomeTileSet){this->nomeTileSet = nomeTileSet;}
void TelaCenario::setCaminhoTileSet(string caminhoTileSet){this->caminhoTileSet = caminhoTileSet;}
void TelaCenario::setPorta(int porta){this->portas.push_back(porta);}
void TelaCenario::setEntrada(int entrada){this->entradas.push_back(entrada);}


void TelaCenario::carregaMapa()
{
	this->mapa.carregar(this->json);
	this->mapa.carregarConfigTileSet(this->nomeTileSet, this->caminhoTileSet);
}

void TelaCenario::carregaMapa(string json, string nomeTileSet, string caminhoTileSet)
{
	this->mapa.carregar(json);
	this->mapa.carregarConfigTileSet(nomeTileSet, caminhoTileSet);

	this->json = json;
	this->nomeTileSet = nomeTileSet;
	this->caminhoTileSet = caminhoTileSet;
}

int TelaCenario::desenhaInterface(Personagem player, string nomeObjeto, int addXCentral, int addYCentral)
{
	player.carregarAnimacao(this->mapa.getObjeto(nomeObjeto));
	this->mapa.setPosCentro((player.getXcentral() + addXCentral), (player.getYcentral() + addYCentral));
	return 0;
}
