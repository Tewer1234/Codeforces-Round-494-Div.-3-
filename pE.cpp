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
#define SIZE 400005
using namespace std;
typedef pair<int,int> pp;
int deg[SIZE];
int par[SIZE];
//distance , position
set <pp> st;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,d,k,flag=1;
  cin>>n>>d>>k;
  
  if (n<=d) flag=0;
  for (int i=0;i<d;i++){
    if (deg[i]<k and deg[i+1]<k){
      deg[i]++;
      deg[i+1]++;
      par[i+1]=i;
    }else{
      flag=0;
      break;
    }
  }
  
  if (flag){
    for (int i=1;i<d;i++) st.insert(make_pair(max(i,d-i),i));
    for (int i=d+1;i<n;i++){
      // stack <pp> stl=st;
      // cout<<i<<"\n"; 
      // while (!stl.empty()){
        //position , dis
        // cout<<stl.top().second<<" "<<par[stl.top().second]<<" "<<stl.top().first<<" "<<deg[stl.top().second]<<"\n";
      //   stl.pop();
      // }
      int pos,dis,change=0;
      while (!st.empty()){
        pos=st.begin()->second;
        dis=st.begin()->first;
        if (deg[pos]<k and dis<d){
          deg[pos]++;
          deg[i]++;
          par[i]=pos;
          st.insert(make_pair(dis+1,i));
          change=1;
          break;
        }else{
          st.erase(st.begin());
        }
      }
      // cout<<change<<"\n\n";
      if (!change){
        flag=0;
        break;
      }
    }
    if (!flag) cout<<"NO";
    else{
      cout<<"YES\n";
      for (int i=2;i<=n;i++){
        if (par[i]) cout<<par[i]<<" "<<i<<"\n";
        else cout<<par[i]+1<<" "<<i<<"\n";
      }
    }
  }else cout<<"NO";
  return 0; 
}
