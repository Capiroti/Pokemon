#pragma once
#include "tela.h"
class TelaCenario :
	public Tela
{
public:
	TelaCenario();
	~TelaCenario();

	void carregaMapa(string  nomeJson, string nomeTileSet, string caminhoTileSet);
	void desenha();
};

