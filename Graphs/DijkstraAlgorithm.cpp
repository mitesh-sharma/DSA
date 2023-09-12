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

        void shortestDistanceDijkstra(int src, int n){
            vector <int> dist(n, INT_MAX);
            set <pair<int, int>> st;
            dist[src] = 0;
            st.insert(make_pair(0, src));

            while(!st.empty()){
                //fetch the smallest or top element from set
                auto topElement = *(st.begin());
                int nodeDistance = topElement.first;
                int node = topElement.second;
                st.erase(st.begin());
                for(auto nbr: adjList[node]){
                    if(nodeDistance + nbr.second < dist[nbr.first]){
                        //finding entry in set
                        //insert in dist array and set both
                        dist[nbr.first] = nodeDistance + nbr.second;
                        st.insert(make_pair(dist[nbr.first], nbr.first));
                    } 
                }
            }
            cout << "minimum distances for all nodes: " << endl;
            for(int i=0; i<n; i++){
                cout << i << "->" << dist[i] << ", ";
            }
            cout << endl;
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

    g.shortestDistanceDijkstra(0, n);
    return 0;
}