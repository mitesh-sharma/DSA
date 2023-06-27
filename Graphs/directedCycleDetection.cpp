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

        bool checkCyclicDirectedGraphDFS(int src, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsvisited){
            visited[src] = true;
            dfsvisited[src] = true;

            for(auto nbr : adjList[src]){
                if(!visited[nbr]){
                    bool ans = checkCyclicDirectedGraphDFS(nbr, visited, dfsvisited);
                    if(ans){
                        return true;
                    }
                }
                else{
                    if(dfsvisited[nbr] == true){
                        return true;
                    }
                }
            }
            dfsvisited[src] = false;
            return false;
        }
};
int main()
{
    Graph <int> g;
    int n;
    cout << "Enter number of Nodes: ";
    cin >> n;   

    g.addEdge(0,1,1);
    g.addEdge(1,4,1);
    g.addEdge(4,3,1);
    g.addEdge(3,2,1);
    // g.addEdge(2,1,1);

    g.printAdjList();

    unordered_map <int, bool> visited;
    unordered_map <int, bool> dfsvisited;
    bool ans;
    for(int i=0; i<n; i++){
        ans = g.checkCyclicDirectedGraphDFS(i, visited, dfsvisited);
    }

    if(ans){
        cout << "Cycle present" << endl;
    }
    else{
        cout << "Cycle Not Present"<< endl;
    }
    return 0;
}