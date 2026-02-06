#include <iostream>
using namespace std;


void pattern1(int n){
for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
}

void pattern2(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
}

void pattern3(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        cout<<endl;
    }
}

void pattern4(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<i;
        }
        cout<<endl;
    }
}

void pattern5(int n){
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern6(int n){
for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        cout<<endl;
    }
}

void pattern7(int n){
   for(int i=0;i<n;i++){
       for(int j=0;j<n-i-1;j++){
        cout<<" ";
       }
       for(int k=0;k<2*i+1;k++){
        cout<<"*";
       }
   
       cout<<endl;
    }
 
}

void pattern8(int n){
    for(int i=0;i<n;i++){
    for(int k=0;k<i;k++){
        cout<<" ";
    }
    for(int j=0;j<(2*n)-(i*2+1);j++){
           cout<<"*";
        }
    cout<<endl;
    }
   
}

void pattern9(int n){
for(int i=0;i<n;i++){
       for(int j=0;j<n-i-1;j++){
        cout<<" ";
       }
       for(int k=0;k<2*i+1;k++){
        cout<<"*";
       }
   
       cout<<endl;
    }
      for(int i=0;i<n;i++){
    for(int k=0;k<i;k++){
        cout<<" ";
    }
    for(int j=0;j<(2*n)-(i*2+1);j++){
           cout<<"*";
        }
    cout<<endl;
    }
}

void pattern10(int n){
for(int i=0;i<=2*n-1;i++){
    int star=i;
    if(i>n)
    star=2*n-i;
    for(int j=1 ;j<=star;j++){
        cout<<"*";
    }
    cout<<endl;
}
}

void pattern11(int n){
for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
        if((i+j)%2==0)
        cout<<"1";
        else
        cout<<"0";
    }
    cout<<endl;
}
}

void pattern12(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        for(int k=1;k<=2*(n-i);k++)
        {
            cout<<" ";
        }
        for(int l=i;l>=1;l--){
            cout<<l;
        }
        cout<<endl;
    }

}

void pattern13(int n){
     int number=1;
    for(int i=1;i<=n;i++){
       
        for(int j=1;j<=i;j++){
            cout<<number<<" " ;
             number++;
        }
       
        cout<<endl;
    }
}

void pattern14(int n){
    for(int i=0;i<n;i++){
        for(char ch='A';ch<='A'+i;ch++)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

void pattern15(int n){
for(int i=n-1;i>=0;i--){
    for(char ch='A';ch<='A'+i;ch++)
    {
        cout<<ch<<" ";
    }
    cout<<endl;
}
}

void pattern16(int n){
   
for(int i=0;i<n;i++){
    char ch='A'+i;
    for(int j=0;j<=i;j++){
        cout<< ch<<" ";
    }
    cout<<endl;
}
}

void pattern17(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
         char ch='A';
         int breakpoint=(2*i+1)/2;
        for(int j=1;j<=2*i+1;j++){
            cout<<ch;
            if(j<= breakpoint)
            ch++;
            else
            ch--;
        }
        cout<<endl;
    }
}

void pattern18(int n){
    for(int i=0;i<n;i++){
    for (char ch ='E'-i; ch<='E'; ch++) 
    {
        cout<<ch<<" ";
    }
    cout<<endl;
}
}

void pattern19(int n){
    for(int i=1;i<=n;i++){
        for(int j=n;j>=i;j--){
            cout<<"*";
        }
        
        for(int j=1;j<=2*(i-1);j++){
           cout<<" ";
        }

        for(int j=n;j>=i;j--){
            cout<<"*";
        }
        cout<<endl;
    }
 int intis=8;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=k;i++){
            cout<<"*";
        }
        for(int j=0;j<intis;j++){
            cout<<" ";
        }
        for(int i=1;i<=k;i++){
            cout<<"*";
        }
        intis-=2;
        cout<<endl;
    }
}

void pattern20(int n){
     int intis=8;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=k;i++){
            cout<<"*";
        }
        for(int j=0;j<intis;j++){
            cout<<" ";
        }
        for(int i=1;i<=k;i++){
            cout<<"*";
        }
        intis-=2;
        cout<<endl;
    }


        for(int i=1;i<=n;i++){
        for(int j=n;j>=i;j--){
            cout<<"*";
        }
        
        for(int j=1;j<=2*(i-1);j++){
           cout<<" ";
        }

        for(int j=n;j>=i;j--){
            cout<<"*";
        }
        cout<<endl;
    }
 }

void pattern21(int n){
 for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(i==0||j==0||i==n-1||j==n-1){
            cout<<"*";
        }
        else cout<<" ";
    }
    cout<<endl;
 }
 }

void pattern22(int n){
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<2*n-1;j++){
            int top=i;
            int left=j;
            int right=(2*n-2)-j;
            int down=(2*n-2)-i;
            cout<<(n- min(min(top,down),min(left,right)))<<" ";
        }
        cout<<endl;
    }
}


int main(){
    int n;
    cin>>n;
   // pattern1(n);
    //pattern2(n);
    //pattern3(n);
    //pattern4(n);
   // pattern5(n);
   //pattern6(n);
  // pattern7(n);
 // pattern8(n);
// pattern9(n);
//pattern10(n);
//pattern11(n);
//pattern12(n);
//pattern13(n);
//pattern14(n);
//pattern15(n);
// pattern16(n);
//pattern17(n);

//pattern18(n);
//pattern19(n);
//pattern20(n);
//pattern21(n);
pattern22(n);
    return 0;
}
