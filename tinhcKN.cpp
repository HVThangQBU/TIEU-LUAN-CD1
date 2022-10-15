#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int comb(int n , int k )
{
	int c[50][50];
	c[0][0] = 1 ;
	for ( int i = 1 ; i <= n ; i++ )
	{
		c[i][0] = 1;
		c[i][i] = 1;
		for ( int j = 1 ; j <= i -1 ; j++ )
		{
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}	
	 return c[n][k];
}
int main()
{
	int n,k;
	do{
	cout << "Nhap n: ";
	cin >> n;
	cout << "Nhap k: ";
	cin >> k;
	if( n < k)
	cout << "Hay nhap lai !" <<endl;
    }while ( n < k);
   	cout << "Ket qua cua to hop C : "<< comb(n,k)<<endl;
    
}
