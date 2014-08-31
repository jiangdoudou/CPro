#ifndef _graph_h
#define _graph_h

#include <vector>
#include <string>
#include <list>
#include <map>

using namespace std;

typedef int Index;
typedef unsigned UInt32;
typedef int Weight;
struct Node
{
	Index InternalNumber;
	string RealName;
	Weight weight;
};

struct Cell
{
	Node *CurrentNode;
	list<Node*> Children;
	UInt32 Indegree;
	UInt32 TopoNumber;
};

struct Graph
{
	vector<Cell*> Cells;
	UInt32 Size;
};

struct Table
{
	bool Known;
	int Distance;
	Node *CurrentNode;
	Node *ParentNode;
	bool operator > (Table &tableEntry)
	{
		if(Distance > tableEntry.Distance)
			return true;
		else
			return false;
	}

	bool operator < (Table &tableEntry)
	{
		if(Distance < tableEntry.Distance)
			return true;
		else
			return false;
	}

	bool operator <= (Table &tableEntry)
	{
		if(Distance <= tableEntry.Distance)
			return true;
		else
			return false;
	}
	bool operator >= (Table &tableEntry)
	{
		if(Distance >= tableEntry.Distance)
			return true;
		else
			return false;
	}
};


#define VertexNumber 8
#define NotAVertex (-1)
#define Infinity 0x8FFFFFFF

typedef struct Table TableInstance[VertexNumber];

Node *InitializeNode(string name, Index index, Weight weight);

Cell *InitializeCell();
Graph *InitializeGraph();
Cell *GetCellWithZeroIndegree(Graph *g);
void TopoSortV1(Graph *G);
void TopoSortV2(Graph *g);

void InitTable(Table table[], int tableSize);
void ShortPathUnweighted(Table table[], Graph *graph, Node *startNode);
void ShortPathUnweightedV2(Table table[], Graph *graph, Node *startNode);
#endif
