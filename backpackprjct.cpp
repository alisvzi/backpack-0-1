#include <bits/stdc++.h>
using namespace std;
//--------------------------------------------------
int max(int a,int b) 
{ 
    if(a>b) return a;
    return b; 
}
//--------------------------------------------------
int Kooleh(int KOL,int Vazn[],int Arzesh[],int n)
{
    if((n==0)||(KOL==0)) 
      return 0;
	if(Vazn[n-1]>KOL) 
	  return Kooleh(KOL,Vazn,Arzesh,n - 1);
	else 
	  return max(Arzesh[n-1]+Kooleh(KOL-Vazn[n-1],Vazn,Arzesh,n-1),Kooleh(KOL,Vazn,Arzesh,n-1));
}
//--------------------------------------------------
int Dynamic_Kooleh(int KOL,int Vazn[],int Arzesh[],int n) 
{ 
   int i, g; 
   int K[n+1][KOL+1]; 
   for(i=0;i<=n;i++) 
   { 
       for(g=0;g<=KOL;g++) 
       { 
           if((i==0)||(g==0)) 
             K[i][g]=0; 
           else if(Vazn[i-1]<=g) 
             K[i][g]=max(Arzesh[i-1]+K[i-1][g-Vazn[i-1]],K[i-1][g]); 
           else
             K[i][g]=K[i-1][g]; 
       } 
   } 
  
   return K[n][KOL]; 
} 
//--------------------------------------------------
int main()
{
    
	int Arzesh[100],Vazn[100];
	int KOL,n,i,x;
	double time_taken;
	clock_t start,end;
	 

	cout<<"Tedad Kala ? : ";
	cin>>n;
    cout<<"Zarfiat Kooleh ? : ";
	cin>>KOL;
	for(i=0;i<n;i++)
	{
	    cout<<"Arzesh["<<i+1<<"] ? : ";
	    cin>>Arzesh[i];
	    cout<<"Vazn["<<i+1<<"] ? : ";
	    cin>>Vazn[i];
	}
	start = clock(); 
	  x=Kooleh(KOL,Vazn,Arzesh,n);
    end = clock(); 
    cout<<"\n-----------------------------\n";
	cout<<"Ravesh-e Agabgard : \n";
	cout<<"Arzesh Kol = "<<x;
	time_taken=1000*double(end-start)/double(CLOCKS_PER_SEC); 
	cout<<"\nZaman Ejra = "<<fixed<<time_taken<<setprecision(8); 
	cout<<" milli sec ";
	
	start = clock(); 
	  x=Dynamic_Kooleh(KOL,Vazn,Arzesh,n);
    end = clock(); 
    cout<<"\n-----------------------------\n";
	cout<<"Ravesh-e Pooya : \n";
	cout<<"Arzesh Kol = "<<x;
	time_taken=1000*double(end-start)/double(CLOCKS_PER_SEC); 
	cout<<"\nZaman Ejra = "<<fixed<<time_taken<<setprecision(8); 
	cout<<" milli sec ";
	return 0;
}

