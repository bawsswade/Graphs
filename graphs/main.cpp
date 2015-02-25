#include "graph.h"

int main()
{
	GraphNode Node(1);			//	create node
	GraphNode *pNode = &Node;	//	ptr to node

	GraphNode Node1(2);			//	create node
	GraphNode *pNode1 = &Node1;	//	ptr to node

	Graph myGraph;				//	create graph of Nodes
	myGraph.AddNode(pNode);
	myGraph.AddNode(pNode1);

	myGraph.DisplayAllNodes();
	//GraphNode *Node2;
	//NodeA->AddEdge(NodeB, 2.0f);
	//Node->m_aEdges.push_back(*Node);

	//Node->m_aEdges 

	//myGraph.AddNode(Node);

	system("pause");
};