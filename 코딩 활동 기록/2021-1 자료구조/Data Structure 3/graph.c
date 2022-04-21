#define _CRT_SECURE_NO_WARNINGS

#include "graph.h"
#include "queue.h"
#include "stack.h"

void print_error() {
	printf("Error\n");
}

void print_arrays(Graph* G) {

	printf("array O : ");
	for (int i = 0; i < G->n; i++) {
		printf("%d ", G->O[i]);
	}
	printf("\n");

	printf("array E : ");
	for (int i = 0; i < G->m; i++) {
		printf("%d ", G->E[i]);
	}
	printf("\n");

	printf("array W : ");
	for (int i = 0; i < G->m; i++) {
		printf("%d ", G->W[i]);
	}
	printf("\n");
}

///////////// Don't touch /////////////

void construct(Graph* G, char* file) {

	FILE* fp = fopen(file, "r");
	int size = 0;
	int count = 0;
	int** temparr;
	int temp = -1;
	
	int n, m = 0; // n은 vertex, m은 edge * 2

	fscanf(fp, "%d", &size);
	n = size;

	G->n = size;

	temparr = malloc(sizeof(int*) * size);

	for (int i = 0; i < size; i++)
	{
		temparr[i] = malloc(sizeof(int) * size);
	}

	for (int i = 0; i < size; i++) // temparr에 배열 일단은 저장
	{
		for (int j = 0; j < size; j++)
		{
			fscanf(fp, "%d", &temparr[i][j]);
		}
	}

	for (int i = 0; i < size; i++) // temparr에 배열 일단은 저장
	{
		for (int j = 0; j < size; j++)
		{
			if (temparr[i][j] != 0) m++; // edge * 2 수 저장
		}
	}

	G->E = malloc((sizeof(int) * m)); // 해당 vertex와 인접한 vertex
	G->O = malloc((sizeof(int) * n)); // 인접한 vertex 개수 (E 먼저 구현)
	G->W = malloc((sizeof(int) * m)); // E의 가중치 (E 먼저 구현)

	for (int i = 0; i < size; i++) // E 구현
	{
		for (int j = 0; j < size; j++)
		{
			if (temparr[i][j] != 0)
			{
				G->E[count] = j;
				count++;
			}
		}	
	}

	G->m = count; // m 저장

	for (int i = 0; i < size; i++) // 강의에서부터 Graph는 모두 0에서 순서대로 생성되는듯 하지만 일단은..
	{
		for (int j = 0; j < size; j++)
		{
			if (temparr[i][j] != 0)
			{
				temp = i;
				break;
			}
		}
		if (temp != -1)
			break;
	}

	count = 1;
	G->O[temp] = 0;

	for (int i = temp + 1; i < m; i++) // O 구현 
	{
		if (G->E[i] > G->E[i + 1])
		{
			G->O[count] = i + 1;
			count++;
		}
	}

	count = 0;

	for (int i = 0; i < size; i++) // W 구현
	{
		for (int j = 0; j < size; j++)
		{
			if (temparr[i][j] != 0)
			{
				G->W[count] = temparr[i][j];
				count++;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		free(temparr[i]);
	}

	free(temparr);
	fclose(fp);
	
}

void print_matrix(Graph* G) {
	
	int count = 0;
	int temp = 0;
	int size = G->n;

	int** temparr = malloc(sizeof(int*) * size);

	for (int i = 0; i < size; i++)
	{
		temparr[i] = malloc(sizeof(int) * size);
	}

	for (int i = 0; i < size; i++) // 초기화
	{
		for (int j = 0; j < size; j++)
		{
			if (G->E[temp] == j)
			{
				if (G->O[count + 1] < temp)
					continue;
				temparr[i][j] = 1;
				temp++;
			}
			else
			{
				temparr[i][j] = 0;
			}
		}

		count++;
	}
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
				printf("%d ", temparr[i][j]);
		}
		
		printf("\n");
	}

	for (int i = 0; i < size; i++)
	{
		free(temparr[i]);
	}

	free(temparr);
}

