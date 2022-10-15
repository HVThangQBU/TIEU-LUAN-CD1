#include <iostream>
using namespace std;
#define namTrieu 5000
void Ruttien(int n){
    int X[6]= {0};
    int D[6];
    D[0] = 500;
    D[1] = 200;
    D[2] = 100;
    D[3] = 50;
    D[4] = 20 ;
    D[5] = 10 ;
    int tong = 0;
    int x,i=0;
    while(tong!=n && n<= namTrieu)
    {
        X[i] = ( n - tong )/D[i];
        if(tong + X[i]*D[i] <= n )
        {
        tong = tong +X[i]*D[i];
        }
        i++;
    }
    if(tong == n ) 
        for(int i = 0 ; i <6 ; i++)
        cout <<" \n so tien  "<<D[i]<<" can rut so to : "<<X[i];
    else 
        cout<<"So tien ban rut phai nho hon 5 trieu va phai la boi so cua 10  ";
}

int main()
{
    int n;
    cout<<"So tien can rut: ";
	cin>>n;
	Ruttien(n);
     return 0;
}

