#include "tela.h"

class TelaCenario :
	public Tela
{

private:
	string json;
	string nomeTileSet;
	string caminhoTileSet;
	vector<int> portas;
	vector<int> entradas;

public:
	TelaCenario();
	~TelaCenario();

	string getJson();
	string getNomeTileSet();
	string getCaminhoTileSet();
	vector<int> getPortas();
	vector<int> getEntradas();

	void setJson(string json);
	void setNomeTileSet(string nomeTileSet);
	void setCaminhoTileSet(string caminhoTileSet);
	void setPorta(int porta);
	void setEntrada(int entrada);

	void carregaMapa(TileMap &mapa);
	void carregaMapa(string json, string nomeTileSet, string caminhoTileSet, TileMap &mapa);
	void desenhaInterface(Personagem &player, string nomeObjeto, int addXCentral, int addYCentral, TileMap &mapa);
	int verificarMudancaMapa(TileMap &mapa, Personagem &player);
};

