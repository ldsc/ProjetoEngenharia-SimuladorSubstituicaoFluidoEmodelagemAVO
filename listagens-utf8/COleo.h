#ifndef COLEO_H
#define COLEO_H

#include "CFluido.h"

#include <iostream>

/// Esta classe representa o fluido óleo e contém atributos e métodos deste. Herdeira de CFLuido.
class COleo: public CFluido
{
	private:
		double api; /// Densidade em API
		double rs; /// Razão de solubilidade
		
	public:
		COleo() {}; /// Construtor
		~COleo() {}; /// Destrutor
		void Setapi(double _api); /// Set
		double Getapi(); ///Get
		void Setrs(double _rs); ///Set
		double Getrs(); ///Get
		virtual double Rho(); ///Cálculo da densidade da fase óleo
		virtual double K(); ///Cálculo do mód. de Incompressibilidade da fase óleo
};

#endif