#include "CGas.h"

#include <cmath>

void CGas::Setg(double _g){g=_g;}
	
double CGas::Getg(){return g;}
	
double CGas::Rho()
	{ 
	  
	double tk; ///Temperatura em Kelvin
	tk = t + 273.17;
	  
	double pr; ///Pressão reduzida
	pr = p/(4.892 - 0.4048*g);
	  
	double tr; ///Temperatura reduzida
	tr = tk/(94.72 + 170.75*g);
	  
	double r=8.31441; //Constante dos gases 
	 
	double a;
	a = 0.03 + 0.00527*pow((3.5 - tr),3.0);
	 
	double b;
	b = 0.642*tr - 0.007*pow(tr,4.0) - 0.52;
	  
	double c;
	c = 0.109*pow((3.85 - tr),2.0);
	  
	double d;
	d = exp(-1.0*(0.45 + 8.0*pow((0.56 - (1.0/tr)),2.0))*(pow(pr,1.2)/tr));
	  
	double z; ///Fator de Incompressibilidade
	z = a*pr + b + c*d;
	  
	rho = (28.8*g*p)/(z*r*tk);
	  
	return rho;
	  
	}
	  
double CGas::K() //Correlação apresentando erros
	 
	{
	  
	double pr; ///Pressão reduzida
	pr = p/(4.892 - 0.4048*g);
	  
	double gamma;
	gamma = 0.85 + (5.6/(pr + 2.0)) + (27.1/pow((pr + 3.5),2.0) - 8.7*exp(-0.65*(pr +1.0)));
	  
	double tk; ///Temperatura em Kelvin
	tk = t + 273.17;
	  
	double tr; ///temperatura reduzida
	tr = tk/(94.72 + 170.75*g);
	  
	double m;
	m = 1.2*(-1*(0.45 + 8.0*pow((0.56 - (1.0/tr)),2.0)*(pow(pr,0.2)/tr)));
	  
	double c;
	c = 0.109*pow((3.85 - tr),2.0);
	  
	double d;
	d = exp(-1.0*(0.45 + 8.0*pow((0.56 - (1.0/tr)),2.0))*(pow(pr,1.2)/tr));
	  
	double b;
	b = 0.642*tr - 0.007*pow(tr,4.0) - 0.52;
	  
	double a;
	a = 0.03 + 0.00527*pow((3.5 - tr),3.0);
	  
	double z; ///Fator de Incompressibilidade
	z = a*pr + b + c*d;
	  
	double f;
	f = c*d*m + a;
	  
	double kg;
	k = (p*gamma)/(1.0 - pr/(z*f));
	  
	return k;
	}
	  