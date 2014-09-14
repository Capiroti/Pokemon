#include "PokemonAgua.h"

PokemonAgua::PokemonAgua(void)
{
}

PokemonAgua::~PokemonAgua(void)
{
}

//GETTERS E SETTERS
bool PokemonAgua::getBolha(){return this->bolha;}
bool PokemonAgua::getHidroBomba(){return this->hidroBomba;}
bool PokemonAgua::getPistolaDeAgua(){return this->pistolaDeAgua;}
	 
void PokemonAgua::setBolha(bool bolha){this->bolha = bolha;}
void PokemonAgua::setHidroBomba(bool hidroBomba){this->hidroBomba = hidroBomba;}
void PokemonAgua::setPistolaDeAgua(bool pistolaDeAgua){this->pistolaDeAgua = pistolaDeAgua;}
//------------------
	 
void PokemonAgua::Bolha()
{
	cout << "USANDO BOLHA!!!" << endl;
}
void PokemonAgua::HidroBomba()
{
	cout << "USANDO HIDROBOMBA!!!" << endl;
}
void PokemonAgua::PistolaDeAgua()
{
	cout << "USANDO PISTOLA DE AGUA!!!" << endl;
}