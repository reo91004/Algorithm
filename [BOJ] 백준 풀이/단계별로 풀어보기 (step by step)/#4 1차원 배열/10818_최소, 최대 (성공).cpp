#include <iostream>
int arr[1000001];

int main()
{
    int N;
    int min = 1000000;
    int max = -1000000;

    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];

        if (min > arr[i])
            min = arr[i];
        if (max < arr[i])
            max = arr[i];
    }

    std::cout << min << " " << max;

    return 0;
}