#include "graph.h"

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