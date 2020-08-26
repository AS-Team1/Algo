#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;
class Graph
{
	int V;
	list<int> *adj;

	public:
		Graph(int V);
		void addEdge(int v , int w);
		void KhansAlgo();
};

Graph::Graph(int V)
{
	this->V =V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v , int w)
{
	adj[v].push_back(w);
}

void Graph::KhansAlgo()
{
	vector<int>_indegree(V , 0);

	for(int u = 0 ; u < V ; u++)
	{
		list<int>::iterator it;
		for(it = adj[u].begin() ; it !=adj[u].end() ; ++it)
			_indegree[*it]++;
	}
	
	queue<int>q;
	for(int i = 0 ; i  <V ; i++)
		if(_indegree[i] == 0)
			q.push(i);

	vector<int> top_order;
	int cnt=0;
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		top_order.push_back(v);

		list<int>::iterator it;
		for(it = adj[v].begin() ; it !=adj[v].end() ; ++it)
		{
			if(--_indegree[*it] == 0)
				q.push(*it);
		}
		cnt++;
	}

	if(cnt != V)
	{
	cout << "There is an Cycle in the Graph" << endl;
	return;
	}

	for(int i = 0 ; i <V ; i++){
		cout << top_order[i] << " ";
	}

}

int main()
{
	Graph g(6);
	g.addEdge(5 , 2);
	g.addEdge(5 , 0);
	g.addEdge(4 , 0);
	g.addEdge(4 , 1);
	g.addEdge(2 , 3);
	g.addEdge(3 , 1);

	g.KhansAlgo();
	return 0;
}
