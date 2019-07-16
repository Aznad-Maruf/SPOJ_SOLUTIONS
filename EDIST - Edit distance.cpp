#include<bits/stdc++.h>
using namespace std;

int min( int n1, int n2, int n3 ){
    return min( n1, min( n2, n3 ));
}

int cont;

int minDis( string &st1, string &st2, int s1, int s2, vector < vector< int > > &v ){
    cont++;

    if(s1==0)return s2; /// when st1 is empty need to insert s2 no. of elements.
    if( s2==0 ) return s1; /// when st2 is empty need to remove s1 no. of elements.

    if( v[s1][s2]!= -1 )return v[s1][s2];

    if( st1[s1-1] == st2[s2-1] )return v[s1][s2]= minDis( st1, st2, s1-1, s2-1, v );

    else
    return v[s1][s2] = 1+min(
               minDis( st1, st2, s1, s2-1, v ), //insert
               minDis( st1, st2, s1-1, s2, v ), //remove
               minDis( st1, st2, s1-1, s2-1, v ) // replace
               );

}

int  main(){
    int a_i, b_i, n, m, s1, s2, testCase ;
    string st1, st2;

    /// Compute the minimum number of steps to convert st1 to st2 ;
    /*
     steps are :-->
     1. Insert.
     2. replace
     3. remove
    */
cin>>testCase;
while(testCase--){
    cin>>st1>>st2;

    s1= st1.size();
    s2= st2.size();
    vector< vector< int > > v( s1+1, vector< int > (s2+1, -1 ));
cont=0;
    cout<<minDis( st1, st2, s1, s2, v )<<endl;
    //cout<<cont<<endl;
}
//main();
}


