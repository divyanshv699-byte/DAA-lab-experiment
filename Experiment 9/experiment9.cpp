#include<iostream>
#include<climits>
using namespace std;
#define MAX 100

void dijkstra(int graph[MAX][MAX],int n,int source){
    int dist[MAX];
    bool visited[MAX];

    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
        visited[i]=false;
    }
    dist[source]=0;

    for(int count=0;count<n;count++){
        int u=-1;
        int mindist=INT_MAX;
        for(int i=0;i<n;i++){
            if(!visited[i] && dist[i]<mindist){
                mindist=dist[i];
                u=i;
            }
        }
        if(u==-1)
            break;
        
        visited[u]=true;
    

        for(int v=0;v<n;v++){
            if(!visited[v] && graph[u][v]!=0 && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }

    cout<<"\n shortest distances from source"<<source<<":\n";
    for(int i=0;i<n;i++){
        if(dist[i]==INT_MAX){
            cout<<"vertex "<<i<<" ->infinite\n";
        }
        else{
            cout<<"vertex "<<i<<"->"<<dist[i]<<"\n";
            
        }

    }
        
    



}

int main(){
    int graph[MAX][MAX];
    int n, source;
    cout<<"enter number of vertices";
    cin>>n;
    cout<<"enter adjancy marix(enter 0 is there is no vertex)";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
    cout<<"enter source vertex(0 to"<<n-1<<")";
    cin>>source;
    dijkstra(graph,n,source);
    return 0;

    

}