#pragma once
#include <iostream>
#include <vector>
#include <ctime> 
#include <cstdlib>
#include <string>
#include <fstream>
#include <map>
#include <list>
#include<algorithm>
#include<bits/stdc++.h>
// #include "WA.cpp"
#include <queue>

using namespace std;
class Graph{
     public:
          Graph(int d);
          ~Graph(){};


          void print();
          void addEdge(int node1, int node2);
          tuple <vector<int>, int> RouterSearch1(int x, int city_a, int city_b);
          tuple <vector<int>, int> RouterSearch2(int n);
          void Routersearch3(int source);
          void BFS(int begin, int x);
          void RouterSearch4(int v);
          void printTest(); 
 
     private: 
          int v;
          list <int> *my_list;
          vector<int> array;
         void DFS(int source, map<int, bool> &discovered);
         map<int, list<int>>a; 
};
