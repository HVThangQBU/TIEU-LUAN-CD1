#include <bits/stdc++.h>
using namespace std;
string S1,S2;
int L[50][50];
void input()
{
	cout << "Nhap xau "<<endl;
	cout << "Nhap xau S1: ";
	getline(cin,S1);
	cout << "Nhap xau S2: ";
	getline(cin,S2);
}
void XauConMax()
{
	int d=0,t = 0;
	string X;
	
	for(int i = 0; i < S2.length(); i++ )
	{
		for(int j = t; j < S1.length(); j++)
		{
			if ( S2[i] == S1[j] )
			{
				X += S2[i];
				t = j;
				d++;
				break;
			}
		}
	}
	if( d == 0)
	{
		cout << "\nkhong co xau con chung!" <<endl;
		exit(0);
	}
	else
		cout << "Xau con chung max : " << X;
		cout << "\nDo dai cua xau con max: " << d;
}
int main()
{
    input();
	XauConMax();
	return 0;
}
