#include<bits/stdc++.h>
using namespace std;

#define LL long long

vector < LL > v(10e6,-1);

LL coin( LL n ){
    if( n< 2 ) return n;
    if( n< 10e6 &&v[n]!=-1 )return v[n];
    LL temp= max( n, coin(n/2)+coin(n/3)+coin(n/4) );
    if(n< 10e6 )v[n]=temp;
    return temp;

}

int main(){
    LL n, a_i, b_i, temp;

    while(cin>>n){
    cout<<coin(n)<<endl;
    }
    main();
}
