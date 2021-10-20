#include <cstdlib>
#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;

bool cmp (const pair<int, int>& a, const pair<int, int>& b) {
	
  	return a.second < b.second;
}

int main()
{

	int C, N, temp1, temp2;
	
	cin >> C >> N;
	
	multiset<int> seniorsT;
	vector<pair<int, int>> freshmanT(N);
	
	for (int i = 0; i < C; i++)
	{
		cin >> temp1;
		seniorsT.insert(temp1); 
	}
	
	for (int i = 0; i < N; i++)
	{
		cin >> temp1 >> temp2;
		freshmanT[i] = make_pair(temp1, temp2);
	}

	sort(freshmanT.begin(), freshmanT.end(), cmp);
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		auto it = seniorsT.lower_bound(freshmanT[i].first);
		
		if (*it <= freshmanT[i].second)
		{
			result ++;
			seniorsT.erase(seniorsT.find(*it));
			
		}
	}

	cout << result;

}