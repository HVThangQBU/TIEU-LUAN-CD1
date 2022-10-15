#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
 int n,w;
class DoVat{
    public:
    string Ten;
    float Giatri;
    int Soluong;
    float Trongluong;
    float DonGia(){
    	return Giatri/Trongluong;
	}
    void input()
    {
    	fflush(stdin);
        cout << "Nhap Ten: ";
        getline(cin,Ten);
        cout << "Nhap trong luong: ";
        cin >> Trongluong;
        cout << "Nhap Gia Tri: ";
        cin >> Giatri;
    }
 
    void output()
    {
        cout << "Ten: " << Ten << endl;
 		cout << "Trong Luong: " << Trongluong << endl;
 		cout << "  Gia Tri: " << Giatri << endl;
 		cout << "Don Gia: " << DonGia() << endl;
    }
};
//sap xep cac do vat theo don gia giam dan 
void SapXep(DoVat a[], int n)
{
    DoVat tmp;
    for(int i = 0;i < n;i++){
        for(int j = i+1; j < n;j++){
            if(a[i].DonGia() < a[j].DonGia()){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}
void ChonDoVat(DoVat a[],int n,int w){
	int tong = 0;
	int D[n] = {0};
	SapXep(a,n);
  for(int i = 0 ; i < n ;i++ )
   {
  	  	a[i].Soluong= (w - tong)/a[i].Trongluong;
		if (tong+a[i].Trongluong*a[i].Soluong <= w)
		{
	 		tong = tong +(a[i].Trongluong*a[i].Soluong);
	 	}
	} 
		for(int i = 0 ; i <n ; i++)
		{
        	cout << " \n Do vat : " << a[i].Ten << " ; So luong bo: "<<a[i].Soluong << " ; Trong luong: " << a[i].Trongluong << " ; Gia tri: " << a[i].Giatri <<endl;
	
		}
		cout << "Trong luong cua ba lo: " << w <<endl;
		cout << "Tong trong luong cua cac do vat: " << tong <<endl;
		cout << "Trong luong con thua trong ba lo: " << w - tong <<endl;
        cout << "Trong luong con lai khong du de bo them do vat nao nua !!! ";
}
int main(){
    DoVat a[50];
    cout << "Nhap so do vat hien co: ";
    cin >> n;
    cout << "Nhap trong luong cua chiec tui: ";
    cin >> w;
    for(int i = 0 ; i < n ;i++ )
	{
    	cout << "Do vat thu "<< i + 1 <<endl;
    	a[i].input();
    }
    ChonDoVat(a,n,w);
    return 0;
    
}

