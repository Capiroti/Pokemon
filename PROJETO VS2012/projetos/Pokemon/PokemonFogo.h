#pragma once
#include "pokemon.h"
class PokemonFogo :
	public Pokemon
{
private:
	bool queimar;
	bool explosaoArdente;
	bool inferno;

public:
	PokemonFogo();
	~PokemonFogo();

	//GETTERS E SETTERS
	bool getQueimar();
	bool getExplosaoArdente();
	bool getInferno();

	void setQueimar(bool queimar);
	void setExplosaoArdente(bool explosaoArdente);
	void setInferno(bool inferno);
	//------------------

	void Queimar();
	void ExplosaoArdente();
	void Inferno();
};

