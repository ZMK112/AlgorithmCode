#include <iostream>
#include <fstream>
#include<sstream>
#include <vector>
#include <queue>
using namespace std;

int maxScoreSightseeingPair(vector<int>& A) {
    int maxs = A[0];
    int sum = 0;
    for (int i = 1; i < A.size(); i++)
    {
        sum = max(sum, maxs + A[i] - i);
        maxs = max(maxs, A[i] + i);
    }
    return sum;
}