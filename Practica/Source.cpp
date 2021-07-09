#include "NumarComplex.h"
#include "Sistem.h"

double mod(double x)
{
	if (x < 0)
		return -x;
	else
		return x;
}

int main()
{
	
	int n;
	std::cin >> n;
	
	Sistem<NumarComplex> s(n);
	s.Citire_Coeficienti();
	s.Factorizare();
	s.Gauss_Partial();
	s.Gauss_Total();


	return 0;
}