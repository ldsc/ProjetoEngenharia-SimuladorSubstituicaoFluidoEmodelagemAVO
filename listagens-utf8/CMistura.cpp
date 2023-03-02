#include "CMistura.h"

#include <cmath>
#include <vector>
#include <fstream>

using namespace std;
	
vector <double> CMistura::Rhofl()
	
	{ 
          rhofl.resize(101);
	  
	  for(int i = 0; i <= 100; i++)	    
	  {	
          rhofl[i] = ((i/100.0) * pagua->rho + ((1.0-(i/100.0))*poleo->rho));   
	  }
	  
	  return rhofl;
	}
	
vector <double> CMistura::Kfl()
 	
 	{ 
 
	  kfl.resize(101);
 	  for(int i = 0; i <= 100; i++)
 	    
 	  {
 	  kfl[i] = (1.0/(((i/100.0)/pagua->k)+(1.0-(i/100.0))/poleo->k));
 	  }
 	  
 	  return kfl; 
 	 }

void CMistura::Entrada_propriedades()

	{	
 	double _t;
  	cout << "Entre com valor da temperatura in situ em graus Celsius:  ";
  	cin >> _t;
 	cout << endl;
 	pagua->Sett(_t); 
 	poleo->Sett(_t); 

 	double _p;
  	cout << "Entre com valor da pressão de poros em MPa:  ";
  	cin >> _p;
 	cout << endl;
 	pagua->Setp(_p);
 	poleo->Setp(_p);


 	double _sal;
  	cout << "Entre com valor da salinidade da água em ppm:  ";
  	cin >> _sal;
 	cout << endl;
	pagua->Setsal(_sal);


 	double _api;
  	cout << "Entre com valor da densidade em API do óleo:  ";
  	cin >> _api;
 	cout << endl;
	poleo->Setapi(_api);
	
	}
	
void CMistura::Saida_propriedades()
	
	{
	 string nome_arquivo_saida;
	 nome_arquivo_saida = "Resultados_fluidos.txt";
	 ofstream fout(nome_arquivo_saida.c_str());
         cin.get();
	 
	 fout << "PROPRIEDADES DA ÁGUA (SALMOURA)" << "\n";
	 fout << "Pressão:  " << pagua->Getp() << " MPa"<< "\n";
	 fout << "Temperatura:  " << pagua->Gett() << " graus Celsius"<< "\n";
	 fout << "Salinidade:  " << pagua->Getsal() << " ppm"<< "\n";
	 fout << "Densidade:  " << pagua->Rho() << " g/cm3"<< "\n";
	 fout << "Módulo de incompressibilidade:  " << pagua->K() << "MPa" << "\n\n";
	 
	 fout << "PROPRIEDADES DO ÓLEO" << "\n";
	 fout << "Pressão:  " << poleo->Getp() << " MPa"<< "\n";
	 fout << "Temperatura:  " << poleo->Gett() << " graus Celsius"<< "\n";
	 fout << "Densidade API:  " << poleo->Getapi() << " API"<< "\n";
	 fout << "Densidade:  " << poleo->Rho() << " g/cm3"<< "\n";
	 fout << "Módulo de incompressibilidade:  " << poleo->K() << "MPa" << "\n\n";
	 
	 Rhofl();
	 Kfl();
	 
	 fout << "PARA O FLUIDO EFETIVO (ÓLEO + ÁGUA)" << "\n\n";
	 fout << "DENSIDADE" << "\n";
	 
	 for(int i = 0; i <= 100; i++)
	 {
	 fout << "Sw = " << i << "% = " << rhofl[i] << "\n"; 
	 }
	
	 fout << "\nMÓDULO DE INCOMPRESSIBILIDADE" << "\n";
	 
	 for(int i = 0; i <= 100; i++)
	 {
	 fout << "Sw = " << i << "% = " << kfl[i] << "\n"; 
	 }
	 
	 cout << "Os dados inicializados e calculados para os fluidos foram salvos no arquivo externo " << nome_arquivo_saida << ". Aperte ENTER para continuar. " << "\n"; 
	 cin.get();
        }
	  
  