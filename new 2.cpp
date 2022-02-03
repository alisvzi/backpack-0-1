#include <iostream>
#define INF 99999
#define V 100
using namespace std;
// dar payin tabeei baray mhsbey msir ha dar nazar migirim
void Msir(int dist[V][V],int n)
{
    int i;
	cout<<"Matris kootah tarin masir :\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		  if(dist[i][j]==INF)
		   cout<<"INF"<<"   ";
		  else
			cout<<dist[i][j]<<"  ";
		cout<<"\n";
	}
}
//gesmt algoritm floyd marshal 
void floyd(int grph[V][V],int n)
{
	int dist[V][V],i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			dist[i][j]=grph[i][j];

	for(k=0;k<n;k++)
	  for(i=0;i<n;i++)
	    for(j=0;j<n;j++)
		  if( (dist[i][k]+dist[k][j]) < dist[i][j] )
      	   dist[i][j]=dist[i][k]+dist[k][j];

	Msir(dist,n);
}

int main()
{
   
    int grph[V][V];
    int i,j,n;
    cout<<"Tedad Gere ha ra vard konid ::::::\t";
    cin>>n;
    
    cout<<"Fasele ha ra vared konid :::::::\n";
    for(i=0;i<n;i++)
    { 
        for(j=0;j<n;j++)
        {
            cout<<"Faseleh Grf["<<i+1<<"] to Grf["<<j+1<<"] : ";
            cin>>grph[i][j];
            if(grph[i][j]==-1) grph[i][j]=INF;
        }
    }
	floyd(grph,n);
	return 0;
}
