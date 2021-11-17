#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#define Item std::pair<int, int>
#define N 3
#define fs first
#define sd second

bool compare(Item a, Item b);

//Item fs=value, sd=weight
int main()
{
    int W = 50;

    Item arr[N];

    arr[0] = std::make_pair(60, 10);
    arr[1] = std::make_pair(100, 20);
    arr[2] = std::make_pair(120, 30);

    std::sort(arr, arr + N, compare);

    Item Bag(0, 0);

    for (int i = 0; i < N; i++)
    {
        if (W > Bag.sd + arr[i].sd)
        {
            Bag = std::make_pair(Bag.fs + arr[i].fs, Bag.sd + arr[i].sd);
        }
        else if (W == Bag.sd)
        {
            break;
        }
        else
        {
            int p = arr[i].fs / arr[i].sd;
            Bag = std::make_pair(Bag.fs + p * (W - Bag.sd), W);
        }
    }

    std::cout << "Bag's value is " << Bag.fs << "\nBag's weight is " << Bag.sd << std::endl;

    return 0;
}

bool compare(Item a, Item b)
{
    return a.fs / a.sd >= b.fs / b.sd;
}