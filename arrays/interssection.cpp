#include<bits/stdc++.h>
using namespace std;
//TC O(n1*n2)
void intersec(int arr1[],int arr2[],int n1,int n2){
    vector <int> arr;
    int v[n2]={0};
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(arr1[i]==arr2[j] && v[j]==0){
                arr.push_back(arr1[i]);
                v[j]=1;
                break;
            }
            if(arr2[j]>arr1[i]) break;
        }
    }
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

}

//TC O(n1+n2)
void intersection(int arr1[],int arr2[],int n1,int n2){
    vector <int> arr;
    int i=0,j=0;
    while(i<n1 &&j<n2){
        if(arr1[i]<arr2[j]){
            i++;
        }
        else if (arr1[i]>arr2[j])
        {
            j++;
        }
        
        else{
            arr.push_back(arr1[i]);
            i++;
            j++;
        }
    }
     for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
  int arr1[]={1,1,2,3,4,5};
   int arr2[]={2,3,4,4,5,6};
     int n1=sizeof(arr1)/sizeof(arr1[0]);
        int n2=sizeof(arr2)/sizeof(arr2[0]);
   
intersection(arr1,arr2,n1,n2);
    return 0;
}