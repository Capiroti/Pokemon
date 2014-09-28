#include "Jogo.h"


void Jogo::controladorTelas()
{
	switch (indiceTela)
	{
	case MENU:
		if(telaMenu -> desenhaInterface())
		{
			//Pergunta pro usuario o sexo e carrega a animacao passando o sexo
			player.setSexo(GAROTA);
			indiceTela = CASAANDAR2; // depois do menu começa o jogo;
		}
		break;

	case CASAANDAR2:
		if(entrouCenario)
		{
			carregarCenario("dados/tilemaps/Jsons/CasaPersonagemAndar2.json", "CasaPersonagemA2", "dados/tilemaps/TileSets/ConfigTileSetCasaAndar2.txt",0,0);
			entrouCenario = false;
		}
		break;

	case CASAANDAR1:
		if(entrouCenario)
		{
			carregarCenario("dados/tilemaps/Jsons/CasaPersonagemAndar1.json", "CasaPersonagemA1", "dados/tilemaps/TileSets/ConfigTileSetCasaAndar1.txt",0,0);
			entrouCenario = false;
		}
		break;

	case CASAINIMIGO:
		if(entrouCenario)
		{
			carregarCenario("dados/tilemaps/Jsons/CasaRival.json", "CasaRival", "dados/tilemaps/TileSets/ConfigTileSetCasaRival.txt",0,0);
			entrouCenario = false;
		}
		break;

	case LABORATORIO:
		if(entrouCenario)
		{
			carregarCenario("dados/tilemaps/Jsons/Laboratorio.json", "Laboratorio", "dados/tilemaps/TileSets/ConfigTileSetLaboratorio.txt",0,0);
			entrouCenario = false;
		}
		break;

	case PALLET:
		if(entrouCenario)
		{
			carregarCenario("dados/tilemaps/Jsons/Pallet.json","TileSet" ,"dados/tilemaps/TileSets/ConfigTileSet.txt",0,0);
			entrouCenario = false;
		}
		break;

	case ROTA01:
		if(entrouCenario)
		{
			carregarCenario("dados/tilemaps/Jsons/Rota01.json","TileSet" ,"dados/tilemaps/TileSets/ConfigTileSet.txt",0,0);
			entrouCenario = false;
		}		
		break;

	case VIRIDIAN:
		if(entrouCenario)
		{
			carregarCenario("dados/tilemaps/Jsons/Viridian.json","TileSet" ,"dados/tilemaps/TileSets/ConfigTileSet.txt",0,0);
			entrouCenario = false;
		}
		break;
	}
	if(!entrouCenario)
	{
		player.atualizar();
		testPlayerMapa();
	}
}

void Jogo::carregarCenario(string json,string nomeTileSet, string caminhoTileSet, int addXCentral, int addYCentral)
{
	mapa.descarregar();
	telaCenario->setJson(json);
	telaCenario->setNomeTileSet(nomeTileSet);
	telaCenario->setCaminhoTileSet(caminhoTileSet);

	telaCenario->carregaMapa(mapa);
	telaCenario->desenhaInterface(player,"Player", addXCentral, addYCentral,mapa);
}

Jogo::Jogo()
{
	indiceTela = MENU;
	player.setSpritesCarregados(false);
}

Jogo::~Jogo()
{
}

void Jogo::testPlayerMapa()
{
	if(!player.estaMovendo())
		{		
			if(teclado.segurando[TECLA_DIR])
			{
				if(mapa.tileECaminhavel(player.getXcentral() + 1.0, player.getYcentral()))
				{
					player.movePara(player.getXcentral() + 1.0, player.getYcentral());
				}
			}
			else if(teclado.segurando[TECLA_ESQ])
			{
				if(mapa.tileECaminhavel(player.getXcentral() - 1.0, player.getYcentral()))
				{
					player.movePara(player.getXcentral() - 1.0, player.getYcentral());
				}
			}
			else if(teclado.segurando[TECLA_CIMA])
			{
				if(mapa.tileECaminhavel(player.getXcentral(), player.getYcentral() - 1.0))
				{
					player.movePara(player.getXcentral(), player.getYcentral() - 1.0);
				}
			}
			else if(teclado.segurando[TECLA_BAIXO])
			{
				if(mapa.tileECaminhavel(player.getXcentral(), player.getYcentral() + 1.0))
				{
					player.movePara(player.getXcentral(), player.getYcentral() + 1.0);
				}
			}
		}	

		//Centraliza o mapa na posição central do Player
		mapa.setPosCentro(player.getXcentral(), player.getYcentral()+10);
	
		//Verifica Colisão com objetos de mudança de cenário
		indiceTelaAtual = indiceTela;
		telaCenario->verificarMudancaMapa(mapa,player, indiceTela); //atualiza o indice da tela
		if(indiceTela != indiceTelaAtual)
			entrouCenario = true;
		else
			entrouCenario = false;

		//	7)	desenhar o tilemap (player eh desenhado junto)
		mapa.desenhar();

}

void Jogo::criaPokemon(int idPokemon)
{
	ifstream arquivo;
	arquivo.open("");

}

void Jogo::inicializar()
{
	uniInicializar(600, 400, false);
	telaMenu = new TelaMenu();
	telaCenario = new TelaCenario();
}

void Jogo::finalizar()
{
	telaMenu->~TelaMenu();
	telaCenario->~TelaCenario();
	uniFinalizar();
}

void Jogo::executar()
{
	while(!teclado.soltou[TECLA_ESC] && !aplicacao.sair)
	{
		uniIniciarFrame();
		controladorTelas();
		uniTerminarFrame();
	}
}