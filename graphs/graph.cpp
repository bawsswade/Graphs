#include "graph.h"

GraphNode::GraphNode(int a_iNum)
{
	this->m_iNodeNumber = a_iNum;
}

void Graph::AddNode(GraphNode* a_pNode)
{
	m_aNodes.push_back(a_pNode);
}

void Graph::RemoveNode(GraphNode* a_pNode)
{
	auto it = m_aNodes.begin();
	//GraphNode* ptr = m_aNodes.begin();
	for (it; it != m_aNodes.end(); it++)
	{
		//it->m_aEdges; // is it not a pointer/iterator in NodeList?
	}

	/*auto its = std::find(m_aNodes.begin(), m_aNodes.end(), a_pNode);

	if (its != m_aNodes.end())
		m_aNodes.erase(it);*/
}

void GraphNode::AddEdge(GraphNode *endNode, float cost)
{
	Edge temp;
	temp.m_pEnd = endNode;
	temp.m_pStart = this;
	temp.m_fCost = cost;
	this->m_aEdges.push_back(temp);
}

void Graph:: DisplayAllNodes()
{
	std::vector<GraphNode*>::iterator it;
	for (it = this->m_aNodes.begin(); it != this->m_aNodes.end(); ++it) {
		cout << "Node " << (*it)->m_iNodeNumber << endl;
	}
}