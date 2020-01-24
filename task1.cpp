#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

double x, max, min, sum, sred, med, perc[1000], perc100, percentil;
double mas[1000];
int steps = 0;
ifstream fin;

void percent()
{
	int temp;
	for (int i = 0; i < steps - 1; i++)
	{
		for (int j = 0; j < steps - i - 1; j++)
		{
			if (mas[j] > mas[j + 1])
			{
				temp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < steps; i++)
	{
		if (fin.eof())
		{
			perc100 = max * 0.9;
			perc[i] = mas[i] * 0.9;
			if (perc[i] < perc100) percentil = (steps - 1);
		}
	}
	if (fin.eof())
	{
		cout << fixed << setprecision(2) << percentil << endl;
	}
}

void median()
{
	int temp;
	for (int i = 0; i < steps - 1; i++)
	{

		for (int j = 0; j < steps - i - 1; j++)
		{
			if (mas[j] > mas[j + 1])
			{
				temp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = temp;
			}
		}
	}
	if (steps % 2 == 0)	med = (mas[steps / 2 + 1] + mas[steps / 2 - 1]) / 2;
	else med = mas[steps / 2];

	if (fin.eof()) cout << fixed << setprecision(2) << med << endl;
}

void maximum()
{
	if (max < x) max = x;
	if (fin.eof()) cout << max << endl;
}

void minimum()
{
	if (x < min) min = x;
	if (fin.eof()) cout << min << endl;
}

void srednee()
{
	sum += x;
	sred = sum / steps;
	if (fin.eof()) cout << sred << endl;
}




int main()
{
	setlocale(LC_ALL, "rus");


	fin.open("test1.txt");

	while (fin >> x)
	{
		mas[steps] = x;
		steps++;
		percent();
		median();
		maximum();
		minimum();
		srednee();

	}

	fin.close();

	return 0;
}


