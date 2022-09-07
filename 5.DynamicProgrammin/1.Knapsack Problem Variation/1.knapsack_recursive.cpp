You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one 
quantity of each item.In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively.
Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than
or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).

Example 1:

Input:
N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3
Example 2:

Input:
N = 3
W = 3
values[] = {1,2,3}
weight[] = {4,5,6}
Output: 0
  //recursive case
  int knapSack(int W, int wt[], int val[], int n) 
    { 
       if(n==0 || W==0)return 0;
       if(wt[n-1] <= W)
           return max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),
                      knapSack(W,wt,val,n-1));
       else
            return knapSack(W,wt,val,n-1);
    }
//memosisation
void* memset( void* str, int ch, size_t n);
Parameters:

str[] : Pointer to the object to copy the character.
ch : The character to copy.
n : Number of bytes to copy.
  char str[] = "geeksforgeeks";
    memset(str, 't', sizeof(str));//op ttttttttttttttt
Note: We can use memset() to set all values as 0 or -1 for integral data types also. It will not work if we use it to set as other values. 
  The reason is simple, memset works byte by byte.
  // CPP Program to demonstrate that we can use memset() to
// set all values as 0 or -1 for integral data types also
#include <bits/stdc++.h>
using namespace std;

// Driver Code
int main()
{
	int a[5];

	// all elements of A are zero
	memset(a, 0, sizeof(a));
	for (int i = 0; i < 5; i++)
		cout << a[i] << " ";
	cout << endl;

	// all elements of A are -1
	memset(a, -1, sizeof(a));
	for (int i = 0; i < 5; i++)
		cout << a[i] << " ";
	cout << endl;

	// Would not work
	memset(a, 5, sizeof(a)); // WRONG
	for (int i = 0; i < 5; i++)
		cout << a[i] << " ";
}
0 0 0 0 0 
-1 -1 -1 -1 -1 
84215045 84215045 84215045 84215045 84215045
// this does the same
memset(arr, 0, sizeof arr); 
memset(array,0,M*N*sizeof (int));


//memoisation -- Top to down approch
   int t[1001][1001];
   int flag=0;
   int knapSack(int W, int wt[], int val[], int n) 
   {
       if(flag==0)
       {
         memset(t,-1,sizeof(t));
         flag++;
       }
     if(n==0||W==0)
     return 0;
     if(t[n][W]!=-1)
     return t[n][W];
     if(wt[n-1]<=W)
     return t[n][W]=max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
     else
     return t[n][W]=knapSack(W,wt,val,n-1);
   }
or
	Solution(){
        memset(v,-1,sizeof(v));
    }make constructor

//bottom up approch
int Knapsack(int wt[], int val[], int W, int n) {
	int t[n + 1][W + 1]; // DP matrix

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= W; j++) {
			if (i == 0 || j == 0) // base case
				t[i][j] = 0;
			else if (wt[i - 1] <= j) { // current wt can fit in bag
				int val1 = val[i - 1] + t[i - 1][j - wt[i - 1]]; // take current wt
				int val2 = t[i - 1][j]; // skip current wt
				t[i][j] = max(val1, val2);
			}
			else //if (wt[i - 1] > j) // current wt doesn't fit in bag
				t[i][j] = t[i - 1][j];
		}
	}

	return t[n][W];
}

