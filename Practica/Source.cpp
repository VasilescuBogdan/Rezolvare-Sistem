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
	unsigned int n;
	std::cin >> n;
	
	Sistem<double> s(n);
	s.Citire_Coeficienti();
	s.Gauss_Partial();
	
	return 0;
}