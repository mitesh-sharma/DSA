#include<iostream>
#include<unordered_map>
#include<list>
#include <queue>
#include <stack>
#include <set>
using namespace std;
template <typename T>

class Graph{

    unordered_map<T, list <pair<int, int>>> adjList;

    public:
        void addEdge(T u, T v, int wt,bool isdirected){
            adjList[u].push_back({v,wt});

            if(!isdirected){
                adjList[v].push_back({u,wt});
            }
        }

        void printAdjList(){
            for(auto node:adjList){
                cout << node.first << " -> ";
                for(auto nbr: node.second){
                    cout << "(" << nbr.first << ", " << nbr.second << ") ";
                }
                cout << endl;
            }
        }

        void floydWarshall(int n){
            vector <vector <int>> dist(n, vector <int> (n, 1e9));
            for(int i=0; i<n; i++){
                dist[i][i] = 0;
            }

            for(auto t: adjList){
                for(auto nbr: t.second){
                    int u = t.first;
                    int v = nbr.first;
                    int wt = nbr.second;
                    dist[u][v] = wt;
                }
            }

            for(int helper=0; helper<n; helper++){
                for(int src=0; src<n; src++){
                    for(int dest=0; dest<n; dest++){
                        dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
                    }
                }
            }

            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    cout << dist[i][j] << " ";
                }
                cout << endl;
            }
        }

};
int main()
{
    Graph <int> g;

    // weighted graph
    int n;
    cout << "enter number of Nodes: ";
    cin >> n;
    g.addEdge(0,1,3,1);
    g.addEdge(0,3,5,1);
    g.addEdge(1,0,2,1);
    g.addEdge(1,3,4,1);
    g.addEdge(2,1,1,1);
    g.addEdge(3,2,2,1);

    g.printAdjList();
    cout << endl;

    g.floydWarshall(n);

    return 0;
}