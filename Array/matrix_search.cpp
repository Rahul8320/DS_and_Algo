#include <bits/stdc++.h>
using namespace std;

int main()
{
    int row,col;
    int target;
    cin >> row >> col;
    cin >> target;
    int arr[row][col];
    for(int i=0;i<row;i++)
	{
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    bool check = false;
    int r = 0;
    int c = col-1;
    while (r < row and c >= 0)
    {
        if(arr[r][c] == target)
        {
            check = true;
            break;
        }
        if (arr[r][c] > target)
        {
            c--;
        }
        else
        {
            r++;
        }
    }
    if (check)
    {
        cout << "Element Present " << endl;
    }
    else
    {
        cout << "Element not Present " << endl;
    }
    return 0;
}
