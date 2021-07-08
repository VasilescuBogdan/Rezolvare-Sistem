#include "NumarComplex.h"
#include "Sistem.h"

int main()
{
	unsigned int n;
	std::cin >> n;
	
	Sistem<double> s(n);
	s.Citire_Coeficienti();
	s.Gauss_Partial();
	
	return 0;
}