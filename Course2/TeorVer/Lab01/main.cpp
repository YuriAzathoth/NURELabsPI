#include <iostream>
#include <math.h>
#include <map>
#include <random>
#include <time.h>
#include <vector>

using namespace std;

//#define USE_RANDOM
//#define RANDOM_COUNT 4
//#define RANDOM_MIN 10
//#define RANDOM_MAX 12

bool IsPair(int iNum) { return iNum % 2 == 0; }

void Sort(int* iData, int iDataCount)
{
	int iTemp;
	int iPrev;
	for (int i = 1; i < iDataCount; i++)
	{
		iTemp = iData[i];
		iPrev = i - 1;
		while(iPrev >= 0 && iData[iPrev] > iTemp)
		{
			iData[iPrev + 1] = iData[iPrev];
			iData[iPrev] = iTemp;
			iPrev--;
		}
	}
}

void PrintData(const int* iData, int iDataCount)
{
	for (int i = 0; i < iDataCount; i++)
		cout << iData[i] << " ";
	cout << endl;
}

float Middle(const int* iData, int iDataCount)
{
	float fSum = 0.0f;
	for (int i = 0; i < iDataCount; i++)
		fSum += (float)iData[i];
	return fSum / (float)iDataCount;
}

float Dispersion(const int* iData, int iDataCount, float fMiddle)
{
	float fSum = 0.0f;
	for (int i = 0; i < iDataCount; i++)
		fSum += pow((float)iData[i] - fMiddle, 2.0f);
	return fSum / (float)(iDataCount - 1);
}

float Mediana(const int* iData, int iDataCount)
{
	if (IsPair(iDataCount))
		return (float)(iData[iDataCount / 2 - 1] + iData[iDataCount / 2]) / 2.0f;
	else
		return iData[(iDataCount + 1) / 2 - 1];
}

int Max(const int* iData, int iDataCount)
{
	int iMax = INT_MAX * -1;
	for (int i = 0; i < iDataCount; i++)
		if (iData[i] > iMax)
			iMax = iData[i];
	return iMax;
}

int Min(const int* iData, int iDataCount)
{
	int iMin = INT_MAX;
	for (int i = 0; i < iDataCount; i++)
		if (iData[i] < iMin)
			iMin = iData[i];
	return iMin;
}

int* Moda(const int* iData, int iDataCount, int &riModaCount)
{
	int iPrev = -1 * INT_MAX;
	int iPrevMaxFreq = 0;
	int iMaxFreq = 0;
	map<int, int> mapFreq;

	for (int i = 0; i < iDataCount; i++)
	{
		int iCurr = iData[i];
		if (iCurr != iPrev)
			mapFreq[iCurr] = 0;
		mapFreq[iCurr]++;
		iPrev = iCurr;
	}

	for (auto it = mapFreq.cbegin(); it != mapFreq.cend(); it++)
	{
		int iCurrFrec = (*it).second;
		if (iCurrFrec > iMaxFreq)
		{
			iPrevMaxFreq = iMaxFreq;
			iMaxFreq = iCurrFrec;
		}
	}

	if (iMaxFreq < 2)
		return NULL;

	vector<int> vecModa;
	for (auto it = mapFreq.cbegin(); it != mapFreq.cend(); it++)
		if ((*it).second == iMaxFreq)
			vecModa.push_back((*it).first);

	if (vecModa.size() == mapFreq.size())
		return NULL;

	riModaCount = vecModa.size();
	int* iModa = new int[riModaCount];
	int i = 0;
	for (auto it = vecModa.cbegin(); it != vecModa.cend(); it++, i++)
		iModa[i] = (*it);

	return iModa;
}

float Quantil(const int* iData, int iDataCount, float fQuantil)
{
	float fDivider = (float)iDataCount * fQuantil;
	float fPosition = fDivider - 1.0f;
	if (fDivider - floor(fDivider) == 0.0f)
		return iData[(int)fPosition];
	else
	{
		if (fPosition >= 1.0f)
			return (iData[(int)floor(fPosition)] + iData[(int)ceil(fPosition)]) / 2.0f;
		else
			return iData[(int)ceil(fPosition)];
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

#ifdef USE_RANDOM
	srand(time(0));
	int iDataCount = RANDOM_COUNT;
#else
	int iDataCount;
	cout << "Введите размер массива: ";
	cin >> iDataCount;
	cout << endl;
#endif // USE_RANDOM

	int* iData = new int[iDataCount];

	for (int i = 0; i < iDataCount; i++)
#ifdef USE_RANDOM
		iData[i] = rand() % (RANDOM_MAX - RANDOM_MIN) + RANDOM_MIN;
#else
	{
		cout << "Данные №" << i << ": ";
		cin >> iData[i];
		cout << endl;
	}
#endif // USE_RANDOM

	cout << "Исходные данные:" << endl;
	PrintData(iData, iDataCount);

	Sort(iData, iDataCount);
	cout << "Отсортированные данные:" << endl;
	PrintData(iData, iDataCount);
	cout << endl;

	float fMiddle = Middle(iData, iDataCount);
	cout << "Выборочное среднее:\t" << fMiddle << endl;

	float fDispersion = Dispersion(iData, iDataCount, fMiddle);
	cout << "Выборочная дисперсия:\t" << fDispersion << endl;
	cout << "Стандартное отклонение:\t" << sqrt(fDispersion) << endl;
	cout << "Медиана:\t\t" << Mediana(iData, iDataCount) << endl;

	int iModaCount = 0;
	int* iModa = Moda(iData, iDataCount, iModaCount);
	cout << "Мода:\t\t\t";
	if (iModa)
	{
		PrintData(iModa, iModaCount);
		delete[] iModa;
	}
	else
		cout << "Отсутствует" << endl;

	int iMin = Min(iData, iDataCount);
	int iMax = Max(iData, iDataCount);
	cout << "Максимальное значение:\t" << iMax << endl;
	cout << "Минимальное значение:\t" << iMin << endl;
	cout << "Разброс:\t\t" << iMax - iMin << endl;
	cout << "Квантиль 0.1:\t\t" << Quantil(iData, iDataCount, 0.1f) << endl;
	cout << "Квантиль 0.25:\t\t" << Quantil(iData, iDataCount, 0.25f) << endl;
	cout << "Квантиль 0.5:\t\t" << Quantil(iData, iDataCount, 0.5f) << endl;
	cout << "Квантиль 0.75:\t\t" << Quantil(iData, iDataCount, 0.75f) << endl;

	delete[] iData;

	cin.getline(NULL, 0);
	return 0;
}
