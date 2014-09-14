#pragma once
#include <string>
#include <iostream>

using namespace std;
class Pokemon
{
private:
	int id;
	string nome;
	char sexo;
	string fotoPerfil;
	float altura;
	float peso;
	int level;
	int hp;
	int maxHp;
	int experiencia;
	int ataque;
	int defesa;
	int velAtaque;
	int velDefesa;
	int velocidade;
	int status; //envenenado/paralisado/congelado/em chamas
	bool vantagem; // caso o pokemon oposto seja do tipo contrario FOGO > PLANTA
	bool desvantagem; // caso o pokemon oposto tenha vantgaem sobre este AGUA > FOGO

public:
	Pokemon();
	~Pokemon();

	//GETTERS E SETTERS
	int getId();
	string getNome();
	char getSexo();
	string getFotoPerfil();
	float getAltura();
	float getPeso();
	int getLevel();
	int getHp();
	int getMaxHp();
	int getExperiencia();
	int getAtaque();
	int getDefesa();
	int getVelAtaque();
	int getVelDefesa();
	int getVelocidade();
	int getStatus(); 
	bool getVantagem(); 
	bool getDesvantagem();

	void setId(int id);
	void setNome(string nome);
	void setSexo(char sexo);
	void setFotoPerfil(string fotoPerfil);
	void setAltura(float altura);
	void setPeso(float peso);
	void setLevel(int level);
	void setHp(int hp);
	void setMaxHp(int maxHp);
	void setExperiencia(int experiencia);
	void setAtaque(int ataque);
	void setDefesa(int defesa);
	void setVelAtaque(int velAtaque);
	void setVelDefesa(int velDefesa);
	void setVelocidade(int velocidade);
	void setStatus(int status);
	void setVantagem(bool vantagem);
	void setDesvantagem(bool desvantagem);
	//-----------------------

	bool Atacar();
	bool Defender();
	bool GerenciaHP();
	void GerenciaExperiencia();
	void AplicaVantagem();
	void AplicaDesvantagem();
};

