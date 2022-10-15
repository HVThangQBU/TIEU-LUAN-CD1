#include <bits/stdc++.h>
#include <fstream>
using namespace std;
struct DoVat {
	string ten;
	int trongLuong, giaTri;
    int phuongAn;
};
int n,W;
DoVat DV[50];
int F [50][100];
//bang tong gia tri do vat duoc chon
int X [50][100];
//bang so luong do vat duoc chon
void TaoBang(DoVat DV[],int n,int W,  int F[50][100], int X[50][100])
{
	int xk, yk, k;
	//xk,yk V div gi
	int FMax, XMax, v;
	for(v = 0; v <= W; v++)
	{
		X[1][v] = v / DV[1].trongLuong;
		F[1][v] = X[1][v] * DV[1].giaTri;
	}
	for(k = 2; k < n + 1;k++)
	{
		X[k][0] = 0;
		F[1][0] = 0;
		for(v = 1; v <= W; v++)
		{
			FMax = F[k - 1][v];
			XMax = 0;
			yk = v / DV[k].trongLuong;
			for(xk = 0; xk <= yk; xk++)
			{
				int G = v - xk * DV[k].trongLuong;
				int Vk = xk * DV[k].giaTri;
				if ((F[k - 1][G] + Vk) > FMax )
				{
					FMax = F[k - 1][G] + Vk;
					XMax = xk;
				}
				F[k][v] = FMax;
				X[k][v] = XMax;
			}
		}
	}
	cout << "Ma tran tong gia tri va so luong chon cac do vat " << endl;
	for(int h = 0; h <=	W; h++){
		cout <<setw(8)<<"    "<<h;
	}
	for(k = 1; k < n + 1;k++)
	{	cout << endl;
		for(v = 0; v <= W; v++)
		{
			cout << setw(6)<<" || " << F[k][v];
			cout << ":" << X[k][v];
		}
	}
}
void TraBang(DoVat DV[],int n,int W,  int F[50][100], int X[50][100])
{
	int k,v;
	v = W;
	cout <<endl;
	cout <<setw(35)<<"Bang ket qua " << endl;
	cout <<"\n " << setw(10) << "Ten do vat " << setw(10) << " || Trong luong " << setw(10) << " || GiaTri " <<setw(10) << " || So do vat duoc chon" <<endl;
	for(k = n; k >= 0; k-- )
	{ 	
		if(X[k][v] > 0)
		{
			DV[k].phuongAn = X[k][v];
			v = v - X[k][v] * DV[k].trongLuong;
			cout << setw(10) << DV[k].ten << setw(10) <<"||     "<< DV[k].trongLuong << setw(15) <<"||     "<< DV[k].giaTri << setw(15) <<"||          " << DV[k].phuongAn << endl;
		} 
	}
}
int main()
{
	ifstream fileInput ("D:\\Balo.txt");
    if(fileInput.fail()) 
	{
        cout << "Error opening file\n";
        return -1;
    }
    fileInput >> n;
	fileInput >> W ;
    while ( !fileInput.eof())
    {
    	for(int i = 1 ; i <=n; i++)
		{
    		fileInput>>DV[i].ten;
    		fileInput >>DV[i].trongLuong;
			fileInput >>DV[i].giaTri;
		}
    }
    cout <<setw(30)<< "Bang cac do vat " <<endl;
    cout <<"\n " << setw(10) << "Ten do vat " << setw(10) << " || Trong luong " << setw(10) << " || GiaTri " <<endl;
    for(int i = 1 ; i <= n; i++)
	{
       	cout << setw(10) << DV[i].ten << setw(10) <<"||     "<< DV[i].trongLuong << setw(15) <<"||     "<< DV[i].giaTri << endl;
	}
   TaoBang(DV,n,W,F,X);
   TraBang(DV,n,W,F,X);
/*	cout << "Nhap so luong do vat:"; cin >> n;
	cout << "Nhap so kg ma cai tui co the chua:"; cin >> W;
	for (int i = 1; i<=n; i++)
	{
		cout <<"Do vat thu "<< i << ":" << endl;
		fflush(stdin);
		cout <<"Ten do vat:"; getline(cin,DV[i].ten);
		cout <<"Trong luong:"; cin >> DV[i].trongLuong;
		cout <<"Gia tri:"; cin >> DV[i].giaTri;
	}*/
 	fileInput.close();
	return 0;
}
