#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Graph {
    vector<vector<char>> adjList;
    unordered_map<char, int> vertexIndices;

public:
    Graph(int V) {
        adjList.resize(V);
    }

    void addEdge(char u, char v) {
        int indexU = getIndex(u);
        int indexV = getIndex(v);

        adjList[indexU].push_back(v);
        adjList[indexV].push_back(u);
    }

    int countEdges() {
        int count = 0;
        for (int i = 0; i < adjList.size(); i++) {
            count += adjList[i].size();
        }
        return count / 2;
    }

    void Indegree() {
        for (int i = 0; i < adjList.size(); i++) {
            int degree = adjList[i].size();
            cout << "Vertex " << getVertexByIndex(i) << " has an indegree of " << degree << endl;
        }
    }

    void Outdegree() {
        for (int i = 0; i < adjList.size(); i++) {
            int outdegree = adjList[i].size();
            cout << "Vertex " << getVertexByIndex(i) << " has an outdegree of " << outdegree << endl;
        }
    }

    bool hasEdge(char u, char v) {
        int indexU = getIndex(u);
        for (char vertex : adjList[indexU]) {
            if (vertex == v) {
                return true; 
            }
        }
        return false;
    }

private:
    int getIndex(char vertex) {
        if (vertexIndices.find(vertex) == vertexIndices.end()) {
            int newIndex = vertexIndices.size();
            vertexIndices[vertex] = newIndex;
            return newIndex;
        }
        return vertexIndices[vertex];
    }

    char getVertexByIndex(int index) {
        for (const auto& entry : vertexIndices) {
            if (entry.second == index) {
                return entry.first;
            }
        }
        return '\0'; 
    }
};

int main() {
    int V = 6;
    Graph g(V);
    g.addEdge('f', 'e');
    g.addEdge('f', 'a');
    g.addEdge('f', 'b');
    g.addEdge('a', 'f');
    g.addEdge('a', 'b');
    g.addEdge('b', 'a');
    g.addEdge('b', 'f');
    g.addEdge('b', 'e');
    g.addEdge('b', 'd');
    g.addEdge('b', 'c');
    g.addEdge('e', 'f');
    g.addEdge('e', 'b');
    g.addEdge('e', 'd');
    g.addEdge('d', 'e');
    g.addEdge('d', 'b');
    g.addEdge('d', 'c');
    g.addEdge('c', 'd');
    g.addEdge('c', 'b');

    int edges = g.countEdges();
    cout << "Number of edges in the graph: " << edges << endl;
    
    char u = 'b', v = 'c';
    if (g.hasEdge(u, v)) {
        cout << "Edge (" << u << ", " << v << ") exists in the graph." << endl;
    } else {
        cout << "Edge (" << u << ", " << v << ") does not exist in the graph." << endl;
    }

    g.Indegree();
    g.Outdegree();

    return 0;
}
