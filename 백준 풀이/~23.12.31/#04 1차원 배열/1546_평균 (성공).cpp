#include <iostream>

int main()
{
    int N, M = 0;
    int arr[1000] = {0};
    float sum = 0.0;

    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
        if (M < arr[i])
            M = arr[i];
    }

    for (int i = 0; i < N; i++)
        sum += ((float)arr[i] / (float)M * 100);

    std::cout << sum / N;

}