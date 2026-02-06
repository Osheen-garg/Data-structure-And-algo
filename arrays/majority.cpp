#include<bits/stdc++.h>
using namespace std;
int sol1(vector <int> arr ){
    int n=arr.size();
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]) {
                cnt++;}
        }
        if(cnt>(n/2)) 
        {return arr[i];}
    }
    return -1;
}

int sol2(vector <int>arr){
    map <int,int>mpp;
    int n=arr.size();
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it:mpp){
        if(it.second>(n/2)){
            return it.first;
        }
    }
    return -1;
}

int sol3(vector <int> arr){
    int n=arr.size();
    int ele;
    int cnt=0;
    for(int i=0;i<n;i++){
       if(cnt==0){
        cnt=1;
        ele=arr[i];
       }
       else if(ele==arr[i]){
        cnt++;
       }
       else{
        cnt--;
       }
    }

    int cnt1=0;
    for(int i=0;i<n;i++){
        if(arr[i]==ele){
            cnt1++;
        }
    }
    if(cnt1>(n/2)) return ele;
    return -1;

}
int main(){
    vector <int> arr={2,2,1,1,1,2,2};
cout<<sol3(arr);

}