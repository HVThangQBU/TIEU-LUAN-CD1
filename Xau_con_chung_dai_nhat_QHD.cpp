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
	S1 = " " + S1;
	S2 = " " + S2;	
}
void XauConMax()
{
	for(int i = 0; i < S2.length()+1; i++ )
	{
		L[i][0] = 0;
		for(int j = 0; j < S1.length()+1; j++)
	 {
			L[0][j] = 0;
			if ( S2[i] == S1[j] )
			{
				L[i][j] = 1 + L[i - 1][j - 1] ;
			}
			else
			{
				L[i][j] = max(L[i - 1][j] , L[i][j - 1]);
			}
	   	}
	}
		if(L[S2.length() - 1][S1.length() - 1] == 0)
	{
		cout << "\nkhong co xau con chung!" <<endl;
		exit(0);
	}
	for(int i = 0; i < S2.length(); i++ )
	{
		cout << endl;
		for(int j = 0; j < S1.length(); j++)
		{
	    	cout<<":"<<L[i][j];
	    }	
	}
}
void TruyVet()
{
	string X = " ";
	int n = S1.length() - 1;
	int m = S2.length() - 1;
	while (L[m][n] != 0 )
	{
		if ( S2[m] == S1[n] )
		{
			X += S2[m];
			m--;
			n--;
		}
		else
		{
		    if (L[m -1][n] > L[m][n - 1])
	    	{
			    m --;
		    }
		    else n --;
	    }
	    
	}
	reverse(X.begin(), X.end());
	cout << "\nDo dai xau con max :" << L[S2.length() - 1][S1.length() - 1];
	cout << "\nXau con chung max : " << X <<endl;	
}
int main()
{
    input();
	XauConMax();
	TruyVet();
	return 0;
}
