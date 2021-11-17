#include <stdio.h>

void MergeSort(int arr[], int left, int right);
void Merge(int arr[], int left, int mid, int right);

int main()
{
    int arr[7] = {3, 2, 6, 7, 1, 4, 5};

    printf("정렬 전 : ");

    for (int i = 0; i < 7; i++)
        printf("%d ", arr[i]);

    MergeSort(arr, 0, 6);

    printf("\n정렬 후 : ");

    for (int i = 0; i < 7; i++)
        printf("%d ", arr[i]);

    return 0;
}

void MergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2; // 중앙에서 나눠야 하기 때문에
        MergeSort(arr, left, mid); // 다시 recursive하게 넣음
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right); // 둘을 합침
    }
}

void Merge(int arr[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left; // 각각 i, j, k에 위치 기억해둠
    int temp[7]; // 임시 배열

    // 합치는 과정
    // 먼저 i는 left였으니 mid를 넘어가면 안되고, j는 mid+1이었으니 right를 넘어가면 안된다.
    // 그 후, 각 배열에 있는 (실제로는 배열 하나지만) 값을 비교해 temp에 넣는다.
    // 만약 i나 j가 mid를 넘어가면 이미 모든 값들이 들어간 것이므로 종료한다.

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // 둘중에 이미 조건에 맞지 않는 while문은 실행되지 않고, 나머지는 남은 숫자 옮김

    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    for (int a = left; a <= right; a++)
        arr[a] = temp[a];
}