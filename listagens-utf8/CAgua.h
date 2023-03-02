#ifndef CAGUA_H
#define CAGUA_H

#include "CFluido.h"

#include <iostream>

/// Esta classe representa o fluido água e contém atributos e métodos deste. Herdeira de CFLuido.
class CAgua: public CFluido

{
	private:
		double sal; ///Salinidade 
		
	public:
	  
		CAgua() {}; ///Construtor
		~CAgua() {}; ///Destrutor
		void Setsal(double _sal); ///Set
		double Getsal();  ///Get
		virtual double Rho(); ///Cálculo da densidade da fase salmoura (brine)
		virtual double K(); ///Cálculo do mód. de Incompressibilidade da fase salmoura (brine)
};

#endif