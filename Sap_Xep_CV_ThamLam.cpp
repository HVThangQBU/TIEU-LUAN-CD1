#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
class CongViec{
    public:
    string Ten;
    int STime;
    int ETime;
  
    void input()
    {
    	do{
    	fflush(stdin);
        cout << "Nhap Ten CV : ";
        getline(cin,Ten);
        cout << "Nhap thoi gian bat dau CV : ";
        cin >> STime;
        cout << "Nhap thoi gian ket thuc CV : ";
        cin >> ETime;
        if( STime > ETime)
        cout << "Thoi gian bat dau khong duoc lon hon thoi gian ket thuc !!!"<<endl;
        }while(STime > ETime );
    }
 
    void output()
    {
        cout << "Ten: " << Ten << endl;
 		cout << "Thoi gian bat dau: "<< STime <<endl;
 		cout << "Thoi gian ket thuc: "<< ETime <<endl;
    }
};
//sap xep cong viec theo gioi gian ket thuc tang dan 
void SapXep(CongViec CV[], int n)
{
    CongViec tmp;
    for ( int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if ( CV[i].ETime > CV[j].ETime) {
                tmp = CV[i];
                CV[i] = CV[j];
                CV[j]= tmp;
            }
        }
    }
}
void LuaChonCV(CongViec CV[],int n)
{
	int X;
	int dem = 0;
	SapXep(CV,n);
	X= CV[0].STime;
	for(int i = 0 ; i < n ; i++)
	{
		if( X <= CV[i].STime )
		{
			X = CV[i].ETime;
			dem++;
			cout << "Ten "<<CV[i].Ten<<"; Thoi gian bat dau: "<< CV[i].STime <<"; Thoi gia Ket Thuc: "<< X <<endl;
		}
	}
	cout <<"So cong viec: "<< n<<endl;
	cout << "Tong so cong viec duoc chon: " << dem <<endl;
	
}
int main()
{	
	CongViec CV[100];
	int n;
	cout << "Nhap so luong cong viec: ";
	cin >> n;
	for ( int i = 0; i < n; i++)
	{
		cout << "Cong viec thu " << i + 1<<endl;
		CV[i].input();
	}		
	LuaChonCV(CV,n);
//	for ( int i = 0; i < n; i++){
//	CV[i].output();
//	}		
}
