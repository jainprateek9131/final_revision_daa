Input: N = 4, arr[] = [5, 2, 6, 4], diff = 3
Output: 1
Explanation: We can only have a single partition which is shown below:
{5, 2} and {6, 4} such that S1 = 7 and S2 = 10 and thus the difference is 3

Input: N = 5, arr[] = [1, 2, 3, 1, 2], diff = 1
Output: 5
Explanation: We can have five partitions which is shown below
{1, 3, 1} and {2, 2} – S1 = 5, S2 = 4
{1, 2, 2} and {1, 3} – S1 = 5, S2 = 4
{3, 2} and {1, 1, 2} – S1 = 5, S2 = 4
{1, 2, 2} and {1, 3} – S1 = 5, S2 = 4
{3, 2} and {1, 1, 2} – S1 = 5, S2 = 4
  
Let sum of subset 1 be s1 and subset 2 with s2
s1 - s2 = diff (given)
s1 + s2=sum of array (logical)
Therefore adding both eq we get :
2s1= diff + sum of array
s1= (diff + sum of array)/2;
Problem reduces to find no of subsets with given sum

#include <iostream>
using namespace std;

int countOfSubsetSum(int arr[], int n, int s){
    // Step 1: initialization
    int t[n+1][s+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < s+1; j++)
        {
            if(i == 0) t[i][j] = false;
            if(j == 0) t[i][j] = true;
        }
    }

    // Step 2: Iterative code
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < s+1; j++)
        {
            if(arr[i-1] <= j) t[i][j] = t[i-1][j - arr[i-1]] + t[i-1][j];
            else if(arr[i-1] > j) t[i][j] = t[i-1][j];
        }
    }

    // Step 2: return the number of subset
    return t[n][s];   
}

int main()
{
    int arr[] = {1, 1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int diff = 1;

    int sumOfArr = 0;
    for (int i = 0; i < size; i++)
    {
        sumOfArr += i;
    }

    int sum = (diff + sumOfArr) / 2;

    int res = countOfSubsetSum(arr, size, sum);
    cout<< "The count will be "<<res<<endl;

    return 0;
}

