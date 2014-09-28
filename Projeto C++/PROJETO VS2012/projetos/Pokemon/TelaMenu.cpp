#include "TelaMenu.h"


TelaMenu::TelaMenu()
{
	fonte.carregar("dados/mono.ttf",20);

	_x2 = 482;
	_y2 = 185;

	nome.setFonte(&fonte);
	nome.setCor(0,0,0);

	opcaoF.setFonte(&fonte);
	opcaoF.setCor(70,130,180);

	opcaoM.setFonte(&fonte);
	opcaoM.setCor(70,130,180);

	opcaoM.setTexto("MENINO");
	opcaoF.setTexto("MENINA");

	//posição inicial do retangulo
	setXYiniciais();

	//carrega os sprites
	carregarSprites();

	nomePersonagem[0]='\0';

	contadorLetras = 0; 
	controle = 5;
	sexo=0;
}

TelaMenu::~TelaMenu()
{
	fonte.descarregar();
}

int TelaMenu::getSexo(){ return sexo;}

string TelaMenu::getNome(){ return nomePersonagem; }

void TelaMenu::carregarSprites()
{
	//parte de escolher o sexo
	recursos.carregarSpriteSheet("fundoEscolhaSexo","dados/Menu/EscolhaSexo/fundo.png",1,1);
	fundoEscolhaSexo.setSpriteSheet(recursos.getSpriteSheet("fundoEscolhaSexo"));

	recursos.carregarSpriteSheet("opcoes","dados/Menu/EscolhaSexo/opcoes.png",1,1);
	opcoes.setSpriteSheet(recursos.getSpriteSheet("opcoes"));

	recursos.carregarSpriteSheet("navegacao","dados/Menu/EscolhaSexo/navegacao.png",1,1);
	navegacao.setSpriteSheet(recursos.getSpriteSheet("navegacao"));

	//parte de escolher o nome
	recursos.carregarSpriteSheet("letrasMai","dados/Menu/EscolhaNome/letrasMa.jpg",1,1);
	letrasMai.setSpriteSheet(recursos.getSpriteSheet("letrasMai"));

	recursos.carregarSpriteSheet("letrasMin","dados/Menu/EscolhaNome/letrasMi.jpg",1,1);
	letrasMin.setSpriteSheet(recursos.getSpriteSheet("letrasMin"));

	recursos.carregarSpriteSheet("numeros","dados/Menu/EscolhaNome/numeros.jpg",1,1);
	numeros.setSpriteSheet(recursos.getSpriteSheet("numeros"));	
}

void TelaMenu::setXYiniciais()
{
	this->_x = 80; 
	this->_y = 200;
	this->indiceColuna=0;
	this->indiceLinha=0;
}

void TelaMenu::setValoresLinhaColuna(int l, int c)
{
	totalValoresLinha = l;
	totalValoresColuna = c;
}

//inicializa array de caracteres com os valores da tabela ascii
void TelaMenu::inicializaArrayCaracteres(int tipo) 
{
	int i,j,vinicial,vfinal;

	switch (tipo)
	{
	case 1: //minusculas
		vinicial = 97;
		vfinal = 122;
		break;
	case 2: //numeros
		vinicial = 48;
		vfinal = 57;
		break;
	case 5: //maiusculas
		vinicial = 65;
		vfinal = 90;
		break;
	}

	for(i=0,j=vinicial;i<(totalValoresColuna*totalValoresLinha),j<vfinal;i++,j++)
	{
		if(tipo!=2) // diferente de numeros
		{
			if(i==6)
			{
				caracteres[i]=46;
				j--;
			}
			else if(i==13)
			{
				caracteres[i]=44;
				j--;
			}
			else
			{
				caracteres[i]=j;
			}
		}
		else // se forem os numeros
		{
			switch(i)
			{
			case 10:
				caracteres[i]=33;
				break;
			case 11:
				caracteres[i]=63;
				break;
			case 12:
				caracteres[i]=123;
				break;
			case 13:
				caracteres[i]=125;
				break;
			case 14:
				caracteres[i]=47;
				break;
			case 15:
				caracteres[i]=249;
				break;
			case 16:
				caracteres[i]=34;
				break;
			case 17:
				caracteres[i]=34;
				break;
			case 18:
				caracteres[i]=39;
				break;
			case 19:
				caracteres[i]=39;
				break;
			default:
				caracteres[i]=j;
			}
			
		}

	}
}

void TelaMenu::setArray_SetValores(int linhas, int colunas, int tipo)
{
	setValoresLinhaColuna(linhas,colunas);
	caracteres = new char[totalValoresLinha*totalValoresColuna];
	inicializaArrayCaracteres(tipo);
}

void TelaMenu::DesenhaTexto(char *texto, float x, float y)
{
	nome.setAncora(0,0.5);
	nome.setTexto(texto);
	nome.desenhar(x,y);		
}

