#include <iostream>
#define MAX 1000001

using namespace std;

// 문제 이름 : 가운데를 말해요
// 최대 힙, 최소 힙 하나씩 써서 구현하였다.

int min_heap[MAX];
int max_heap[MAX];
int min_heap_size = 0;
int max_heap_size = 0;

void insert_max_heap(int item) {
	int i = ++max_heap_size;

	while ((i != 1) && (item > max_heap[i / 2])) {
		max_heap[i] = max_heap[i / 2];
		i /= 2;
	}

	max_heap[i] = item;
}

void insert_min_heap(int item) {
	int i = ++min_heap_size;

	while ((i != 1) && (item < min_heap[i / 2])) {
		min_heap[i] = min_heap[i / 2];
		i /= 2;
	}

	min_heap[i] = item;
}

void delete_max_heap() {
	int item = max_heap[1]; // 루트
	int temp = max_heap[(max_heap_size)--]; // 마지막 노드
	int parent = 1;
	int child = 2;

	while (child <= max_heap_size)
	{ // 현재 노드의 자식노드 중 더 큰 자식노드를 찾는다.
		if ((child < max_heap_size) && (max_heap[child]) < max_heap[child + 1])
			child++;
		if (temp >= max_heap[child])
			break;

		max_heap[parent] = max_heap[child]; // 부모 노드를 자식 노드로 덮어씌움
		parent = child;
		child *= 2;
	}

	max_heap[parent] = temp;
}

void delete_min_heap() {
	int item = min_heap[1]; // 루트
	int temp = min_heap[(min_heap_size)--]; // 마지막 노드
	int parent = 1;
	int child = 2;

	while (child <= min_heap_size)
	{ // 현재 노드의 자식노드 중 더 큰 자식노드를 찾는다.
		if ((child < min_heap_size) && (min_heap[child]) > min_heap[child + 1])
			child++;
		if (temp < min_heap[child])
			break;

		min_heap[parent] = min_heap[child]; // 부모 노드를 자식 노드로 덮어씌움
		parent = child;
		child *= 2;
	}

	min_heap[parent] = temp;
}

int compare(int item) {
	// 첫 번째 삽입 때, 무조건 max heap에 처음 들어가야 한다.
	if (max_heap_size == 0) {
		insert_max_heap(item);
		return max_heap[1];
	}
	
	if (max_heap_size - min_heap_size == 1)
		insert_min_heap(item);
	else
		insert_max_heap(item);

	if (max_heap[1] > min_heap[1]) {
		int tempmax = max_heap[1];
		int tempmin = min_heap[1];
		delete_max_heap();
		delete_min_heap();

		insert_max_heap(tempmin);
		insert_min_heap(tempmax);
	}


	// 일단 숫자는 추가했다. 더 작은 숫자를 리턴하면 된다.

	if (max_heap_size == 1 && min_heap_size == 0)
		return max_heap[1];

	if (min_heap[1] <= max_heap[1])
		return min_heap[1];
	else
		return max_heap[1];

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, temp;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> temp;

		cout << compare(temp) << "\n";
	}
}