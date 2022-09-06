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
int psum[1000000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,k;
  cin>>n>>k;
  for (int i=1;i<=n;i++) cin>>ary[i],psum[i]=psum[i-1]+ary[i];
  
  double ans=0,temp;
  int range;
  for (int i=1;i<=n;i++){
    for (int j=i+k-1;j<=n;j++){
      temp=(double)psum[j]-psum[i-1];
      range=j-i+1;
      temp=(double) temp/range;
      // cout<<temp<<"\n";
      ans=max(ans,temp);
    }
  }
  cout<<fixed<<setprecision(6)<<ans;
  return 0; 
}
