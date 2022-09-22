// Ориентированный граф на основе смежной матрицы + обход в глубину и ширину

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // Библиотека для ввода - вывода
#include <locale.h> // Библиотека для использования локализации
#define MAX 4 // Количество строк / столбцов

//=====================================BFS (В ширину)=====================================

void breadth_first_search(int adj[][MAX], int visited[], int start)
{
	int queue[MAX], rear = -1, front = -1, i, k;
	for (k = 0; k < MAX; k++)
		visited[k] = 0;

	queue[++rear] = start;
	++front;
	visited[start] = 1;

	while (rear >= front)
	{
		start = queue[front++];
		printf("%c-", start + 65);

		for (i = 0; i < MAX; i++)
		{
			if (adj[start][i] && visited[i] == 0)
			{
				queue[++rear] = i;
				visited[i] = 1;
			}
		}
	}
}

//=====================================DFS (в глубину)=====================================

void depth_first_search(int adj[][MAX], int visited[], int start)
{
	int stack[MAX];
	int top = -1, i, k;
		for (k = 0; k < MAX; k++)
			visited[k] = 0;
    
		stack[++top] = start;
		visited[start] = 1;

		while (top != -1)
		{
			start = stack[top--];
				printf("%c-", start + 65);
			for (i = 0; i < MAX; i++)
			{
				if (adj[start][i] && visited[i] == 0)
				{
					stack[++top] = i;
					visited[i] = 1;
					break;
				}
			}
		}
}

//=====================================Тело программы=====================================


int main()
{
	int visited[MAX] = { 0 };
	int adj[MAX][MAX], i, j;
	int option, size;

	setlocale(LC_ALL, "Rus");

	do
	{
		printf("\n ======ГЛАВНОЕ МЕНЮ====== \n");
		printf("\n 1) Ввести значения в граф \n");
		printf("\n 2) BFS обход \n");
		printf("\n 3) DFS обход \n");
		printf("\n 4) Выход \n");
		printf("\n\n Укажите опцию : \n");
        scanf("%d", &option);

		switch (option) // Использование оператора switch для выбора опции
		{
		case 1:printf("\n Введите смежную матрицу: \n");
			for (i = 0; i < MAX; i++)
			for (j = 0; j < MAX; j++)
			scanf("%d", &adj[i][j]);
			break;

		case 2: printf("BFS (обход в ширину): \n");
			breadth_first_search(adj, visited, 0);
			break;

		case 3: printf("DFS (обход в глубину): \n");
			depth_first_search(adj, visited, 0);
			break;
		}
	}
	while (option != 4);
	getchar();
	return 0;
}