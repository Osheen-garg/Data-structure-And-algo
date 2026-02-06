#include<bits/stdc++.h>
using namespace std;

vector <int> sol1(vector<int> &arr){
    vector<vector<int>>all;
    vector<int>orignal=arr;
    sort(arr.begin(),arr.end());
    do{
     all.push_back(arr);
    }while (next_permutation(arr.begin(),arr.end()));
    
    for(int i=0;i<all.size();i++){
        if(orignal==all[i]){
            if(i==all.size()-1)
                return all[0];
            
            return all[i+1];
        }
    }
    return arr;
}

void sol2(vector<int>& arr){
    int index=-1;
    for(int i=arr.size()-2;i>=0;i--){
         if(arr[i]<arr[i+1]){
            index=i;
            break;
         }
    }
    if(index==-1){
        reverse(arr.begin(),arr.end());
        return;
    }
 for(int i=arr.size()-1;i>index;i--){
    if(arr[i]>arr[index]){
        int temp=arr[i];
        arr[i]=arr[index];
        arr[index]=temp;
        break;
    }
 }
 reverse(arr.begin()+index+1,arr.end());

}
int main(){
    vector <int> arr={1,3,2};
    // vector<int>ans=sol1(arr);
    sol2(arr);
    for(auto it: arr){
        cout<<it<<" ";
    }
    return 0;
}