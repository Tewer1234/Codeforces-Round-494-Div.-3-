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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a,b,x;
  string s="";
  cin>>a>>b>>x;
  
  int len=a+b;
  if (x%2==0){
    if (a>b){
      for (int i=0;i<x/2;i++) s+="01";
      for (int i=0;i<b-(x/2);i++) s+="1";
      for (int i=0;i<a-(x/2);i++) s+="0";
    }else{
      for (int i=0;i<x/2;i++) s+="10";
      for (int i=0;i<a-(x/2);i++) s+="0";
      for (int i=0;i<b-(x/2);i++) s+="1";
    }
  }else{
    if (a>b) {
      for (int i=0;i<x/2;i++) s+="01";
      for (int i=0;i<a-(x/2);i++) s+="0";
      for (int i=0;i<b-(x/2);i++) s+= "1";
    }else{
      for (int i=0;i<x/2;i++) s+="10";
      for (int i=0;i<b-(x/2);i++) s+="1";
      for (int i=0;i<a-(x/2);i++) s+="0";
    }
  }
  cout<<s;
  return 0; 
}
