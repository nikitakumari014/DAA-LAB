#include<bits/stdc++.h>
using namespace std;
int lis(int nums[],int n)
 {
   int lis[n]; 
	lis[0] = 1; 
	for (int i = 1; i < n; i++ ) 
	{ 
		lis[i] = 1; 
		for (int j = 0; j < i; j++ ) 
			if ( nums[i] > nums[j] && lis[i] < lis[j] + 1) 
				lis[i] = lis[j] + 1; 
	} 
	return *max_element(lis, lis+n); 
} 
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin >> arr[i];
    int largest = lis(arr,n);
    cout<<"Largest LIS: "<<largest<<endl;
}