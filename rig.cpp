#include<iostream>
using namespace std;
int n;
void RightRotate(int *a , int k)
{
	int b[n];
	int dest = k%n;
	for(int i=0 ; i < n ; i++){
		b[dest++] = a[i];
		if(dest == n) dest = 0;
	}
	for(int i = 0 ; i < n ; i++){
		a[i] = b[i];
	}
}
int main()
{
	int k ; 
	cin >> n >> k;
	int ap[n];
	for(int i=0;i < n ; i++){
		cin >> ap[i];
	}
	RightRotate(ap , k);
	for(int i = 0 ; i < n ; i++){
		cout << ap[i] << " ";
	}
	return 0;
	
}
