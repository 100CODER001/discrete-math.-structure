//Write a Program to check if a given graph is a complete graph. Represent the graph using the Adjacency List representation.

#include <iostream>
#include <iomanip>
using namespace std;

class Graph{
	int n;
	int **mat;
	
	public:
	Graph(){
		n=0;
	}
	
	void input(){
			do{
				cout<<"Enter number of vertices in undirected graph : ";
				cin>>n;
				if(n<1){
					cout<<"Error : number of vertices can't be less than 1.\n\n";
				}
			}while(n<1);
			
			mat = new int*[n];
			for(int i=0; i<n; i++){
				int m;
				do{
					cout<<"Enter number of adjacent vertices of vertex "<<i<<" : ";
					cin>>m;
					if(m<0||m>n)
					cout<<"Error : number of adjacent vertices of vertex can't be less than 0 or greater than total number of vertices.\n";
				}while(m<0||m>n);
				mat[i]=new int[m+1];
				mat[i][0]=m;
				if(m>0){
					cout<<"Enter adjacent vertices of vertex "<<i<<" : ";
					for(int j=1; j<=m; j++ ){
						cin>>mat[i][j];
					}	
				}
			}
			
			cout<<endl;
			return;
		}
		
		void display(){
			cout<<"Adjacency list of undirected graph.\n\n";
			cout<<"Vertex\tadjacent vertices\n";
			for(int i=0; i<n; i++){
				cout<<"   "<<i<<"  \t  ";
				for(int j=1; j<=mat[i][0]; j++){
					cout<<mat[i][j]<<"  ";
				}
				cout<<endl;
			}
			cout<<endl;
			return;
		}
		
		bool ismember(int row, int v){
			for(int i=1; i<=mat[row][0]; i++){
				if(mat[row][i]==v)
				return 1;
			}
			return 0;
		}
		
		bool isComp(){
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					if((j==i&&ismember(i,j))||(j!=i&&!ismember(i,j)))
					return 0;	
				}
			}
			return 1;
		}
		
		~Graph(){
			for(int i=0; i<n; i++)
				delete mat[i];
			delete mat;
		}
};

int main(){
	Graph g;
	g.input();
	g.display();
	if(g.isComp()){
		cout<<"It is a complete graph.";
	}else{
		cout<<"It is not a complete graph.";
	}
	return 0;
}
