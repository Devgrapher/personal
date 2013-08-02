// Arctic.cpp : Defines the entry point for the console application.
// http://www.algospot.com/judge/problem/read/ARCTIC

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>


struct Pos
{
	double x;
	double y;
};

int campNum = 0;
Pos campPos[100] = {0,};
double table[100][100] = {0,};
int visit[100] = {0,};
int visitcnt = 0;

void DFS(int i, double max)
{
	visit[i] = 1;
	++visitcnt;
	for (int k = 0; k < campNum; ++k)
	{
		if (!visit[k] && table[i][k] <= max) // ���� �湮���߰�, ���� ��ȣ�ִ�ġ���� �����ٸ�
		{
			DFS(k, max);
		}
	}
}

bool Pred(double m, double /*v*/)
{
	std::fill(visit, visit + 100, 0);
	visitcnt = 0;
	DFS(0, m);

	if (visitcnt != campNum) // �湮���� ��尡 �ִٸ�(������ �׷���)
	{
		return true; // ���� m���� �������� Ž��
	}
	else
	{
		return false;
	}
}

double Process()
{
	std::set<double> lenSet;

	// �� ��庰 �Ÿ� ����
	for (int i = 0; i < campNum; ++i)
	{
		for (int j = 0; j < campNum; ++j)
		{
			if (i == j) continue;
			double x = campPos[i].x - campPos[j].x;
			double y = campPos[i].y - campPos[j].y;
			double len = sqrt((x * x) + (y * y));
			table[i][j] = len;
			lenSet.insert(len);
		}
	}

	std::set<double>::iterator v = std::lower_bound(lenSet.begin(), lenSet.end(), 0, Pred);
	return *v;
}

int main()
{
	int testNum = 0;
	std::cin >> testNum;
	for (int i = 0; i < testNum; ++i)
	{
		std::cin >> campNum;
		for (int j = 0; j < campNum; ++j)
		{
			std::cin >> campPos[j].x >> campPos[j].y;
		}

		double a = Process();
		printf("%.2lf\n", a);
	}
	return 0;
}

/*
double Round(double n) 
{
	double temp;
	temp = n * 100;
	n = floor(temp + 0.5);    //0.5�� ������ ���� 
	return n / 100;   
}*/