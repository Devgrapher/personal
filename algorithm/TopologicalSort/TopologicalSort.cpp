// TopologicalSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <deque>

class TopologicalSort
{
public:
	TopologicalSort(int N)
	{
		graph_.assign(N + 1, 0);
		for (int i = 0; i < N + 1; ++i)
		{
			graph_[i].assign(N + 1, 0);
		}
		visited_.assign(N + 1, 0);
	}
	void AddLine(int from, int to)
	{
		graph_[from][to] = 1;
	}

	void DfsVisit(int vertex)
	{
		// �湮 üũ
		visited_[vertex] = 1;

		for (size_t i = 1; i < graph_.size(); ++i)
		{
			int f = graph_[vertex][i];
			if (i == vertex || // �ڱ� �ڽ��� ���
				f == 0) // ������ ���°��
			{
				continue; 
			}

			if (visited_[i] == 0) // �湮���� ������
			{
				// �ڽſ��� ����� �������� �̵�
				DfsVisit(i);
			}
		}
		// �ڽ��� ����� ��带 ��� �湮�Ͽ����� �� ������ �湮 �Ϸ��� ����.

		// �湮 �Ϸ��ϸ� ��������� ó���� ����
		// �湮 ������ ������ order��.
		order_.push_front(vertex);
	}

	void Dfs()
	{
		for (size_t i = 1; i < graph_.size(); ++i)
		{
			if (visited_[i] == 0)
			{
				DfsVisit(i);
			}
		}
	}

	const std::deque<int>& GetOrder() { return order_; }

private:
	std::vector<std::vector<int>> graph_;
	std::vector<int> visited_;
	std::deque<int> order_;
};




int _tmain(int argc, _TCHAR* argv[])
{
	while(!std::cin.fail())
	{
		int singer = 0;
		int pd = 0;
		std::cin >> singer >> pd;
		if (std::cin.fail()) { break; }

		TopologicalSort graph(singer);

		int pn = 0; // ���� ����
		int n = 0; // ���� ����
		for (int pdCnt = 0; pdCnt < pd; ++pdCnt)
		{
			int singNum = 0;
			std::cin >> singNum;
			for (int singCnt = 0; singCnt < singNum; ++singCnt)
			{
				std::cin >> n;
				if (singCnt > 0)
				{
					graph.AddLine(pn, n);
				}
				pn = n;
			}
		}

		graph.Dfs();

		const std::deque<int>& order = graph.GetOrder();
		for (size_t i = 0; i < order.size(); ++i)
		{
			std::cout << order[i] << std::endl;
		}
		std::cout << std::endl;
	}
	
	return 0;
}

