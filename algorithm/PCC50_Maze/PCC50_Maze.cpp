// PCC50_Maze.cpp : Defines the entry point for the console application.
//


// �̷� �ִܰŸ�, ���α׷��� ���׽�Ʈ ç��¡ 50p
// �ʺ�켱 Ž������ ��� ���� �湮�Ѵ�.
// ���� �켱 Ž���� �������� ����̰� �������� ������ �ʺ�켱 Ž���� ����.

#include "stdafx.h"
#include <queue>
#include <iostream>
#include <sstream>



int g_table[101][101] = {0,};
int g_dist[101][101] = {0,};
int DIRECT[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

typedef std::pair<int,int> POS;
std::queue<POS> que;

void BFS(POS pos)
{
	que.push(pos);

	while(que.empty() == false)
	{
		POS cur = que.front();
		que.pop();

		// �湮
		if (g_table[cur.first][cur.second] == 2) // �����̶�� �׸�
		{
			continue;
		}

		// �ڽ� ����
		for (int i = 0; i < 4; ++i)
		{
			POS child = std::make_pair(DIRECT[i][0] + cur.first, DIRECT[i][1] + cur.second);
			if (g_table[child.first][child.second])
			{
				if (g_dist[child.first][child.second])
				{
					continue; // �湮�� ���
				}
				g_dist[child.first][child.second] = g_dist[cur.first][cur.second] + 1; // ��������� �Ÿ� �Է�.
				que.push(child);
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int N,M = 0;
	std::wcin >> N >> M;

	// �Է� ó��

	std::wstring line; 
	std::getline(std::wcin, line); // �����ϳ� ����

	POS start;
	POS end;
	for (int i = 0; i < N; ++i)
	{
		std::getline(std::wcin, line);

		if (line.length() < M)
		{
			continue;
		}
		for (int j = 0; j < M; ++j)
		{
			switch (line[j])
			{
			case L'#':
				g_table[i+1][j+1] = 0;
				break;
			case L'S':
				start = std::make_pair(i+1, j+1);
				g_table[i+1][j+1] = 1;
				break;
			case L'G':
				g_table[i+1][j+1] = 2;
				end = std::make_pair(i+1, j+1);
				break;
			default:
				g_table[i+1][j+1] = 1;
			}
		}
	}

	// ó��
	BFS(start);

	std::wcout << g_dist[end.first][end.second] << std::endl;

	return 0;
}

