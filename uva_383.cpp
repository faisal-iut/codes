#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<limits.h>
using namespace std;
#define MAX_D 10
#define MAX_M 30
#define MAX_N 435
#define MAX_P 10
int dataset;
int M, N, P;
char vertex_list[MAX_M][3];
char fst_node[MAX_N][3];
char snd_node[MAX_N][3];
char fst_req[MAX_P][3];
char snd_req[MAX_P][3];
int graph[MAX_M][MAX_M];
int size[MAX_P];
int mapped_index[3000];
int source[MAX_P];
int destination[MAX_P];
int dist[MAX_M];
bool spt[MAX_M];
int ans;
int final_cost[MAX_D][MAX_P];
int Ps[MAX_D];

int index_mapping(char node[])
{
	int index;
	int dec=100;
	index = (node[0] - 'A') * dec + (node[1] - 'A');
	return index;
}

int min_dist_index()
{
	int min_index=0;
	int min = INT_MAX;
	for (int i = 0; i < M; i++)
	{
		if (!spt[i] && dist[i]<min)
		{
			min = dist[i];
			min_index = i;
		}
	}
	return min_index;
}

int dijcastre(int src, int dest)
{
	int index;
	dist[src] = 0;
	for (int i = 0; i < M - 1; i++)
	{
		index = min_dist_index();
		spt[index] = true;
		for (int i = 0; i < M; i++)
		{
			if (!spt[i] && graph[index][i] && dist[index] != INT_MAX && dist[index] + graph[index][i] < dist[i])
			{
				dist[i] = dist[index] + graph[index][i];
			}
		}
	}
	return dist[dest];
}

void initialize()
{
	for (int i = 0; i < M; i++)
	{
		for (int k = 0; k < M; k++)
		{
			graph[i][k] = 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		graph[mapped_index[index_mapping(fst_node[i])]][mapped_index[index_mapping(snd_node[i])]] = 1;
		graph[mapped_index[index_mapping(snd_node[i])]][mapped_index[index_mapping(fst_node[i])]] = 1;
	}
	for (int i = 0; i < P; i++)
	{
		source[i] = mapped_index[index_mapping(fst_req[i])];
		destination[i] = mapped_index[index_mapping(snd_req[i])];
	}

}

void solve(int j)
{

		initialize();
		for (int i = 0; i < P; i++)
		{
			for (int i = 0; i < M; i++)
			{
				dist[i] = INT_MAX;
				spt[i] = false;
			}
			ans = 0;
			ans = dijcastre(source[i], destination[i]);
			if (ans == INT_MAX)
			{
				ans = -1;
			}
			final_cost[j][i] = 100 * ans*size[i];

		}

}

void print_output()
{
	cout << "SHIPPING ROUTES OUTPUT" << endl<<endl;
	for (int j = 0; j < dataset; j++)
	{
		cout << "DATA SET  " << j + 1 << endl<<endl;
		for (int i = 0; i < Ps[j]; i++)
		{
			if (final_cost[j][i] < 0)
			{
				cout << "NO SHIPMENT POSSIBLE" << endl;
			}
			else
			{
				cout << "$" << final_cost[j][i] << endl;
			}

		}
		cout << endl;
	}
	cout << "END OF OUTPUT"<<endl;

}

void read_input()
{

	cin >> M >> N >> P;
	for (int i = 0; i < M; i++)
	{
		cin >> vertex_list[i];
		mapped_index[index_mapping(vertex_list[i])] = i;

	}
	for (int i = 0; i < N; i++)
	{
		cin >> fst_node[i] >> snd_node[i];
	}
	for (int i = 0; i < P; i++)
	{
		cin >> size[i] >> fst_req[i] >> snd_req[i];
	}


}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> dataset;
	for (int j = 0; j < dataset; j++)
	{
		read_input();
		solve(j);
		Ps[j] = P;
	}

	print_output();

}
