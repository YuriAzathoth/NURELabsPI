#include <cstdio>
#include "CSeller.h"
using namespace std;

int main()
{
	CSeller Seller;
	Seller + "Ford" + "Daewoo" + "BMW" + "Mercedes";

	for (size_t i = 0; i < Seller.GetCarCount(); i++)
		Seller.GetCar(i).SetPrice(200000 + i * 25000);

	for (size_t i = 0; i < Seller.GetCarCount(); i++)
	{
		CCar &rCar = Seller.GetCar(i);
		printf("| %10s | %d |\n", rCar.GetModel(), rCar.GetPrice());
	}
	printf("\n");

    Seller - "Ford" - "Daewoo";

	for (size_t i = 0; i < Seller.GetCarCount(); i++)
	{
		CCar &rCar = Seller.GetCar(i);
		printf("| %10s | %d |\n", rCar.GetModel(), rCar.GetPrice());
	}

	return 0;
}
