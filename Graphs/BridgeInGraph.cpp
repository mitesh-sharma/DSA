#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include <queue>
#include <stack>
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

        int countSCC(){
            
        }

};
int main()
{
    Graph <int> g;

    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(4,5,1);
    g.addEdge(5,2,1);

    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    g.printAdjList();
    cout << endl;

    
    
    return 0;
}