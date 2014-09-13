#include "PokemonPlanta.h"

PokemonPlanta::PokemonPlanta(void)
{
}

PokemonPlanta::~PokemonPlanta(void)
{
}

//GETTERS E SETTERS
bool PokemonPlanta::getBalaDeSemente(){ return this->balaDeSemente;}
bool PokemonPlanta::getFolhaNavalha(){ return this->folhaNavalha;}
bool PokemonPlanta::getEsferaSolar(){ return this->esferaSolar;}
	 
void PokemonPlanta::setBalaDeSemente(bool balaDeSemente){this->balaDeSemente = balaDeSemente;}
void PokemonPlanta::setFolhaNavalha(bool folhaNavalha){this->folhaNavalha = folhaNavalha;}
void PokemonPlanta::setEsferaSolar(bool esferaSolar){this->esferaSolar = esferaSolar;}
//------------------
	
void PokemonPlanta::BalaDeSemente()
{
	cout << "USOU BALA DE SEMENTE!!!" << endl;
}
void PokemonPlanta::FolhaNavalha()
{
	cout << "USOU FOLHA NAVALHA!!!" << endl;
}
void PokemonPlanta::EsferaSolar()
{
	cout << "USOU ESFERA SOLAR!!!" << endl;
}
