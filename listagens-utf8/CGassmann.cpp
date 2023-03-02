#include "CGassmann.h"

#include <vector>
#include <cmath>

using namespace std;
	
vector <double> CGassmann::Ksat()

	{   
	  ksat.resize(101);
	  
	  for(int i = 0; i <= 100; i++)
	    {
	      ksat[i] = (procha->kdrydado + ((pow((1.0 - procha->kdrydado/procha->kma),2.0))/(procha->phi/(pmistura->kfl[i]) + (1.0 - procha->phi)/procha->kma - (procha->kdrydado/pow(procha->kma,2.0)))));
	    }

	  return ksat;
	}
	  
vector <double> CGassmann::Rhosat()
	
	{ 
	  rhosat.resize(101);
	  
	  for (int i = 0; i <= 100; i++)
	    {
	    rhosat[i] = (procha->rhoma*(1.0-procha->phi) + pmistura->rhofl[i]*(procha->phi));
	    }
	    
 	  return rhosat;
	}
	
vector <double> CGassmann::Vp()
 	
	{ 
	  vp.resize(101);	
	  
	  for (int i = 0; i <= 100; i++)  
	    {  
	    vp[i] = (sqrt(((ksat[i]*pow(10.0,6.0)) + (((4.0/3.0)*procha->mima)*pow(10.0,6.0)))/(rhosat[i]*pow(10.0,3.0))));	  
	    }
	    
 	  return vp;
 	}
 	
vector <double> CGassmann::Vs()
 	
	{ 
	  vs.resize(101);
	  
	  for (int i = 0; i <= 100; i++)
	  
	    { 
	    vs[i] = (sqrt((procha->mima*pow(10.0,6.0))/(rhosat[i]*pow(10.0,3.0))));
	    }
	  
 	  return vs;
 	}
 	
vector <double> CGassmann::Ksat_perfil()

	{ 
	 
	for(int i = 0; i < pperfil->prof.size(); i++)
	   
	  {  
	    ksatperfil.push_back((pperfil->densidade[i]*(pow(pperfil->velp[i] * 1000.0,2.0) - (4.0/3.0) * pow(pperfil->vels[i] * 1000.0,2.0)))/1000.0);
	  }
	  
	 return ksatperfil;
	}
	
vector <double> CGassmann::Kdry_perfil() 

	{ 
	 
	for(int i = 0; i < pperfil->prof.size(); i++)
	   
	  {  
	    kdryperfil.push_back((ksatperfil[i]*(((pperfil->porosidade[i] * procha->kma)/pmistura->kfl[100]) + 1 - pperfil->porosidade[i]) - procha->kma)/(((pperfil->porosidade[i] * procha->kma)/pmistura->kfl[100]) + ksatperfil[i]/procha->kma - 1.0 - pperfil->porosidade[i]));
	  }

	 return kdryperfil;
	}

vector <double> CGassmann::Mi_perfil() 

	{ 
	 
	for(int i = 0; i < pperfil->prof.size(); i++)
	   
	  {  
	    miperfil.push_back((pperfil->densidade[i] * pow(pperfil->vels[i] * 1000.0,2.0))/1000.0);
	  }
	 
	 return miperfil;
	}
	
vector <double> CGassmann::Ksat_perfil_substituido() 

	{ 
	 
	for(int i = 0; i < pperfil->prof.size(); i++)
	   
	  {  
	    ksatperfilsubstituido.push_back(kdryperfil[i] + (pow(1.0 - (kdryperfil[i]/procha->kma),2.0))/((pperfil->porosidade[i]/pmistura->kfl[0]) + ((1.0 - pperfil->porosidade[i])/procha->kma) - kdryperfil[i]/pow(procha->kma,2.0)));
	  }

	 return ksatperfilsubstituido;
	}

vector <double> CGassmann::Rhosat_perfil_substituido() 

	{ 
	 
	for(int i = 0; i < pperfil->prof.size(); i++)
	   
	  {  
	    rhosatperfilsubstituido.push_back(procha->rhoma * (1.0 - pperfil->porosidade[i]) + pmistura->rhofl[0] * pperfil->porosidade[i]);
	  }

	 return rhosatperfilsubstituido;
	}

vector <double> CGassmann::Vp_perfil_substituido() 

	{ 
	 
	for(int i = 0; i < pperfil->prof.size(); i++)
	   
	  {  
	    vpperfilsubstituido.push_back(sqrt(((ksatperfilsubstituido[i]*pow(10.0,6.0)) + (((4.0/3.0)*miperfil[i])*pow(10.0,6.0)))/(rhosatperfilsubstituido[i]*pow(10.0,3.0))));
	  }
	  
	 return vpperfilsubstituido;
	  
	 }
	
void CGassmann::Plotar()

	{
        
	vector <double> sw;
	
	for (int i = 0; i <= 100; i++) ///Criando o vetor de saturação(0-100)
	  {
	    sw.push_back(i);
	  }
	
	Gnuplot fig("lines");       
        fig.Grid(); 
        fig.set_xlabel("Saturacao ");
        fig.set_ylabel("Velocidade P ");
	fig.plot_xy(sw,vp,"Variacao da velocidade da onda P com o aumento da saturacao");
	
	Gnuplot fig1("lines");       
        fig1.Grid(); 
        fig1.set_xlabel("Saturacao ");
        fig1.set_ylabel("Velocidade S");
	fig1.plot_xy(sw,vs,"Variacao da velocidade da onda S com o aumento da saturacao");
	
	Gnuplot fig2("lines");       
        fig2.Grid(); 
        fig2.set_xlabel("Saturacao ");
        fig2.set_ylabel("Densidade");
	fig2.plot_xy(sw,rhosat,"Variacao da densidade com o aumento da saturacao");
	
	cin.get();
	
	}
	
void CGassmann::Plotar_substituicao()

	{

	    vector <double> velp1;
	    
	    for (int i = 0; i < pperfil->prof.size(); i++)
	      {
	      velp1.push_back
	      (pperfil->velp[i]*1000.0);
	      }  
	    
	    Gnuplot fig10("lines");
	    fig10.Grid(); 
	    fig10.set_xlabel("Velocidade P (m/s)");
	    fig10.set_ylabel("Profundidade (m) ");
	    fig10.plot_xy(velp1,pperfil->prof," Velocidade P (antes da substituicao: agua)");
 	    fig10.replot();
 	    fig10.plot_xy(vpperfilsubstituido,pperfil->prof," Velocidade P (apos a substituicao: oleo)");
	    
	    cin.get();
	
	}