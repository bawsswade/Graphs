#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class GraphNode
{
public:
	struct Edge
	{
		GraphNode* m_pStart;
		GraphNode* m_pEnd;
		float m_fCost;
	};
	typedef std::vector<Edge> EdgeList;
	GraphNode(){};
	GraphNode(int a_iNum);
	
	EdgeList m_aEdges;

	void AddEdge(GraphNode *endNode, float cost);

	int m_iNodeNumber;
	~GraphNode(){};
};

class Graph
{
	typedef std::vector<GraphNode*> NodeList;
public:
	//Creates an empty graph
	Graph(){};
	//Creates a graph with the given number of nodes the contents and links of the nodes are randomized
	Graph(unsigned int a_uiNodeCount);

	void AddNode(GraphNode* a_pNode);
	void RemoveNode(GraphNode* a_pNode);

	void DisplayAllNodes();

	NodeList m_aNodes;
	~Graph(){};
};


#endif //_GRAPH_H_