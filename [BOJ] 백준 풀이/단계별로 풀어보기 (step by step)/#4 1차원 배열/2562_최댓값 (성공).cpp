#include <iostream>

int main()
{
    int arr[9]; // 9개의 서로 다른 자연수이므로, 배열의 크기를 9로 지정한다.
    int temp;
    int max = 0; // 최댓값을 찾기 위한 임시값
    int pos; // 위치를 찾기 위한 임시값

    for (int i=0; i<9; i++)
    {
        std::cin >> temp;
        arr[i] = temp;
    }

    for (int i=0; i<9; i++)
    {
        if (max < arr[i]) // 최댓값을 찾는 과정
        {
            max = arr[i];
            pos = i + 1; // 위치를 저장해야 하므로 +1을 해야 한다.
        }
    }

    std::cout << max << "\n" << pos;
}