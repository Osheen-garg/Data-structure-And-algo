#include<bits/stdc++.h>
using namespace std;


// TC=O(n*2)
//SC=O(n)
void moveZeros(vector <int> &nums,int n){
   vector <int> temp;
   for(int i=0;i<n;i++){
    if(nums[i]!=0){
        temp.push_back(nums[i]);
    }
   }          
   int s=temp.size();
   for(int i=0;i<s;i++){
    nums[i]=temp[i];
   }      
   for(int i=s;i<n;i++){
    nums[i]=0;
   }           


}

//TC=O(N)
//SC=O(1)
void moveZerosO(vector <int> &nums,int n){
int j=-1;
for( int i=0;i<n;i++){
    if(nums[i]==0){
        j=i;
        break;
    }
}

for(int i=j+1;i<n;i++){
    if(nums[i]!=0){
         int temp=nums[i];
    nums[i]=nums[j];
    nums[j]=temp;
    j++;
    }
   
}
}
int main(){
        vector <int> v={0,1,4,0,5,2};
    int n=v.size();
    moveZerosO(v,n);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

    return 0;
}
