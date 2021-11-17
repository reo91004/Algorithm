#include <iostream>
#include <cstring>

int main()
{
    int C, N;
    int arr[1000] = {0};
    double count, sum;

    std::cin >> C;

    for (int i=0; i<C; i++)
    {
        sum = 0;
        count = 0;

        std::cin >> N;
        
        for (int j=0; j<N; j++)
        {
            std::cin >> arr[j];
            sum = sum + arr[j];
        }
        
        sum /= N;

        for (int k=0; k<N; k++)
            if (sum < arr[k])
                count += 1;
        
        std::cout << std::fixed;
        std::cout.precision(3);
        std::cout << count / N * 100 << "%" << "\n";

    }
}