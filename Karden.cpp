#include<iostream>
#include<climits>
using namespace std;
int n ; 
/*int maxSubArraySum(int a[])
{
	int max_so_far = INT_MIN , max_ending_here=0;
	for(int i=0 ; i < n ; i++)
	{
		cout << endl;
		cout << "max_ending_here--- "<< max_ending_here << " a[i]--  " << a[i] << endl;
		max_ending_here = max_ending_here + a[i];
		if(max_ending_here < 0 ){
			max_ending_here = 0 ;
		}
		else if(max_so_far < max_ending_here){
			cout << i << endl;
			max_so_far = max_ending_here;
		}

	}
	return max_so_far;
}
*/
int maxSubArraySum(int a[])
{
	int curr_max = a[0];
	int max_so_far = a[0];
	for(int i = 1 ; i < n ; i++)
	{
		cout << "curr_max--- " << curr_max << "  max_so_far---- " << max_so_far << endl;
		curr_max = max(a[i],curr_max+a[i]);
		max_so_far = max(max_so_far , curr_max);
	}
	return max_so_far;
}
int main()
{
	cin >>  n ;
	int a[n];
	int max = 0;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
	}
	max = maxSubArraySum(a);
	cout << max << endl;

}
