#include "Pessoa.h"

Pessoa::Pessoa()
{
}

Pessoa::~Pessoa()
{
}

//GETTERS E SETTERS
string Pessoa::getNome(){return this->nome;}
int Pessoa::getIdade(){return this->idade;}
char Pessoa::getSexo(){return this->sexo;}

void Pessoa::setNome(string nome){this->nome = nome;}
void Pessoa::setIdade(int idade){this->idade = idade;}
void Pessoa::setSexo(char sexo){this->sexo = sexo;}
//--------------------
	 
void Pessoa::Falar()
{
	cout << "Estou Falando!!!" << endl;
}
void Pessoa::Andar()
{
	cout << "Estou Andando!!!" << endl;
}

