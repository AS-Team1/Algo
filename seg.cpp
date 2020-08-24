#include<iostream>
using namespace std;

int n;
const int N = 100000;
int tree[2*N];

void build(int *a)
{
	for(int i = 0 ; i < n ; i++ )
		tree[i+n] = a[i];
	for(int i = n-1 ; i>0 ; --i)
	{
		tree[i]= tree[i<<1] + tree[i<<1 | 1];
	}
	for(int i = 1  ; i < 2*n ; i++)
	{
		cout << tree[i] << " ";
	}
}
int Query(int l , int r)
{
	int res = 0;
	for(l += n , r+=n ; l<r ; l>>=1 , r>>=1)
	{
		if(l&1){
		res += tree[l++];

		}
		if(r&1){
		res += tree[--r];
		}
	}
	return res;
}

void Update(int p , int val)
{
	tree[p+n] = val;
	p= p+n;

	for(int i = p ; i >1 ; i>>=1 ){
		tree[i>>1]= tree[i]+tree[i ^ 1];
	}
	cout << "After Update" << endl;
	for(int i = 1  ; i < 2*n ; i++)
	{
		cout << tree[i] << " ";
	}
}
int main()
{
	cin >> n;
	int a[n];
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
	}
	build(a);
	cout << endl;
	cout << Query(3 , 6) << endl;
	Update(5 , 90);
}
