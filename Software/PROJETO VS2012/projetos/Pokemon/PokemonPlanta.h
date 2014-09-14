#pragma once
#include "pokemon.h"
class PokemonPlanta :
	public Pokemon
{
private:
	bool balaDeSemente;
	bool folhaNavalha;
	bool esferaSolar;

public:
	PokemonPlanta();
	~PokemonPlanta();

	//GETTERS E SETTERS
	bool getBalaDeSemente();
	bool getFolhaNavalha();
	bool getEsferaSolar();

	void setBalaDeSemente(bool balaDeSemente);
	void setFolhaNavalha(bool folhaNavalha);
	void setEsferaSolar(bool esferaSolar);
	//------------------

	void BalaDeSemente();
	void FolhaNavalha();
	void EsferaSolar();
};

