#include<bits/stdc++.h>
using namespace std;

vector < int > v;

void alphaCode( string &st, int pos, int s ){
    if (pos >= s ) return;
    if(v.empty()) v.push_back( st[ pos ] );
    else{
        for( int x : v ){

        }
    }
}

int main(){
    int n, a_i, b_i, ans, l;
    string st;
    while( cin>>st && st!="0" ){

            l=st.size();
            alphaCode( st, 0, l );
    }
}
