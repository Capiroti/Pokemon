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

void TelaCenario::verificarMudancaMapa(TileMap &mapa, Personagem &player, int &indiceTela)
{
	if(mapa.existeObjetoDoTipoNaPos("EntradaPrimeiroAndar",player.getXcentral(),player.getYcentral()))
		indiceTela = CASAANDAR1;
	else if(mapa.existeObjetoDoTipoNaPos("EntradaSegundoAndar",player.getXcentral(),player.getYcentral()))
		indiceTela = CASAANDAR2;
	else if(mapa.existeObjetoDoTipoNaPos("SaidaCasa",player.getXcentral(),player.getYcentral()))
		indiceTela = PALLET;
	else if(mapa.existeObjetoDoTipoNaPos("EntradaLaboratorio",player.getXcentral(),player.getYcentral()))	
		indiceTela = LABORATORIO;
	else if(mapa.existeObjetoDoTipoNaPos("SaidaLaboratorio",player.getXcentral(),player.getYcentral()))
		indiceTela = PALLET;
	else if(mapa.existeObjetoDoTipoNaPos("CasaPersonagem",player.getXcentral(),player.getYcentral()))	
		indiceTela = CASAANDAR1;
	else if(mapa.existeObjetoDoTipoNaPos("CasaRival",player.getXcentral(),player.getYcentral()))
		indiceTela = CASAINIMIGO;
	else if(mapa.existeObjetoDoTipoNaPos("EntradaRota01",player.getXcentral(),player.getYcentral()))
		indiceTela = ROTA01;
	else if(mapa.existeObjetoDoTipoNaPos("EntradaViridian",player.getXcentral(),player.getYcentral()))
		indiceTela = VIRIDIAN;
	else if(mapa.existeObjetoDoTipoNaPos("EntradaPallet",player.getXcentral(),player.getYcentral()))
		indiceTela = PALLET;
}