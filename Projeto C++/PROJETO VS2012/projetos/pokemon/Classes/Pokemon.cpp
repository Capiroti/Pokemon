#include "Pokemon.h"

Pokemon::Pokemon()
{
}

Pokemon::~Pokemon()
{
}

//GETTERS E SETTERS
int Pokemon::getId(){return this->id;}
string Pokemon::getNome(){return this->nome;}
char Pokemon::getSexo(){return this->sexo;}
string Pokemon::getFotoPerfil(){return this->fotoPerfil;}
float Pokemon::getAltura(){return this->altura;}
float Pokemon::getPeso(){return this->peso;}
int Pokemon::getLevel(){return this->level;}
int Pokemon::getHp(){return this->hp;}
int Pokemon::getMaxHp(){return this->maxHp;}
int Pokemon::getExperiencia(){return this->experiencia;}
int Pokemon::getAtaque(){return this->ataque;}
int Pokemon::getDefesa(){return this->defesa;}
int Pokemon::getVelAtaque(){return this->velAtaque;}
int Pokemon::getVelDefesa(){return this->velDefesa;}
int Pokemon::getVelocidade(){return this->velocidade;}
int Pokemon::getStatus(){return this->status;}
bool Pokemon::getVantagem(){return this->vantagem;}
bool Pokemon::getDesvantagem(){return this->desvantagem;}

void Pokemon::setId(int id){this->id = id;}
void Pokemon::setNome(string nome){this->nome = nome;}
void Pokemon::setSexo(char sexo){this->sexo = sexo;}
void Pokemon::setFotoPerfil(string fotoPerfil){this->fotoPerfil = fotoPerfil;}
void Pokemon::setAltura(float altura){this->altura = altura;}
void Pokemon::setPeso(float peso){this->peso = peso;}
void Pokemon::setLevel(int level){this->level = level;}
void Pokemon::setHp(int hp){this->hp = hp;}
void Pokemon::setMaxHp(int maxHp){this->maxHp = maxHp;}
void Pokemon::setExperiencia(int experiencia){this->experiencia = experiencia;}
void Pokemon::setAtaque(int ataque){this->ataque = ataque;}
void Pokemon::setDefesa(int defesa){this->defesa = defesa;}
void Pokemon::setVelAtaque(int velAtaque){this->velAtaque = velAtaque;}
void Pokemon::setVelDefesa(int velDefesa){this->velDefesa = velDefesa;}
void Pokemon::setVelocidade(int velocidade){this->velocidade = velocidade;}
void Pokemon::setStatus(int status){this->status = status;}
void Pokemon::setVantagem(bool vantagem){this->vantagem = vantagem;}
void Pokemon::setDesvantagem(bool desvantagem){this->desvantagem = desvantagem;}
//-----------------------
	 
bool Pokemon::Atacar()
{
	cout << "Atacando!!!" << endl;
	return false;
}
bool Pokemon::Defender()
{
	cout << "Defendendo!!!" << endl;
	return false;
}
bool Pokemon::GerenciaHP()
{
	cout << "Gerenciando HP!!!" << endl;
	return false;
}
void Pokemon::GerenciaExperiencia()
{
	cout << "Gerenciando Experiencia" << endl;
}
void Pokemon::AplicaVantagem()
{
	cout << "Aplicando Vantagem!!!" << endl;
}
void Pokemon::AplicaDesvantagem()
{
	cout << "Aplicando Desvantagem!!!" << endl;
}
