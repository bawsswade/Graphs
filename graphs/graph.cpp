#include "graph.h"

GraphNode::GraphNode(int a_iNum)
{
	this->m_iNodeNumber = a_iNum;
}

void GraphNode::DisplayEdges()
{
	std::vector<Edge>::iterator it;
	cout << "Node " << this->m_iNodeNumber << " connects to: ";
	for (it = this->m_aEdges.begin(); it != this->m_aEdges.end(); ++it) {
		cout << it->m_pEnd->m_iNodeNumber << ", "; /*<< ". cost = " << it->m_fCost << endl;*/
	}
	cout << endl;
}

void Graph::AddNode(GraphNode* a_pNode)
{
	m_aNodes.push_back(a_pNode);
}

void Graph::RemoveNode(GraphNode* a_pNode)
{
	std::vector<GraphNode*>::iterator pNode = this->m_aNodes.begin();
	for (pNode; pNode != m_aNodes.end(); pNode++)
	{
		(*pNode)->RemoveEdges(a_pNode);
	}
}

void GraphNode::RemoveEdges(GraphNode *n)
{
	std::vector<Edge>::iterator it = this->m_aEdges.begin();
	while (it != this->m_aEdges.end())
	{
		if (it->m_pEnd == n)
		{
			//	erase returns random iterator to next element (have to assign it to it)
			it = m_aEdges.erase(it);
		}
		else
		{
			if (it != this->m_aEdges.end())
				it++;
		}
	}
}

void GraphNode::AddEdge(GraphNode *endNode, float cost)
{
	Edge temp;
	temp.m_pEnd = endNode;
	temp.m_pStart = this;
	temp.m_fCost = cost;
	this->m_aEdges.push_back(temp);
}

void Graph::DisplayNodes()
{
	std::vector<GraphNode*>::iterator it;
	for (it = this->m_aNodes.begin(); it != this->m_aNodes.end(); ++it) {
		cout << "Node " << (*it)->m_iNodeNumber << endl;
	}
}

void Graph::ResetVisited()
{
	std::vector<GraphNode*>::iterator it;
	for (it = this->m_aNodes.begin(); it != this->m_aNodes.end(); ++it) {
		(*it)->m_bVisited = false;
	}
}

bool Graph::SearchDFS(GraphNode* a_pStart, GraphNode* a_pEnd)
{
	std::stack<GraphNode*> oNodeStack;
	oNodeStack.push(a_pStart);

	while (!oNodeStack.empty())
	{
		GraphNode* pCurrent = oNodeStack.top();
		oNodeStack.pop();

		//	error checking if visisted
		if (pCurrent->m_bVisited == true)
		{
			continue;
		}

		//	set visited 
		pCurrent->m_bVisited = true;

		//	exit when found end
		if (pCurrent == a_pEnd)
		{
			return true;
		}

		// add all the neighbours of the current node onto the stack
		for ( int i = 0 ; i < pCurrent->m_aEdges.size() ; ++i )
		{
			if (pCurrent->m_aEdges[i].m_pEnd->m_bVisited != true)
			{
				oNodeStack.push(pCurrent->m_aEdges[i].m_pEnd);
			}
		}
	}

	//return false if we didn't find a_pEnd
	return false;
}

bool Graph::SearchDFSrec(GraphNode* a_pStart, GraphNode* a_pEnd)
{
	if (a_pStart->m_iNodeNumber != a_pEnd->m_iNodeNumber)
	{
		for (int i = 0; i < a_pStart->m_aEdges.size(); i++)
		{
			if (SearchDFSrec(a_pStart->m_aEdges[i].m_pEnd, a_pEnd))
				return true;
		}
	}
	else
		return true;
	return false;
}

bool Graph::SearchBFS(GraphNode* a_pStart, GraphNode* a_pEnd)
{
	std::queue<GraphNode*> oNodeQueue;
	oNodeQueue.push(a_pStart);

	while (!oNodeQueue.empty())
	{
		GraphNode* pCurrent = oNodeQueue.front();
		oNodeQueue.pop();

		//	error checking if visisted
		if (pCurrent->m_bVisited == true)
		{
			continue;
		}

		//	set visited 
		pCurrent->m_bVisited = true;

		//	exit when found end
		if (pCurrent == a_pEnd)
		{
			return true;
	}	

		// add all the neighbours of the current node onto the queue
		for (int i = 0; i < pCurrent->m_aEdges.size(); ++i)
		{
			if (pCurrent->m_aEdges[i].m_pEnd->m_bVisited != true)
			{
				oNodeQueue.push(pCurrent->m_aEdges[i].m_pEnd);
			}
			/*if (pCurrent->m_aEdges[i].m_pEnd == a_pEnd)
				return true;*/
		}
	}

	//return false if we didn't find a_pEnd
	return false;
}
