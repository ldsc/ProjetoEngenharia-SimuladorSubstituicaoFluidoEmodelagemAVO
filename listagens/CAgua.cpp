#include "CAgua.h"

#include <cmath>

void CAgua::Setsal(double _sal){sal=_sal;}
	
double CAgua::Getsal(){return sal;}

double CAgua::Rho()
	{ 
	  double salu; ///Salinidade em unidades corrigidas
	  salu = sal/1000000.0;
	  double rhow; ///Densidade da água doce
	   double t2 = t*t; double t3 = t2*t; double t4 = t2*t2;
	   double p2 = p*p;double p3 = p*p2;double p4 = p2*p2;
	  rhow = 1.0 + 1.0e-6*(-80.0*t - 3.3*t2 + 0.00175*t3 + 489.0*p- 2.0*t*p + 0.016*t2*p -1.3e-5*t3*p- 0.333*p2 - 0.002*t*p2);
	  rho = rhow + salu*( 0.668 + 0.44*salu + 1.0e-6*(300.0*p- 2400.0*p*salu + t*( 80.0 + 3.0*t- 3300.0*salu - 13.0*p + 47.0*p*salu)));
	  return rho;
	}
	
double CAgua::K()
	{
	  double salu; ///Salinidade em unidades corrigidas
	  salu = sal/1000000.0;
	  double vw; ///Velocidade na água doce
           double t2 = t*t; double t3 = t2*t; double t4 = t2*t2;
	   double p2 = p*p;double p3 = p*p2;double p4 = p2*p2;
	  vw = 1402.85 + 1.524*p + 3.437e-3*p2 -1.197e-5*p3 + 4.871*t -0.0111*t*p + 1.739e-4*t*p2 -1.628e-6*t*p3 - 0.04783*t2 + 2.747e-4*t2*p -2.135e-6*t2*p2 + 1.237e-8*t2*p3 + 1.487e-4*t3 -6.503e-7*t3*p -1.455e-8*t3*p2 + 1.327e-10*t3*p3 - 2.197e-7*t4 + 7.987e-10*t4*p + 5.230e-11*t4*p2 - 4.614e-11*t4*p3;
	  double vb; ///Velocidade na água salina
	  vb = vw + salu*(1170.0 - 9.6*t + 0.055*t2 - 8.5e-5*t3 + 2.6*p - 0.0029*t*p - 0.0476*p2 + pow(salu,1.5)*(780.0 - 10.0*p + 0.16*p2) - 1820.0*pow(salu,2.0));
	  k = (pow(vb,2.0)*rho)/1000.0;
	  return k;
	}
	