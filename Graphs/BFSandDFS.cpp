#include<iostream>
#include<unordered_map>
#include<list>
#include <queue>
using namespace std;
template <typename T>

class Graph{

    unordered_map<T, list <int>> adjList;
    public:
        void addEdge(T u, T v, bool isdirected){
            adjList[u].push_back(v);

            if(!isdirected){
                adjList[v].push_back(u);
            }
        }

        void printAdjList(){
            for(auto node:adjList){
                cout << node.first << " -> ";
                for(auto neighbor: node.second){
                    cout << neighbor <<" ";
                }
                cout << endl;
            }
        }
};
int main()
{
    Graph <int> g;

    //add edges (u, v, directed)
    g.addEdge(0,1,0);

    //printGraph
    g.printAdjList();
    cout << endl;

    return 0;
}