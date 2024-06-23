// Program to print BFS traversal from a given 
// source vertex. BFS(int s) traverses vertices  
// reachable from s. 
#include<iostream> 
#include <list> 
  
using namespace std; 
  
// This class represents a directed graph using 
// adjacency list representation 
class Graph 
{ 
    int V;    // No. of vertices 
  
    // Pointer to an array containing adjacency 
    // lists 
    list<int> *adj;    
public: 
    Graph(int V);  // Constructor 
  
    // function to add an edge to graph 
    void addEdge(int v, int w);  

    // function to display adjacency list 
    void display();  
  
    // prints BFS traversal from a given source s 
    int BFS(int s, int e);   
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
} 

void Graph::display() 
{ 
        // Iterate and print values of the list
    std::cout << "\nfor (int n : l)\n";
    for (int v=0; v<V; v++)
    {
      std::cout << "vertex v: " << v << " - ";
      for (int n : adj[v]) {
          std::cout << n << ", ";
      }
      std::cout << std::endl;
    }
} 

/* 
  Breadth First Search
  Input:
      s: start location
      e: end location
    Returns:
      the found vertice number or -1 if path not found.
*/
int Graph::BFS(int s, int e) {
  int *visited = new int[V];  
  list<int> queue;
  queue.push_back(s);

  while (!queue.empty()) {
    int current = queue.front();
    if (current == e) {
      return e;
    }
    queue.pop_front();
    bool marked = false;
    for (int i = 0; i < V; i++) {
      if (visited[current] == 1) {
        marked = true;
      }
    }
    if (!marked) {
      visited[current] = 1;
    }
    for (int w: adj[current]) {
      marked = false;
      for(int i = 0; i < V; i++) {
        if (visited[w] == 1) {
          marked = true;
        }
      }
      if (!marked) {
        queue.push_back(w);
      }
    }
  }
  //delete[] visited; // Cleanup allocated memory
  return -1;
  
}
  
// Driver program to test methods of graph class 
int main() 
{ 
    int size = 0;
    int count = 0;
    int start = 0;
    int end = 0;
    int result = 0;
    
    // Create a graph given in the above diagram 

    cout << "Enter number of vertices \n";
    cin >> size;
        Graph g(size); 
    int* arr = new int[size];
    cout << "Array size " << size << endl;
    for (int i=0; i < size; i++)
    {
      cout << "data for vertice: " << i << endl;
      cin >> count;
          for (int j=0; j < count; j++)
          {
            int t;
            cin >> t;
            cout << t << ", ";
            g.addEdge(i,t);
          }
          cout << endl;
    }
    cin >> start;
    cin >> end;
  
    cout << "Following is display of adj matrix";
    g.display();
    cout << "BFS Traversal from " << start << " to " << end << "\n"; 
    result = g.BFS(start, end); 
    if (result >= 0)
      cout << "Path exists to vertice " << result;
    else
      cout << "Path does not exists to vertice " << result;
  
    return 0; 
} 