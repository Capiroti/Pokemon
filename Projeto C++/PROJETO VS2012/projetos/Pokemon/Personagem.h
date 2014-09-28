#pragma once
#include "Pessoa.h"
#include "Pokemon.h"
#include "libunicornio.h"

#define GAROTO 0
#define GAROTA 1

#define ANDANDO_ABAIXO 0
#define ANDANDO_ACIMA 1
#define ANDANDO_DIREITA 2
#define ANDANDO_ESQUERDA 3
#define FRAME_ANIMACAO_PARADO 1

class Personagem : public Pessoa
{
private:
	bool movendo, spritesCarregados;
	float oldX, oldY, nextX, nextY, interpolador;
	ObjetoTile* objeto;
	vector<Pokemon> listaPokemon;

public:

	bool getSpritesCarregados();

	void setSpritesCarregados(bool spritesCarregados);

	vector<Pokemon> getListaPokemon();
	Pokemon getPokemon(int indice);

	void setListaPokemon(vector<Pokemon> listaPokemon);
	void setPokemon(Pokemon pokemon);


	void carregarAnimacao(ObjetoTile* obj);
	void atualizarAnimacao(ObjetoTile* obj);
	void atualizar();
	void movePara(float x, float y);

	bool estaMovendo();

	float getXcentral();
	float getYcentral();

	Personagem();
	~Personagem();
};