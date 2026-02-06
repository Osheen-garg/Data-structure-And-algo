#include<bits/stdc++.h>
using namespace std;

vector <int> sol1(vector <int> arr){
  vector <int> pos;
  vector <int> neg;
  int n=arr.size();
  for(int i=0;i<n;i++){
    if(arr[i]>0) pos.push_back(arr[i]);
    else neg.push_back(arr[i]);
  }

  for(int i=0;i<(n/2);i++){
    arr[2*i]=pos[i];
    arr[2*i+1]=neg[i];
  }

  return arr;
}

vector <int> sol2(vector <int> arr){
      int n=arr.size();
  vector <int> ans(n,0);
  int posIndex=0;
  int negIndex=1;
  for(int i=0;i<n;i++){
   if(arr[i]<0){
    ans[negIndex]=arr[i];
    negIndex+=2;
   }
   else{
    ans[posIndex]=arr[i];
    posIndex+=2;
   }
  }


  return ans;
}

vector <int> sol3(vector <int> arr){
  vector <int> pos;
  vector <int> neg;
  int n=arr.size();
  for(int i=0;i<n;i++){
    if(arr[i]>0) pos.push_back(arr[i]);
    else neg.push_back(arr[i]);
  }
  if(pos.size()<neg.size()){
  for(int i=0;i<pos.size();i++){
    arr[2*i]=pos[i];
    arr[2*i+1]=neg[i];
  }
  int index=pos.size();
  for(int i=pos.size();i<neg.size();i++){
    arr[index]=neg[i];
    index++;
  }
  }
else{
  for(int i=0;i<neg.size();i++){
    arr[2*i]=pos[i];
    arr[2*i+1]=neg[i];
  }
   int index=neg.size()*2;
  for(int i=neg.size();i<pos.size();i++){
    arr[index]=pos[i];
    index++;
  }
}

  return arr;
}

int main(){
vector <int> arr={1,2,-4,-5,3,4};
vector <int> ans=sol3(arr);
for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
}
    return 0;
}