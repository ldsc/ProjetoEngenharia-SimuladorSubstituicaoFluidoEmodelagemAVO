#include "CRocha.h"

#include <cmath>
#include <fstream>

using namespace std;

void CRocha::Setkdrydado(double _kdrydado){kdrydado=_kdrydado;}
	
double CRocha::Getkdrydado(){return kdrydado;}

void CRocha::Setphi(double _phi){phi=_phi;}
	
double CRocha::Getphi(){return phi;}
	
void CRocha::Setkx(double _kx){kx=_kx;}
	
double CRocha::Getkx(){return kx;}
	
void CRocha::Setrhox(double _rhox){rhox=_rhox;}
	
double CRocha::Getrhox(){return rhox;}
	
void CRocha::Setmix(double _mix){mix=_mix;}
	
double CRocha::Getmix(){return mix;}
		
void CRocha::Setfx(double _fx){fx=_fx;}
	
double CRocha::Getfx(){return fx;}
	
void CRocha::Setky(double _ky){ky=_ky;}
	
double CRocha::Getky(){return ky;}

void CRocha::Setrhoy(double _rhoy){rhoy=_rhoy;}
	
double CRocha::Getrhoy(){return rhoy;}
	
void CRocha::Setmiy(double _miy){miy=_miy;}
	
double CRocha::Getmiy(){return miy;}
	
void CRocha::Setfy(double _fy){fy=_fy;}
	
double CRocha::Getfy(){return fy;}
	
double CRocha::Rhoma()
	{ 
	  rhoma = fx*rhox + fy*rhoy;
	  return rhoma;
	}

double CRocha::Kma()
	{ 
	  /// Utiliza-se a correlação de Voigh-Reuss-Hills
	  double kvoigh;
	  kvoigh = fx*kx + fy*ky;
	  
          double kreuss;    
	  kreuss = 1.0/ (fx/kx + fy/ky);

	  kma = 0.5* (kvoigh + kreuss);
	  return kma;
	}
	  
double CRocha::Mima()
	{ 
	  /// Utiliza-se a correlação de Voigh-Reuss-Hills
	  double mivoigh;
	  mivoigh = fx*(1.0-phi)*kx + fy*(1.0-phi)*ky;
	  
	  double mireuss;
	  mireuss = 1.0/ ((fx*(1.0-phi))/kx + (fy*(1.0-phi))/ky);

	  mima = 0.5* (mivoigh + mireuss);
	  return mima;
	}
	
