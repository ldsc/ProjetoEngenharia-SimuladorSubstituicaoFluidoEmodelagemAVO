#ifndef CPERFIL_H
#define CPERFIL_H

#include<iostream>
#include<vector>

#include "CGnuplot.h"

using namespace std;

/// Classe com atributos e métodos para trabalhar com os perfis 
class CPerfil

{
	public:
		
		string nome_arquivo_entrada; ///Armazena o nome do arquivo com os perfis
		string nome_arquivo_saida;
		vector <double> prof; ///Vetor com os valores de porosidade obtido a partir dos perfis
		vector <double> velp; ///Vetor com os valores de velocidade compressional obtido a partir dos perfis
		vector <double> vels; ///Vetor com os valores de volocidade cisalhante obtido a partir dos perfis
		vector <double> densidade; ///Vetor com os valores de densidade obtido a partir dos perfis
		vector <double> gammaray; ///Vetor com os valores de raios gama obtido a partir dos perfis
		vector <double> porosidade; ///Vetor com os valores de porosidade obtido a partir dos perfis
		
	public:
		CPerfil() {}; ///Construtor
		~CPerfil() {}; ///Destrutor
		void Ler_perfis(); ///Ler os dados de perfis do arquivo externo
		void Plotar_perfis(); ///Plota os perfis carregados
		
};

#endif