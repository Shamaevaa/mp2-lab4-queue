#pragma once
#ifndef _Proccecor_
#define _Proceccor_
#include "TQueue.h"
#include <Windows.h>
#include <iostream>
#include <vector>

using namespace std;

struct Task
{
	int cores = 0;
	int tacts = 0;
};

struct Procecor
{
	vector <Task> proces;
	int coresProc = 0;
};
class Proceccor
{
private:
	int Time;
	int NumberOfCycle = 0;
	int completed = 0;
	int random = 0;
	int size = 0;
	double processorInt = 0;
	double queueInt = 0;
	int queueError = 0;
	int prostoyQueue = 0;
	int otkazproc = 0;
	int prostoyProc = 0;
	int kolPostTask = 0;
public:
	void Wait(Queue<Task> &q2ue, Procecor &proc, int time);
	void Working(int _queueSize, int _time, int _cores, double _processorInt, double _queueInt);
	Task TaskGeneration();
	void Printf(int kolPostTask, int prostoyQueue, int prostoyProc, int time, int completed, int NumberOfCycle);
};

#endif