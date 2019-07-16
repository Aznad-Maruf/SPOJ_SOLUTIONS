#include<bits/stdc++.h>
using namespace std;


long long noOfNodes, noOfEdges, noOfTrialEdges, src, des, maxi = 1e10;

vector < vector < pair < long long, long long > > > graph, graphR;
vector < long long > distanceF, distanceB;

void reverseGraph(){
    long long a_i, b_i, temp;

    for( a_i=1; a_i<=noOfNodes; a_i++ ){
        for( auto x: graph[a_i] ){
            graphR[x.second].push_back( make_pair( x.first, a_i ) );
        }
    }

}

void minD( vector < long long > & distance, vector < vector < pair < long long, long long > > > & graphh, long long srcc ){
    long long a_i, b_i, n, temp, cu, dis;
    distance.resize( noOfNodes+1, maxi );
    vector < long long > isVisited( noOfNodes+1, false );
    priority_queue < pair < long long, long long >, vector < pair < long long, long long > >, greater < pair < long long, long long > > > pq;

     pq.push( make_pair( 0, srcc ) ); distance[srcc] = 0;

    while( !pq.empty() ){
            //cout<<pq.top().second<<endl;
        cu = pq.top().second;
        dis = distance[cu];
        pq.pop();

        if( isVisited[cu] ) continue;
        isVisited[cu] = true;

        for( auto x: graphh[cu] ){
            if( dis+x.first < distance[x.second] ){
                    //cout<<cu<<" "<<dis<<" "<<distance[x.second]<<endl;
                distance[x.second] = dis+x.first;
                pq.push( make_pair( distance[x.second], x.second ) );
            }
        }

        //cout<<cu<<endl;

        //for( a_i=1; a_i<= noOfNodes; a_i++ ) cout<<a_i<<" "<<distance[a_i]<<endl;
    }

    //for( a_i=1; a_i<= noOfNodes; a_i++ ) cout<<a_i<<" "<<distance[a_i]<<endl;

    //return distance[des];

}

void addEdge( long long n1, long long n2, long long d, vector < vector < pair < long long, long long > > > & graphh ){
    graphh[n1].push_back( make_pair( d, n2 ) );
}

void printV( vector < long long > &v ){
    for( long long a_i=1; a_i<v.size(); a_i++ ) cout<<a_i<<" "<<v[a_i]<<endl;
    cout<<endl;
}

int main(){
    long long a_i, b_i, n, testCase, n1, n2, d, mini, temp1, temp2, tn1, tn2 , temp;

    cin>>testCase;
    while( testCase-- ){
        cin>>noOfNodes>>noOfEdges>>noOfTrialEdges>>src>>des;

        graph.clear(); distanceF.clear(); distanceB.clear(); graphR.clear();
        graph.resize( noOfNodes+1 ); graphR.resize( noOfNodes+1 );

        while( noOfEdges-- ){
            cin>>n1>>n2>>d;
            addEdge( n1, n2, d, graph );
            addEdge( n2, n1, d, graphR );
        }

        minD( distanceF, graph, src );

        //prlong longV( distanceF );

        //reverseGraph();

        minD( distanceB, graphR, des );

        //prlong longV( distanceB );

        mini = distanceF[des];
        while( noOfTrialEdges-- ){
            cin>>n1>>n2>>d;

            temp1 = distanceF[n1] + distanceB[n2] + d;
            temp2 = distanceF[n2] + distanceB[n1] + d;

            temp = min( temp1, temp2 );
            //cout<<temp<<endl;

            mini = min( temp, mini );
            //cout<<mini<<endl;

        }

        if( mini == maxi ) cout<<-1<<endl;
        else cout<<mini<<endl;

    }

}
