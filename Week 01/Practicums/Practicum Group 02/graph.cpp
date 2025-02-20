#include <iostream>
#pragma warning(disable:4996)

namespace CONSTANTS
{
	constexpr int MAX_NODE_NAME_SIZE = 10;
}

struct Node
{
	char name[CONSTANTS::MAX_NODE_NAME_SIZE + 1]{};
};

struct Edge
{
	Node from;
	Node to;
};

struct Graph
{
	Edge* edges = nullptr;
	size_t nodesCount = 0;
	size_t edgesCount = 0;
	size_t edgesCapacity = 0;
};

void freeMatrix(char** matrix, size_t rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}

void updateNodesCount(Graph& graph)
{
	char** allNames = new char* [graph.edgesCount * 2];
	size_t namesCount = 0;

	for (size_t i = 0; i < graph.edgesCount * 2; i++)
	{
		allNames[i] = new char[CONSTANTS::MAX_NODE_NAME_SIZE + 1];
	}

	for (size_t i = 0; i < graph.edgesCount; i++)
	{
		bool isFromFound = false;
		bool isToFound = false;

		for (size_t j = 0; j < namesCount; j++)
		{
			if (strcmp(graph.edges[i].from.name, allNames[j]) == 0)
			{
				isFromFound = true;
			}
			if (strcmp(graph.edges[i].to.name, allNames[j]) == 0)
			{
				isToFound = true;
			}
		}

		if (!isFromFound)
		{
			strncpy(allNames[namesCount], graph.edges[i].from.name, CONSTANTS::MAX_NODE_NAME_SIZE);
			allNames[namesCount][CONSTANTS::MAX_NODE_NAME_SIZE] = '\0';
			namesCount++;
		}

		if (!isToFound)
		{
			strncpy(allNames[namesCount], graph.edges[i].to.name, CONSTANTS::MAX_NODE_NAME_SIZE);
			allNames[namesCount][CONSTANTS::MAX_NODE_NAME_SIZE] = '\0';
			namesCount++;
		}
	}

	graph.nodesCount = namesCount;
	freeMatrix(allNames, graph.edgesCount * 2);
}

Graph readGraph()
{
	Graph graph;
	
	std::cin >> graph.edgesCount;
	std::cin.ignore();

	graph.edges = new Edge[graph.edgesCount];
	graph.edgesCapacity = graph.edgesCount;

	for (int i = 0; i < graph.edgesCount; i++)
	{
		std::cin >> graph.edges[i].from.name >> graph.edges[i].to.name;
	}

	updateNodesCount(graph);
	return graph;
}

void deleteGraph(Graph& graph)
{
	delete[] graph.edges;
	graph.edges = nullptr;

	graph.nodesCount = 0;
	graph.edgesCount = 0;
	graph.edgesCapacity = 0;

}

void resize(Graph& graph, size_t newCapacity)
{
	Edge* newEdges = new Edge[newCapacity];

	for (int i = 0; i < graph.edgesCount; i++)
	{
		newEdges[i] = graph.edges[i];
	}

	delete[] graph.edges;
	graph.edges = newEdges;
	graph.edgesCapacity = newCapacity;
}

void addEdge(const Node& from, const Node& to, Graph& graph)
{
	if (graph.edgesCount >= graph.edgesCapacity)
	{
		resize(graph, graph.edgesCapacity * 2);
	}

	graph.edges[graph.edgesCount++] = { from, to };
}

int findEdge(const Edge& edge, Graph& graph)
{
	for (int i = 0; i < graph.edgesCount; i++)
	{
		if (strcmp(graph.edges[i].from.name, edge.from.name) == 0
			&& strcmp(graph.edges[i].to.name, edge.to.name) == 0)
		{
			return i;
		}
	}

	return -1;
}

void removeEdge(const Edge& edge, Graph& graph)
{
	int removeAt = findEdge(edge, graph);
	if (removeAt == -1)
	{
		std::cerr << "[ERROR] Edge does not exist" << std::endl;
		return;
	}

	for (int i = removeAt; i < graph.edgesCount - 1; i++)
	{
		graph.edges[i] = graph.edges[i + 1];
	}

	graph.edgesCount--;

	if (graph.edgesCount < graph.edgesCapacity / 2)
	{
		resize(graph, graph.edgesCapacity / 2);
	}
}

size_t getIndegree(const Node& node, const Graph& graph)
{
	size_t indegree = 0;

	for (int i = 0; i < graph.edgesCount; i++)
	{
		if (strcmp(graph.edges[i].to.name, node.name) == 0)
		{
			indegree++;
		}
	}

	return indegree;
}

size_t getOutdegree(const Node& node, const Graph& graph)
{
	size_t outdegree = 0;

	for (int i = 0; i < graph.edgesCount; i++)
	{
		if (strcmp(graph.edges[i].from.name, node.name) == 0)
		{
			outdegree++;
		}
	}

	return outdegree;
}

bool isComplete(const Graph& graph)
{
	return graph.edgesCount == graph.nodesCount * (graph.nodesCount - 1);
}

void printGraph(const Graph& graph)
{
	std::cout << "[Directed Graph]" << std::endl;
	std::cout << "[Edges Count] " << graph.edgesCount << std::endl;
	std::cout << "[Nodes Count] " << graph.nodesCount << std::endl;

	for (size_t i = 0; i < graph.edgesCount; i++)
	{
		std::cout << graph.edges[i].from.name << " -> " << graph.edges[i].to.name << std::endl;
	}

	std::cout << std::endl;
}

int main()
{
	Graph graph = readGraph();
	printGraph(graph);

	Node a = { "A" };
	Node b = { "B" };
	Node c = { "C" };

	std::cout << "Adding edge A->C" << std::endl;
	addEdge(a, c, graph);
	printGraph(graph);
	std::cout << "[C] indegree: " << getIndegree(c, graph) << std::endl;
	std::cout << std::endl;

	std::cout << "Removing edge B->C" << std::endl;
	Edge edgeToRemove = { b, c };
	removeEdge(edgeToRemove, graph);
	printGraph(graph);
	std::cout << "[C] indegree: " << getIndegree(c, graph) << std::endl;
	std::cout << std::endl;

	deleteGraph(graph);
	std::cout << "Graph deleted." << std::endl;

	return 0;
}
