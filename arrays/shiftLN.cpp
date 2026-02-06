#include<bits/stdc++.h>
using namespace std;
void shiftLeftbyNplace(int arr[],int n,int d){
       if(d==0) return;
    if(d>n) d=d%n;
    int temp[d];
    for(int i=0;i<d;i++){
        temp[i]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=arr[i+d];
    }
 
 for(int i=0;i<d;i++){
     arr[n-d+i]=temp[i];
 }
    for(int i=0;i<n;i++){
  cout<<arr[i]<<" ";

}
cout<<endl;
}

void shiftRightbyNplace(int arr[],int n,int d){
    if(d==0) return;
    if(d>n) d=d%n;
    int temp[d];
    for(int i=0;i<d;i++){
temp[i]=arr[n-d+i];
    }
    for(int i=n-1;i>=d;i--){
        arr[i]=arr[i-d];
    }
    for(int i=0;i<d;i++){
        arr[i]=temp[i];
    }
       for(int i=0;i<n;i++){
  cout<<arr[i]<<" ";}
}

void reverse(int arr[],int start,int end){
    while(start<=end){
 int temp=arr[start];
 arr[start]=arr[end];
 arr[end]=temp;
 start++;
 end--;
    }
}

void recursiveRight(int arr[],int n,int k){
    reverse(arr,0,n-k-1);
    reverse(arr,n-k,n-1);
    reverse(arr,0,n-1);
}

 void recursiveleft(int arr[],int n,int k){
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
    reverse(arr,0,n-1);
}
int main(){
        
    int arr[]={1,2,3,4,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
     int d;
     cout<<"Enter the number";
     cin>>d;
    // recursiveleft(arr,n,d);
    recursiveRight(arr,n,d);
            for(int i=0;i<n;i++){
  cout<<arr[i]<<" ";}

   //shiftLeftbyNplace(arr,n,d);
   //shiftRightbyNplace(arr,n,d);
    return 0;
}