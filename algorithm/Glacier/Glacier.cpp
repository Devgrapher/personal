// Glacier.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <queue>

int N = 0;
int M = 0;
int arr[302][302] = {0,};
typedef std::pair<int,int> POS;
int DIR[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

void Aging(POS p, int (*visit)[302])
{
	for (int i = 0; i < 4; ++i)
	{
		int n = p.first + DIR[i][0];
		int m = p.second + DIR[i][1];
		if (arr[n][m] == 0 && visit[n][m] == 0)
		{
			arr[p.first][p.second] = std::max(arr[p.first][p.second] - 1, 0);
		}
	}
}

void BFS(POS start, int (*visit)[302])
{
	std::queue<POS> que;
	que.push(start);

	while (que.empty() == false)
	{
		POS p = que.front();
		que.pop();
		if (visit[p.first][p.second])// ���⼭ �ߺ�üũ�ؾ���. �ڽ� �����Ҷ� �ϸ� �ȵ�.
		{
			continue;
		}

		Aging(p, visit);
		visit[p.first][p.second] = 1;

		// �ڽ� �߰�
		for (int i = 0; i < 4; ++i)
		{
			int n = p.first + DIR[i][0];
			if (n > N) continue;
			int m = p.second + DIR[i][1];
			if (m > M) continue;
			if (arr[n][m] == 0)
			{
				continue;
			}

			POS c = std::make_pair(n, m);

			que.push(c);
		}
	}
}



int Turn()
{
	bool bfs = false;
	int visit[302][302] = {0,};
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (arr[i][j])
			{
				if (bfs)
				{
					if (visit[i][j] == 0)
						return 0; // bfs�� �������� �ִµ� �湮�� �ȵȳ�尡 �ִٸ� �ɰ�������.
					else
						continue;
				}

				POS p = std::make_pair(i, j);
				BFS(p, visit);
				bfs = true;
			}
		}
	}
	if (bfs == false)
	{
		// �ѹ��� �湮���ߴٸ� ������ ��� ����
		return -1;
	}

	return 1;
}


int main()
{
	std::cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			std::cin >> arr[i][j];
		}
	}

	int year = 0;
	int r = 0;
	do 
	{
		++year;
		r = Turn();
	} while (r == 1);
	if (r == -1)
	{
		year = 0;
	}
	else
	{
		--year;// �ɰ������� Ȯ���ϱ����� �������� �ѹ� �� �湮�����Ƿ� 1 ���ҽ�Ų��.
	}
	std::cout << year;

	return 0;
}

