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
vector <ll> p[1000000];
ll t[1000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,q,num,cnt=0;
  cin>>n>>q;
  t[0]=1;
  map <int,int> mp;
  for (int i=1;i<=n;i++){
    cin>>ary[i];
    auto it=mp.find(ary[i]);
    if (it==mp.end()){
      cnt++;
      mp[ary[i]]=cnt;
      p[mp[ary[i]]].pb(ary[i]);
    }
    else p[mp[ary[i]]].pb(p[mp[ary[i]]][p[mp[ary[i]]].size()-1]+ary[i]);
  }
  
  // for (auto it:mp){
  //   cout<<it.first<<": ";
  //   for (int i=0;i<p[mp[it.first]].size();i++){
  //     cout<<p[mp[it.first]][i]<<" ";
  //   }
  //   cout<<"\n";
  // }
  for (int i=1;i<=30;i++) t[i]=t[i-1]*2;
  
  for (int i=1;i<=q;i++){
    cin>>num;
    int pos=0;
    for (int j=1;j<=30;j++){
      if (t[j]>num){
        pos=j-1;
        break;
      }
    }
    
    int temp,ans=0;
    for (int j=pos;j>=0;j--){
      if (!num) break;
      // cout<<num<<"\n";
      int l=0,r=p[mp[t[j]]].size()-1,mid;
      temp=-1;
      // cout<<" "<<l<<" "<<r<<"\n";
      while (l<=r){
        mid=(l+r)/2;
        if (num-p[mp[t[j]]][mid]>=0){
          temp=mid;
          l=mid+1;
        }else r=mid-1;
      }
      // cout<<temp<<"fefe\n";
      // if (temp!=-1) cout<<p[mp[t[j]]][temp]<<"\n";
      if (temp!=-1){
        num-=p[mp[t[j]]][temp];
        ans+=(temp+1);
      }
    }
    
    if (num) cout<<-1<<"\n";
    else cout<<ans<<"\n";
  }
  return 0; 
}
