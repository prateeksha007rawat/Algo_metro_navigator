
#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

using namespace std;


#define V 27
//arr is true when we get the final shortest path
int count1=1;
int count2=0;

void clrscr()
{
   system("cls");
}
int minDistance(int dist[], bool arr[])
{

int min = INT_MAX, index;

for (int v = 0; v < V; v++)
{
	if (arr[v] == false && dist[v] < min)
    {


		min = dist[v], index = v;
    }
}
return index;
}


int printdistance(int dist[], int n, int destination)
{
    ofstream myfile;
    myfile.open("details.txt", ios::app);
    cout<<"DETAILED TRIP : \n "<<endl;
 cout<<"From "<<n<<" to "<<destination<<" the distance is "<<dist[destination]<<" Kms"<<endl;

 cout<<"The fare of your trip : "<<"Rs. "<< dist[destination]*2<<"/-"<<endl;
 cout<<"The time required to complete the trip : "<<(dist[destination])/2<<" Minutes"<<endl;
myfile<<" New User "<<" Distance : "<<dist[destination]<<" Fare : "<<  dist[destination]*2<<" Time : "<<(dist[destination])/2<<"\n";
myfile.close();
count1++;
}

/*
void printtime(int dist[], int n, int destination)
{
    cout<<"  The time required to complete the trip : "<<(dist[destination])/15<<" hours"<<endl;
}


void printfare(int dist[], int n, int destination)
{
    cout<<"  The fare of your trip : "<<"Rs. "<< dist[destination]*2<<"/-"<<endl;
}
*/
void printpath(int parent[], int j)
{

    // Base Case : If j is source
    if (parent[j] == - 1)
        return;

    printpath(parent, parent[j]);

    cout<<j<<" -> ";
}


void dijkstrashortestpath(int graph[V][V], int src, int dest, int ch )
{
	int dist[V];

	bool arr[V];

	int parent[V];

	for (int i = 0; i < V; i++)
    {


		dist[i] = INT_MAX;
		 arr[i] = false;
		  parent[0]=-1;

    }

	dist[src] = 0;

	for (int count = 0; count < V-1; count++)
	{
	int u = minDistance(dist, arr);

	arr[u] = true;

	for (int v = 0; v < V; v++)
      {



		if (!arr[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
       {

			 parent[v] = u;
			dist[v] = dist[u] + graph[u][v];
	   }

      }
	}

    if(ch==1)
    {
        printdistance(dist, src, dest);
    }
	/*printdistance(dist, src, dest);
	cout<<"  Shortest path : ";
	printpath(parent, dest);
	*/


	/*else if(ch==2)
    {
        cout<<"\t\t\t\t\t\tShortest path : ";
        printpath(parent, dest);
    }*/
}

int main()
{

int s,d,opt;    //----------------------------------------------------------------  //-----------------------------------------------------------------------------
string n;       //  0   1  2  3   4   5   6   7   8   9   10   11   12   13   14   15   16   17   18   19   20   21   22   23   24   25  26
int graph[V][V] = {{0,  5, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {5,  0, 8, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  8, 0, 6,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 6, 0,  10, 0,  0,  0,  0,  7,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 10, 0,  12, 0,  0,  0,  0,  0,   0,   16,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  12, 0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  11, 0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  11, 0,  9,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  9,  0,  16, 0,   0,   0,   0,   21,  0,   0,   0,   0,   0,   6,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 7,  0,  0,  0,  0,  16, 0,  3,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  3,  0,   2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   12,  0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  2,   0,   9,   0,   0,   11,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  16, 0,  0,  0,  0,  0,  0,   9,   0,   14,  0,   22,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   14,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  21, 0,  0,   0,   0,   0,   0,   13,  7,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   11,  22,  0,   13,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   7,   0,   0,   14,  0,   0,   0,   0,   0,   21,  0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   14,  0,   11,  0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   11,  0,   9,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   9,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  6,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   15,  0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   15,  0,   13,  0,   20,  0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  12,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   13,  0,   19,  0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   21,  0,   0,   0,   0,   0,   19,  0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   20,  0,   0,   0,   2,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   2,   0,  8},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   8,  0},
					};

						time_t time_;

	time(&time_);

    startmenu:
       // while(1)
clrscr();


cout<<" SELECT "<<endl;
cout<<"1.BASIC DETAILS"<<endl;
cout<<"2.FULL PATH"<<endl;
cout<<"3.EXIT"<<endl;

cout<<"CHOICE - ";
cin>>opt;
switch(opt)
{
    case 1:
        clrscr();
        goto up1;
        up1:



       cout<<endl<<endl;


cout<<"Enter your starting point : ";
cin>>s; //----------------------------------------------------------------------
cout<<"Enter your destination point : ";
cin>>d;  //----------------------------------------------------------------------
cout<<endl<<endl;



	dijkstrashortestpath(graph, s, d, opt);

	cout<<endl<<endl;

	cout<<"Do you want to continue? : ";
	cin>>n;
	if(n=="YES"||n=="yes"||n=="Yes")
    {
        goto startmenu;
    }
    else
    {
        exit(0);
    }
	break;

	case 2:
	    clrscr();
	    goto up2;

                up2:


       cout<<endl<<endl;
       cout<<"Enter starting point : ";
cin>>s;
cout<<"Enter destination point : ";
cin>>d;
cout<<endl<<endl;

	dijkstrashortestpath(graph, s, d, opt);

	cout<<endl<<endl;

	cout<<"Do you want to continue? : ";
	cin>>n;
	if(n=="YES"||n=="yes"||n=="Yes")
    {
        goto startmenu;
    }
    else
    {
        exit(0);
    }
	break;
	case 3:
        exit(0);

    default :
        cout<<"Invalid input";
        break;


}

	return 0;
}
