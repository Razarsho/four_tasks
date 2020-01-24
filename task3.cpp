#include <iostream>
#include <fstream>

using namespace std;

ifstream csh1, csh2, csh3, csh4, csh5;
int steps1, steps2, steps3, steps4, steps5, max_chel;
float cash1[16], cash2[16], cash3[16], cash4[16], cash5[16], a, great[16], max;

void mda1()
{
	csh1.open("Cash1.txt");
	while (csh1 >> a)
	{
		cash1[steps1] = a;
		if (csh1.eof()) break;
		steps1++;

	}
	csh1.close();
}

void mda2()
{
	csh2.open("Cash2.txt");
	while (csh2 >> a)
	{
		cash2[steps2] = a;
		steps2++;

	}
	csh2.close();
}

void mda3()
{
	csh3.open("Cash3.txt");
	while (csh3 >> a)
	{
		cash3[steps3] = a;
		steps3++;

	}
	csh3.close();
}

void mda4()
{
	csh4.open("Cash4.txt");
	while (csh4 >> a)
	{
		cash4[steps4] = a;
		steps4++;

	}
	csh4.close();
}

void mda5()
{
	csh5.open("Cash5.txt");
	while (csh5 >> a)
	{
		cash5[steps5] = a;
		steps5++;

	}
	csh5.close();
}

void sum()
{
	for (int i = 0; i <= steps1; i++)
	{
		great[i] = cash1[i] + cash2[i] + cash3[i] + cash4[i] + cash5[i];
		if (great[i] > max) max = great[i];
	}
	for (int i = 0; i <= steps1; i++)
	{
		if (great[i] == max)
		{
			max_chel = i + 1;
			break;
		}
	}
}


int main()
{

	mda1();
	mda2();
	mda3();
	mda4();
	mda5();
	sum();
	cout << max_chel << endl;
}

