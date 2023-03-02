#include "CAvo.h"

#include <cmath>
#include <vector>

using namespace std;

void CAvo::Setvp2(double _vp2){vp2=_vp2;}
	
double CAvo::Getvp2(){return vp2;}

void CAvo::Setrho2(double _rho2){rho2=_rho2;}
	
double CAvo::Getrho2(){return rho2;}

void CAvo::Setvs2(double _vs2){vs2=_vs2;}
	
double CAvo::Getvs2(){return vs2;}

void CAvo::Setvp1(double _vp1){vp1=_vp1;}
	
double CAvo::Getvp1(){return vp1;}

void CAvo::Setrho1(double _rho1){rho1=_rho1;}
	
double CAvo::Getrho1(){return rho1;}

void CAvo::Setvs1(double _vs1){vs1=_vs1;}
	
double CAvo::Getvs1(){return vs1;}

vector <double> CAvo::Rshuey()
	{  
 	 deltarho = rho2 - rho1;
 	 deltavp = vp2 - vp1;
 	 deltavs = vs2 - vs1;
 	 rhomed = (rho2 + rho1)/2.0;
 	 vpmed = (vp2 + vp1)/2.0;
 	 vsmed = (vs2 + vs1)/2.0;
	  
	 rshuey.resize(41);
	 for(int i = 0; i <= 40; i++)
	    
	  {    
	  rshuey[i] = (0.5*(deltavp/vpmed + deltarho/rhomed) + (0.5*(deltavp/vpmed) - 2.0*(pow(vsmed,2.0)/pow(vpmed,2.0))*((deltarho/rhomed) + ((2.0*deltavs)/vsmed)))*pow(sin((i*3.14)/(180.0)),2.0));
	  }

	 return rshuey;
	 }

vector <double> CAvo::Raki()

	 {  
 	 deltarho = rho2 - rho1;
 	 deltavp = vp2 - vp1;
 	 deltavs = vs2 - vs1;
 	 rhomed = (rho2 + rho1)/2.0;
 	 vpmed = (vp2 + vp1)/2.0;
 	 vsmed = (vs2 + vs1)/2.0;
	 
	 raki.resize(41);
	 for(int i = 0; i <= 40; i++)
	    
	  {   
	  double alfa, beta, gama;
	  
	  alfa = 1.0/(2.0*pow(cos((i*3.14)/(180.0)),2.0));
	  
	  beta = -4.0 * ((pow(vsmed,2.0))/(pow(vpmed,2.0))) * pow(sin((i*3.14)/(180.0)),2.0);
	  
	  gama = 0.5 - 2 * ((pow(vsmed,2))/(pow(vpmed,2))) * pow(sin((i*3.14)/(180.0)),2.0);
	    
	  raki[i] = (deltavp/vpmed*alfa + deltavs/vsmed*beta + deltarho/rhomed*gama);
	  }

	 return raki;
	
	 }

vector <double> CAvo::Rzoeppritz() 
	  
	 {
	 double r0,r1,r2,r3,r4;
 	 r0 = 1.0;
	 r1 = vp2/vp1;
	 r2 = vs1/vp1;
	 r3 = vs2/vp1;
	 r4 = rho2/rho1;
	  
	 rzoeppritz.resize(41);
	  
	 for(int i = 0; i <= 40; i++)
	    
	  {    
	  double t0,t1,t2,t3;
	  
	  t0 = (r0 * sin((i*3.14)/(180.0)))/(pow((1 - pow(r0,2.0) * pow(sin((i*3.14)/(180.0)),2.0)),0.5));
	  t1 = (r1 * sin((i*3.14)/(180.0)))/(pow((1 - pow(r1,2.0) * pow(sin((i*3.14)/(180.0)),2.0)),0.5));
	  t2 = (r2 * sin((i*3.14)/(180.0)))/(pow((1 - pow(r2,2.0) * pow(sin((i*3.14)/(180.0)),2.0)),0.5));
	  t3 = (r3 * sin((i*3.14)/(180.0)))/(pow((1 - pow(r3,2.0) * pow(sin((i*3.14)/(180.0)),2.0)),0.5));
	  
	  double q,a,b;
	  
	  q = 2.0 * pow(sin((i*3.14)/(180.0)),2.0) * (r4  * pow(r3,2.0) - pow(r2,2.0));
	  a = pow((r4-q),2.0) * t1 * t3;
	  b = pow((r4-q-1.0),2.0)*t0*t1*t2*t3;
	  
	  rzoeppritz[i] = ((pow(q,2.0) - r4*t0*t3 + r4*t1*t2 - ((pow((1.0 + q),2.0))*t0*t2) + a + b)/(((pow((1.0 + q),2.0)*t0*t2) + a + b) + (pow(q,2.0) + r4*t0*t3 + r4*t1*t2)));
	  }
	  
	  return rzoeppritz;
	
	  }