void CRocha::Entrada_propriedades() 
	{
   	cout << "Entre com o valor da porosidade média da camada em fração: ";
   	cin >> phi;
 	cout << endl;
 
 	cout << "Nessa simulação de teste a matriz será modelada considerando ser composta por 2 componentes: " << "\n"; 
	
	cout << "A tabela com as propriedades de minerais constituintes das rochas mais comuns é apresentada abaixo como auxílio para a entrada dos dados subsequentes" << "\n\n";
	cout << "Adaptado da TABELA 3.1 " << "\n";
	cout << "MINERAL        " << "  .  " << "K (MPa)" << "  .  " << "Mi(Mpa)" << "  .  " << "Rho(g/cm3)" << "\n";
	cout << "Quartzo        " << "  .  " << "  37000" << "  .  " << " 44000 " << "  .  " << "   2.65   " << "\n";
	cout << "Feldspato      " << "  .  " << "  37500" << "  .  " << " 15000 " << "  .  " << "   2.62   " << "\n";
	cout << "Plagioclásio   " << "  .  " << "  75600" << "  .  " << " 25600 " << "  .  " << "   2.63   " << "\n";
	cout << "Argilominerais " << "  .  " << "  30000" << "  .  " << "  8200 " << "  .  " << "   2.80   " << "\n";
	cout << "Calcita        " << "  .  " << "  76800" << "  .  " << " 32000 " << "  .  " << "   2.71   " << "\n";
	cout << "Dolomita       " << "  .  " << "  94900" << "  .  " << " 45000 " << "  .  " << "   2.87   " << "\n";
	cout << "Anidrita       " << "  .  " << "  44800" << "  .  " << " 29100 " << "  .  " << "   2.98   " << "\n";
	cout << "Pirita         " << "  .  " << " 147400" << "  .  " << "135500 " << "  .  " << "   4.93   " << "\n";
	cout << "Hematita       " << "  .  " << " 100200" << "  .  " << " 95200 " << "  .  " << "   5.24   " << "\n\n";
	
   	cout << "Entre com o valor do módulo de incompressibilidade do primeiro componente da matriz da rocha em Mpa: ";
   	cin >> kx;
 	cout << endl;

   	cout << "Entre com o valor da densidade do primeiro componente da matriz da rocha em g/cm3: ";
   	cin >> rhox;
 	cout << endl;
 
   	cout << "Entre com o valor do modulo de cisalhamento do primeiro componente da matriz da rocha em MPa: ";
   	cin >> mix;
 	cout << endl;

  	cout << "Entre com o valor do módulo de incompressibilidade do segundo componente da matriz da rocha em MPa: ";
   	cin >> ky;
 	cout << endl;

   	cout << "Entre com o valor da densidade do segundo componente da matriz da rocha em g/cm3: ";
   	cin >> rhoy;
 	cout << endl;

  	cout << "Entre com o valor do modulo de cisalhamento do segundo componente da matriz da rocha em MPa: ";
   	cin >> miy;
 	cout << endl;

   	cout << "Entre com a fração do primeiro componente na rocha: ";
   	cin >> fx;
 	cout << endl;

   	cout << "Entre com a fração do segundo componente na rocha: ";
   	cin >> fy;
 	cout << endl;
	
	double ftotal;
	ftotal = fx + fy;
	if( ftotal != 1)
	{
	  cout << "Você entrou com frações dos componentes da rocha somadas diferente de 1, o que é fisicamente irreal nesta modelagem, Sugerimos reiniciar a simulação." << "\n\n";
	}
	
   	cout << "Entre com o valor do módulo de incompressibilidade da rocha seca em MPa: ";
   	cin >> kdrydado;
 	cout << endl;	
	}
	
void CRocha::Saida_propriedades()
	{
	 string nome_arquivo_saida;
	 nome_arquivo_saida = "Resultados_rocha.txt";
	 ofstream fout(nome_arquivo_saida.c_str());
         cin.get();
	 
	 fout << "Porosidade: " << phi << "\n";
	 fout << "Módulo de incompressibilidade da rocha seca: " << kdrydado << "\n\n";
	 
	 fout << "PROPRIEDADES DO PRIMEIRO COMPONENTE" << "\n";
	 fout << "Módulo de incompressibilidade:  " << kx << " MPa"<< "\n";
	 fout << "Densidade:  " << rhox << " g/cm3"<< "\n";
	 fout << "Módulo de cisalhamento:  " << mix << " MPa"<< "\n";
	 fout << "Fração de volume na rocha:  " << fx << endl << "\n";
	 
	 fout << "PROPRIEDADES DO SEGUNDO COMPONENTE" << "\n\n";
	 fout << "Módulo de incompressibilidade:  " << ky << " MPa"<< "\n";
	 fout << "Densidade:  " << rhoy << " g/cm3"<< "\n";
	 fout << "Módulo de cisalhamento:  " << miy << " MPa"<< "\n";
	 fout << "Fração de volume na rocha:  " << fy << "\n\n\n";
	 
	 fout << "PROPRIEDADES DA MATRIZ DA ROCHA (CONSIDERANDO OS DOIS COMPONENTES)" << "\n";
	 fout << "Módulo de incompressibilidade:  " << Kma() << " MPa"<< "\n";
	 fout << "Densidade:  " << Rhoma() << " g/cm3"<< "\n";
	 fout << "Módulo de cisalhamento:  " << Mima() << " MPa"<< "\n";
	 
	 cout << "Os dados inicializados e calculados foram salvos no arquivo externo " << nome_arquivo_saida << ".  Aperte ENTER para continuar. "<< "\n";
	 
	 cin.get();
	 
        }
	  
	
	 