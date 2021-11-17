#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct TreeNode {
    int weight; // 가중치
    char ch;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct {
    TreeNode* ptree;
    char ch;
    int key;
} element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

// 최소 히프 생성
HeapType* create()
{
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h)
{
    h->heap_size = 0;
}

void insert_min_heap(HeapType* h, element item)
{
    int i = ++(h->heap_size);

    while ((i != 1) && (item.key < h->heap[i / 2].key))
    {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }

    h->heap[i] = item;
}

element delete_min_heap(HeapType* h)
{
    int parent, child;
    element item, temp;

    item = h->heap[1]; // 루트
    temp = h->heap[(h->heap_size)--]; // 마지막 노드
    parent = 1;
    child = 2;

    while (child <= h->heap_size)
    { // 현재 노드의 자식노드 중 더 큰 자식노드를 찾는다.
        if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key)
            child++;
        if (temp.key < h->heap[child].key)
            break;

        h->heap[parent] = h->heap[child]; // 부모 노드를 자식 노드로 덮어씌움
        parent = child;
        child *= 2;
    }

    h->heap[parent] = temp;
    return item;
}

// 이진 트리 생성
TreeNode* make_tree(TreeNode* left, TreeNode* right)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));

    node->left = left;
    node->right = right;

    return node;
}

// 이진 트리 제거
void destory_tree(TreeNode* root)
{
    if (root == NULL)
        return;
    destory_tree(root->left);
    destory_tree(root->right);
    free(root);
}

int is_leaf(TreeNode* root)
{
    return !(root->left) && !(root->right);
}

void print_array(int codes[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d", codes[i]);
    printf("\n");
}

void print_codes(TreeNode* root, int codes[], int top) // 트리를 전부 출력
{
    if (root->left) // 좌측은 0
    {
        codes[top] = 0;
        print_codes(root->left, codes, top + 1);
    }

    if (root->right) // 우측은 1
    {
        codes[top] = 1;
        print_codes(root->right, codes, top + 1);
    }

    if (is_leaf(root))
    {
        printf("%c : ", root->ch);
        print_array(codes, top);
    }
}

void huffman_tree(int freq[], char ch_list[], int n)
{
    TreeNode* node, * temp;
    HeapType* heap;
    element e, e1, e2;
    int codes[100];
    int top = 0;

    heap = create();
    init(heap);

    for (int i = 0; i < n; i++) // 각 단어들마다 빈 트리 생성, 이를 최소 heap에 넣는다.
    {
        node = make_tree(NULL, NULL);
        e.ch = node->ch = ch_list[i];
        e.key = node->weight = freq[i];
        e.ptree = node;
        insert_min_heap(heap, e);
    }

    for (int i = 1; i < n; i++) // 본격적으로 허프만 생성. 요소 둘을 합친 트리를 다시 최소 heap에 넣는다.
    {
        e1 = delete_min_heap(heap);
        e2 = delete_min_heap(heap);

        temp = make_tree(e1.ptree, e2.ptree);
        e.key = temp->weight = e1.key + e2.key;
        e.ptree = temp;
        printf("%d + %d -> %d \n", e1.key, e2.key, e.key);
        insert_min_heap(heap, e);
    }

    e = delete_min_heap(heap); // 최종 트리
    print_codes(e.ptree, codes, top);
    destory_tree(e.ptree);
    free(heap);
}

int main(void)
{
    char ch_list[] = { 's', 'i', 'n', 't', 'e' };
    int freq[] = { 4, 6, 8, 12, 15 };
    huffman_tree(freq, ch_list, 5);
    return 0;
}