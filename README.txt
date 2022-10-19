graphGen.cpp generate a directed graph with each node as a city
and each edge as a flight service from one node to the
other. The output is in the format of:
-------------------------------------------------------------
From:   Moscow, Russia
To  :   Beijing, People's Republic of China
        Montevideo, Uruguay

From:   Hong Kong, SAR
To  :   Miami, United States
        Dhaka, Bangladesh
...
-------------------------------------------------------------  

WA.cpp read from city.name and flight.txt and intialize a
adjacency matrix based graph representaion of the flight
information.  It associates each city with an integer as
its ID and prints out the flight information from each city 
to other cities using the IDs assigned.

Initially we have to generate Graphs: 
 g++ graphGen.cpp


To run graphGen:
  type 
	./a.out 5 (for five cities, where 5 is the number of cities to generate the graph)
To compile WA:
  type g++ WA.cpp
to run type
	./a.out
After that the out put should up as presented in the report.



1) At first adjacency lists were created from the given graphGen file.
2) Route Search 1: For Route Search 1, we implemented Breadth First Search that returns the smallest number of connection between two nodes or cities in this situation and if there is no such route, then it displays no connection between the selected cities.
3) Route Search 2: For Route Search 2, we used Breadth First Search algorithm again since it is more efficient in this case when compared to Depth First Search. 
Initially, the code prompts the user to enter the departure city (city A) and the arrival city (city D) and then it asks the user to enter two layover cities (city B and city C).
We call the function Route Search 1 to find the connection from city A to city B and then city B to city C and then city C to city D.
After finding the connection it displays out the shortest connections from city A to city D.
4) Route Search 3: For Route Search 3, we used Depth First Search algorithm again since it is more efficient in this case when compared to Breadth First Search. 
Initially we made a DFS function which returns the list of connections that can be travelled from the selected city.
In this function, we have also implemented Route Search 1 and DFS function was called to find as less connections as possible to return to the selected city.
5) Route Search 4: For Route Search 4, we used Breadth First Search algorithm again since it is more efficient in this case when compared to Depth First Search. 
Initially before starting this function, we created a function for BFS and implemented that function in the Route Search 4 function to find the common city attached to the other mentioned cities by the user.
And if all the cities mentioned by the user has a common city connected to it, we displayed the connection and if there was no such route, no connections were displayed.

