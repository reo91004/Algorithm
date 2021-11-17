#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> Multiplication(const vector<int> &a, const vector<int> &b);
void addTo(vector<int> &a, const vector<int> &b, int k);
void subFrom(vector<int> &a, const vector<int> &b);
void normalize(vector<int> &num);
vector<int> multiply(const vector<int> &a, const vector<int> &b);

int main()
{
    vector<int> x, y, result;
    string temp;

    cout << "첫 번째 수 입력 : ";
    cin >> temp;

    for (int i = temp.size() - 1; i >= 0; i--)
        x.push_back(temp[i] - '0');

    cout << "두 번째 수 입력 : ";
    cin >> temp;

    for (int i = temp.size() - 1; i >= 0; i--)
        y.push_back(temp[i] - '0');

    result = Multiplication(x, y);

    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i];
}

vector<int> Multiplication(const vector<int> &x, const vector<int> &y)
{
    int xlen = x.size();
    int ylen = y.size();

    if (xlen < ylen)
        Multiplication(y, x);

    if (xlen == 0 || ylen == 0)
        return vector<int>();

    if (xlen <= 5)
        return multiply(x, y);

    int half = xlen / 2;

    vector<int> x0(x.begin(), x.begin() + half);
    vector<int> x1(x.begin() + half, x.end());
    vector<int> y0(y.begin(), y.begin() + min<int>(y.size(), half));
    vector<int> y1(y.begin() + min<int>(y.size(), half), y.end());

    vector<int> p1 = Multiplication(x1, y1);
    vector<int> p0 = Multiplication(x0, y0);

    addTo(x0, x1, 0);
    addTo(y0, y1, 0);

    vector<int> p2 = Multiplication(x0, y0);

    subFrom(p2, p0);
    subFrom(p2, p1);

    vector<int> result;
    addTo(result, p0, 0);
    addTo(result, p2, half);
    addTo(result, p1, half + half);

    return result;
}

void addTo(vector<int> &x, const vector<int> &y, int k)
{
    int length = y.size();
    x.resize(max(x.size() + 1, y.size() + k));

    for (int i = 0; i < length; i++)
        x[i + k] += y[i];

    for (int i = 0; i < x.size(); i++)
        if (x[i] >= 10)
        {
            x[i + 1] += x[i] / 10;
            x[i] %= 10;
        }

    while (x.size() > 1 && x.back() == 0)
        x.pop_back();
}

void subFrom(vector<int> &a, const vector<int> &b)
{
    int length = b.size();
    a.resize(max(a.size() + 1, b.size()) + 1);

    for (int i = 0; i < length; i++)
        a[i] -= b[i];

    for (int i = 0; i < a.size(); i++)
        if (a[i] < 0)
        {
            a[i] += 10;
            a[i + 1] -= 1;
        }
}

// 자릿수 올림을 처리한다.
void normalize(vector<int> &num)
{
    num.push_back(0);

    for (int i = 0; i < num.size() - 1; i++) //num.size()-1 중요
    {
        if (num[i] < 0)
        {
            int borrow = (abs(num[i]) + 9) / 10;
            num[i + 1] -= borrow;
            num[i] += borrow * 10;
        }
        else
        {
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    while (num.size() > 1 && num.back() == 0)
        num.pop_back();
}

vector<int> multiply(const vector<int> &a, const vector<int> &b)
{
    vector<int> c(a.size() + b.size() + 1, 0);
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            c[i + j] += (a[i] * b[j]);

    normalize(c);
    return c;
}
