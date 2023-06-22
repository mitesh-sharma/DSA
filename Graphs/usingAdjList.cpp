#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template <typename T>

class Graph{

    unordered_map<T, list <pair<T, int>>> adjList;
    //for non weighted 
    // unordered_map<int, list <int>> adjList;

    public:
        //To create an edge
        void addEdge(T u, T v, int weight, bool isdirected){
            //if directed = 1, graph is directed
            //if directed = 0, graph is not directed

            //creating a node from u to v
            adjList[u].push_back({v, weight});

            // for non weighted
            // adjList[u].push_back(v);

            if(!isdirected){
                //if not directed, we add edge from v to u also
                adjList[v].push_back({u,weight});

                //for non weighted
                // adjList[v].push_back(u);
            }
        }
        //print the list
        void printAdjList(){
            for(auto node:adjList){
                cout << node.first << " -> ";
                for(auto neighbor: node.second){
                    cout << "(" <<neighbor.first << ", " << neighbor.second << ") ";

                    // for non weighted
                    // cout << neighbor << endl;
                }
                cout << endl;
            }
        }
};

int main()
{
    Graph <char> g;
    g.addEdge('A','B',3,0);
    g.addEdge('B','C',4,0);
    g.addEdge('C','A',5,0);
    cout << "start node -> (end node, weight)" << endl;
    g.printAdjList();

    return 0;
}