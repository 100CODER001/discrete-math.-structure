#include<iostream>
#include<cmath>

using namespace std;

int main()
{
		int s,m,n;
	char A[10][2];
	char B[10][2];
	

cout<<"enter number of vertex :";
	cin>>n; 
	cout<<"enter vertex name : ";
	for(int i=0;i<n;i++){
		cin>>B[i][0];
	}
	
	
	
	
	cout<<"enter number of ordered pairs : ";
	cin>>s;
	cout<<"enter ordered pairs of edges of directed graph : ";
	
	for(int i=0;i<s;i++){
	cout<<" (";
		for (int j=0;j<2;j++){
			cin>>A[i][j];
			
		}cout<<")";
	}
	
	
	
	for(int i=0;i<s;i++){
		cout<<endl;
		for (int j=0;j<2;j++){
			
			if (j==0){
			
			cout<<A[i][j]<<" is directed to  ";
	}else{
		cout<<A[i][j];
	}
	}
 }	
	  cout<<endl<<"--------------------------"<<endl;
	  	for(int i=0;i<n;i++){
			m=0;
		for (int j=0;j<s;j++)
	{
          if(B[i][0]==A[j][0]){
		  
               m+=1;
			   }
               
         
	       

	      
}
	  	  cout<<endl<<"OUT DEGREE OF ("<<B[i][0]<<") IS "<<m;}
	  	  
	  	  
	  	  
	  	  

		 cout<<endl<<"--------------------------"<<endl;
		for(int i=0;i<n;i++){
			m=0;
		for (int j=0;j<s;j++)
	{
          if(B[i][0]==A[j][1]
		  ){
		  
               m+=1;
			   }
      }
      
  
	
	  
	  	  cout<<endl<<"IN DEGREE OF ("<<B[i][0]<<") IS "<<m;
}
	
	
	
	
	
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*
	int v, nin, nout, inver, outver;
	cout << "\nEnter the no. of vertices: ";
	cin >> v;
	
	int matrix[v][v];
	for(int i=0; i<v; i++)
		for(int j=0; j<v; j++)
			 matrix[i][j] = 0;
	
	for(int i=0; i<v; i++)
	{
		cout << "Enter the no. of edges incoming to vertex " << i+1 << ": ";
		cin >> nin;
		for(int x=0; x<nin; x++)
		{
			cout << "Enter the vertex from which incoming edge to vertex " << i+1 << " is emerging from: ";
			cin >> inver;
			matrix[i][inver -1] = -1;
		}
		
		cout << "Enter the no. of edges outgoing from vertex " << i+1 << ": ";
		cin >> nout;
		for(int y=0; y<nout; y++)
		{
			cout << "Enter the vertex to which outgoing edge from vertex " << i+1 << " is ending at: ";
			cin >> outver;
			matrix[i][outver -1] = 1;
		}
	}
	
	for(int i=0; i<v; i++)
	{
		int indegree=0, outdegree=0;
		for(int j=0; j<v; j++)
		{
			if(matrix[i][j] == 1)
				outdegree += matrix[i][j];
			
			if(matrix[i][j] == -1)
				indegree += matrix[i][j];
		}
		
		cout << "\n\nIn-degree of vertex " << i+1 << " is " << abs(indegree)
			 << "\tOut-degree of vertex " << i+1 << " is " << outdegree;
	}
	
	return 0;
}*/
