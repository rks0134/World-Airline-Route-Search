/***********************************************************
  Group#  : 13
  Member  : Prem Adhikari, Rohit Kumar Shaw.
  Synopsis: Implementation of the Route Searches.
***********************************************************/


#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include <map>
#include <list>
#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <tuple>
#include "routesearch.h"

using namespace std;
const int INT = 140;//max const
int counter =0; 
int a_array[INT];
int b_array[INT];
int c_array[INT];
// graph constructor
Graph::Graph(int v)
{
    this->v = v;
    my_list = new list<int>[v];
};

// adding edge
void Graph::addEdge(int node1, int node2)
{
    list<int>::iterator findIter = find(my_list[node1].begin(), my_list[node1].end(), node2);
    if (findIter == my_list[node1].end())
    {
        my_list[node1].push_back(node2);
    }

    list<int>::iterator findIter2 = find(my_list[node2].begin(), my_list[node2].end(), node1);
    if (findIter2 == my_list[node2].end())
    {
        my_list[node2].push_back(node1);
    }
};
void Graph::printTest() {
    for(int i = 0; i<v; i++) {
        cout<<array[i]<<" ";
    }
}

// printing the adjacency list of the graph
void Graph::print()
{
    for (int i = 0; i < v; i++)
    {
        cout << "City " << i << "->";
        for (int nbr : my_list[i])
        {
            cout << nbr << ", ";
        }
        cout << endl;
    }
};




map<const string, int> city;

tuple<vector<int>, int> Graph::RouterSearch1(int x, int city_a, int city_b)
{

    bool find = false;
    list<int> flights;
    bool visit[x];
    int start[x], dist[x];
    for (int i = 0; i < x; i++)
    {
        visit[i] = false;
        dist[i] = INT_MAX;
        start[i] = -1;
    }

    visit[city_a] = true;
    dist[city_a] = 0;
    flights.push_back(city_a);
    while (!flights.empty())
    {
        int node = flights.front();
        flights.pop_front();
        for (int nbr : my_list[node])
        {
            if (visit[nbr] == false)
            {
                visit[nbr] = true;
                dist[nbr] = dist[node] + 1;
                start[nbr] = node;
                flights.push_back(nbr);

                if (nbr == city_b)
                {
                    find = true;
                    break;
                }
            }
        }
    }

    if (find == false)
    {
        cout << "No such routes can be detected. ";
    }

    vector<int> my_path;
    int path = city_b;
    my_path.push_back(path);
    while (start[path] != -1)
    {
        my_path.push_back(start[path]);
        path = start[path];
    }

    cout << "Total connections: " << dist[city_b] << endl;

    cout << "Route: ";
    for (int i = my_path.size() - 1; i >= 0; i--)
    {
        cout << my_path[i] << " ";
    }
    cout << endl;
    return make_tuple(my_path, dist[city_b]);
}

// void Graph::RouterSearch2(int n)
// {
//     Graph graph(n);
// }
void Graph::DFS(int source, map<int, bool> &discovered)
{
        cout<<source<<" ";
        array.push_back(source);
        // for(int i = 0; i<v; i++) {
        //     array[i] = source;
        //     cout<<array[i]<<" ";
        // }
        discovered[source]=true;
        for(auto nbr: my_list[source])
        {
                if(!discovered[nbr])
                {
                    DFS(nbr, discovered);
                }
        }
}
void Graph::Routersearch3(int source)
{

    map<int,bool> discovered;
     for(auto p: a)
     {
        int node = p.first;
        discovered[node]=false;
     }
        //

        DFS(source, discovered);
        RouterSearch1(v,array[v-1],array[0]);
}

