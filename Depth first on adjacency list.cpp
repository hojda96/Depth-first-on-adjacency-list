/*
 Implement a depth-first search (DFS) algorithm to traverse a graph represented as an adjacency list.
*/


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool runDFS(vector<vector<int>> graph, int startingPosition);

// function to add an edge for an undirected graph
void addEdge(vector<vector<int>>& graph, int u, int v) {
	graph[u].push_back(v); // add v to u’s list
	graph[v].push_back(u); // add u to v’s list 
}

int main() {
	int numVertices = 5; // graph with 5 vertices
	vector<vector<int>> adjList(numVertices);

	// adding edges
	addEdge(adjList, 0, 1);
	addEdge(adjList, 0, 4);
	addEdge(adjList, 1, 2);
	addEdge(adjList, 1, 3);
	addEdge(adjList, 1, 4);
	addEdge(adjList, 2, 3);
	addEdge(adjList, 3, 4);

	
	for (int i = 0; i < numVertices; ++i) { // print adjacency list
		cout << i << ": ";
		for (int j : adjList[i]) {
			cout << j << " ";
		}
		cout << endl;
	}

	cout<<"Function completed with return value: " <<runDFS(adjList, 1);

}

bool runDFS(vector<vector<int>> graph, int startingPosition )
{
	vector<bool> noted(graph.size(), false); //list of all nodes
	stack<int> toDoList;


	toDoList.push(startingPosition);
	noted[startingPosition] = true;
	
	int currentlyIn;


	while (!toDoList.empty()){

	
		cout << "entering node " << toDoList.top() << endl;
		currentlyIn = toDoList.top();
		toDoList.pop();
		

		for  (auto var : graph[currentlyIn])
		{
			if (!noted[var]) {
				toDoList.push(var);
				cout << "adding node " << var << endl;
				noted[var] = true;
			}
		}
		cout << "exiting node " << currentlyIn << endl;
		
	}

	for (auto var : noted) //check if all visited
	{
		if (!var) return false; 
	}
	return true;
}