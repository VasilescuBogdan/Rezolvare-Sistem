#include "NumarComplex.h"
#include "Sistem.h"

int main()
{
	int n;
	std::string s;

	std::cout << "Da numarul de ecuatii si necunoscute (n < 100) : ";
	try {
		std::cin >> n;
		if (n >= 100)
			throw 0;
	}
	catch (int err)
	{
		do
		{
			std::cout << "Error: matrix dimension not supported! " << std::endl << "Try again!";
			std::cin >> n;
		} while (n >= 100);
	}
	std::cout << "Tipul de sistem (Real sau Complex) : ";
	
	try {
		std::cin >> s;
		if (s != "Real" || s != "Complex")
			throw 0;
	}
	catch (int err)
	{
		do
		{
			std::cout << "Error: Data type not supported!" << std::endl << "Try again!";
			std::cin >> n;
		} while (s != "Real" || s != "Complex");
	}
	
	
	if (s == "Real")
	{
		Sistem<double> S(n);
		std::cout << "Dati coeficientii : " << std::endl;
		S.Citire_Coeficienti();
		std::cout << "Metoda de rezolvare a sistemului (scrie GaussPartial, GaussTotal, Factorizare, Jacobi sau SeidelGauss) : ";
		
		try
		{
			std::cin >> s;
			if (s != "GaussPartial" || s != "GaussTotal" || s != "Factorizare" || s != "Jacobi" || s != "SeidelGauss")
				throw 0;
		}
		catch (int err)
		{
			do 
			{
				std::cout << "Error: Method not supported!" << std::endl << "Try again!";
				std::cin >> s;
			} while (s != "GaussPartial" || s != "GaussTotal" || s != "Factorizare" || s != "Jacobi" || s != "SeidelGauss");
		}
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
			std::cout << "Alegeti eroarea maxima admisa : ";
			std::cin >> e;
			std::cout << "Alegeti numarul maxim de iteratii : ";
			
			std::cin.exceptions(std::istream::failbit);
			try {
				std::cin >> itmax;
				if (!std::cin)
					throw 0;
			}
			catch (int err) {
				do {
					std::cout << "Number of iterations must be integer!" << std::endl << "Try again!";
					std::cin >> itmax;
				} while (!std::cin);
			}
			
			S.Jacobi(x, e, itmax);
		}
		if (s == "SeidelGauss")
		{
			double x[10], e;
			int itmax;
			std::cout << "Presupuneti aproximatia initiala a solutiei : ";
			for (int i = 1; i <= n; i++)
				std::cin >> x[i];
			std::cout << "Alegeti eroarea maxima admisa : ";
			std::cin >> e;
			
			std::cout << "Alegeti numarul maxim de iteratii : ";
			std::cin.exceptions(std::istream::failbit);
			try {
				std::cin >> itmax;
				if (!std::cin)
					throw 0;
			}
			catch (int err) {
				do {
					std::cout << "Number of iterations must be integer!" << std::endl << "Try again!";
					std::cin >> itmax;
				} while (!std::cin);
			}

			S.Seidel_Gauss(x, e, itmax);
		}
	}
	else
		if (s == "COMPLEX" || s == "complex" || s == "Complex")
		{
			Sistem<NumarComplex> S(n);
			std::cout << "Dati coeficientii (partea reala urmata de partea imaginara) : " << std::endl;
			S.Citire_Coeficienti();
			std::cout << "Metoda de rezolvare a sistemului (scrie GaussPartial, GaussTotal, Factorizare, Jacobi sau SeidelGauss) : ";
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
				std::cout << "Alegeti eroarea maxima admisa : ";
				std::cin >> e;
				std::cout << "Alegeti numarul maxim de iteratii : ";
				
				std::cin.exceptions(std::istream::failbit);
				try {
					std::cin >> itmax;
					if (!std::cin)
						throw 0;
				}
				catch (int err) {
					do {
						std::cout << "Number of iterations must be integer!" << std::endl << "Try again!";
						std::cin >> itmax;
					} while (!std::cin);
				}

				S.Jacobi(x, e, itmax);
				
			}
			
			if (s == "SeidelGauss")
			{
				NumarComplex x[10];
				double e;
				int itmax;
				std::cout << "Presupuneti aproximatia initiala a solutiei : ";
				for (int i = 1; i <= n; i++)
					std::cin >> x[i];
				std::cout << "Alegeti eroarea maxima admisa : ";
				std::cin >> e;
				std::cout << "Alegeti numarul maxim de iteratii : ";
				
				std::cin.exceptions(std::istream::failbit);
				try {
					std::cin >> itmax;
					if (!std::cin)
						throw 0;
				}
				catch (int err) {
					do {
						std::cout << "Number of iterations must be integer!" << std::endl << "Try again!";
						std::cin >> itmax;
					} while (!std::cin);
				}

				S.Seidel_Gauss(x, e, itmax);
			}
		}
	

	return 0;
}