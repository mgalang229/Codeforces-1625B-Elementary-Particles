#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
	int n;
	cin >> n;
	int a[n];
	map<int, set<int>> mp;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		mp[a[i]].insert(i);
	}
	int ans=0;
	for(auto x : mp) {
		if((int)x.second.size()==1)
			continue;
		vector<int> vec;
		for(int id : x.second)
			vec.push_back(id);
		for(int i=0; i+1<(int)vec.size(); ++i) {
			int fr=vec[i]+1;
			fr=min(fr, vec[i+1]+1);
			int bk=n-vec[i]-1;
			bk=min(bk, n-vec[i+1]-1);
			ans=max(ans, fr+bk);
		}
	}
	cout << (ans>0?ans:-1) << "\n";
	//int ans=0;
	//for(int i=0; i<n; ++i) {
		//int dup=-1;
		//for(int j=i+1; j<n; ++j)
			//if(a[i]==a[j]) {
				//dup=j;
				//break;
			//}
		//if(dup==-1)
			//continue;
		//int fr=i+1;
		//fr=min(fr, dup+1);
		//int bk=n-i-1;
		//bk=min(bk, n-dup-1);
		//ans=max(ans, fr+bk);
	//}
	//cout << (ans>0?ans:-1) << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--)
		solve();
}
