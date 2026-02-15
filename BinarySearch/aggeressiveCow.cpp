#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool canPlace(vector<int>arr, int cow,int dis){
    int count=1;
    int lastPos=arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i]-lastPos>=dis){
           count++;
           lastPos=arr[i];
        }
        if(count==cow) return true;
    }
   return false;

}
int sol1(vector <int> arr,int cow){
    sort(arr.begin(),arr.end());
    int n=arr.size();
    int ans=0;
    int maxDis=arr[n-1]-arr[0];
    for(int i=1;i<=maxDis;i++){
        if(canPlace(arr,cow,i)){
            ans= i;
        }
    }
    return ans;
}

int sol2(vector <int> arr,int cow){
    sort(arr.begin(),arr.end());
    int n=arr.size();
    int ans=0;
    int low=1;
    int high=arr[n-1]-arr[0];

    while (low<=high)
    {
        int mid=(high+low)/2;
        if(canPlace(arr,cow,mid)){
                    ans= mid;
                    low=mid+1;
        }
        else{
            high=mid-1;
        }
    }    
    
    return ans;
}

int main(){
      vector<int> stalls = {0,3,4,7,10,9};
    int cows = 4;
    cout << sol2(stalls, cows) << endl;
    return 0;
}