#include<stdio.h>
#include<math.h>
#include<iostream>
#include<stdio.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
#define tram 100000
#define namChuc 50000
#define haiChuc 20000
#define muoiChuc 10000
int n;
int X1 ;
int X2 ;
int X3 ;
int X4 ;
void RutTien(){
	if( n % muoiChuc !=0 ){
	cout <<"so tien khong hop le \n";
	exit(0);}
	else{
	X1 = n / tram ;
	n = n % tram;
	X2 = n /namChuc;
	n = n % namChuc;
	X3 = n / haiChuc;
	n = n % haiChuc;
	X4 = n / muoiChuc;
	n = n % muoiChuc;
	cout<<"\nMOT TRAM  "<< X1;
	cout <<"\nNAM CHUC : " << X2;
	cout << "\nHAI CHUC " <<X3;
	cout  << "\nMUOI CHUC " << X4;
	}
}
int main(){
	cout <<"nhap so tien can rut n : ";
	cin >>n;
	RutTien();
	return 0;
	
}