int adjacent(Graph* G, int u, int v) {
	
	int temp_u, temp_v, temp_uplus, temp_vplus; // (0, 3)이 들어왔다고 가정
	int diffu = 0;
	int diffv = 0;
	int check = 0;
	temp_u = G->O[u]; // O[0] = 0 
	temp_uplus = G->O[u + 1]; // O[1] = 2 
	temp_v = G->O[v]; // O[3] = 7 
	temp_vplus = G->O[v + 1]; // O[4] = 10

	diffu = temp_uplus - temp_u; // 2 - 0 = 2
	diffv = temp_vplus - temp_v; // 10 - 7 = 3

	for (int i = 0; i < diffu; i++)
	{
		if (G->E[temp_u] == v)
		{
			check++;
			break;
		}
		temp_u++;
	}

	for (int i = 0; i < diffv; i++)
	{
		if (G->E[temp_v] == u)
		{
			check++;
			break;
		}
		temp_v++;
	}

	if (check == 2)
		return 1;
	else
		return 0;
}

void add_edge(Graph* G, int i, int j, int weight) {
	
	if (i >= G->n || j >= G->n)
	{
		print_error();
	}
	else if (adjacent(G, i, j) == 1)
	{
		print_error();
	}
	else if (weight > 100 || weight < 1)
	{
		print_error();
	}
	else
	{
		int temp;

		if (i > j)
		{
			temp = i;
			i = j;
			j = temp;
		}

		G->m += 2; // edge가 하나 추가되었으니 2 추가, edge(1, 3)을 추가했다 가정하자.
		int size = G->n;
		int temp_u = G->O[i]; // O[1] = 2 
		int temp_uplus = G->O[i + 1]; // O[2] = 4 
		int temp_v = G->O[j]; // O[3] = 7 
		int temp_vplus = G->O[j + 1]; // O[4] = 10
		int diffu = temp_uplus - temp_u; // 4 - 2 = 2
		int diffv = temp_vplus - temp_v; // 10 - 7 = 3

		int index = -1;		
		int count = -1;

		for (int k = 0; k < diffu; k++)
		{
			if (G->E[temp_u] > j)
			{
				index = temp_u;
			}
			temp_u++;
		}

		if (index == -1)
			index = temp_u;

		realloc(G->E, sizeof(int) * (G->m));

		for (int k = (G->m - 1); k >= index; k--)
		{
			G->E[k + 1] = G->E[k];
			G->W[k + 1] = G->W[k];
		}
		G->E[index] = j;
		G->W[index] = weight;

		index = -1;
		temp_v++;
		temp_vplus++;

		for (int k = 0; k < diffv; k++)
		{
			if (G->E[temp_v] > i)
			{
				index = temp_v;
				break;
			}
			temp_v++;
		}
		
		if (index == -1)
			index = temp_u;

		for (int k = (G->m - 1); k >= index; k--)
		{
			G->E[k + 1] = G->E[k];
			G->W[k + 1] = G->W[k];
		}
		G->E[index] = i;
		G->W[index] = weight;

		// E, W 변형 완료

		if (i < j)
			count = i;
		else
			count = j;

		for (int k = count; k < G->m; k++) // O 구현 (강의에서부터 Graph는 모두 0에서 순서대로 생성되는듯)
		{
			if (G->E[k] > G->E[k + 1])
			{
				G->O[count] = k + 1;
				count++;
			}
		}

		// O 변형 완료
	}
}

void delete_edge(Graph* G, int i, int j) {

	if (adjacent(G, i, j) == 0)
	{
		print_error();
	}
	else
	{
		int temp;

		if (i > j)
		{
			temp = i;
			i = j;
			j = temp;
		}

		int size = G->n;
		int temp_u = G->O[i]; 
		int temp_uplus = G->O[i + 1]; 
		int temp_v = G->O[j]; 
		int temp_vplus = G->O[j + 1]; 
		int diffu = temp_uplus - temp_u; 
		int diffv = temp_vplus - temp_v; 

		int index = -1;
		int count = -1;

		for (int k = 0; k < diffu; k++)
		{
			if (G->E[temp_u] == j)
			{
				index = temp_u;
			}
			temp_u++;
		}

		if (index == -1)
			index = temp_u;

		for (int k = index; k < G->m; k++)
		{
			G->E[k] = G->E[k + 1];
			G->W[k] = G->W[k + 1];
		}

		index = -1;
		temp_v--;
		temp_vplus--;

		for (int k = 0; k < diffv; k++)
		{
			if (G->E[temp_v] == i)
			{
				index = temp_v;
				break;
			}
			temp_v++;
		}

		if (index == -1)
			index = temp_u;

		for (int k = index; k <= G->m; k++)
		{
			G->E[k] = G->E[k + 1];
			G->W[k] = G->W[k + 1];
		}

		G->m -= 2; 
		realloc(G->E, sizeof(int) * (G->m));

		// E, W 변형 완료

		if (i < j)
			count = i;
		else
			count = j;

		for (int k = count; k <= G->m - 1; k++) // O 구현 (강의에서부터 Graph는 모두 0에서 순서대로 생성되는듯)
		{
			if (G->E[k] > G->E[k + 1])
			{
				G->O[count] = k + 1;
				count++;
			}
		}

		// O 변형 완료
	}
}

