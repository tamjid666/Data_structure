#include<iostream>
using namespace std; 
const int N = 1e5+10; 
int a[N];

void merge(int l,int r,int mid)
{
	int l_sz = mid - l + 1 , r_sz = r-mid ; 

	int L[l_sz+1] , R[r_sz+1];
	for(int i=0; i<l_sz; ++i) L[i] = a[i+l];
	for(int j=0; j<r_sz; ++j) R[j] = a[j+mid+1]; 

	L[l_sz] = R[r_sz] = INT_MAX ; 

	int l_i = 0 , r_i = 0 ; 
	for(int i=l; i<=r; ++i)
		a[i] = ((L[l_i] <= R[r_i]) ? L[l_i++] : R[r_i++]); 
}
void mergeSort(int l,int r)
{
	if(l==r) return ; 
	int mid = ((l+r)>>1);
	mergeSort(l,mid);
	mergeSort(mid+1,r);
	merge(l,r,mid);
}
int main()
{
	int n ; cin >> n ; 
	for(int i=0; i<n; ++i)
		cin >> a[i]; 

	mergeSort(0,n-1); 
	for(int i=0; i<n; ++i)
		cout << a[i] << " " ; 
}