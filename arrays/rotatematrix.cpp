#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>sol1(vector<vector<int>>matrix){
    int n=matrix.size();
     vector<vector<int>>rotated(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        rotated[j][n-i-1]=matrix[i][j];
        }
    }
    return rotated;
}

vector<vector<int>>sol2(vector<vector<int>>matrix){
   
    int n=matrix.size();
    //transpose
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
          int temp=matrix[i][j];
          matrix[i][j]=matrix[j][i];
          matrix[j][i]=temp;
        }
    }
    //reverse row
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }

    return matrix;
}

int main(){
    vector<vector<int>>matrix={{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>>rotated=sol2(matrix);
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<rotated[i][j]<<" ";
        }
 cout<<"\n";
    }
    return 0;
}