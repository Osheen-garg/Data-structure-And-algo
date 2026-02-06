#include<bits/stdc++.h>
using namespace std;
void sortarrsol1(vector <int> arr){
   sort(arr.begin(),arr.end());
       for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
   
}
void sortarrsol2(vector <int> arr){
    int count_0=0;
    int count_1=0;
    int count_2=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0){
            count_0++;
        }
        else if(arr[i]==1){
            count_1++;
        }
        else{
            count_2++;
        }
    }
    for(int i=0;i<count_0;i++){
        arr[i]=0;
    }
    for(int i=count_0;i<(count_0+count_1);i++){
        arr[i]=1;
    }
    for(int i=count_1;i<(count_0+count_1+count_2);i++){
        arr[i]=2;
    }
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
void sortarrsol3(vector <int> arr){
    int n=arr.size();
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            int temp=arr[mid];
            arr[mid]=arr[low];
            arr[low]=temp;
            mid++;
            low++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            int temp=arr[mid];
            arr[mid]=arr[high];
            arr[high]=temp;
            mid++;
            high--;
        }
    }
        for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}


int main(){
    vector <int> arr={2,1,0 ,1,0,0,2,1,1};
    sortarrsol3(arr);
    // for(int i=0;i<arr.size();i++){
    //     cout<<arr[i]<<" ";
    // }
    return 0;

}