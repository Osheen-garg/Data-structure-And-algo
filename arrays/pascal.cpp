#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int pascalElement(int n,int r){
    long res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);
    }
    return res;
}
vector<int> pascalRow(int n){
    long long ans=1;
    vector <int> ansRow;
    ansRow.push_back(1);
    cout<<ans<<" ";
    for(int i=1;i<n;i++){
        ans=ans*(n-i);
        ans=ans/i;
       ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int N){
    vector<vector<int>>ans;
    for(int i=1;i<=N;i++){
        ans.push_back(pascalRow(i));
    }
    return ans;
}

int main(){
    // cout<<pascalElement(3,2);
    // pascalRow(6);
    vector<vector<int>> ans=pascalTriangle(8);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}