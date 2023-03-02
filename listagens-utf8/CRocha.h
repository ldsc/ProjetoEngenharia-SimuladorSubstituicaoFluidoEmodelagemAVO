#ifndef CROCHA_H
#define CROCHA_H

#include <iostream>
#include <fstream>

///Classe que representa a rocha, com seus atributos e métodos
class CRocha

{
	public:
		
		double kdrydado; ///Módulo de incompressibilidade fornecido
		double phi; ///Porosidade
		double kx; ///Módulo de incompressibilidade do primeiro componente
		double ky; ///Módulo de incompressibilidade do segundo componente
		double rhox; ///Densidade do primeiro componente
		double rhoy; ///Densidade do segundo componente
		double mix; ///Módulo de cisalhamento do primeiro componente
		double miy; ///Módulo de cisalhamento do segundo componente
		double fx; ///Fração do primeiro componente na rocha
		double fy; ///Fração do segundo componente na rocha
		double kma; ///Módulo de incompressibilidade da matriz considerando os dois componentes
		double rhoma; ///Densidade da matriz considerando os dois componentes
		double mima; ///Módulo de cisalhamento da matriz considerando os dois componentes
		
	public:
	  
		CRocha() {}; ///Construtor 
		~CRocha() {}; ///Destrutor
		void Setkdrydado(double _kdrydado); 
		double Getkdrydado(); ///Get
		void Setphi(double _phi); ///Set
		double Getphi(); ///Get
		void Setkx(double _kx); ///Set
		double Getkx(); ///Get
		void Setky(double _ky); ///Set
		double Getky(); ///Get 
		void Setrhox(double _rhox); ///Set
		double Getrhox(); ///Get 
		void Setrhoy(double _rhoy); ///Set
		double Getrhoy(); ///Get
		void Setmix(double _mix); ///Set
		double Getmix(); ///Get
		void Setmiy(double _miy); ///Set
		double Getmiy(); ///Get
		void Setfx(double _fx); ///Set
		double Getfx(); ///Get
		void Setfy(double _fy); ///Set
		double Getfy(); ///Get 
		double Rhoma(); ///Cálculo da densidade para a matriz da rocha
		double Kma(); ///Cálculo do módulo de incompressibilidade para a matriz da rocha
		double Mima(); ///Cálculo do módulo de cisalhamento para a matriz da rocha
		void Entrada_propriedades(); ///Utilizado para pedir ao usuário as propriedades da rocha e seus componentes
		void Saida_propriedades(); ///Utilizado para escrever em arquivo externo as propriedades fornecidas e calculadas
};

#endif