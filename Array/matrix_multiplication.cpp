#include <bits/stdc++.h>
using namespace std;

int main()
{
    int row,col;
    int row2,col2;
    cin >> row >> col;
    cin >> row2 >> col2;
    if (col != row2)
    {
        return 0;
    }
    int arr[row][col];
    int brr[row2][col2];
    int array[row][col2];
    for(int i=0;i<row;i++)
	{
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cin >> brr[i][j];
        }
    }
    for(int i=0;i<row;i++)
	{
        for (int j = 0; j < col2; j++)
        {
            int sum = 0;
            for (int k = 0; k < col; k++)
            {
                sum += (arr[i][k] * brr[k][j]);
            }
            array[i][j] = sum;
        }
    }
    for(int i=0;i<row;i++)
	{
        for (int j = 0; j < col2; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
