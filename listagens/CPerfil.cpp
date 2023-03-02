#include "CPerfil.h"
#include "CGnuplot.h"

#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

void CPerfil::Ler_perfis()

	{
	 double prof_, velp_, vels_, densidade_, gammaray_,  porosidade_;

	 string s;
	 cout<<"Informe o nome do arquivo de entrada (com a extenção): "<<"\n"; 
         cin>>nome_arquivo_entrada;
         cin.get();

         ifstream fin(nome_arquivo_entrada.c_str()); 
 
         fin>>s;fin>>s;fin>>s;fin>>s;fin>>s;fin>>s;
	 
	 while(!fin.eof())
	 
	 {
	      fin>>prof_; fin>>velp_;fin>>vels_;fin>>densidade_;fin>>gammaray_;fin>>porosidade_;
	      
	      prof.push_back(prof_);
	      velp.push_back(velp_);
	      vels.push_back(vels_);
	      densidade.push_back(densidade_);
	      gammaray.push_back(gammaray_);
	      porosidade.push_back(porosidade_);
	 }
	 
	 fin.close();

	 }	 
	 
void CPerfil::Plotar_perfis()
	 
	 {
	  Gnuplot fig4("lines");       
	  fig4.Grid(); 
	  fig4.set_xlabel("Velocidade P (m/s) ");
	  fig4.set_ylabel("Profundidade (m)");
	  fig4 << "set yrange [*:*] reverse";
	  fig4.plot_xy(velp,prof,"Perfil de velocidade P"); 
	  fig4 << "set terminal png size 1200,900";
          fig4 << "set output 'Perfil de Velocidade P.png'";
	  fig4.plot_xy(velp,prof,"Perfil de velocidade P"); 
	  
	  Gnuplot fig5("lines");       
	  fig5.Grid(); 
	  fig5.set_xlabel("Velocidade S (m/s)");
	  fig5.set_ylabel("Profundidade (m)");
	  fig5 << "set yrange [*:*] reverse";
	  fig5.plot_xy(vels,prof,"Perfil de velocidade S");
	  fig5 << "set terminal png size 1200,900";
          fig5 << "set output 'Perfil de Velocidade S.png'";
	  fig5.plot_xy(vels,prof,"Perfil de Velocidade S");
	  
	  Gnuplot fig6("lines");       
	  fig6.Grid(); 
	  fig6.set_xlabel("Raios Gama (API)");
	  fig6.set_ylabel("Profundidade (m)");
	  fig6 << "set yrange [*:*] reverse";
	  fig6.plot_xy(gammaray,prof,"Perfil de raios gama");
	  fig6 << "set terminal png size 1200,900";
          fig6 << "set output 'Perfil de Raios Gama.png'";
	  fig6.plot_xy(gammaray,prof,"Perfil de raios gama");
	  
	  Gnuplot fig7("lines");       
	  fig7.Grid(); 
	  fig7.set_xlabel("Densidade (g/cm3)");
	  fig7.set_ylabel("Profundidade (m)");
	  fig7 << "set yrange [*:*] reverse";
	  fig7.plot_xy(densidade,prof,"Perfil de densidade");
	  fig7 << "set terminal png size 1200,900";
          fig7 << "set output 'Perfil de Densidade.png'";
	  fig7.plot_xy(densidade,prof,"Perfil de densidade");
	  
	  Gnuplot fig8("lines");       
	  fig8.Grid(); 
	  fig8.set_xlabel("Porosidade (fracao)");
	  fig8.set_ylabel("Profundidade (m)");
	  fig8 << "set yrange [*:*] reverse";
	  fig8.plot_xy(porosidade,prof,"Perfil de porosidade");
	  fig8 << "set terminal png size 1200,900";
          fig8 << "set output 'Perfil de Porosidade.png'";
	  fig8.plot_xy(porosidade,prof,"Perfil de porosidade");
	 
	  cin.get();
	  
	 }

