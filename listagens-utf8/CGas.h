#ifndef CGAS_H
#define CGAS_H

#include "CFluido.h"

#include <iostream>

/// Esta classe representa o fluido gás e contém atributos e métodos deste. Herdeira de CFLuido.
class CGas: public CFluido

{
	private:
		double g; //Gravidade específica do gas
		
	public:
	  
		CGas() {}; //Construtor
		~CGas() {}; //Destrutor
		void Setg(double _g); // Set
		double Getg(); // Get
		virtual double Rho(); //Cálculo da densidade da fase óleo
		virtual double K(); //Cálculo do mód. de Incompressibilidade da fase óleo
};

#endif