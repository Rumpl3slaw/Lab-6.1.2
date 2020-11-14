#include <iostream>
#include <iomanip>

using namespace std;

void Create(int* a, const int size, const int Low, const int High,int i);
void Cout(int* a, const int size,int i);
int Condition(int* a, const int size,int i,int S);
int Sum(int* a, const int size, int i,int S);


	int main()
	{
		srand((unsigned)time(NULL));
		const int size = 25;
		int a[size];

		int Low = -20;
		int High = 30;

		Create(a, size, Low, High, 0);
		cout << "Masyv:" << endl;
		cout << endl;
		Cout(a, size, 0);
		cout << endl;
		int Q = Condition(a, size, 0, 0);

		cout << "Modyfikovanyi Masyv:" << endl;
		cout << endl;
		Cout(a, size, 0);
		cout << endl;

		int value = Sum(a, size, 0, 0);
		cout << "Suma elementiv z kriteriyu=" << value<< endl;
		cout << endl;
		cout << "Kil`kist` elementiv z kriteriyu=" << Q<< endl;

		return 0;
	}

void Create(int* a, const int size, const int Low, const int High,int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if(i < size - 1)
		Create(a, size, Low, High, i + 1);
}
void Cout(int* a, const int size,int i)
{
	cout << setw(5) << a[i];
	if (i < size - 1)
		Cout(a, size, i+1);
	else;
}
int Condition(int* a, const int size,int i,int S)
{
		if (a[i] < 0 || a[i] > 0 && a[i] % 2 == 0)
			S += 1;
		else
			a[i] = 0;
		if (i < size - 1)
			return Condition(a, size, i + 1, S);
		else
	        return S;
}
int Sum(int* a, const int size,int i,int S)
{
	S += a[i];
	if (i < size - 1)
		return Sum(a, size, i + 1, S);
	else
		return S;
}