void Graph::BFS(int begin, int x){
    ++counter;
    list<int>flights;
    bool visit[x];
    int start[x], dist[x], end, k=0;
    for (int i = 0; i < x; i++){
        visit[i] = false;
        dist[i] = INT_MAX;
        start[i] = -1;
    }
    
    visit[begin] = true;
    dist[begin] = 0;
    flights.push_back(begin);
    while(!flights.empty()){
        int node = flights.front();
        flights.pop_front();
        //list[k] = node + 1;
        //k++;
        for (int nbr:my_list[node]){
            if (visit[nbr] == false){
                visit[nbr] = true;
                dist[nbr] = dist[node] + 1;
                start[nbr] = node;
                flights.push_back(nbr);
                 end = nbr;
            }
        }
    }

    vector<int> my_path;
    int path = end;
    my_path.push_back(path);
    while (start[path] != -1) {
        my_path.push_back(start[path]);
        path = start[path];
    }
    if(counter == 1){
       for(int i=0; i<my_path.size(); i++){
           a_array[i]= my_path[i]+1;
		   
       }  
    }
    else if (counter ==2){
        for(int i=0; i<my_path.size(); i++){
           b_array[i]= my_path[i]+1;
       }
    }
    else if(counter==3){
        for(int i=0; i<my_path.size(); i++){
           c_array[i]= my_path[i]+1;
       }
    }
    
    cout << "Total connections to last node: "<< dist[end]<< endl;
 
    cout << "Route: ";
    for (int i = my_path.size() - 1; i >= 0; i--){
        cout << my_path[i] << " ";
    }
    cout << endl;
};
void Graph::RouterSearch4(int v) {
	Graph graph(v);
    int a, b,c, k;
    cout<< "First friend is at: ";
    cin>> a;
    cout<< "Second friend is at: ";
    cin>> b;
    cout<< "Third friend is at: ";
    cin>>c;
	cout << endl;
    BFS(a, v);
    BFS(b,v);
    BFS(c,v);
    bool same = false, same2 =false;
   for(int i=1;i<140;i++ ){
        for(int j=1;j<140;j++){
            if ( b_array[j] == a_array[i]){
                same==true;
            }
        }
        for(int k=1;k<140;k++){
            if(c_array[k]==a_array[i]){
                same2==true;
            }
        }
        if(same==true && same2==true){
            cout<<endl<<"Meet at:"<< a_array[i]<<endl;
            auto cat = graph.RouterSearch1(a,a_array[i],v);
			//int cat1 = distance_4;
            auto dog= graph.RouterSearch1(b,a_array[i],v);
			//int dog1 = distance_4;
            auto fish= graph.RouterSearch1(c,a_array[i],v);
			//int fish1 = distance_4;
            break;
        }
    }
	if(same==false && same2==false){
		cout << "No such route. " << endl;
	}
};

