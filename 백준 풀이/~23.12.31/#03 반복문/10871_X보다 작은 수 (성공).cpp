#include <iostream>

int main() 
{
    int N, X, input;

    std::cin >> N >> X;

    for (int i=0; i<N; i++)
    {
        std::cin >> input;

        if (X > input)
            std::cout << input << " ";
    }
}