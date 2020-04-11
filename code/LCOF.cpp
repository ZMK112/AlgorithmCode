#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int findRepeatNumber(vector<int>& nums)
{
    int lens = nums.size();
    for(int i = 0; i < lens; i++){
        while (nums[i] != i){
            if (nums[i] == nums[nums[i]])
            {
                return nums[i];
            }
            swap(nums[i], nums[nums[i]]);
        }
    }
    return 0;
}


bool containsDuplicate_one(vector<int>& nums)
{
    unordered_set<int> dup(nums.begin(), nums.end()); 
    if (dup.size() != nums.size()){
        return true;
    }
    return false;
}

bool containsDuplicate(vector<int>& nums)
{
    int lens = nums.size();
    unordered_map<int,int> dup; 
    if (lens < 2){
        return false;
    }
    
    for(int i = 0; i < lens; i++){
        dup[nums[i]]++;
        if(dup[nums[i]] > 1){
            return true;
        }
    }
    return false;
}

bool Find(int* matrix, int rows, int columns, int numbers)
{
    bool found = false;
    if (matrix != nullptr && rows > 0 && columns > 0)               
    {
        int row = 0;
        int column = columns - 1;
        while (row < rows && columns>= 0)       
        {
            if (matrix[rows * columns + columns] == numbers){
                found = true;
                break;
            }
            else if(matrix[row * columns + column] > numbers){
                column--;
            }
            else{
                row++;
            }
        }
    }
    return found;
}

// searchMatrix
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
{   
    if (matrix.empty())
    {
        return  false;
    }
    
    int rows = matrix.size();
    int columns = matrix[0].size();
    int row = 0;
    int column = columns - 1;
    if(rows > 0 || columns > 0){
        while (row < rows && column > -1){
            if (matrix[row][column] == target)
            {   
                return true;
            }
            else if (matrix[row][column] > target)
            {
                column--;
            }
            else
            {
                row++;
            }
        }
    }
    return false;
}

// void replaceBlank(char string[], int length)
// {
//     if (string == nullptr || length <= 0)
//     {
//         return;
//     }
//     int rawLength = 0;
//     int numBlank = 0;
//     int i = 0;
//     while (string[i] != '\0')
//     {
//         rawLength++;
//         if(string[i] == ' '){
//             numBlank++;
//         }
//         i++;
//     }

//     int length = rawLength + numBlank * 2;
//     int p1 = rawLength;
//     int p2 = length;
//     while (p1 > -1 && p2 > p1)
//     {
//         if(string[p1] = ' '){
//             string[p2--] = '0';
//             string[p2--] = '2';
//             string[p2--] = '%';
//         }
//         else
//         {
//             string[p2--] = string[p1];
//         }
//         p1--;
//     }
    
     
    
// }

string replaceSpace(string s)
{
    int rawLength = s.length();
    int numBlank = 0;
    if (rawLength == 0)
    {
        return s;
    }
    
    for(int i = 0; i < rawLength; i++){
        if (s[i] == ' '){
            numBlank++;
        }
    }
    
    int p2 = rawLength + 2 * numBlank;
    int p1 = rawLength;
    char string[p2];

    while (p1 > -1 && p2 > p1)
    {
        if(s[p1] == ' '){
            string[p2--] = '0';
            string[p2--] = '2';
            string[p2--] = '%';
        }
        else
        {
            string[p2--] = s[p1];
        }
        p1--;
    }
    printf("%s",string);
    return s;
}

int main()
{
    // vector<vector<int>> nums = {{-5}};
    // findNumberIn2DArray(nums,-5);
    replaceSpace("We are happy.");
    return 0;
}
