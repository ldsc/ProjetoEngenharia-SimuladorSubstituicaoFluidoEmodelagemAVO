#ifndef CAVO_H
#define CAVO_H

#include <iostream>
#include <vector>

#include "CGassmann.h"
#include "CGnuplot.h"

using namespace std;

///Classe com atributos e m�todos para a modelagem AVO.
class CAvo

{
	public:
		double vp2; ///Velocidade compressional da camada inferior
		double vs2; ///Velocidade cisalhante na camada inferior
		double rho2; ///Densidade da camada inferior
		double vp1; ///Velocidade compressional da camada superior
		double vs1; ///Velocidade cisalhante da camada superior
		double rho1; ///Densidade da camada superior
		double deltarho; ///Diferen�a entre as densidades das camadas
		double deltavp; ///Diferen�a entre as velocidades compressionais das camadas
		double deltavs; ///Diferen�a entre as velocidades cisalhantes das camadas
		double vpmed; ///Velocidade compressional m�dia entre as camadas
		double vsmed; ///Velocidade cisalhante m�dia entre as camadas
		double rhomed; ///Densidade m�dia entre as camadas
		vector <double> rshuey; ///Vetor que armazena os valores da refletividade calculado pelo m�todo de Shuey
		vector <double> raki; ///Vetor que armazena os valores da refletividade calculado pelo m�todo de Aki & Richards
		vector <double> rzoeppritz; ///Vetor que armazena os valores da refletividade calculado pelo m�todo de Zoeppritz
		CGassmann* pgassmann; ///Cria ponteiro para a classe CGassmann
		CGnuplot fig3; ///Cria objeto do tipo CGnuplot
		CGnuplot fig12; ///Cria objeto do tipo CGnuplot
		CGnuplot fig13; ///Cria objeto do tipo CGnuplot
		CGnuplot fig14; ///Cria objeto do tipo CGnuplot
	public:
	  
		CAvo(CGassmann* _pgassmann): pgassmann(_pgassmann) {}; ///Construtor
		~CAvo() {}; //Destrutor
		void Setvp2(double _vp2); ///Set
		double Getvp2(); ///Get
		void Setvs2(double _vs2); ///Set
		double Getvs2(); ///Get
		void Setrho2(double _rho2); ///Set
		double Getrho2(); ///Get
		void Setvp1(double _vp1); ///Set
		double Getvp1(); ///Get
		void Setvs1(double _vs1); ///Set
		double Getvs1(); ///Get
		void Setrho1(double _rho1); ///Set
		double Getrho1(); ///Get
		vector <double> Rshuey(); ///C�lculo da refletividade pelo m�todo de Shuey
		vector <double> Raki(); ///C�lculo da refletividade pelo m�todo de Aki & Richards
		vector <double> Rzoeppritz(); ///C�lculo da refletividade pelo m�todo de Zoeppritz
 		void Entrada_saturacao(); ///Usu�rio escolhe o valor da satura��o em que se deseja fazer a modelagem AVO e os valores de Vp, Vs e densidade para essa satura��o s�o selecionados.
		void Entrada_camada_superior(); ///Pede ao usu�rio os dados de Vp, Vs e densidade da camada superior (sugerida como folhelho)
		void Plotar_refletividade(); ///Plota os gr�ficos da refletividade pelos m�todos propostos
		
};

#endif