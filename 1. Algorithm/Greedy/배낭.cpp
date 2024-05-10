#include <iostream>
#include <vector>
#include <algorithm>

int W = 50;

using namespace std;

bool sortingkp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first / p1.second >= p2.first / p2.second;
}

void greedy_knaspack(vector<pair<int, int>>& kp, int n)
{
    vector<pair<int, int>> p; // 단위 무게당 가치 저장

    for (int i = 0; i < n; i++)
        p.push_back(make_pair(kp[i].first / kp[i].second, 0)); // p에 삽입

    sort(p.begin(), p.end(), greater<>());
    sort(kp.begin(), kp.end(), sortingkp);

    int cw = W;
    int cnt = 0;
    int value = 0;

    while (cw > 0 && cnt < n)
    {
        p[cnt].second = min(kp[cnt].second, cw); // 들어가지 않은 값 중 가장 가치가 높은 것과 총합 중 최소

        if (cw - p[cnt].second <= 0)
        {
            float temp = (cw / (float)kp[cnt].second);
            value = value + (float)kp[cnt].first * temp;
            cw = cw - cw * (cw / kp[cnt].second);
        }
        else
        {
            value = value + kp[cnt].first;
            cw = cw - kp[cnt].second, cw;
        }

        cout << value << "\n";
        cnt++;

        if (cw == 0)
            break;
    }
}

int main()
{
    vector<pair<int, int>> kp; // 가치, 무게

    kp.push_back(make_pair(60, 10));
    kp.push_back(make_pair(100, 20));
    kp.push_back(make_pair(120, 30));

    greedy_knaspack(kp, kp.size());
}