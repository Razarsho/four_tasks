#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

ifstream fin;
char time;
int steps, x[1000], xmins[1000], xhours[1000], vremia[1000], compares[1000], max_chel;
string mins, hours;
int steps1, comp[10000];

void da()
{

	for (int i = 0; i <= steps; i++)
	{
		if (x[i] == 10)
		{
			mins = std::to_string(x[i + 1]) + std::to_string(x[i + 2]);
			hours = std::to_string(x[i - 1]);


			//  Для счёта
			xhours[i] = std::stoi(hours);
			xmins[i] = std::stoi(mins);



		}


		if (x[i - 5] == 10)
		{
			hours = std::to_string(x[i - 2]) + std::to_string(x[i - 1]);
			xhours[i] = std::stoi(hours);

		}

		if ((xhours[i] * 60 <= 1200) && (xhours[i] + xmins[i] != 0))
		{
			vremia[steps1] = xhours[i] * 60 + xmins[i];
			//		cout << "hours = " << xhours[i] << endl;
				//	cout << "mins = " << xmins[i] << endl;
				//	cout << vremia[steps1] <<  endl;
			for (int z = vremia[steps1]; z < vremia[steps + 1]; z++)
			{
				cout << z << endl;
			}
			steps1++;

		}
	}
}

void mda()
{
	int start[1000], end[1000], compare[1000];
	for (int i = 0; i < steps1; i += 2)
	{
		start[i] = vremia[i];
		end[i] = vremia[i + 1];
		//	cout << "start = " << start[i] << " end = " << end[i] << endl;
		for (int j = start[i]; j < end[i]; j++)
		{
			compare[i] = j;
			compares[j]++;
			if (max_chel < compares[j]) max_chel = compares[j];
			//		cout << " min =  " << min << "max = " << max << endl;
			if ((compares[j] > 1) && (compares[j] == max_chel))
			{
				cout << j / 60 << ":" << j % 60 << endl;
				//				cout << "compares = " << compares[j] << endl;

			}
		}
	}
}






int main()
{
	fin.open("task4.txt");
	while (fin >> time)
	{
		x[steps] = time - 48;
		steps++;
	}
	da();
	mda();
	fin.close();
}

