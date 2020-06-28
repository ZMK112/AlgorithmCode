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

bool canFinish1(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> visit;
    vector<node*> graph;

    for (int i = 0; i < numCourses; i++)
    {
        visit.push_back(-1);
        graph.push_back(new node(i));
    }
    
    for (int j = 0; j < prerequisites.size(); j++)
    {
        node *begin = graph[prerequisites[j][1]];
        node *end = graph[prerequisites[j][0]];
        begin->neibor.push_back(end);
    }
    
    for (int i = 0; i < graph.size(); i++)
    {
        if (visit[i] == -1 && !dfs(graph[i], visit))
        {
            return false;
        }
    }
    
    return true;
}


bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<node*> graph;
    vector<int> dep;

    for (int i = 0; i < numCourses; i++)
    {
        dep.push_back(0);
        graph.push_back(new node(i));
    }
    
    for (int i = 0; i < prerequisites.size(); i++)
    {
        node* begin = graph[prerequisites[i][1]];
        node* end = graph[prerequisites[i][0]];
        begin->neibor.push_back(end);
        dep[prerequisites[i][0]]++;
    }
    
    queue<node*> Q;
    for (int i = 0; i < numCourses; i++)
    {
        if (dep[i] == 0)
        {
            Q.push(graph[i]);
        }
    }
    
    while (!Q.empty())
    {
        node* p = Q.front();
        Q.pop();

        for (int i = 0; i < p->neibor.size(); i++)
        {
            dep[p->neibor[i]->flag]--;
            if (dep[p->neibor[i]->flag] == 0)
            {
                Q.push(p->neibor[i]);
            }
        }
    }

    for (int i = 0; i < dep.size(); i++)
    {
        if (dep[i] != 0)
        {
            return false;
        }
    }
    
    return true;
}