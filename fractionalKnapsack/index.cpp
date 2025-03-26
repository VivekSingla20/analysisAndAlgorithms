#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int val;
    int wt;
    double ratio;
};

bool comp(Item a, Item b)
{
    return a.ratio > b.ratio;
}

double knapsack(vector<Item> &items, int cap)
{
    sort(items.begin(), items.end(), comp);

    double total = 0.0;
    int curr = 0;

    for (int i = 0; i < items.size(); i++)
    {
        if (curr + items[i].wt <= cap)
        {
            curr += items[i].wt;
            total += items[i].val;
        }
        else
        {
            int remain = cap - curr;
            total += items[i].val * ((double)remain / items[i].wt);
            break;
        }
    }

    return total;
}

int main()
{
    int n, cap;
    cout << "enter number of items: ";
    cin >> n;

    cout << "enter maximum capacity of knapsack: ";
    cin >> cap;

    vector<Item> items(n);
    cout << "enter value and weight for each item:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "item " << i + 1 << " (value weight): ";
        cin >> items[i].val >> items[i].wt;
        items[i].ratio = (double)items[i].val / items[i].wt;
    }

    double max = knapsack(items, cap);
    cout << "maximum value in knapsack: " << max << endl;

    return 0;
}