int main(int argc, char *argv[])
{
    int i, j, node1, node2, n;
    string line;

    cout << "Please enter the number of cities in your graph: " << endl;
    cout << "---------------------------------------------------" << endl;
    cin >> n;
    // n = 140;
    Graph graph(n);

    char lineChar[256];

    ifstream cityFile;
    cityFile.open("city.name", ios::in);
    string array[n];
    for (i = 0; i < n; i++)
    {

        std::getline(cityFile, line);
        line.erase(std::prev(line.end()));

        city[line] = i;
        array[i] = line;

        cout << "City: " << line;
        cout << " - " << i << endl;
    }

    cityFile.close();

    ifstream flightFile;
    flightFile.open("flight2.txt", ios::in);

    while (flightFile.getline(lineChar, 256))
    {
        /* if line constains From: */
        line = lineChar;

        if (line.find("From:", 0) == 0)
        {
            line.erase(0, 7);
            for (int i = 0; i < n; i++)
            {
                if (array[i].length() + 1 == line.length() && array[i][0] == line[0] && array[i][3] == line[3])
                {
                    node1 = city[array[i]];
                }
            }
        }
        else
        {
            line.erase(0, 7);
            for (int i = 0; i < n; i++)
            {
                if (array[i].length() + 1 == line.length() && array[i][0] == line[0] && array[i][3] == line[3])
                {
                    node2 = city[array[i]];
                }
            }
            graph.addEdge(node1, node2);
        }
    }
    flightFile.close();

    /* printing  the graph */
    cout << endl
         << "The graph generated can be represented by the following adjacent list: " << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
    graph.print();

    // graph.RouterSearch3(n);

    int choice;
    bool repeat = true;
    while(repeat=true)
    {
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "|	        World Airlines Route Search                   |" << endl;
        cout << "|1)Route Search From City A and City B.                       |" << endl;
        cout << "|2)Route Search From City A and City D through City B and C   |" << endl;
        cout << "|3)Route Search back to A after visiting all three cities.    |" << endl;
        cout << "|4)Connection among three cities.                             |" << endl;
        cout << "|5)Exit                                                       |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;

        cout << "----> "; // getting the choice from user
        cin >> choice;

        if (choice == 1)
        {
            int city_a, city_b;
            cout << "Enter the departing city: ";
            cin >> city_a;
            cout << "Enter the arrival city: ";
            cin >> city_b;
            cout << endl;
            graph.RouterSearch1(n, city_a, city_b);
            repeat = true;
            
        }
        else if (choice == 2)
        {

            int a, b, c, d;
            cout << "Enter the departing city: ";
            cin >> a;
            cout << "Enter the arrival city: ";
            cin >> d;
            cout << endl;
            cout << "Enter the first transit city: ";
            cin >> b;
            cout << "Enter the second transit city: ";
            cin >> c;
            cout << endl;

            vector<int> final_path = {};

            // graph.RouterSearch1(n,a,b);
            auto r1 = graph.RouterSearch1(n, a, b);
            auto connection_1 = get<1>(r1);
            auto rvec1 = get<0>(r1);

            auto r2 = graph.RouterSearch1(n, a, c);
            auto connection_2 = get<1>(r2);
            auto rvec2 = get<0>(r2);

            if (connection_1 <= connection_2)
            {
                // this indicates b is shortest route compared to c.

                // so now the route is a b

                // need to find route from b to c

                // use r1
                auto r3 = graph.RouterSearch1(n, b, c);
                auto connection_3 = get<1>(r3);
                auto rvec3 = get<0>(r3);
                // finally need to find route from c to d
                auto r4 = graph.RouterSearch1(n, c, d);
                auto connection_4 = get<1>(r4);
                auto rvec4 = get<0>(r4);

                // now add appropriate route to final_vector

                for (int i = rvec1.size() - 1; i >= 0; i--)
                {
                    final_path.push_back(rvec1[i]);
                }

                // ignore first
                for (int i = rvec3.size() - 2; i >= 1; i--)
                {
                    final_path.push_back(rvec3[i]);
                }

                // ignore first as it was already added in previous step
                for (int i = rvec4.size() - 1; i >= 0; i--)
                {
                    final_path.push_back(rvec4[i]);
                }
            }
            else
            {
                // this indicates c is better route than a.

                // use r2
                auto r3 = graph.RouterSearch1(n, c, b);
                auto connection_3 = get<1>(r3);
                auto rvec3 = get<0>(r3);
                auto r4 = graph.RouterSearch1(n, b, d);
                auto connection_4 = get<1>(r4);
                auto rvec4 = get<0>(r4);

                for (int i = rvec2.size() - 1; i >= 0; i--)
                {
                    final_path.push_back(rvec2[i]);
                }

                // ignore first
                for (int i = rvec3.size() - 2; i >= 1; i--)
                {
                    final_path.push_back(rvec3[i]);
                }

                // ignore first as it was already added in previous step
                for (int i = rvec4.size() - 1; i >= 0; i--)
                {
                    final_path.push_back(rvec4[i]);
                }
            }

            cout << endl
                 << "Path: ";
            for (auto x : final_path)
            {
                cout << x << "  ";
            }

            cout << endl;
            cout << "Total number of connection: " << final_path.size() - 1 << endl;
            repeat = true;
        
        }
        else if (choice == 3)
        {
            cout<<"travel destination: ";
            int p;
            cin>>p;
            graph.Routersearch3(p);
            repeat = true;
          
        }
        else if (choice == 4)
        {
            graph.RouterSearch4(n);
            repeat = true;
          
        }
        else if (choice == 5)
        {
            cout << "Thank you for using the World Airline Search Route." << endl;
            repeat = false; // false becasue user exits the menu
            break;
        }
        else
        {
            cout << "Invalid selection (" << choice << "). Enter option 1 - 4." << endl; // if user presses a inncorect number from the menu option.
            repeat = true;
            
        }

    } 

    return 0;
}