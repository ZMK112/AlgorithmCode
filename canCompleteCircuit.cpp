#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total = 0, tank = 0, start = 0;
    for (int i = 0; i < cost.size(); i++)
    {
        tank = gas[i] - cost[i];
        if (tank < 0 )
        {
            start = i + 1;
            total += tank;
            tank = 0;
        }
    }
    return total + tank > 0 ? start : -1;
}