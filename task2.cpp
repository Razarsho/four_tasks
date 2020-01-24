#include <fstream>
#include <iostream>

using namespace std;


float x, y, xA, xB, xC, xD, yA, yB, yC, yD, D, da1, da2, da3, da4, da5, da6;
ifstream figure, points;
int answer;
float iskl = 0;

void answer0and1()
{
	if (((x == xA) && (y == yA)) || ((x == xB) && (y == yB)) || ((x == xC) && (y == yC)) || ((x == xD) && (y == yD)))	answer = 0;
}

void answer2()
{
	da1 = (xA - x) * (yB - yA) - (xB - xA) * (yA - y);
	da2 = (xB - x) * (yC - yB) - (xC - xB) * (yB - y);
	da3 = (xC - x) * (yA - yC) - (xA - xC) * (yC - y);



	da4 = (xD - x) * (yA - yD) - (xA - xD) * (yD - y);
	da5 = (xC - x) * (yD - yC) - (xD - xC) * (yC - y);
	da6 = (xA - x) * (yC - yA) - (xC - xA) * (yA - y);


	// треугольник ABC
	if (((da1 > 0) && (da2 > 0) && (da3 > 0)) || ((da1 < 0) && (da2 < 0) && (da3 < 0))) 	answer = 2;
	// треугольник DCA
	else if (((da4 > 0) && (da5 > 0) && (da6 > 0)) || ((da4 < 0) && (da5 < 0) && (da6 < 0)))  	answer = 2;
	// исключение из формулы (если одна из вершин четырёхугольника [0;0])
	else if (((x == 0) || (y == 0)) && (((da1 < 0) && (da2 < 0) && (da3 < 0) && (da4 >= 0) && (da5 >= 0) && (da6 >= 0)) || ((da1 < 0) && (da2 < 0) && (da4 < 0) && (da3 >= 0) && (da5 >= 0) && (da6 >= 0)) || ((da1 < 0) && (da2 < 0) && (da5 < 0) && (da3 >= 0) && (da4 >= 0) && (da6 >= 0)) || ((da1 < 0) && (da2 < 0) && (da6 < 0) && (da3 >= 0) && (da4 >= 0) && (da5 >= 0)) || ((da1 < 0) && (da3 < 0) && (da4 < 0) && (da2 >= 0) && (da5 >= 0) && (da6 >= 0)) || ((da1 < 0) && (da3 < 0) && (da5 < 0) && (da2 >= 0) && (da4 >= 0) && (da6 >= 0)) || ((da1 < 0) && (da3 < 0) && (da6 < 0) && (da2 >= 0) && (da4 >= 0) && (da5 >= 0)) || ((da1 < 0) && (da4 < 0) && (da5 < 0) && (da2 >= 0) && (da3 >= 0) && (da6 >= 0)) || ((da1 < 0) && (da4 < 0) && (da6 < 0) && (da2 >= 0) && (da3 >= 0) && (da5 >= 0)) || ((da1 < 0) && (da5 < 0) && (da6 < 0) && (da2 >= 0) && (da3 >= 0) && (da4 >= 0)) || ((da2 < 0) && (da3 < 0) && (da4 < 0) && (da1 >= 0) && (da5 >= 0) && (da6 >= 0)) || ((da2 < 0) && (da3 < 0) && (da5 < 0) && (da1 >= 0) && (da4 >= 0) && (da5 >= 0)) || ((da2 < 0) && (da3 < 0) && (da6 < 0) && (da1 >= 0) && (da4 >= 0) && (da5 >= 0)) || ((da2 < 0) && (da4 < 0) && (da5 < 0) && (da1 >= 0) && (da3 >= 0) && (da6 >= 0)) || ((da2 < 0) && (da4 < 0) && (da6 < 0) && (da1 >= 0) && (da3 >= 0) && (da5 >= 0)) || ((da2 < 0) && (da5 < 0) && (da6 < 0) && (da1 >= 0) && (da3 >= 0) && (da4 >= 0)) || ((da3 < 0) && (da4 < 0) && (da5 < 0) && (da1 >= 0) && (da2 >= 0) && (da6 >= 0)) || ((da3 < 0) && (da4 < 0) && (da6 < 0) && (da1 >= 0) && (da2 >= 0) && (da5 >= 0)) || ((da3 < 0) && (da5 < 0) && (da6 < 0) && (da1 >= 0) && (da2 >= 0) && (da4 >= 0)) || ((da4 < 0) && (da5 < 0) && (da6 < 0) && (da1 >= 0) && (da2 >= 0) && (da3 >= 0))))
	{
		answer = 3; iskl = 1;
	}
	else answer = 3;

	// гипотенуза AC
	if (((da1 > 0) && (da2 > 0) && (da3 == 0)) || ((da1 < 0) && (da2 < 0) && (da3 == 0)))	 answer = 2;

	// гипотенуза CA
	if (((da4 > 0) && (da5 > 0) && (da6 == 0)) || ((da4 < 0) && (da5 < 0) && (da6 == 0)))	answer = 2;

	// стороны четырёхугольника ABCD
	if (((da1 == 0) || (da2 == 0)) || ((da4 == 0) || (da5 == 0))) if (iskl == 0)	answer = 1;




}



int main()
{
	setlocale(LC_ALL, "rus");

	figure.open("№1.txt");

	while (figure)
	{
		figure >> xA;
		figure >> yA;

		figure >> xB;
		figure >> yB;

		figure >> xC;
		figure >> yC;

		figure >> xD;
		figure >> yD;
	}

	points.open("№2.txt");

	while (points)
	{
		points >> x;
		points >> y;
		if (points.eof()) break;
		answer2();
		answer0and1();
		cout << answer << endl;
		iskl = 0;

	}

	figure.close();
	points.close();
}

