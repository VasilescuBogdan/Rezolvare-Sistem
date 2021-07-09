#include "NumarComplex.h"
#include "Sistem.h"

int main()
{
	int n;
	std::string s;
	std::cout << "Da numarul de ecuatii si necunoscute : ";
	std::cin >> n;
	std::cout << "Tipul de sistem (Real sau Complex) : ";
	std::cin >> s;
	
	if (s == "real" || s == "REAL")
	{
		Sistem<double> S(n);
		S.Citire_Coeficienti();
		std::cout << "Metoda de rezolvare a sistemului (scrie GaussPartial, GaussTotal, Factorizare, Jacobi sau Seidel-Gauss) : ";
		std::cin >> s;
		if (s == "GaussPartial")
			S.Gauss_Partial();
		if (s == "GaussTotal")
			S.Gauss_Total();
		if (s == "Factorizare")
			S.Factorizare();
		if (s == "Jacobi")
		{
			double x[10], e;
			int itmax;
			std::cout << "Presupuneti aproximatia initiala a solutiei : ";
			for (int i = 1; i <= n; i++)
				std::cin >> x[i];
			std::cout << "Alegeti eroarea minima admisa : ";
			std::cin >> e;
			std::cout << "Alegeti numarul maxim de iteratii : ";
			std::cin >> itmax;
			S.Jacobi(x, e, itmax);
		}
		if (s == "Seidel-Gauss")
		{
			double x[10], e;
			int itmax;
			std::cout << "Presupuneti aproximatia initiala a solutiei : ";
			for (int i = 1; i <= n; i++)
				std::cin >> x[i];
			std::cout << "Alegeti eroarea minima admisa : ";
			std::cin >> e;
			std::cout << "Alegeti numarul maxim de iteratii : ";
			std::cin >> itmax;
			S.Seidel_Gauss(x, e, itmax);
		}
	}
	else
		if (s == "COMPLEX" || s == "complex")
		{
			Sistem<NumarComplex> S(n);
			S.Citire_Coeficienti();
			std::cout << "Metoda de rezolvare a sistemului (scrie GaussPartial, GaussTotal, Factorizare, Jacobi sau Seidel-Gauss) : ";
			std::cin >> s;
			if (s == "GaussPartial")
				S.Gauss_Partial();
			if (s == "GaussTotal")
				S.Gauss_Total();
			if (s == "Factorizare")
				S.Factorizare();
			if (s == "Jacobi")
			{
				NumarComplex x[10]; 
				double e;
				int itmax;
				std::cout << "Presupuneti aproximatia initiala a solutiei : ";
				for (int i = 1; i <= n; i++)
					std::cin >> x[i];
				std::cout << "Alegeti eroarea minima admisa : ";
				std::cin >> e;
				std::cout << "Alegeti numarul maxim de iteratii : ";
				std::cin >> itmax;
				S.Jacobi(x, e, itmax);
				if (s == "Seidel-Gauss")
				{
					NumarComplex x[10];
					double e;
					int itmax;
					std::cout << "Presupuneti aproximatia initiala a solutiei : ";
					for (int i = 1; i <= n; i++)
						std::cin >> x[i];
					std::cout << "Alegeti eroarea minima admisa : ";
					std::cin >> e;
					std::cout << "Alegeti numarul maxim de iteratii : ";
					std::cin >> itmax;
					S.Seidel_Gauss(x, e, itmax);
				}
			}
		}
	

	return 0;
}