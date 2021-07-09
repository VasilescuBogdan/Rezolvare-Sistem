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
	
	Sistem<double> s(n);
	s.Citire_Coeficienti();
	s.Gauss_Total();
	
	double e;
	double x[10];
	unsigned int itmax;
	e = 0.00001;
	for (int i = 1; i <= n; i++)
		x[i] = 0;
	itmax = 10;

	//s.Jacobi(x, e, itmax);
	//s.Seidel_Gauss(x, e, itmax);

	return 0;
}