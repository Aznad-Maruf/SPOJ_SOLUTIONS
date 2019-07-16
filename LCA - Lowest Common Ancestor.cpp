#include<bits/stdc++.h>
using namespace std;


vector < vector < int > > tree;
vector < int > label;
vector < bool > isVisited;
vector < int > parent;
void addEdge( int n1, int n2 ){
    if( n1 > n2 ) swap( n1, n2 );
    parent[n2]=n1;
    tree[n1].push_back( n2 );
}

void dfs( int cuN ){
    int a_i, b_i, n=tree.size()-1;
    if( isVisited[cuN] ) return;
    for( int x: tree[cuN] ){
            label[x]=label[cuN]+1;
            dfs( x );
    }
    isVisited[cuN] = true;
}

int lcs( int n1, int n2 ){
    while( n1 != n2 ){
        if( label[n1] > label[n2] ) n1=parent[n1];
        else if( label[n2] > label[n1] ) n2= parent[n2];
        else{
            n1=parent[n1];
            n2=parent[n2];
        }
    }
    return n1;
}


int main(){
    int a_i, b_i, noOfNodes, noOfEdges, n1, n2, testCase, temp, q, a_t=0;
    cin>>testCase;
    while( testCase-- ){
        cin>>noOfNodes;

        tree.resize( noOfNodes+1 );
        label.resize( noOfNodes+1, 0 );
        isVisited.resize( noOfNodes+1, false );
        parent.resize( noOfNodes+1, 1 );
        for( a_i=0; a_i<=noOfNodes; a_i++ ) parent[a_i]=a_i;

    noOfEdges = noOfNodes-1;

        a_i=1;
        while( a_i<=noOfNodes ){
            cin>>temp;
            while( temp-- ){
                cin>>n2;
                addEdge( a_i, n2 );
            }
            a_i++;
        }

        dfs( 1 );

    //for( a_i=1; a_i<=noOfNodes; a_i++ ) cout<<a_i<<" -> "<<label[a_i]<<endl;

    cin>>q;
    cout<<"Case "<<++a_t<<":"<<endl;
    while( q-- ){
        cin>>n1>>n2;
        cout<<lcs( n1, n2 )<<endl;
    }

    tree.clear();
    label.clear();
    isVisited.clear();
    parent.clear();

    }
}
