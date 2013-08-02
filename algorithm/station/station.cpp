// station.cpp : Defines the entry point for the console application.
// http://211.228.163.31/pool/station/station.php?pname=station

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

int N = 0;
std::vector<std::pair<int,int> > in;
const int MAXINT = 1000000;
int dp[10000] = {0,};
int MaxY[10000][10000] = {0,};

void InitMaxY(int i, int j) // i���� j-1���������� �ִ� Y���� ���Ѵ�.
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j < N; ++j)
		{
			if (j == 0)
			{
				MaxY[i][j] = in[0].second;
			}
			else
			{
				MaxY[i][j] = std::max(MaxY[i][j-1], in[j].second);
			}
		}
	}
}

int Cost(int i, int j)// i���� j���� �ϳ��� ������(���簢��)���� ������ �ּ� ���.
{
	int x = in[i].first; // �������� x ��ǥ
	int maxY = MaxY[i][j]; // i���� j������ �ִ� Y��.
	return std::max(in[j].first - x, maxY); // ������� �ִ� ���.(�ִ�Y�� j���� �̵��Ÿ��� ū ��)
}

int Process()
{
	std::fill(dp, dp + 10000, MAXINT);

	dp[0] = in[0].second * 2; // �ֿ��� ��ǥ�� Y ���� ������ ����.(������ �Ÿ��� 0�̹Ƿ� X�� ��� ����)
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < i; ++j)
		{
			dp[i] = std::min(dp[i], dp[j] + Cost(j + 1, i));
		}
		// ó������ i���� �ϳ��� ������������ ��뵵 �߰��� ���Ѵ�.
		dp[i] = std::min(dp[i], Cost(0, i));
	}

	return dp[N-1];
}

int Pred(const std::pair<int, int>& l, const std::pair<int, int>& r)
{
	return l.first < r.first ? 1 : 0;
}

int main()
{
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
		in.push_back(std::make_pair(x, abs(y) * 2)); // �̸� *2�� �صд�. ������ cost���� �� ��.
	}
	std::sort(in.begin(), in.end(), Pred);

	InitMaxY(0, N);

	std::cout << Process();

	return 0;
}

/*
int Cost(int i, int j)// i���� j���� �ϳ��� ������(���簢��)���� ������ �ּ� ���.
{
	int s = in[i].first; // �������� x ��ǥ
	int maxY = in[i].second;
	for (int k = i + 1; k <= j; ++k)
	{
		maxY = std::max(maxY, in[k].second); // ������� �ִ�Y��.
		
	}
	return std::max(in[j].first - s, maxY * 2); // ������� �ִ� ���.(�ִ�Y�� j���� �̵��Ÿ��� ū ��)

}
*/