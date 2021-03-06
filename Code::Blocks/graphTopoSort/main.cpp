#include <iostream>
#include "graph.h"

template <class RealNameType, class IndexType>
Node *InitializeNode(RealNameType name, IndexType index)
{
	Node *node = new Node;
	node->RealName = name;
	node->InternalNumber = index;
	return node;
}

Cell *InitializeCell()
{
	Cell *cell = new Cell;
	cell->Indegree = 0;
	cell->TopoNumber = 0;
	return cell;
}
Graph *InitializeGraph()
{
	Graph *graph = new Graph;
	UInt32 numberofVertex = 1;
	int numberOfEdge = 0;
	cin >> numberOfEdge;
	string str1, str2;
	while(numberOfEdge)
	{
		cin >> str1 >> str2;

		if(mapping.find(str1) == mapping.end())
		{
			mapping.insert(pair<string, UInt32>(str1, numberofVertex));

			Node *node = InitializeNode(str1, numberofVertex);
			Cell *cell = InitializeCell();
			cell->CurrentNode = node;
			graph->Cells.push_back(cell);
			graph->Size ++;
			numberofVertex++;
		}
		if(mapping.find(str2) == mapping.end())
		{
			mapping.insert(pair<string, UInt32>(str2, numberofVertex));

			Node *node = InitializeNode(str2, numberofVertex);
			Cell *cell = InitializeCell();
			cell->CurrentNode = node;
			graph->Cells.push_back(cell);
			graph->Size ++;
			numberofVertex++;
		}

		map<string, UInt32>::iterator iter = mapping.find(str2);
		graph->Cells[mapping.find(str1)->second - 1]->Children.push_back(InitializeNode(iter->first, iter->second));
		graph->Cells[mapping.find(str2)->second - 1]->Indegree ++;
		numberOfEdge--;
	}

	return graph;
}

void TopoSort(Graph G)
{
}

int main()
{
	Graph *graph = InitializeGraph();
		for(UInt32 b = 0; b < graph->Cells.size(); b++)
		{
            cout << graph->Cells[b]->CurrentNode->RealName;
            cout << graph->Cells[b]->CurrentNode->InternalNumber << ": ";
            cout << graph->Cells[b]->Indegree;
			for(list<Node*>::iterator iter = graph->Cells[b]->Children.begin();
					iter != graph->Cells[b]->Children.end(); iter++)
			{
				cout << (*iter)->RealName << " ";
				cout << (*iter)->InternalNumber << "->";
			}
			cout << endl;
		}
}
