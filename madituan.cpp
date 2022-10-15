#include <iostream>
#define max 8
using namespace std;
int A[max][max] = {0};
int X[8] = { 2, 1,-1,-2,-2,-1, 1, 2};
int Y[8] = { 1, 2, 2, 1,-1,-2,-2,-1};
int n,dem = 0;
void xuat() {
	dem++;
    cout << "Buoc di thu "<<dem<<"\n";
    for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			cout <<A[i][j]<<"  " ;
		}	
		cout << endl;
	}
}
void Try(int i,int x,int y)
{
	for(int k=0; k<8; k++)
	{	
		int u = x + X[k];
		int v = y + Y[k];
		 if (u >= 0 && u < n&&v >= 0 && v < n&& A[u][v] == 0)
		{	
			A[u][v]=i;
			if(i < n*n)
				Try(i+1,u,v);
			else
		        xuat();	
				A[u][v]=0;
		}
	}
}
int main()
{
	int x,y;
    cout << "Nhap kich thuoc ban co n : ";
    cin >> n;
    cout << "Nhap vi tri ban dau\nx: ";
    cin >>x;
    cout << "y: ";
    cin >>y;
    A[x][y] = 1;
    Try(2,x,y);
    cout << "Khong tim thay duong di ";
	return 0;
}
