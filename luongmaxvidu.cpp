#include <iostream>
#include <string.h>
#include <limits.h>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
// so dinh toi da do thi da cho 
#define V 8
bool findpath(int c[V][V],int s, int t, int p[]) {
   
	bool visited[V];
	memset(visited, 0, sizeof(visited));
	queue<int> q;
	q.push(s);
	visited[s] = true;
	p[s] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
    		for (int v = 0; v < V; v++)
			{
				if (visited[v] == false && c[u][v] > 0) 
				{
					if (v == t) 
						{
							p[v] = u;
							return true;
						}
					q.push(v);
					p[v] = u;
					visited[v] = true;
				}
			}
	}
    return false;
}
int IncFlow(int c[V][V],int s,int t){
	int u,v;
	int p[V];
	int max_flow = 0;
	while (findpath ( c, s, t, p) )
	{ 
		int path_flow = INT_MAX;
		cout << "Duong tang luong: "<< endl;
		cout << setw(3) << " Duong di " << setw(3) << " Trong so hien tai " << endl;
        for ( v = t; v != s; v = p[v] ) 
		{
            u = p[v];
            path_flow = min ( path_flow, c[u][v] );
            cout << setw(5) << p[v] << setw(8) << c[u][v] << endl;
        }
        cout << "path_flow:" << path_flow << endl;
        cout << setw(3) << "Canh moi" << setw(8) << "Canh cu" << endl;
        for ( v = t; v != s; v = p[v] ) 
		{
            u = p[v];
            c[u][v] -= path_flow;
            c[v][u] += path_flow;
            cout << setw(5) << c[v][u] << setw(8) << c[u][v] << endl;
		}
        max_flow += path_flow;
    }
    return max_flow;
}


int main(){
	int G[V][V] = { { 0, 4, 9, 0, 0, 0, 0, 0 }, { 0, 0, 4, 0, 0, 6,0,0 },
			{ 0, 0, 0, 0, 10, 0,0,0 }, { 0, 2, 0, 0, 3, 0,0,0 },
			{ 0, 8, 0, 0, 0, 1,4,0 }, { 0, 0, 0, 2, 0, 0,0,10 },
			{ 0, 0, 0, 0, 0, 9,0,2 }, { 0, 0, 0, 0, 0, 0,0,0 }}; 
	cout<<"luong cuc dai:"<<	IncFlow(G,0,7);

 	return 0;
}	


