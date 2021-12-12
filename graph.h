#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

using namespace std;
struct LinkedListNode {
    LinkedListNode* next;
    int station;
    double x;
    double y;
};

struct AdjacencyList {
    int vertex;
    double x;
    double y;
    LinkedListNode* edges = NULL;
};

struct Graph {
    vector<AdjacencyList> adjLists;
    int n;
    map<string, int> station_to_int;
    // Graph(vector<AdjacencyList> ad, int n_) :adjLists(ad), n(n_) {}
};

Graph* createSubway(vector<string> filename);

map<pair<int, int>, string> BFS(Graph* g, int startingIdx);

vector<vector<int> > FloyWarshall(Graph* g);

void printPath(vector<vector<int> >& path, int v, int u);

vector<int> returnPath(vector<vector<int> >& path, int v, int u);