#pragma once

#include <iostream>
#include <vector>
#include <functional>

using namespace std;
namespace krusalgraph
{

	struct Edge
	{
		int src, dest;
	};

	//std::pair<int, Edge> weightedEdge;

	class Graph
	{
	public:
		int vertices;
		std::map<int, Edge> edges;

	
		Graph(int v) : vertices(v){}
		void addEdge(int src, int dest, int weight)
		{
			//std::pair<int, Edge> weightedEdge{ weight,{src,dest} };
			edges[weight] =  Edge{ src,dest };
		}

	
	};

	void run()
	{
		Graph graph(4);
		graph.addEdge(0, 1, 2);
		graph.addEdge(1, 2, 3); 
		graph.addEdge(0, 3, 4);
		graph.addEdge(3, 2, 1);

		//Already sorted
		for_each(graph.edges.begin(), graph.edges.end(), [](const std::pair<int,Edge> &mypair) { cout << mypair.first << "->Edge:"<< mypair.second.src << ":" << mypair.second.dest << endl; });

		int visited[4] = { 0 };
		for (auto n : graph.edges)
		{
			
		}



	}

}