#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

typedef struct order {
    int mNumber, mQuantity, mPrice;
} order;

struct Find {
    int num;
    bool operator() (order temp) {
        return (temp.mNumber == num);
    }

};

deque<deque<order>> buying(5);
deque<deque<order>> selling(5);
deque<deque<int>> profit(5);

bool cmpbuy(const order& a, const order& b)
{
    if (a.mPrice > b.mPrice)
        return true;
    else if (a.mPrice == b.mPrice)
        if (a.mNumber < b.mNumber)
            return true;

    return false;
}

bool cmpsell(const order& a, const order& b)
{
    if (a.mPrice < b.mPrice)
        return true;
    else if (a.mPrice == b.mPrice)
        if (a.mNumber < b.mNumber)
            return true;

    return false;
}

void init()
{
    deque<deque<order>> tempbuying(5);
    deque<deque<order>> tempselling(5);
    deque<deque<int>> tempprofit(5);

    buying = tempbuying;
    selling = tempselling;
    profit = tempprofit;
}

int buy(int mNumber, int mStock, int mQuantity, int mPrice)
{
    order tempbuy;
    tempbuy.mNumber = mNumber; tempbuy.mQuantity = mQuantity; tempbuy.mPrice = mPrice;
    buying[mStock - 1].push_back(tempbuy);

    if (selling[mStock - 1].size() != 0)
        sort(selling[mStock - 1].begin(), selling[mStock - 1].end(), cmpsell);

    while (1) {
        if (buying[mStock - 1].size() == 0)
            return 0;

        if (selling[mStock - 1].size() == 0)
            return buying[mStock - 1].back().mQuantity;

        // 매도 희망 가격이 더 낮은 주문이 있다면
        if (buying[mStock - 1].back().mPrice >= selling[mStock - 1].front().mPrice) {
            // 매도량이 매수량보다 적다면 
            if (buying[mStock - 1].back().mQuantity - selling[mStock - 1].front().mQuantity >= 0) {
                buying[mStock - 1].back().mQuantity -= selling[mStock - 1].front().mQuantity;
                profit[mStock - 1].push_back(selling[mStock - 1].front().mPrice);
                selling[mStock - 1].pop_front();

                if (buying[mStock - 1].back().mQuantity == 0) {
                    buying[mStock - 1].pop_back();
                    return 0;
                }
                else
                    continue;
            }

            // 매도량이 매수량보다 많다면 
            else {
                selling[mStock - 1].front().mQuantity -= buying[mStock - 1].back().mQuantity;
                profit[mStock - 1].push_back(selling[mStock - 1].front().mPrice);
                buying[mStock - 1].pop_back();
                return 0;
            }
        }

        else {
            return buying[mStock - 1].back().mQuantity;
        }
    }
}

int sell(int mNumber, int mStock, int mQuantity, int mPrice)
{
    order tempsell;
    tempsell.mNumber = mNumber; tempsell.mQuantity = mQuantity; tempsell.mPrice = mPrice;
    selling[mStock - 1].push_back(tempsell);

    if (buying[mStock - 1].size() != 0)
        sort(buying[mStock - 1].begin(), buying[mStock - 1].end(), cmpbuy); // 내림차순 정렬

    while (1) {
        if (selling[mStock - 1].size() == 0)
            return 0;

        if (buying[mStock - 1].size() == 0)
            return selling[mStock - 1].back().mQuantity;

        // 매수 희망 가격이 매도 희망 가격 이상이라면
        if (buying[mStock - 1].front().mPrice >= selling[mStock - 1].back().mPrice) {
            // 매수량이 매도량보다 적다면 
            if (buying[mStock - 1].front().mQuantity - selling[mStock - 1].back().mQuantity <= 0) {
                selling[mStock - 1].back().mQuantity -= buying[mStock - 1].front().mQuantity;
                profit[mStock - 1].push_back(buying[mStock - 1].front().mPrice);
                buying[mStock - 1].pop_front();

                if (selling[mStock - 1].back().mQuantity == 0) {
                    selling[mStock - 1].pop_back();
                    return 0;
                }
                else
                    continue;
            }

            // 매수량이 매도량보다 많다면
            else {
                buying[mStock - 1].front().mQuantity -= selling[mStock - 1].back().mQuantity;
                profit[mStock - 1].push_back(buying[mStock - 1].front().mPrice);
                selling[mStock - 1].pop_back();
                return 0;
            }
        }

        else {
            return selling[mStock - 1].back().mQuantity;
        }
    }
}

void cancel(int mNumber)
{
    Find find;
    find.num = mNumber;

    for (int i = 0; i < 5; i++) {
        auto it = find_if(buying[i].begin(), buying[i].end(), find);
        if (it == buying[i].end()) {
            it = find_if(selling[i].begin(), selling[i].end(), find);
            if (it == selling[i].end())
                continue;
            else {
                selling[i].erase(it);
                break;
            }
        }
        else {
            buying[i].erase(it);
            break;
        }
    }
}

int bestProfit(int mStock)
{
    int val = 0;
    int len = profit[mStock - 1].size();
    for (int i = 0; i < len - 1; i++) {
        int min = *min_element(profit[mStock - 1].begin(), profit[mStock - 1].end() - i - 1);
        val = max(val, profit[mStock - 1][len - 1 - i] - min);
    }

    return val;
}