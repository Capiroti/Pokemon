#include "tela.h"

class TelaCenario :
	public Tela
{

private:
	TileMap mapa;
	string json;
	string nomeTileSet;
	string caminhoTileSet;
	vector<int> portas;
	vector<int> entradas;

public:
	TelaCenario();
	~TelaCenario();

	TileMap getMapa();
	string getJson();
	string getNomeTileSet();
	string getCaminhoTileSet();
	vector<int> getPortas();
	vector<int> getEntradas();

	void setMapa(TileMap mapa);
	void setJson(string json);
	void setNomeTileSet(string nomeTileSet);
	void setCaminhoTileSet(string caminhoTileSet);
	void setPorta(int porta);
	void setEntrada(int entrada);

	void carregaMapa();
	void carregaMapa(string json, string nomeTileSet, string caminhoTileSet);
	int desenhaInterface(Personagem player, string nomeObjeto, int addXCentral, int addYCentral);
};

