#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int> &prices)
{
    size_t size{prices.size()};
    // vector needs at least 2 days
    if (size < 2)
        return 0;

    auto min{min_element(prices.begin(), prices.end())};
    auto max{max_element(prices.begin(), prices.end())};
    auto buy_itr{find(prices.begin(), prices.end(), *min)};
    auto sell_itr{find(prices.rbegin(), prices.rend(), *max)};
    auto buy{distance(prices.begin(), buy_itr)};
    auto sell{distance(prices.rbegin(), sell_itr)};
    sell = size - 1 - sell;
    if (buy<sell && * max> * min) // sell date was after buy date
        return *max - *min;

    int profit{};
    for (int i{}; i < size - 1; i++)
    {
        for (int j{i + 1}; j < size; j++)
        {
            if (profit < prices[j] - prices[i])
                profit = prices[j] - prices[i]; // update if profit can be increased
        }
    }

    return profit > 0 ? profit : 0; // if the profit was nonpositive, return zero
}

int main()
{
    vector<int> vec{7, 1, 5, 3, 6, 4};
    vector<int> vec2{7, 6, 4, 3, 1};
    vector<int> vec3{2, 3, 1, 5, 7, 8};
    vector<int> vec4;
    vector<int> vec5{2, 4, 1};
    vector<int> vec6{2, 1, 2, 1, 0, 1, 2};
    vector<int> vec7{4, 7, 1, 2};
    vector<int> vec8{4, 1, 2};
    vector<int> vec9{7, 4, 1, 2};
    vector<int> vec10{4, 11, 1, 7, 2};
    vector<int> vec11{3, 3, 5, 0, 0, 3, 1, 4};
    cout << maxProfit(vec) << endl;
    cout << maxProfit(vec2) << endl;
    cout << maxProfit(vec3) << endl;
    cout << maxProfit(vec4) << endl;
    cout << maxProfit(vec5) << endl;
    cout << maxProfit(vec6) << endl;
    cout << maxProfit(vec7) << endl;
    cout << maxProfit(vec8) << endl;
    cout << maxProfit(vec9) << endl;
    cout << maxProfit(vec10) << endl;
    cout << maxProfit(vec11) << endl;
    return 0;
}