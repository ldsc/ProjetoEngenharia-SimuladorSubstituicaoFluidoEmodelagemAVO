#include "CFluido.h"
#include "CAgua.h"
#include "COleo.h"
#include "CGas.h"
#include "CGnuplot.h"
#include "CMistura.h"
#include "CRocha.h"
#include "CPerfil.h"
#include "CAvo.h"
#include "CHelp.h"

using namespace std;

int main()

{
        /// Criando os objetos
	CAgua agua;
	COleo oleo;
 	CRocha rocha;
	CPerfil perfil;
	CMistura mistura(&agua,&oleo);
 	CGassmann gassmann(&mistura, &rocha, &perfil);
	CAvo avo(&gassmann);
	CHelp help;
	
	/// Cabeçalho
	cout << "\n-------------------------------------------------------" << endl;
	cout << "SIMULADOR DE SUBSTITUIÇÃO DE FLUIDOS E DE MODELAGEM AVO" << endl << endl;
	cout << "UNIVERSIDADE ESTADUAL DO NORTE FLUMINENSE DARCY RIBEIRO" << endl;
	cout << "....................JANEIRO DE 2016...................." << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "AUTORES: RAFAEL BOECHAT E MAURÍCIO MATOS" <<  endl;
	cout << "VERSÃO 1.0" <<  endl << endl;
	
	int resp;
	cout << "Qual simulação deseja realizar?" << endl;
	cout << "Digite 1 para Substituição de fluidos e modelagem AVO." << endl;
	cout << "Digite 2 para Substituição de fluidos por meio do carregamento de dados de perfis." << endl;
	cout << "Digite 3 para Ajuda." << endl;
	cin >> resp;
      
	switch (resp)
	  
	{
	
	  case 1:

	    cout << "\n---PARTE A1 - PROPRIEDADES DOS FLUIDOS PELAS EQUAÇÕES DE BATZLE & WANG---" << endl << endl;

	    mistura.Entrada_propriedades(); ///Pedimos ao usuário os dados de entrada (p, t, api, salinidade...) dos fluidos.
	    
	    mistura.Saida_propriedades(); ///As propriedades dos fluidos são calculadas e salvas em um arquivo externo.
	    
	    cout << "\n---PARTE A2 - PROPRIEDADES DA ROCHA E FLUIDOS PELAS EQUAÇÕES DE GASSMANN--" << endl << endl;
		    
 	    rocha.Entrada_propriedades(); ///Pedimos ao usuário os dados de entrada da rocha e seus componentes.
	    
	    rocha.Saida_propriedades(); ///As propriedades da rocha são calculadas e salvas em um arquivo externo.
    
	    ///Calculo das propriedades da rocha saturada
	    gassmann.Ksat();
	    gassmann.Rhosat();
	    gassmann.Vp();
	    gassmann.Vs();
	    
	    gassmann.Plotar(); ///Plotando os gráficos das velocidades e densidade com o aumento da saturação.
	    
	    cout << "\n---PARTE A3 - MODELAGEM AVO---" << endl << endl;

	    avo.Entrada_camada_superior(); ///Pedimos ao usuário os valores de Vp, Vs e densidade da camada superior.
	    
	    avo.Plotar_refletividade(); ///Plota em um mesmo gráfico as refletividades calculadas pelos três métodos.
	    
	    cout << "Simulação 1 terminada!\a" << endl;
	    cout << "Aperte ENTER para sair\a" << endl;
	
	  break;
	  
	
	  case 2: 
	
	    cout << "\n\n---PARTE B1 - CARREGANDO E PLOTANDO OS PERFIS---" << endl << endl;
	    
	    perfil.Ler_perfis(); ///Carrega os perfis
	    
	    perfil.Plotar_perfis(); ///Plota os perfis e salva-os externamente.

	    cout << "\n---PARTE B2 -PROPRIEDADES DOS FLUIDOS PELAS EQUAÇÕES DE BATZLE & WANG---" << endl << endl;

	    mistura.Entrada_propriedades(); ///Pedimos ao usuário os dados de entrada (p, t, api, salinidade...) dos fluidos.
	    
	    mistura.Saida_propriedades(); ///As propriedades dos fluidos são calculadas e salvas em um arquivo externo.
	
	    cout << "\n---PARTE B3 - PROPRIEDADES DA ROCHA E FLUIDOS PELAS EQUAÇÕES DE GASSMANN---" << endl << endl;

	    rocha.Entrada_propriedades(); ///Pedimos ao usuário os dados de entrada da rocha e seus componentes.
	
	    rocha.Saida_propriedades(); ///As propriedades da rocha são calculadas e salvas em um arquivo externo.

	    cout << "\n---PARTE B4 - REALIZANDO A SUBSTITUIÇÃO DE FLUIDOS NO ARQUIVO CARREGADO---" << endl << endl;
	    
	    ///Cálculo das propriedades do perfil antes da substituição.
	    gassmann.Ksat_perfil();
	    gassmann.Kdry_perfil();
	    gassmann.Mi_perfil();
	    ///Cálculo das propriedades do perfil após a substituição.
	    gassmann.Ksat_perfil_substituido();
	    gassmann.Rhosat_perfil_substituido();
	    gassmann.Vp_perfil_substituido();
	    
	    gassmann.Plotar_substituicao(); ///Plota o perfil das velocidades antes e após a substituição de fluidos.

	    cout << "Simulação 2 terminada!\a" << endl;
	    cout << "Aperte ENTER para sair\a" << endl;
	 
	  break;
	  
	  case 3:
	    
	    help.Ajuda();
	    cout << "Aperte ENTER para sair\a" << endl;
	    
	  break;
	 
	  default:
	  
	  cout << "Opção incorreta!\a" << endl;
	  cout << "Aperte ENTER para sair\a" << endl;
	 
	  break;
	
	}

	cin.get();
	return 0;
	
}
