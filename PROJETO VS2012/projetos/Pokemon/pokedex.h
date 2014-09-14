#pragma once
#include "Pokemon.h"
class pokedex
{
public:
	pokedex();
	~pokedex();
	bool identificarPokemon(Pokemon pokemon); // busca o pokemon no arquivo, mostra suas informações, e adiciona a lista de pokemons que o personagem possui
private:
	Pokemon pokemons[50]; //numero total de pokemons que o jogador possui
};

