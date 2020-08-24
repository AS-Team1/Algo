#include<iostream>
#include<stack>
#include<list>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;

	void fillOrder(int v ,bool visited[] ,stack<int> &Stack);

	void DFSUtil(int v , bool visited[]);
	public:
		Graph(int V);
		void addEdge(int v , int w);
		void printSCC();
		Graph getTranspose();
};


void Graph::DFSUtil(int v , bool visited[]){
	visited[v] = true;
	cout << v << " ";

	list<int>::iterator it;
	for(it =adj[v].begin() ;it!=adj[v].end() ; ++it)
		if(!visited[*it])
			DFSUtil(*it ,visited);
}
Graph::Graph(int V)
{
	this->V = V;
	cout <<"v--"<< V << " adj--" <<adj << endl;
	adj = new list<int>[V];
}

void Graph::addEdge(int v , int w)
{
	adj[v].push_back(w);
}
void Graph::fillOrder(int v ,bool visited[] ,stack<int> &Stack)
{
	cout << "Before--v---" << v << " ";
	visited[v] = true;
	list<int>::iterator it;
	for(it = adj[v].begin() ; it != adj[v].end() ; ++it){
		cout << "---------------it--------------" << *it << endl;
		cout << "---------------visited[it]--------------" <<visited[*it] << endl;

		if(!visited[*it]){
	//		cout << "*it---"<< *it << endl;
			fillOrder(*it , visited , Stack);
		}
	}
	cout << "v--" << v << endl;
	Stack.push(v);
}
Graph Graph::getTranspose()
{
	Graph g(V);

	for(int i=0 ; i<V ; i++)
	{
		list<int>::iterator it;
		for(it = adj[i].begin();it !=adj[i].end();++it){
			cout << *it << "---";
			g.adj[*it].push_back(i);
		}
		cout << "i--"<<i<< " ";
		cout << endl;
	}
	return g;
}

void Graph::printSCC()
{
	stack<int> Stack;
	bool *visited = new bool[V];
	for(int i = 0 ; i < V ; i++)	//Mark all Vertices as not visited;
	{
		visited[i]=false;
	}
	for(int i=0;i<V;i++){		//FIll Vertices in stack According to \ 
					//there Finishing Time
		if(visited[i] == false){
			fillOrder(i , visited , Stack);
		}
	}
	cout << endl;
/*	while(!Stack.empty()){

		cout << Stack.top() << " ";
		Stack.pop();
	}
*/
	//create Reverse Graph
Graph gr = getTranspose();

	for(int i = 0 ; i < V ; i++)	//Mark all Vertices as not visited;
		visited[i]=false;

	while(Stack.empty()==false){
		int v = Stack.top();
		cout << "vv=---" << v << endl;
		Stack.pop();

		if(visited[v] == false){
		gr.DFSUtil(v ,visited);
		cout << endl;
		}
	}
}
int main()
{
	Graph g(5);
	g.addEdge(1,0);
	g.addEdge(0,2);
	g.addEdge(2,1);
	g.addEdge(0,3);
	g.addEdge(3,4);
	g.printSCC();

	return 0;
}
