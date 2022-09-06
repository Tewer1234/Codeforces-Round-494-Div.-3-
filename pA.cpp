#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#define ll long long int 
#define pb push_back
#define inf 0x3f3f3f3f
using namespace std;
typedef pair<int,ll> pp;
int ary[1000000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  for (int i=1;i<=n;i++){
    cin>>ary[i];
  }
  
  map <int,int> mp;
  for (int i=1;i<=n;i++){
    mp[ary[i]]++;
  }
  
  int ans=0;
  for (auto it:mp){
    int bags=it.second;
    ans=max(ans,bags);
  }
  cout<<ans;
  return 0; 
}
