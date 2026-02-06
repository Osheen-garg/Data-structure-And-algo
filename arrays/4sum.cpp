#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> sol1(vector<int> arr,int target){
    int n=arr.size();
    set<vector<int>>st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int x=k+1;x<n;x++){
                    vector<int> temp;
                    if(target==arr[i]+arr[j]+arr[k]+arr[x]){
                        temp={arr[i],arr[j],arr[k],arr[x]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
     return vector<vector<int>> (st.begin(),st.end());
}

vector<vector<int>> sol2(vector<int> arr,int target){
int n= arr.size();
set<vector<int>>st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<int> hashset;
            for(int k=j+1;k<n;k++){
                long long fourth=(long long)target-(arr[i]+arr[j]+arr[k]);
                if(hashset.find(fourth)!=hashset.end()){
                      vector<int> temp;
                        temp={arr[i],arr[j],arr[k],(int)fourth};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                hashset.insert(arr[k]);
            }
        }
    }
     return vector<vector<int>> (st.begin(),st.end());
}

vector<vector<int>> sol3(vector<int> arr,int target){
vector<vector<int>> ans;
int n=arr.size();
 sort(arr.begin(),arr.end());
 for(int i=0;i<n;i++){
    if(i>0 && arr[i]==arr[i-1]) continue;
    for(int j=i+1;j<n;j++){
    if (j > i + 1 && arr[j] == arr[j - 1]) continue;
    int k=j+1;
    int l=n-1;
    while (k<l){
        long long sum=(long long)arr[i]+arr[j]+arr[k]+arr[l];
        if(sum<target) k++;
        else if(sum>target) l--;
        else{
          ans.push_back({arr[i],arr[j],arr[k],arr[l]});
          k++;
          l--;
          while(k<l && arr[k]==arr[k-1]) k++;
          while(k<l && arr[l]==arr[l+1]) l--;
        }
    }
    }
 }
 return ans;
}
int main(){
   vector<int> arr {4,3,3,4,4,2,1,2,1,1};
   vector<vector<int>> ans=sol3(arr,9);
   for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[0].size();j++){
     cout<<ans[i][j] <<" ";
    }
    cout<<endl;
   }

    return 0;
}