void print_lexdfs(Graph* G) {
	
	int count = 0;
	int temp = 0;
	int size = G->n;

	int** temparr = malloc(sizeof(int*) * size);

	for (int i = 0; i < size; i++)
	{
		temparr[i] = malloc(sizeof(int) * size);
	}

	for (int i = 0; i < size; i++) // 초기화
	{
		for (int j = 0; j < size; j++)
		{
			if (G->E[temp] == j)
			{
				if (G->O[count + 1] < temp)
					continue;
				temparr[i][j] = 1;
				temp++;
			}
			else
			{
				temparr[i][j] = 0;
			}
		}

		count++;
	}

	// 배운 알고리즘을 활용하기 위해 aAdjacency matrix 형태로 만듦

	STACK s;
	stackcreate(&s);
	int arr_visit[MAX_VERTICES];
	int next_vertex = 0;

	for (int i = 0; i < G->n; i++)
	{
		arr_visit[i] = 0;
	}

	push(&s, next_vertex);
	printf("%d ", next_vertex);
	arr_visit[next_vertex] = 1;

	while (!stackisEmpty(&s))
	{
		count = 0;
		for (int i = 0; i < G->n; i++)
		{
			if (temparr[next_vertex][i] == 1 && arr_visit[i] == 0)
			{
				next_vertex = i;
				push(&s, next_vertex);
				printf("%d ", next_vertex);
				arr_visit[next_vertex] = 1;
				break;
			}

			count++;
		}

		if (count == G->n)
		{
			pop(&s);
			if (!stackisEmpty(&s))
				next_vertex = top(&s);
		}
	}

	for (int i = 0; i < size; i++)
	{
		free(temparr[i]);
	}

	free(temparr);

}

void print_lexbfs(Graph* G) {
	
	int count = 0;
	int temp = 0;
	int size = G->n;

	int** temparr = malloc(sizeof(int*) * size);

	for (int i = 0; i < size; i++)
	{
		temparr[i] = malloc(sizeof(int) * size);
	}

	for (int i = 0; i < size; i++) // 초기화
	{
		for (int j = 0; j < size; j++)
		{
			if (G->E[temp] == j)
			{
				if (G->O[count + 1] < temp)
					continue;
				temparr[i][j] = 1;
				temp++;
			}
			else
			{
				temparr[i][j] = 0;
			}
		}

		count++;
	}

	// 배운 알고리즘을 활용하기 위해 aAdjacency matrix 형태로 만듦

	QUEUE q;
	queuecreate(&q);
	int arr_visit[MAX_VERTICES];
	int next_vertex = 0;

	for (int i = 0; i < G->n; i++)
	{
		arr_visit[i] = 0;
	}

	enqueue(&q, next_vertex);
	arr_visit[next_vertex] = 1;
	while (!queueisEmpty(&q))
	{
		next_vertex = dequeue(&q);
		printf("%d ", next_vertex);

		for (int i = 0; i < G->n; i++)
		{
			if (temparr[next_vertex][i] == 1 && arr_visit[i] == 0)
			{
				enqueue(&q, i);
				arr_visit[i] = 1;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		free(temparr[i]);
	}

	free(temparr);
}

int is_connected(Graph* G) {

	int count = 0;
	int temp = 0;
	int size = G->n;

	int** temparr = malloc(sizeof(int*) * size);

	for (int i = 0; i < size; i++)
	{
		temparr[i] = malloc(sizeof(int) * size);
	}

	for (int i = 0; i < size; i++) // 초기화
	{
		for (int j = 0; j < size; j++)
		{
			if (G->E[temp] == j)
			{
				if (G->O[count + 1] < temp)
					continue;
				temparr[i][j] = 1;
				temp++;
			}
			else
			{
				temparr[i][j] = 0;
			}
		}

		count++;
	}

	STACK s;
	stackcreate(&s);
	int arr_visit[MAX_VERTICES];
	int next_vertex = 0;

	for (int i = 0; i < G->n; i++)
	{
		arr_visit[i] = 0;
	}

	push(&s, next_vertex);
	arr_visit[next_vertex] = 1;

	while (!stackisEmpty(&s))
	{
		count = 0;
		for (int i = 0; i < G->n; i++)
		{
			if (temparr[next_vertex][i] == 1 && arr_visit[i] == 0)
			{
				next_vertex = i;
				push(&s, next_vertex);
				arr_visit[next_vertex] = 1;
				break;
			}

			count++;
		}

		if (count == G->n)
		{
			pop(&s);
			if (!stackisEmpty(&s))
				next_vertex = top(&s);
		}
	}

	count = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr_visit[i] == 1)
		{
			count++;
		}
	}

	for (int i = 0; i < size; i++)
	{
		free(temparr[i]);
	}

	free(temparr);

	if (size == count)
		return 1;
	else
		return 0;
}

