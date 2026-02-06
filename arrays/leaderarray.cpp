#include<bits/stdc++.h>
using namespace std;

vector <int> sol1(vector <int> arr){
vector<int> ans;
for(int i=0;i<arr.size();i++){
    bool leader=true;
    for(int j=i+1;j<arr.size();j++){
        if(arr[i]<arr[j]){
            leader=false;
            break;
        }
        // cout<<"1";
    }
    if(leader){
        ans.push_back(arr[i]);
    }
}
return ans;
}

vector <int> leaderArr(vector <int> arr){
vector<int> ans;
int max=INT_MIN;
for(int i=arr.size()-1;i>=0;i--){
    if(arr[i]>max){
        max=arr[i];
        ans.push_back(max);
    }
}
reverse(ans.begin(),ans.end());
return ans;
}

int main(){
  vector <int> arr={10,22,12,3,0,9};
  vector <int> ans=sol2(arr);
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  }
    return 0;
}