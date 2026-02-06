#include<bits/stdc++.h>
using namespace std;
//TC o(m+n)
void union_a(int arr[],int arr2[],int n1,int n2){
   int i=0,j=0;
   vector <int> v;
while(i<n1&&j<n2){
   if(arr[i]<=arr2[j]){
      if(v.size()==0||v.back()!=arr[i]){
    v.push_back(arr[i]);
   }
   i++;
}
else{
   if(v.size()==0||v.back()!=arr2[j]){
    v.push_back(arr2[j]);
   }
   j++;
}
}
while (i<n1){
   if(v.back()!=arr[i]){
   v.push_back(arr[i]);
   }
   i++;
}
while (j<n2){
      if(v.back()!=arr2[j]){
      v.push_back(arr2[j]);
   }  
   j++;
}
 for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}

//TC O(m+n)log(m+n)
//SC O(m+n)
void union_arr(int arr1[],int arr2[],int n1,int n2){
 set <int> st;
 for(int i=0;i<n1;i++){
    st.insert(arr1[i]);
 }
  for(int i=0;i<n2;i++){
    st.insert(arr2[i]);
 }
 int union_st[st.size()];
 int j=0;
 for(int x:st){
    union_st[j++]=x;
 }
     for(int i=0;i<st.size();i++){
        cout<<union_st[i]<<" ";
    }

}

int main(){
  int arr1[]={1,1,2,3,4,5};
   int arr2[]={2,3,4,4,5,6};
     int n1=sizeof(arr1)/sizeof(arr1[0]);
        int n2=sizeof(arr2)/sizeof(arr2[0]);
   // union_arr(arr1,arr2,n1,n2);
      union_a(arr1,arr2,n1,n2);

    return 0;
}