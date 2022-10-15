#include <iostream>
#include<string>
using namespace std;
struct DoVat {
string Ten;
float TrongLuong, GiaTri, DonGia;
      int PhuongAn;
};
void TinhDonGia(DoVat sp[], int n)
{
   for(int i = 1; i <= n; i++)
      sp[i].DonGia = sp[i].GiaTri / sp[i].TrongLuong;
}
void SapXep(DoVat sp[], int n)
 {
    for(int i = 1; i <= n - 1; i++)
       for(int j = i + 1; j <= n; j++)
       if (sp[i].DonGia < sp[j].DonGia)
       swap(sp[i], sp[j]);
 }
 void Greedy(DoVat sp[], int n, float W)
 {
      for (int i = 1; i <= n; i++) {
            sp[i].PhuongAn = W / sp[i].TrongLuong;
            W -= sp[i].PhuongAn * sp[i].TrongLuong;
      }
 }
int main()
{
	DoVat sp[30];
	int n,W;
	cout << "Nhap so luong do vat:"; cin >> n;
	cout << "Nhap so kg ma cai tui co the chua:"; cin >> W;
	for (int i = 1; i<=n; i++)
	{
		cout <<"Do vat thu "<< i << ":" << endl;
		fflush(stdin);
		cout <<"Ten do vat:"; getline(cin,sp[i].Ten);
		cout <<"Trong luong:"; cin >> sp[i].TrongLuong;
		cout <<"Gia tri:"; cin >> sp[i].GiaTri;
	}
	TinhDonGia(sp,n);
	SapXep(sp,n);
	Greedy(sp,n,W);
	cout <<"Dap an:"<< endl;
	for (int i = 1; i <= n; i++) cout <<sp[i].Ten<<" lay "<<sp[i].PhuongAn<<" mon!"<<endl;;
	return 0;
}
