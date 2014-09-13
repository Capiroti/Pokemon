#pragma once
#include "pokemon.h"
class PokemonAgua :
	public Pokemon
{
private:
	bool bolha;
	bool hidroBomba;
	bool pistolaDeAgua;

public:
	PokemonAgua();
	~PokemonAgua();

	//GETTERS E SETTERS
	bool getBolha();
	bool getHidroBomba();
	bool getPistolaDeAgua();

	void setBolha(bool bolha);
	void setHidroBomba(bool hidroBomba);
	void setPistolaDeAgua(bool pistolaDeAgua);
	//------------------

	void Bolha();
	void HidroBomba();
	void PistolaDeAgua();

};