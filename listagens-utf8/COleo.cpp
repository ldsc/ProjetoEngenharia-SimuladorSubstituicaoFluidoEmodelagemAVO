#include "COleo.h"

#include <cmath>

void COleo::Setapi(double _api){api=_api;}
	
double COleo::Getapi(){return api;}
	
void COleo::Setrs(double _rs){rs=_rs;}

double COleo::Getrs(){return rs;}

double COleo::Rho() /// Considerando óleo "morto" (sem gás dissolvido)
	{  
	  double rhoostd;
	  rhoostd = 141.5/(api + 131.5);
	  double rhoop;
	  rhoop = rhoostd + (0.00277*p -1.71e-7*p*p*p*pow((rhoostd - 1.15),2.0) + (3.4e-4*p));
	  rho = rhoop/(0.972 + 3.81e-4*pow((t + 17.78),1.175));
	  return rho;
	}

double COleo::K()
	{
	  double vo; /// Velocidade na fase óleo
	  vo = 2096.0*pow((rho/(2.6 - rho)),0.5) - 3.7*t + 4.64*p + 0.0115*(4.12*(pow((1.08/rho - 1.0),1.2) -1.0))*t*p;
	  k = (pow(vo,2.0)*rho)/1000.0;
	  return k;
	}
