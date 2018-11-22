#include"TProc.h"
#include <ctime>

Task Proceccor::TaskGeneration() //Генератор задач 
{
	srand((unsigned int)time(NULL));
	int pr = rand() % 9 + 1;
	if (pr < (queueInt * 10))
	{
		srand((unsigned int)time(NULL));
		int pr1 = rand() % 9 + 1;
		Task task;
		task.cores = pr1;
		return task;
	}
	else
	{
		Task task = {};
		task.cores = 0;
		return task;
	}
}
void Proceccor::Wait(Queue<Task> &q2ue, Procecor &proc, int Time)
{
	for (int i = 0; i < Time; i++)
	{
		if (!q2ue.IsFull())
		{
			Task task1;
			task1 = TaskGeneration();
			if (task1.cores != 0)
			{
				q2ue.Put(task1);
			}
		}
		else
		{
			queueError++;
		}
		if (q2ue.IsEmpty())
		{
			prostoyQueue++;
		}
		else
		{
			for (int i = 0; i < q2ue.Size(); i++)
			{
				Task task2;
				task2 = q2ue.Check();
				if (task2.cores <= proc.coresProc)
				{
					proc.coresProc -= task2.cores;
					proc.proces.push_back(task2);
					kolPostTask++;
					q2ue.Get();
					continue;
				}
				else
				{
					if (task2.cores > proc.coresProc)
					{
						otkazproc++;
						q2ue.Get();
					}
					else
						break;
				}
			}
		}
		//выполнение 
		if (proc.proces.size() != 0)
		{
			int i = 0;
			for (i; i < proc.proces.size(); i++)
			{
				proc.proces[i].tacts++;
				srand((unsigned int)time(NULL));
				int pr = rand() % 9 + 1;
				if ((double)pr / 10 < processorInt)
				{
					Task task2;
					task2 = proc.proces[i];
					if (task2.tacts == 1)
					{
						continue;
					}
					completed++;
					proc.proces.erase(proc.proces.begin() + i);
					proc.coresProc += task2.cores;
					NumberOfCycle += task2.tacts;
				}
			}
		}
		else
		{
			prostoyProc++;
		}
	}
	Printf(kolPostTask, prostoyQueue, prostoyProc, Time, completed, NumberOfCycle);
}
void Proceccor::Working(int _size, int _time, int _cores, double _processorInt, double _queueInt)
{
	Procecor proc;
	proc.coresProc = _cores;
	Time = _time;
	size = _size;
	processorInt = _processorInt;
	queueInt = _queueInt;
	Queue<Task> q2ue(size);
	Wait(q2ue, proc, Time);
}
void Proceccor::Printf(int kolPostTask, int prostoyQueue, int prostoyProc, int time, int completed, int NumberOfCycle)
{
	cout << "Statistics:" << endl;
	cout << "Number of tasks received in the computer system: " << kolPostTask << endl;
	if (kolPostTask != 0)
		cout << "Number of failures in sevice job: " << (prostoyQueue * 100 / kolPostTask) << "%" << endl;
	else
		cout << "Number of failures in sevice job: " << 0 << endl;
	cout << "Idle clock cycles: " << (prostoyProc * 100 / time) << "%" << endl;
	if (completed != 0)
		cout << "Average time of task execution: " << (double(time - prostoyProc) / double(completed)) << endl;
	else
		cout << "Average time of task execution: " << 0 << endl;
	cout << "Task comleted: " << completed << endl;
	cout << "Total cycles: " << NumberOfCycle << endl;
}

