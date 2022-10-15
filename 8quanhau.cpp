#include<stdio.h>
#include<math.h>
#include<iostream>
#include<stdio.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
int a[8];
int dong [8];
int cheoxuoi[15];
int cheonguoc[15];
int d = 0;
void Xuat(int n){
    for(int i=1;i<=8;i++)
    cout<<" %d"<<a[i];
    printf("\n");
}
void Try(int i,int n)
{
    for(int j = 1;j<=8;j++)
		if(dong[j] &&cheoxuoi[i+j] && cheonguoc[i-j])
	    {
			 a[i] = j; 
			dong[j]= 0;
       		cheoxuoi[i+j]= 0;
       		cheonguoc[i-j]=0;
			     if(i == 8)
			     Xuat(n);
		else
       		Try(i+1,n);
       	    dong[j]= 1;
       	    cheoxuoi[i+j]= 1;
       	    cheonguoc[i-j]=1;
       }
}  
 
int main(){
    int n;
    cout<<"nhap n";
    cin>>n;
    Try(1,n);
    return 0;
}
