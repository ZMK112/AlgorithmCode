#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

struct node
{
    int flag;
    vector<node*> neibor;
    node(int x) : flag(x){};
};

bool dfs(node* p, vector<int>& visit)
{
    visit[p->flag] = 0;
    
    for (int i = 0; i < p->neibor.size(); i++)
    {
        if (visit[p->neibor[i]->flag] == -1)
        {
            if (dfs(p->neibor[i], visit) == 0)
            {
                return false;
            }
        }
        else if(visit[p->neibor[i]->flag] == 0)
        {
            return false;
        }
    }

    visit[p->flag] = 1;
    return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> visit;
    vector<node*> graph;

    for (int i = 0; i < numCourses; i++)
    {
        visit.push_back(-1);
        graph.push_back(new node(i));
    }
    
    for (int j = 0; j < prerequisites.size(); j++)
    {
        
    }
    

}