int shortest_path(Graph* G, int source, int destination)
{
	int count = 0;
	int temp = 0;
	int size = G->n;

	int** temparr = malloc(sizeof(int*) * size);

	for (int i = 0; i < size; i++)
	{
		temparr[i] = malloc(sizeof(int) * size);
	}

	for (int i = 0; i < size; i++) // 초기화
	{
		for (int j = 0; j < size; j++)
		{
			if (G->E[temp] == j)
			{
				if (G->O[count + 1] < temp)
					continue;
				temparr[i][j] = G->W[temp];
				temp++;
			}
			else
			{
				temparr[i][j] = NULL;
			}
		}

		count++;
	}

	count = 0;
	temp = 0;

	int* path = (int*)malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++)
	{
		path[i] = -1;
	}

	int arr[MAX_VERTICES];
	int dist_u[MAX_VERTICES];
	int arr_visit[MAX_VERTICES];
	int next_vertex = 0;

	for (int i = 0; i < G->n; i++)
	{
		arr_visit[i] = 0;

		if (i == source)
		{
			dist_u[i] = 0;
		}
		else
		{
			dist_u[i] = 101;
		}
	}

 	while (count < G->n)
	{
		int min = 101;

		for (int i = 0; i < G->n; i++)
		{
			if (arr_visit[i] == 0 && dist_u[i] < min)
			{
				min = dist_u[i];
				next_vertex = i;
			}	
		}

		if (next_vertex == destination)
		{
			int p = next_vertex;
			while (path[p] != -1)
			{
				arr[temp] = path[p];
				p = path[p];
				temp++;
			}

			for (int i = temp - 1; i >= 0; i--)
				printf("%d ", arr[i]);
			printf("%d", destination);

			for (int i = 0; i < size; i++)
			{
				free(temparr[i]);
			}

			free(temparr);

			return dist_u[destination];
		}
		else
		{
			arr_visit[next_vertex] = 1;

			for (int i = 0; i < G->n; i++)
			{
				if (temparr[next_vertex][i] == NULL)
					continue;
				if (dist_u[i] > dist_u[next_vertex] + temparr[next_vertex][i])
				{
					dist_u[i] = dist_u[next_vertex] + temparr[next_vertex][i];
					path[i] = next_vertex;
			 	}
			}
		}

		count++;
	}

	int p = next_vertex;
	while (path[p] != -1)
	{
		arr[temp] = path[p];
		p = path[p];
		temp++;
	}

	for (int i = temp - 1; i >= 0; i--)
		printf("%d ", arr[i]);
	printf("%d", destination);

	for (int i = 0; i < size; i++)
	{
		free(temparr[i]);
	}

	free(temparr);

	return dist_u[destination];
}