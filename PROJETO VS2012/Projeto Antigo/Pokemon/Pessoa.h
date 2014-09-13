#pragma once
#include <string>
#include <iostream>

using namespace std;
class Pessoa
{
private:
	string nome;
	int idade;
	char sexo;
public:
	Pessoa();
	~Pessoa();

	//GETTERS E SETTERS
	string getNome();
	int getIdade();
	char getSexo();

	void setNome(string nome);
	void setIdade(int idade);
	void setSexo(char sexo);
	//--------------------

	void Falar();
	void Andar();
};

