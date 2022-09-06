#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
int ary[1000000];
string s[1000000];
int dp[1005][1005];
int check[1005][1005];
int main() {
  int n,total=0;
  cin>>n;
  for (int i=0;i<n;i++){
    cin>>s[i];
    total+=s[i].size();
  }
  total+=(n-1);
  
  for (int i=0;i<n;i++){
    for (int j=0;j<=i;j++){
      if (s[i]==s[j]){
        check[i][j]=1;
        check[j][i]=1;
      }
    }
  }
  
  for (int i=n-1;i>=0;i--){
    for (int j=n-1;j>=0;j--){
      if (check[i][j]){
        if (i+1<n and j+1<n) dp[i][j]=dp[i+1][j+1]+1;
        else dp[i][j]=1;
      }
    }
  }
  
  // for (int i=1;i<=n;i++){
  //   for (int j=1;j<=n;j++){
  //     cout<<i<<" "<<j<<": "<<dp[i][j]<<"\n";
  //   }
  //   cout<<"\n";
  // }

  int temp,ans=total,len=0;
  for (int i=0;i<n;i++){
    len=0;
    for (int j=0;i+j<n;j++){
      int flag=0,cnt=1;
      len+=s[i+j].size();
      for (int k=i+j+1;k<n;k++){
        if (dp[i][k]>j){
          cnt++;
          flag=1;
          k+=j;
        }
      }
      
      
        // cout<<i<<" "<<i+j<<" "<<j<<": "<<len<<" "<<cnt<<"\n";
        // cout<<len*cnt<<" "<<(j+1)*cnt<<"\n";
        // cout<<total<<"\n";
        // cout<<total-(len*cnt)<<"\n";
        // cout<<total-len*cnt+(j+1)*cnt<<"\n";
        // cout<<total-len*cnt+(j+1)*cnt-j*cnt<<"\n";
        temp=total-(len*cnt)+((j+1)*cnt)-(j*cnt);
        if (cnt>1) ans=min(ans,temp);
    }
  }
  cout<<ans;
  return 0;
}
