#ifndef CMISTURA_H
#define CMISTURA_H

#include "CAgua.h"
#include "COleo.h"

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

///Classe que representa a mistura de fluidos, chamado fluido efetivo e contém seus atributos e métodos
class CMistura

{
	public:
		vector <double> kfl; ///Vetor com os valores de módulo de incompressibilidade para a mistura de fluidos
		vector <double> rhofl; ///Vetor com os valores de densidade para a mistura de fluidos
		CAgua* pagua; ///Cria ponteiro para objeto da classe CAgua
		COleo* poleo; ///Cria ponteiro para objeto da classe COleo
		
	public:
	  
		CMistura(CAgua* _pagua, COleo* _poleo): pagua(_pagua), poleo(_poleo) {}; ///Construtor	
		~CMistura() {}; ///Destrutor
		vector <double> Rhofl(); ///Cálculo da densidade para mistura de fluidos
		vector <double> Kfl(); ///Cálculo do módulo de incompressibilidade para a mistura de fluidos
		void Entrada_propriedades(); ///Utilizado para pedir o usuário as propriedades dos fluidos 
		void Saida_propriedades(); ///Utilizado para escrever em arquivo externo as propriedades fornecidas e calculadas
};

#endif