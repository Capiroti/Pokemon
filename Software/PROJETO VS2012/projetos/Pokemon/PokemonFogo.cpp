#include "PokemonFogo.h"

PokemonFogo::PokemonFogo()
{
}

PokemonFogo::~PokemonFogo()
{
}

//GETTERS E SETTER
bool PokemonFogo::getQueimar(){return this->queimar;}
bool PokemonFogo::getExplosaoArdente(){return this->explosaoArdente;}
bool PokemonFogo::getInferno(){return this->inferno;}
	 
void PokemonFogo::setQueimar(bool queimar){this->queimar = queimar;}
void PokemonFogo::setExplosaoArdente(bool explosaoArdente){this->explosaoArdente = explosaoArdente;}
void PokemonFogo::setInferno(bool inferno){this->inferno = inferno;}
//------------------
	 
void PokemonFogo::Queimar()
{
	cout << "usando QUEIMAR!!!" << endl;
}
void PokemonFogo::ExplosaoArdente()
{
	cout << "usando EXPLOSAO ARDENTE!!!" << endl;
}
void PokemonFogo::Inferno()
{
	cout << "usando INFERNO!!!" << endl;
}
