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
	
	double e;
	double x[10];
	unsigned int itmax;
	e = 0.01;
	for (int i = 1; i <= n; i++)
		x[i] = 0;
	itmax = 100;


	return 0;
}