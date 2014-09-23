#include "TelaCenario.h"


TelaCenario::TelaCenario()
{
}

TelaCenario::~TelaCenario()
{
}

void TelaCenario::carregaMapa(string  nomeJson, string nomeTileSet, string caminhoTileSet)
{
	this->mapa.carregar(nomeJson);
	this->mapa.carregarConfigTileSet(nomeTileSet,caminhoTileSet);
}

void TelaCenario::desenha()
{

}
