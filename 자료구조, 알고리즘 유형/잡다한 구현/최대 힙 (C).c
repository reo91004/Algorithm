#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
    int key;
} element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

// 생성
HeapType *create()
{
    return (HeapType*)malloc(sizeof(HeapType));
}

// 초기화
void init(HeapType *h)
{
    h->heap_size = 0;
}

// 현재 요소의 개수가 heap_size인 히프 h에 item 삽입
// 삽입
void insert_max_heap(HeapType *h, element item)
{
    int i = ++(h->heap_size);

    while ((i != 1) && (item.key > h->heap[i/2].key))
    {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }

    h->heap[i] = item;
}

element delete_max_heap(HeapType *h)
{
    int parent, child;
    element item, temp;

    item = h->heap[1]; // 루트
    temp = h->heap[(h->heap_size)--]; // 마지막 노드
    parent = 1;
    child = 2;

    while (child <= h->heap_size) 
    { // 현재 노드의 자식노드 중 더 큰 자식노드를 찾는다.
        if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)
            child++;
        if (temp.key >= h->heap[child].key)
            break;
        
        h->heap[parent] = h->heap[child]; // 부모 노드를 자식 노드로 덮어씌움
        parent = child;
        child *= 2;
    }

    h->heap[parent] = temp;
    return item;
}

int main(void)
{
    element e1 = {10}, e2 = {5}, e3 = {30};
    element e4, e5, e6;
    HeapType *heap;

    heap = create();
    init(heap);

    insert_max_heap(heap, e1);
    insert_max_heap(heap, e2);
    insert_max_heap(heap, e3);

    e4 = delete_max_heap(heap);
    printf("< %d >", e4.key);
}
