#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    return a.first > b.first;
}

int getMin(int dis, int quant, vector<pair<int, int>>& stop)
{
    priority_queue<int> q;
    int res = 0;
    stop.push_back({0, 0});
    sort(stop.begin(), stop.end(), cmp);

    for (int i = 0; i < stop.size(); i++)
    {
        int distance = dis - stop[i].first;
        
        while (!q.empty() && quant < distance)
        {
            quant += q.top();
            q.pop();
            res++;
        }

        if (q.empty() && quant < distance)
        {
            return -1;
        }

        quant = quant - distance;
        dis = stop[i].first;
        q.push(stop[i].second);
    }
    return res;
}

int main(){
	std::vector<std::pair<int, int> > stop;
	int N;
	int L;
	int P;
	int distance;
	int fuel;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d %d", &distance, &fuel);
		stop.push_back(std::make_pair(distance, fuel));
	}
	scanf("%d %d", &L, &P);
	printf("%d\n", getMin(L, P, stop));
	return 0;
}