#include <iostream>
#include <string>
#include "TProc.h"

using namespace std;

int main()
{
	int Qsize, time, cores;
	double processorInt, queueInt;
	cout << "Enter Qsize" << endl;
	cin >> Qsize;
	cout << "Enter cores" << endl;
	cin >> cores;
	cout << "Enter Intensivnost processora" << endl;
	cin >> processorInt;
	cout << "Enter Intensivnost queue " << endl;
	cin >> queueInt;
	cout << "Enter JobTime" << endl;
	cin >> time;
	Proceccor proc1;
	proc1.Working(Qsize, time, cores, processorInt, queueInt);
	return 0;
}
