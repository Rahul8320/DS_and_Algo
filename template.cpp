#include <bits/stdc++.h>
using namespace std;

void merge(long int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    int i = 0;
    int j = 0;
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(long int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int m = (l+r-1)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

void solution(){
    int n=0,k=0;
    cin >> n >> k;
    long int arr[n];
    for(long int i=0;i<n;i++){
        cin >> arr[i];
    }
    mergeSort(arr,0,n-1);
    long int sum1=0,sum2=0;
    int count = 0;
    long int j = n -1;
    sum1 = arr[j];
    j--;
    count++;
    sum2 = arr[j];
    count++;
    j--;
    while(j>=0){
        int diff1,diff2;
        diff1 = k -sum1;
        diff2 = k -sum2;
        bool check = true;
        while(diff2>diff1 && sum2<k){
            sum2 += arr[j];
            j--;
            count ++;
            diff2 = k - sum2;
            check = false;
        }
        while(diff1>=diff2 && sum1<k){
            sum1 += arr[j];
            j--;
            count ++;
            diff1 = k - sum1;
            check = false;
        }
        if(check){
            break;
        }
    }
    if(count>0){
        cout << count << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return;
}

int main()
{
	int t;
	cin >> t;
	while(t >0){
        t--;
		solution();
	}
	return 0;
}
