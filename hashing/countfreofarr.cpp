#include<bits/stdc++.h>
using namespace std;

//time Complexity: O(N*N)
//space Complexity: O(N)

void countFreq(int arr[],int n){

    // vector<bool> visited(n,false);

    // for(int i=0;i<n;i++){
    //     if(visited[i]== true) continue;

    //     int count=1;
    //     for(int j=i+1;j<n;j++){
    //       if(arr[i]==arr[j]){
    //         visited[j]=true;
    //         count++;
    //       }
    //     }
    //     cout<<arr[i]<<" "<<count<<endl;
    // }



    /////// TC=O(N)
    /////// SC=O(N)
    unordered_map<int, int> map;
    for(int i=0;i<n;i++){
        map[arr[i]]++;
    }
    for(auto x:map){
        cout<<x.first <<" "<<x.second<<endl;
    }

}
int main(){
    int arr[]={10,30,50,30,20,50,10,40,60};
    int n=sizeof(arr)/sizeof(arr[0]);

  countFreq(arr,n);
}