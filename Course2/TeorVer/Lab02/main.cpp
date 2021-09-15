#include <locale.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

typedef vector<double> TRow;
typedef vector<TRow> TMatrix;

double GeneralAvg(const TMatrix &rMatrix)
{
	int iSum = 0;
	for (auto it1 = rMatrix.cbegin(); it1 != rMatrix.end(); it1++)
		for (auto it2 = (*it1).begin(); it2 != (*it1).end(); it2++)
			iSum += (*it2);
	int iCount = rMatrix.size() * rMatrix.back().size();
	return (double)iSum / (double)iCount;
}

int GeneralSum(const TMatrix &rMatrix)
{
	double dAvg = GeneralAvg(rMatrix);
	double dSum = 0.0f;
	for (auto it1 = rMatrix.cbegin(); it1 != rMatrix.end(); it1++)
		for (auto it2 = (*it1).begin(); it2 != (*it1).end(); it2++)
			dSum += pow((*it2) - dAvg, 2.0);
	return dSum;
}

double FactorSum(const TMatrix &rMatrix, const TRow &rFactor)
{
	double dAvg = GeneralAvg(rMatrix);
	double dFact = 0.0f;
	for (auto it = rFactor.begin(); it != rFactor.end(); it++)
		dFact += (double)rFactor.size() * pow((*it) - dAvg, 2.0);
	return dFact;
}

double ResidualSum(const TMatrix &rMatrix, const TRow &rFactor)
{
	return GeneralSum(rMatrix) - FactorSum(rMatrix, rFactor);
}

double FactorVariance(const TMatrix &rMatrix, const TRow &rFactor)
{
	return FactorSum(rMatrix, rFactor) / (double)(rMatrix.size() - 1);
}

double ResidualVariance(const TMatrix &rMatrix, const TRow &rFactor)
{
	return ResidualSum(rMatrix, rFactor) / (double)(rMatrix.size() * (rMatrix.back().size() - 1));
}

double Fisher(const TMatrix &rMatrix, const TRow &rFactor)
{
	double dResidual = ResidualVariance(rMatrix, rFactor);
	double dFactor = FactorVariance(rMatrix, rFactor);
	double s1 = max(dResidual, dFactor);
	double s2 = min(dResidual, dFactor);
	return s1 / s2;
}

int main()
{
	setlocale(LC_CTYPE, "rus");

	int iTries = 0;
	int iFactors = 0;

	cout << "Количество опытов: ";
	cin >> iTries;
	cout << "Количество факторов: ";
	cin >> iFactors;
	cout << endl;

	TMatrix Matrix;
	TRow Factors;

	for (int i = 0; i < iFactors; i++)
	{
		double n = 0.0;
		cout << "Factor #" << i + 1 << ": ";
		cin >> n;
		Factors.push_back(n);
	}
	for (int i = 0; i < iTries; i++)
	{
		Matrix.push_back(TRow());
		for (int j = 0; j < iFactors; j++)
		{
			double n = 0.0;
			cout << "Фактор " << j + 1 << " Опыт " << i + 1 << ": ";
			cin >> n;
			Matrix.back().push_back(n);
		}
	}

	for (auto it = Factors.begin(); it != Factors.end(); it++)
		cout << *it << " ";
	cout << endl << "------------" << endl;
	for (auto it1 = Matrix.begin(); it1 != Matrix.end(); it1++)
	{
		for (auto it2 = (*it1).begin(); it2 != (*it1).end(); it2++)
			cout << *it2 << " ";
		cout << endl;
	}

	cout << "Результат по Фишеру-Снедекору: " << Fisher(Matrix, Factors) << "  ";

	return 0;
}
