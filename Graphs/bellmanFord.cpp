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

        void BellmanFord(int src, int n){
            vector <int> dist(n, INT_MAX);
            dist[src] = 0;
            
            for(int i=0; i<n-1; i++){
                for(auto t: adjList){
                    for(auto nbr: t.second){
                        int u = t.first;
                        int v = nbr.first;
                        int wt = nbr.second;
                        if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                            dist[v] = dist[u] + wt;
                        }
                    }
                }
            }
            //Check negative cycle
            bool negativeCycle = false;
            for(auto t: adjList){
                for(auto nbr: t.second){
                    int u = t.first;
                    int v = nbr.first;
                    int wt = nbr.second;
                    if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                        negativeCycle = true;
                        dist[v] = dist[u] + wt;
                        break;
                    }
                }
            }

            if(negativeCycle){
                cout << "Negative cycle present in the graph" << endl;
                return ;
            }

            cout << "minimum distances for all nodes: " << endl;
            for(auto i: dist){
                cout << i << " ";
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
    g.addEdge(0,1,-1,1);
    g.addEdge(0,2,4,1);
    g.addEdge(1,2,3,1);
    g.addEdge(1,3,2,1);
    g.addEdge(1,4,2,1);
    g.addEdge(3,1,1,1);
    g.addEdge(3,2,5,1);
    g.addEdge(4,3,-3,1);

    g.printAdjList();
    cout << endl;

    g.BellmanFord(0, n);
    return 0;
}