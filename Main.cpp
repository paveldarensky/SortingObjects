#define _CRT_SECURE_NO_WARNINGS  
#include "Sort.h"
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <random>
#include <iomanip>
#include <cstdio>

int GenerateRandomInt(int a, int b) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(a, b);
	return dis(gen);
}

class Participant
{
public:
	int ID;
	int Tasks;
	int Time;
	int Score;
	int Tryings;

	Participant()
	{
		ID = -1;
		Tasks = GenerateRandomInt(0, 5);
		Time = GenerateRandomInt(60, 300);
		Score = GenerateRandomInt(0, 25);
		Tryings = GenerateRandomInt(0, 20);
	}

	Participant(int x_id, int x_tasks, int x_time, int x_score, int x_tryings) 
	{
		ID = x_id;
		Tasks = x_tasks;
		Time = x_time;
		Score = x_score;
		Tryings = x_tryings;
	}

	bool operator > (Participant& other)
	{
		return this->Сompare(other) > 0;
	}

	bool operator < (Participant& other)
	{
		return this->Сompare(other) < 0;
	}

private:
	int Сompare(Participant& other)
	{
		int diff;

		if (diff = (Score - other.Score)) 
		{
			return diff; 
		}
		if (diff = (Tasks - other.Tasks)) 
		{ 
			return diff; 
		}
		if (diff = (other.Time - Time)) 
		{ 
			return diff; 
		}
		if (diff = (Tryings - other.Tryings))
		{ 
			return diff; 
		}
		diff = (ID - other.ID);

		return diff;
	}
};

void main()
{
	int n;
	std::cout << "Enter the n: ";
	std::cin >> n;

	Participant** Ptr = new Participant * [n];

	std::cout << "Start info:\n\n";
	for (int i = 0; i < n; i++)
	{
		Ptr[i] = new Participant;
		(*Ptr[i]).ID = i + 1;
		printf("ID_%-6d Score_%-6d Tasks_%-6d Time_%-6d Tryings_%-6d\n", (*Ptr[i]).ID, (*Ptr[i]).Score, (*Ptr[i]).Tasks, (*Ptr[i]).Time, (*Ptr[i]).Tryings);
	}

	int count;
	count = Sort<Participant>::SortShell(Ptr, n);

	std::cout << "\n\nEnd info:\n\n";
	for (int i = 0; i < n; i++)
	{
		printf("ID_%-6d Score_%-6d Tasks_%-6d Time_%-6d Tryings_%-6d\n", (*Ptr[i]).ID, (*Ptr[i]).Score, (*Ptr[i]).Tasks, (*Ptr[i]).Time, (*Ptr[i]).Tryings);
	}

	//file
	FILE* file;
	file = fopen("Result.txt", "w");
	if (file == nullptr)
	{
		std::cout << "error open the file!";
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			fprintf(file, "ID_%-6d Score_%-6d Tasks_%-6d Time_%-6d Tryings_%-6d\n", (*Ptr[i]).ID, (*Ptr[i]).Score, (*Ptr[i]).Tasks, (*Ptr[i]).Time, (*Ptr[i]).Tryings);
		}
		std::cout << "\n\nEND INFO IN THE FILE - Result.txt!\n\n";
	}
}