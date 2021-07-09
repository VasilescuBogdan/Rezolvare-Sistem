#include "NumarComplex.h"
#include "Sistem.h"

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