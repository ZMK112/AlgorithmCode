#include <iostream>
#include <vector>
#include <set>                                                                                 
using namespace std;

vector<int> ress;
typedef multiset<int>::iterator setIter;

vector<int> getLeastNumbers(vector<int>& arr, int k) {
    multiset<int> res;
    if (k < 1 || arr.size() < k)
    {
        ress.assign(res.begin(), res.end());
        return ress;
    }

    for (vector<int>::iterator iter = arr.begin(); iter != arr.end(); ++iter)
    {
        if (res.size() < k)
        {
            res.insert(*iter);
        }
        else
        {
            setIter iters = res.end();
            int c= *iters;
            if (*iter < *iters)
            {
                res.erase(iters);
                res.insert(*iter);
            }
        }
    }

    ress.assign(res.begin(), res.end());
    return ress;
}

int main()
{
    vector<int> arr = {6,5,4};
    vector<int> aa=getLeastNumbers(arr,2);
    return 0;
}