void TelaMenu::controleLetras()
{
	if(teclado.pressionou[TECLA_DIR])
	{
		indiceColuna = (indiceColuna+1)%totalValoresColuna;
		if(_x==140)
			_x+=80;

		else if(_x==280)
		{
			if(_y>=200 && _y<=240)
				_x+=110;
			else
				_x+=30;
		}
		else if(_x==310)
			_x-=230;
		else if(_x==390)
			_x-=310;
		else
			_x+=30;
	}

	else if(teclado.pressionou[TECLA_ESQ])
	{
		indiceColuna--;
		if(indiceColuna<0)
			indiceColuna = totalValoresColuna;
		if(_x==80)
		{
			if(_y<=240)
				_x+=310;
			else 
				_x+=230;	
		}
		else if(_x==220)
			_x-=80;
		else if(_x==390)
			_x-=110;
		else
			_x-=30;
	}

	else if(teclado.pressionou[TECLA_CIMA])
	{
		indiceLinha--;
		if(indiceLinha<0)
			indiceLinha=totalValoresLinha;

		if(_y==200)
			_y+=120;
		else if(_y==280)
		{
			if(_x!=310)
				_y-=40;
		}
		else 
			_y-=40;
	}

	else if(teclado.pressionou[TECLA_BAIXO])
	{
		indiceLinha = (indiceLinha+1)%totalValoresLinha;

		if(_y==240)
		{
			if(_x!=390)
				_y+=40;
		}
		else if(_y==320)
		{
			if(_x==310)
				_y-=40;
			else
				_y-=120;
		}
		else 
			_y+=40;

	}
}

void TelaMenu::controleNumeros()
{
	if(teclado.pressionou[TECLA_DIR])
	{
		if(_x==300)
		{
			_x-=220;
		}
		else if(_x==355)
			_x-=275;
		else 
			_x+=55;
	}	

	else if(teclado.pressionou[TECLA_ESQ])
	{
		if(_x==80)
		{
			if(_y!=280)
				_x+=220;
			else
				_x+=275;
		}
		else
			_x-=55;
	}

	else if(teclado.pressionou[TECLA_BAIXO])
	{
		if(_y==280)
		{
			if(_x!=355)
				_y+=40;
		}
		else if(_y==320)
			_y-=120;
		else
			_y+=40;
	}

	else if(teclado.pressionou[TECLA_CIMA])
	{
		if(_y==200)
			_y+=120;
		else if(_y==280)
		{
			if(_x!=355)
				_y-=40;
		}
		else
			_y-=40;
	}
}

int TelaMenu::desenhaInterfaceNome()
{

	uniDepurar("nome",nomePersonagem);
	uniDepurar("sexo",sexo);

	if(teclado.pressionou[TECLA_F1])
	{
		controle=1; //minusculas
		setXYiniciais();
	}
	else if(teclado.pressionou[TECLA_F2])
	{
		controle=2;//numeros
		setXYiniciais();
	}
	else if(teclado.pressionou[TECLA_F3])
	{
		controle=5;//maiusculas
		setXYiniciais();
	}

	letrasMai.desenhar(res_x/2, res_y/2);

	switch(controle)
	{
	case 1:
		letrasMin.desenhar(300,280);
		controleLetras();
		setArray_SetValores(4, 7, controle);
		break;
	case 2:
		numeros.desenhar(300,280);
		controleNumeros();
		setArray_SetValores(4, 5, controle);
		break;
	case 5:
		controleLetras();
		setArray_SetValores(4, 7, controle);
		break;
	}

	//desenha o nome do personagem na tela
	DesenhaTexto(nomePersonagem, 250, 140);

	//desenha o retângulo conforme o usuário mexe nas direcionais
	uniDesenharRetangulo(_x, _y, 25, 35, 255, 0, 0, 255);

	if(teclado.pressionou[TECLA_X])
	{
		if(contadorLetras<=6)// enquanto nao passar do limite vai preenchendo com os valores preenchidos
			nomePersonagem[contadorLetras]=caracteres[indiceColuna+indiceLinha*totalValoresColuna];	

		nomePersonagem[contadorLetras+1]='\0'; // coloca sempre o '\0' depois de cada caracter lido
		contadorLetras++;
	}

	else if(teclado.pressionou[TECLA_C])
	{
		if(contadorLetras>0)
		{
			contadorLetras--;
			nomePersonagem[contadorLetras]=NULL;
		}
	}

	//enter: sai do menu e entra no jogo
	if(teclado.pressionou[TECLA_ENTER])
	{
		if(strlen(nomePersonagem)>3)
		{
			ofstream gravaDados;
			
			char caminho[50]="dados/Arquivos/Players/";
			strcat(nomePersonagem,".txt");
			strcat(caminho,nomePersonagem);
			gravaDados.open(caminho);
			gravaDados  << nomePersonagem << endl;
			gravaDados << sexo << endl;
			gravaDados.close();
			return 2;
		}
		else
	
			return 0;
	}
	else 
		return 0;
}

int TelaMenu::desenhaInterfaceSexo()
{
	fundoEscolhaSexo.desenhar(res_x/2,res_y/2);
	opcoes.desenhar(520,200);

	if(teclado.pressionou[TECLA_BAIXO])
		_y2 = 215;
	else if(teclado.pressionou[TECLA_CIMA])
		_y2 = 185;

	navegacao.desenhar(_x2,_y2);
	opcaoF.desenhar(525,185);
	opcaoM.desenhar(525,215);

	if(teclado.pressionou[TECLA_ENTER])
	{
		if(_y2==185)
			sexo = 1;
		else if(_y2==215)
			sexo = 0;
		proximaTela = desenhaInterfaceNome();
		if(proximaTela==2)
			return 1;
		else
		return 0;
	}
	
	
}

int TelaMenu::controladorTelasIniciais()
{
	telaAtual = desenhaInterfaceSexo();  // 1 sai da tela, 0 continua

	if(telaAtual==1)
		proximaTela = desenhaInterfaceNome(); //1 sai da tela, 0 continua

	if(proximaTela==2)
		return 1;

	else 
		return 0;
}
