#ifndef CGASMANN_H
#define CGASSMANN_H

#include "CRocha.h"
#include "CMistura.h"
#include "CAgua.h"
#include "COleo.h"
#include "CPerfil.h"
#include "CGnuplot.h"

#include <iostream>
#include <vector>

using namespace std;

///Classe que contém as equações de Gassmann para a substituição de fluidos
class CGassmann

{
	public:
		vector <double> ksat; ///Vetor que armazena os valores calculados do módulo de incompressibilidade da rocha saturada
		vector <double> rhosat; ///Vetor que armazena os valores calculados da densidade da rocha saturada
		vector <double> vp; ///Vetor que armazena os valores calculados da velocidade P da rocha saturada
		vector <double> vs; ///Vetor que armazena os valores calculados da velocidade S da rocha saturada
		
		vector <double> ksatperfil; ///Vetor que armazena os valores calculados do módulo de incompressibilidade da rocha saturada a partir dos perfis
		vector <double> kdryperfil; ///Vetor que armazena os valores calculados do módulo de incompressibilidade da seca a partir dos perfis
		vector <double> miperfil; ///Vetor que armazena os valores calculados do módulo de cisalhamento da rocha saturada a partir dos perfis
		
		vector <double> ksatperfilsubstituido; ///Vetor que armazena os valores calculados do módulo de incompressibilidade da rocha saturada a partir dos perfis após a substituição de fluidos
		vector <double> rhosatperfilsubstituido; ///Vetor que armazena os valores calculados da densidade da rocha saturada a partir dos perfis após a substituição de fluidos
		vector <double> vpperfilsubstituido; ///Vetor que armazena os valores calculados da velocidade P da rocha saturada após a substituição de fluidos
		vector <double> vsperfilsubstituido; ///Vetor que armazena os valores calculados da velocidade S da rocha saturada após a substituição de fluidos
		
		CMistura* pmistura; ///Ponteiro para objeto da classe CMistura
		CRocha* procha; ///Ponteiro para objeto da classe CRocha
		CPerfil* pperfil; ///Ponteiro para objeto da classe CPerfil
		
		
	public:
	  
		CGassmann(CMistura* _pmistura, CRocha* _procha, CPerfil* _pperfil): pmistura(_pmistura), procha(_procha), pperfil(_pperfil) {}; /// Construtor
		~CGassmann() {}; ///Destrutor
		vector <double> Ksat(); ///Cálculo do vetor de módulo de incompressibilidade da rocha saturada
		vector <double> Rhosat(); ///Cálculo do vetor de densidade da rocha saturada
		vector <double> Vp(); ///Cálculo do vetor de velocidade compressional da rocha saturada
		vector <double> Vs(); ///Cálculo do vetor de velocidade cisalhate da rocha saturada
		void Plotar(); ///Plota os gráficos de Vp, Vs e rho em função da saturação de água

		///Todos os métodos abaixo, com o final "perfil" são métodos utilizados na parte 2 do trabalho onde os calculos iniciais são feitos a partir de dados de perfis.
		vector <double> Ksat_perfil(); ///Cálculo do vetor de módulo de incompressibilidade da rocha saturada a partir dos perfis (considerando 100% saturada com água)
		vector <double> Kdry_perfil(); ///Cálculo do vetor de módulo de incompressibilidade da rocha seca a partir dos perfis
		vector <double> Mi_perfil(); ///Cálculo do vetor de módulo cisalhamento da rocha saturada a partir dos perfis
 		vector <double> Ksat_perfil_substituido(); ///Cálculo do vetor de módulo de incompressibilidade da rocha saturada após a substituição de fluidos (considerando 100% saturada com óleo)
		vector <double> Rhosat_perfil_substituido(); ///Cálculo do vetor de densidade da rocha saturada a partir dos perfis após a substituição de fluidos
		vector <double> Vp_perfil_substituido(); ///Cálculo do vetor de velocidade compressional da rocha saturada após a substituição de fluidos
		vector <double> Vs_perfil_substituido(); ///Cálculo do vetor de velocidade cisalhante da rocha saturada após a substituição de fluidos
		void Plotar_substituicao(); ///Plota os gráficos de Vp, Vs e rho antes e depois da substituição de fluidos
};

#endif