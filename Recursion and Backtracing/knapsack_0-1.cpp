#include <iostream>
using namespace std;

int knapsack(int value[],int wt[],int n,int W)
{
    if(n==0 || W==0)
    {
        return 0;
    }

    if(wt[n-1] > W)
    {
        return knapsack(value,wt,n-1,W);
    }

    return max((knapsack(value,wt,n-1,W-wt[n-1])+value[n-1]) , knapsack(value,wt,n-1,W));
}

int main()
{
    int value[] = {100,50,150,75,200,355};
    int wt[] = {10,20,30,35,15,55};
    int W = 70;

    cout << knapsack(value,wt,6,W) << endl;
}