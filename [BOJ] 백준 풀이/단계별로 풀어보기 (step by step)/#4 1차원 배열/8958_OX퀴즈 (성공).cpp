#include <iostream>
#include <cstring>

int main()
{
    int N;
    char arr[80];
    int count, score, len;

    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        score = 0;
        count = 1;

        std::cin >> arr;
        len = strlen(arr);

        for (int j = 0; j < len; j++)
        {
            if (arr[j] == 'O')
            {
                score += count;
                count++;
            }

            else if (arr[j] == 'X')
                count = 1;
        }

        std::cout << score << "\n";
    }
}