void CAvo::Entrada_camada_superior()
	  
	  { 
  	   cout << "Entre com valor de Vp da camada superior em m/s:  ";
  	   cin >> vp1;
 	   cout << endl;
	   
  	   cout << "Entre com valor de Vs da camada superior em m/s:  ";
  	   cin >> vs1;
 	   cout << endl; 	   
	   
  	   cout << "Entre com valor da densidade da camada superior em m/s:  ";
  	   cin >> rho1;
 	   cout << endl;  
	   cin.get();
	  }
	  
void CAvo::Plotar_refletividade()
	  {
	    
	  cout << "Pressione ENTER para continuar." << "\n";
	  
	  vector <double> teta;
	
	    for (int i = 0; i <= 40; i++)
	    
	      {
	      teta.push_back(i);
	      }
	      
	   int saturacao;
	   double vp2;
	   double vs2;
	   double rho2;
	   
	  saturacao = 0;
	   vp2 = pgassmann->vp[saturacao];
 	   Setvp2(vp2);
	   vs2 = pgassmann->vs[saturacao];
 	   Setvs2(vs2);
	   rho2 = pgassmann->rhosat[saturacao];
 	   Setrho2(rho2);
	  
	  fig3.set_style("lines");
	  fig3.Grid(); 
	  fig3.set_title("Modelagem AVO para reservatorio 100% saturado com oleo.");
	  fig3.set_xlabel("Angulo (graus) ");
	  fig3.set_ylabel("Refletividade ");
	  fig3.plot_xy(teta,Rshuey()," Refletividade vs Angulo: Metodo de Shuey");
	  fig3.replot();
	  fig3.plot_xy(teta,Raki()," Refletividade vs Angulo: Metodo de Aki & Richards");
	  fig3.replot();
	  fig3.plot_xy(teta,Rzoeppritz()," Refletividade vs Angulo: Metodo de Zoeppritz");
	  
	  saturacao = 100;
	   vp2 = pgassmann->vp[saturacao];
 	   Setvp2(vp2);
	   vs2 = pgassmann->vs[saturacao];
 	   Setvs2(vs2);
	   rho2 = pgassmann->rhosat[saturacao];
 	   Setrho2(rho2);
	  
	  fig13.set_style("lines");
	  fig13.Grid();
	  fig13.set_title("Modelagem AVO para reservatorio 100% saturado com agua.");
	  fig13.set_xlabel("Angulo (graus) ");
	  fig13.set_ylabel("Refletividade ");
	  fig13.plot_xy(teta,Rshuey()," Refletividade vs Angulo: Metodo de Shuey");
	  fig13.replot();
	  fig13.plot_xy(teta,Raki()," Refletividade vs Angulo: Metodo de Aki & Richards");
	  fig13.replot();
	  fig13.plot_xy(teta,Rzoeppritz()," Refletividade vs Angulo: Metodo de Zoeppritz");
 	  cin.get();
	  
	  }
