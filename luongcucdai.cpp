// C++ program for implementation of Ford Fulkerson
// algorithm
#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;

// so dinh trong do thi da cho
#define V 8

/* tra ve true neu co mot duong dan tu nguon  's' den 't' trong bieu do du. Cung dien vào cha [] de luu tru duong dan **/
bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
	// tao mot mang da tham va danh dau tat ca caa dinh khong duoc tham
	// visited
	bool visited[V];
	memset(visited, 0, sizeof(visited));

	// Tao mot hàng doi, xep hàng doi dinh nguon và dánh dau dinh nguon
	// dinh da tham
	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	// vong lap bfs tieu chuan
	while (!q.empty()) {
		int u = q.front();
		q.pop();
 cout << "canh u" <<u<<endl;
		for (int v = 0; v < V; v++) {
			if (visited[v] == false && rGraph[u][v] > 0) {
				
				// neu chung toi tim thay ket noi voi nut chim
				// sau do khong co diem nao trong bfs nua chung toi
				// chi can dat cha me cua no va co the tro lai
				// true
				cout <<"nguoi" << rGraph[u][v];
				if (v == t) {
					parent[v] = u;
					return true;
				}
				q.push(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}

	// chuong toi da khog dat duoc chim trong bfs bat dau tu nguon
	// return false
	return false;
}

// tra ve luong lon nhat tu s den t trong do thi da cho
int fordFulkerson(int graph[V][V], int s, int t)
{
	int u, v;

	// tao do thi phan du va dien vao do thi phan du
	// voi cac cong suat da cho trong bieu do ban dau nhu
	// dung luong du trong do thi du
	int rGraph[V]
			[V]; // do thi phan du trong do rgraph[i][j]
				// cho biet dung luong con lai cua canh
				// tu i den j (neu co canh .
				// Neu rgraph [i][j] la 0, sau do khong co)
	for (u = 0; u < V; u++){

		for (v = 0; v < V; v++){
	
			rGraph[u][v] = graph[u][v];
			cout <<"do thi "<<graph[u][v];
	}	}
	int parent[V]; // mang nay duoc lap day boi BFS va
				// duong dan cua hang

	int max_flow = 0; // khong co luong ban dau

	// tang cuong luong trong khi tere la duong dan tu nguon den 
	//bai bo
	while (bfs(rGraph, s, t, parent)) {
		// tim cong suat du nho nhat cua cac canh doc
		// duong dan duoc dien boi bfs hoac chung ta co the noi tim thay
		// luu luong toi da qua duong dan duoc tim thay
		int path_flow = INT_MAX;
		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
		}
	
	for (u = 0; u < V; u++)
		for (v = 0; v < V; v++)
		//	cout <<"cac dinh "<<u<<"-"<<v <<":"<<rGraph[u][v]<<endl;
		// cap nhat dung luong du cua cac canh va 
		// dao nguoc cac canh doc theo con duong
	
		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}

		// them luong duong dan vao luong tong the
		max_flow += path_flow;
//	for (u = 0; u < V; u++)
//		for (v = 0; v < V; v++)
	//		cout <<"cac  "<<u<<"-"<<v <<":"<<rGraph[u][v]<<endl;
	}

	// tra lai luon tong the
	return max_flow;
}

// chuong trinh dieu khien de kiem tra cac chuc nang tren 
int main()
{
	// hay de chung toi tao moi bieu do duoc hien tri trong vi du tren 
	int graph[V][V]
	= { { 0, 16, 13, 0, 0, 0 }, { 0, 0, 10, 12, 0, 0 },
			{ 0, 4, 0, 0, 14, 0 }, { 0, 0, 9, 0, 0, 20 },
			{ 0, 0, 0, 7, 0, 4 }, { 0, 0, 0, 0, 0, 0 } };
			/*	= { { 0, 4, 9, 0, 0, 0, 0, 0 }, { 0, 0, 4, 0, 0, 6,0,0 },
			{ 0, 0, 0, 0, 10, 0,0,0 }, { 0, 2, 0, 0, 3, 0,0,0 },
			{ 0, 8, 0, 0, 0, 1,4,0 }, { 0, 0, 0, 2, 0, 0,0,10 }
			 ,{ 0, 0, 0, 0, 0, 9,0,2 }, { 0, 0, 0, 0, 0, 0,0,0 }};*/

	cout << "The maximum possible flow is "
		<< fordFulkerson(graph, 0, 7);

	return 0;
}

