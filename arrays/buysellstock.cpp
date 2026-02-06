#include<bits/stdc++.h>
using namespace std;

int profitStock1(vector<int> arr){
    int n = arr.size();
    int maxProfit = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[j] > arr[i]){
                maxProfit = max(arr[j] - arr[i], maxProfit);
            }
        }
    }
    return maxProfit;
}

int profitStock2(vector<int> arr){
    int n = arr.size();
    int maxProfit = 0;
    int minPrice=INT_MAX;
    for(int i = 0; i < n; i++){
       minPrice=min(arr[i],minPrice);
       maxProfit=max(maxProfit,arr[i]-minPrice);
    }
    return maxProfit;
}

int main(){
    vector<int> arr = {10, 7, 5, 8, 11, 9};
    cout << profitStock2(arr);
    return 0;
}
