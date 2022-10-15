#include<iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
#define n 8
int a[n], cc[2*n], cp[2*n],x[n],d;
void boole()
{
	for(int i=0;i<=n-1;i++) 
    	a[i]=1;
	for (int i=0; i< 2*n-1;i++)
	{
		cc[i]=1;
		cp[i]=1;
	}
}
void xuat()
{ 
   d++;
   cout<<"\n cach xep la:"<<d;
   for(int j=0;j<n;j++) cout<<"   "<<x[j]+1;

}
void Try(int i)
{
  for (int j = 0; j <= n-1; j++)
  if (a[j] && cc[i+j] && cp [i -j+n-1])
  {
    x[i] = j; 
	a[j] = 0; 
	cc[i+j] = 0;
    cp[i-j+n-1] = 0;
    if (i == n-1) xuat(); else Try(i + 1);
    a[ j ] = 1;
    cc[i+j] = 1;
    cp[i-j+n-1] = 1;
  }
}
int main(){
 boole();
 Try(0);
}
