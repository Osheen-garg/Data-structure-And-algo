#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long double sol1(vector<int> arr,int k){
    int n=arr.size();
    vector<int> howMany(n-1,0);
    for(int i=1;i<=k;i++){
        int maxInx=-1;
        long double maxSection=-1;
        for(int i=0;i<n-1;i++){
            long double diff=arr[i+1]-arr[i];
            long double sectionLength=diff/(howMany[i]+1.0);
            if(maxSection<sectionLength){
                maxSection=sectionLength;
                maxInx=i;
            }
        }
        howMany[maxInx]++;
    }
long double maxAns=-1;
    for(int i=0;i<n-1;i++){
        long double diff=arr[i+1]-arr[i];
        long double seclen=diff/(howMany[i]+1.0);
        maxAns=max(maxAns,seclen);
    }
    return maxAns;
}

long double sol2(vector<int> arr,int k){
    int n=arr.size();
    vector <int> howMany(n-1,0);
    priority_queue <pair<long double,int>> pq;

    for(int i=0;i<n-1;i++){
        int diff=arr[i+1]-arr[i];
        pq.push({diff,i});
    }

    for(int i=1;i<=k;i++){
    auto tp=pq.top();
    pq.pop();
    int secIndex=tp.second;
    howMany[secIndex]++;
    long double secDiff=arr[secIndex+1]-arr[secIndex];
    long double newlen=secDiff/(howMany[secIndex]+1);
    pq.push({newlen,secIndex});
    }
    return pq.top().first;
}


int GSrequired(long double dist,vector <int> arr){
    int n=arr.size();
    int cnt=0;
    for(int i=1;i<n;i++){
        int diff=(arr[i]-arr[i-1])/dist;
        if((arr[i]-arr[i-1])==(dist * diff)){
            diff--;
        }
        cnt+=diff;
    }
    return cnt;
}

long double sol3(vector<int> arr,int k){
    int n=arr.size();
    long double low=0,high=0;
    for(int i=0;i<n-1;i++){
        high=max(high,(long double)(arr[i+1]-arr[i]));
    }

    long double diff=1e-6;

    while(high-low>diff){
        long double mid=(low+high)/2.0;
        int cnt=GSrequired(mid,arr);
        if (cnt>k) low=mid;
        else high=mid;
    }
    return high;
}

int main(){
    vector<int> arr = {1, 13, 17, 23};
    int k = 5;
    long double ans = sol3(arr, k);

    cout << "The answer is: " << ans << "\n";
    return 0;
}