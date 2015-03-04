#include "graph.h"

int main()
{
	/*GraphNode Node0(0);			//	create node
	GraphNode *pNode0 = &Node0;	//	ptr to node

	GraphNode Node1(1);			//	create node
	GraphNode *pNode1 = &Node1;	//	ptr to node

	GraphNode Node2(2);			//	create node
	GraphNode *pNode2 = &Node2;	//	ptr to node

	GraphNode Node3(3);			//	create node
	GraphNode *pNode3 = &Node3;	//	ptr to node

	GraphNode Node4(4);			//	create node
	GraphNode *pNode4 = &Node4;	//	ptr to node

	GraphNode Node5(5);			//	create node
	GraphNode *pNode5 = &Node5;	//	ptr to node

	Graph myGraph;				//	create graph of Nodes
	myGraph.AddNode(pNode0);	//	add node
	myGraph.AddNode(pNode1);	//	add node
	myGraph.AddNode(pNode2);	//	add node
	myGraph.AddNode(pNode3);	//	add node
	myGraph.AddNode(pNode4);	//	add node
	myGraph.AddNode(pNode5);	//	add node

	Node0.AddEdge(pNode1, 1);	//	add edges for Node0
	Node0.AddEdge(pNode5, 1);

	Node1.AddEdge(pNode2, 1);	//	add edges for Node1

	Node2.AddEdge(pNode3, 1);	//	add edge for Node2
	Node2.AddEdge(pNode0, 1);

	Node3.AddEdge(pNode4, 1);	//	add edge for Node3
	Node3.AddEdge(pNode5, 1);

	Node5.AddEdge(pNode4, 1);	//	add edge for Node5

	//-------Display shit-------
	//myGraph.DisplayNodes();
	//Node3.DisplayEdges();

	cout << myGraph.SearchDFS(pNode0, pNode4) << endl;
	myGraph.ResetVisited();
	cout << myGraph.SearchDFSrec(pNode0, pNode4) << endl;
	myGraph.ResetVisited();
	cout << myGraph.SearchBFS(pNode0, pNode4) << endl;*/

	Graph myGraph(4, 4);	//	create graph

	//myGraph.DisplayNodes();	//	display all nodes and their pos 

	//std::vector<GraphNode*>::iterator it = myGraph.m_aNodes.begin();
	//(*it)->DisplayEdges();	//	display first nodes edges

	std::vector<GraphNode*>::iterator beg = myGraph.m_aNodes.begin();
	beg++;
	std::vector<GraphNode*>::iterator end = myGraph.m_aNodes.end();
	end--;
	cout << myGraph.SearchDFSrec((*beg), (*end)) << endl;

	GraphNode display;
	display = myGraph.FindNode(1, 1);
	cout << display.m_iNodeNumber;

	system("pause");
};