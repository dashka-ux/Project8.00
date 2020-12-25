#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale>
#include <iostream>
#include <conio.h>
#include <time.h>
#include <stack>
#include <queue>
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

using namespace std;
int* dist;
int* dist_2;
int* visited;
int** graph;			// взвешанный ориентированный
int** graph_2;			// взвешанный неориентированный
queue<int>Q;
queue<int>QQ;
int start, start_2;
int N, N_2, j, i, R, max1, dia;
int* ecs;

void BFSD(int v, int N, int** graph) {

	Q.push(v);
	dist[v] = 0;
	while (!Q.empty()) {
		v = Q.front();
		Q.pop();
		for (int i = 0; i < N; i++) {
			if ((graph[v][i] > 0) && (dist[i] == -1)) {
				Q.push(i);
				dist[i] = dist[v] + graph[v][i];
			}
		}
	}
}


int main() {
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Ведите размер матрицы  ");
	scanf_s("%d", &N_2);
	srand(time(NULL));
	graph_2 = new int* [N_2];
	dist_2 = new int[N_2];
	visited = new int[N_2];
	ecs = new int [N_2];

	for (int i = 0; i < N_2; i++)
	{
		graph_2[i] = new int[N_2];
	}
	for (int i = 0; i < N_2; i++)
	{
		dist_2[i] = -1;
	}
	for (int i = 0; i < N_2; i++)
	{
		ecs[i] = 3;
	}

	printf("\n Матрица смежности для взвешенного неориентированного графа \n\n");

	for (i = 0; i < N_2; i++)
	{
		for (j = i; j < N_2; ++j)
		{
			graph_2[i][j] = graph_2[j][i] = rand() % 10;
			graph_2[i][i] = graph_2[j][j] = 0; // чтобы петля(узел) не создавалась
		}

	}
	printf("   ");
	for (j = 0; j < N_2; j++)
	{
		printf("%4d  ", j + 1); //горизонт
	}
	printf("\n\n");
	for (i = 0; i < N_2; i++) {

		printf(" %d ", i + 1); // вертик

		for (j = 0; j < N_2; j++)
		{
			printf("%4d  ", graph_2[i][j]);
		}
		printf("\n\n");
	}

	printf("\n\n Введите начальную вершину ");
	for (start_2 = 0; start_2 < N_2; start_2++) {
		//BFSD_2(start_2 - 1, N_2, graph_2);
		dist = new int[N_2];
		for (int i = 0; i < N_2; i++)
		{
			dist[i] = -1;
		}
		BFSD(start_2 , N_2, graph_2);
		printf("\n\n Вершины      ");
		for (int i = 1; i <= N_2; i++) {
			printf("|%3d ", i);
		}
		printf("\n Расстояние   ");
		for (int i = 0; i < N_2; i++) {
			printf("|%3d ", dist[i]);
		}
		printf("\n\n");

		max1 = 0;
		for (int i = 0; i < N_2; i++)
		{
			if (dist[i] >= max1)
				max1 = dist[i];
		}
		ecs[start_2] = max1;
		{
		dia = 0;
		for (int i = 0; i < N_2; i++)
		{
			if (ecs[i] >= dia)
				dia = ecs[i];
		}
		ecs[start_2] = dia;
	}
	
}

	printf("\n эксцентриситет   ");
	for (int i = 0; i < N_2; i++) {
		printf("|%3d ", ecs[i]);
	}
	for (int i = 0; i < N_2; i++)
		{
			if (dist[i] >= max1)
				max1 = dist[i];
		}
		ecs[start_2] = max1;

		printf("\n диаметр   ");
		for (int i = 0; i < N_2; i++) {
			printf("|%3d ", dia);
		}
		for (int i = 0; i < N_2; i++)
		{
			if (ecs[i] >= dia)
				dia = ecs[i];
		}
		ecs[start_2] = dia;
}
