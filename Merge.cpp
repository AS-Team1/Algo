#include<iostream>
using namespace std;

void  Merge(int *a , int start , int mid , int end)
{
	int i , j , k ,temp[end-start+1];
	i = start;
	k = 0;
	j = mid+1;

	while(i <= mid && j<=end)
	{
		if(a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while(i <= mid){
		temp[k] = a[i];
		k++;
		i++;
	}
	while(j <= end){
		temp[k] = a[j];
		k++;
		j++;
	}
	for(int i = start ; i<=end ; i++)
	{
		a[i] = temp[i-start];
	}

}
void Mergesort(int *a  , int start , int end)
{
	int mid = 0;
	if(start < end)
	{
		mid = (start + end)/2;
		Mergesort(a , start  , mid);
		Mergesort(a , mid+1 , end);
		Merge(a , start , mid , end);
	}
}
int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0 ; i < n; i++){
		cin >> a[i];
	}
	int start = 0;
	int end = n-1;
	Mergesort(a , start , end);

	for(int i =0 ; i < n ; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}
