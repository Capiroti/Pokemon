#include "TelaMenu.h"

float xNome=230;

char maiusculas[28] = {'A','B','C','D','E', 'F','.',
						 'G','H', 'I', 'J', 'K', 'L',',',
						 'M','N','O','P','Q','R','S',
						 'T','U','V','W','X','Y','Z'};

int contadorLetras=0;



void TelaMenu::setXYiniciais()
{
	this->_x = 80; 
	this->_y = 200;
}

TelaMenu::TelaMenu()
{
	fonte.carregar("dados/mono.ttf",20);
	nome.setFonte(&fonte);
	nome.setCor(0,0,0);

	//posição inicial do retangulo
	setXYiniciais();

	controle = 5;

	totalValoresColuna=7;
	totalValoresLinha=4;

	indiceColuna=0;
	indiceLinha=0;

	nomePersonagem[0]='\0';
	
	recursos.carregarSpriteSheet("fundo","dados/Menu/menu.jpg",1,1);
	background.setSpriteSheet(recursos.getSpriteSheet("fundo"));

	recursos.carregarSpriteSheet("menu1","dados/Menu/letras.jpg",1,1);
	letras.setSpriteSheet(recursos.getSpriteSheet("menu1"));
	
	recursos.carregarSpriteSheet("menu2","dados/Menu/numeros.jpg",1,1);
	numeros.setSpriteSheet(recursos.getSpriteSheet("menu2"));	
}

TelaMenu::~TelaMenu()
{
	fonte.descarregar();
}

void TelaMenu::DesenhaTexto(char *texto, float x, float y, float distancia)
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
			if(_y!=280)
				_x-=220;
			else
				_x+=55;
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

int TelaMenu::desenhaInterface()
{
	uniDepurar("nome",nomePersonagem);
	if(teclado.pressionou[TECLA_F1])
	{
		controle = 1; //letras
		setXYiniciais();
	}
	else if(teclado.pressionou[TECLA_F2])
	{
		controle = 2;//numeros
		setXYiniciais();
	}
	else if(teclado.pressionou[TECLA_F3])
	{
		controle =5;//fundo
		setXYiniciais();
	}

	background.desenhar(res_x/2, res_y/2);

	switch(controle)
	{
	case 1:
		letras.desenhar(300,280);
		controleLetras();
		break;
	case 2:
		numeros.desenhar(300,280);
		controleNumeros();
		break;
	case 5:
		controleLetras();
		break;
	}

	if(teclado.pressionou[TECLA_ENTER])
	{
		if(contadorLetras<=6)
		{
			nomePersonagem[contadorLetras]=maiusculas[indiceColuna+indiceLinha*totalValoresColuna];	
			nomePersonagem[contadorLetras+1]='\0';
			contadorLetras++;
		}
	}
	DesenhaTexto(nomePersonagem, 250, 140, 40);

	uniDesenharRetangulo(_x, _y, 25, 35, 255, 0, 0, 255);

	if(mouse.pressionou[BOTAO_DIR])
		return 1;
	else
		return 0;

}


