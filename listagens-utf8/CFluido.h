#ifndef CFLUIDO_H
#define CFLUIDO_H

#include <iostream>

///Esta classe representa um fluido e é base para os fluidos utilizados no simulador.
class CFluido
{
	public:
		double t; ///Temperatura
		double p; ///Pressão
		double rho; ///Densidade do fluido
		double k; ///Módulo de incompressibilidade do fluido
		
	public:
	  
		CFluido() {}; ///Construtor
		~CFluido() {}; ///Destrutor
		void Sett(double _t); ///Set
		double Gett(); ///Get
		void Setp(double _p); ///Set
		double Getp(); ///Get
		virtual double Rho() = 0; ///Cálculo da densidade 
		virtual double K() = 0; ///Cálculo do mód. de Incompressibilidade 
};

#endif