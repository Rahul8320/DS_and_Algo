#include <bits/stdc++.h>
using namespace std;

int main()
{
    int row,col;
    cin >> row >> col;
    int arr[row][col];
    for(int i=0;i<row;i++)
	{
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    int rowStart = 0, columnStart = 0, rowEnd = row-1, columnEnd = col-1;
    while (rowStart <= rowEnd && columnStart <= columnEnd)
    {
        for (int i = columnStart; i <= columnEnd; i++)
        {
            cout << arr[rowStart][i] <<" ";
        }
        rowStart++;
        for (int i = rowStart; i <= rowEnd; i++)
        {
            cout << arr[i][columnEnd] << " ";
        }
        columnEnd--;
        for (int i = columnEnd; i >= columnStart; i--)
        {
            cout << arr[rowEnd][i] << " ";
        }
        rowEnd--;
        for (int i = rowEnd; i >= rowStart; i--)
        {
            cout << arr[i][columnStart] << " ";
        }
        columnStart++;
    }
    return 0;
}
