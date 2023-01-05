#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <vector>

using namespace std;
typedef long long ll;

int N;
ll avgbales;

vector<vector<int>> adj;

vector<ll> bales;
vector<ll> sumSubtree;
vector<tuple<int, int, ll>> order;
ll numOrder = 0;


void dfs(int cur, int parent) {
		
	sumSubtree[cur] = bales[cur] - avgbales;
	for (auto u : adj[cur]) {
		
		if (u != parent) {
			dfs(u, cur);
			sumSubtree[cur] += sumSubtree[u];
		}
	}
	
}

void dfs2(int cur, int parent) {
	
	//from child to cur
	for (auto u : adj[cur])
		if (u != parent) {
			
			if (sumSubtree[u] >= 0){
				dfs2(u, cur);
			
				order.push_back(make_tuple(u, cur, sumSubtree[u]));
				numOrder ++;
			
			}
			
	}
	
	for (auto u : adj[cur])
		if (u != parent) {
			
			//case 2: child has negative sum
			if (sumSubtree[u] < 0){
				
				order.push_back(make_tuple(cur, u, -sumSubtree[u]));
				numOrder ++;
				
				dfs2(u, cur);
			}
		}

}

int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll sumbales = 0, tempBal;
	
	cin >> N;
	sumSubtree.resize(N+1);
	adj.resize(N+1);
	
	bales.push_back(-1);
	for (int i = 1; i<= N; i++)
	{
		cin >> tempBal;
		bales.push_back(tempBal);
		sumbales += tempBal;
	}
	
	avgbales = sumbales / N;
	
	for (int i = 1; i <= N-1; i++)
	{
		int src, dst;
		cin>> src >> dst;
		adj[src].push_back(dst);
		adj[dst].push_back(src);
	}
		
	dfs(1, -1);
	dfs2(1, -1);

	cout << numOrder  << endl;

	for (auto &it: order)
		cout << get<0>(it) << " " << get<1>(it) << " " << get<2>(it) << endl;
}