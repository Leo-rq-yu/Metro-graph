#include <vector>
#include <iterator>
#include <errno.h>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <fstream>
#include <queue>
#include <map>
#include <cmath>
#include "graph.h"
using namespace std;

Graph* createSubway(vector<string> filename) {
    Graph* g = new Graph();
    g->n = 300;
    g->adjLists.resize(301);
    for (int j = 0; j < 301; j++) {
        g->adjLists[j].vertex = -1;
    }
    for (unsigned int l = 0; l < filename.size(); l++) {
        string line;
        string file = filename[l];
        ifstream infile (file.c_str());
        vector<vector<string> > all;
        if (infile.is_open()) {
            while (getline(infile, line)) {
                // do things
                vector<string> separate;
                string word = "";
                for (unsigned int i = 0; i < line.length(); i++) {
                    char x = line[i];
                    if (x == ' ') {
                        // cout<<word<<endl;
                        separate.push_back(word);
                        word = "";
                    } else {
                        word = word + x;
                    }
                }
                all.push_back(separate);
            }
            for (int i = 0; i < int(all.size()); i++) {
                // g->station_to_int[all[i][2]] = stoi(all[i][0]);
                // LinkedListNode* node1 = new LinkedListNode();
                // node1->next = g->adjLists[stoi(all[i][0])].edges;
                // node1->station = stoi(all[i][0]);
                // node1->x = stod(all[i][3]);
                // node1->y = stod(all[i][4]);
                // g->adjLists[stoi(all[i][0])].edges = node1;

                if (g->adjLists[stoi(all[i][0])].vertex == -1) {
                    g->adjLists[stoi(all[i][0])].vertex = stoi(all[i][0]);
                    g->adjLists[stoi(all[i][0])].x = stod(all[i][3]);
                    g->adjLists[stoi(all[i][0])].y = stod(all[i][4]);
                }
                if (i - 1 >= 0) {
                    LinkedListNode* node2 = new LinkedListNode();
                    node2->next = g->adjLists[stoi(all[i][0])].edges;
                    node2->station = stoi(all[i - 1][0]);
                    node2->x = stod(all[i - 1][3]);
                    node2->y = stod(all[i - 1][4]);
                    g->adjLists[stoi(all[i][0])].edges = node2;
                }
                if (i + 1 < int(all.size())) {
                    LinkedListNode* node3 = new LinkedListNode();
                    node3->next = g->adjLists[stoi(all[i][0])].edges;
                    node3->station = stoi(all[i + 1][0]);
                    node3->x = stod(all[i + 1][3]);
                    node3->y = stod(all[i + 1][4]);
                    g->adjLists[stoi(all[i][0])].edges = node3;
                }
            }
        }
    }
    return g;
}

//return a map that reflects label in each edge
//edge is represented by a pair of int and int
map<pair<int, int>, string> BFS(Graph* g, int startingIdx) {
    //index of nodes that should be searched
    queue<int> workingList;
    //if the entry is false, the corresponding node is not visited
    vector<bool> visitedList(g->adjLists.size(), false);
    //initialize the map
    map<pair<int, int>, string> labels;
    //start bfs by pushing the first node into queue
    workingList.push(startingIdx);
    while (workingList.empty() == false) {
        
        //get the front node in the queue
        int curr_idx = workingList.front();
        workingList.pop();
        //check all neighbors
        LinkedListNode* neighbor = g->adjLists[curr_idx].edges;
        //std::cout << "aa" << curr_idx << std::endl;
        while (neighbor != NULL) {
            
            //initialize the edge between current node and one of the neighbor
            pair<int, int> e;
            e.first = curr_idx;
            e.second = neighbor->station;
            //edges are undirectional so initialize edges in both directions
            pair<int, int> rev_e;
            rev_e.first = e.second;
            rev_e.second = e.first;
            //if the edge is not unlabeled (not in the map), label the edge
            //if the edge is already labeled, do nothing
            if (labels.count(e) == 0 && labels.count(rev_e) == 0) {
                //if already visited that node, mark it as cross edge
                //if not visited, mark it as discovery edge, mark that neighbor as visited, and add it to queue
                //std::cout << neighbor->station << std::endl;
                if (visitedList[neighbor->station] == true) {
                    labels[e] = "CROSS";
                    labels[rev_e] = "CROSS";
                } else {
                    labels[e] = "DISCOVERY";
                    labels[rev_e] = "DISCOVERY";
                    visitedList[neighbor->station] = true;
                    workingList.push(neighbor->station);
                }
            }
            //go to the next neighbor
            neighbor = neighbor->next;
        }
    }
    return labels;
}

 vector<vector<int> > FloyWarshall(Graph* g) {
    vector<vector<double> > d(301, vector<double>(301));
    // vector<float> s;
    // s.resize(301);
    // for (int i = 0; i < 301; i++) {
    //     d.push_back(s);
    // }
    for (int i = 0; i < 301; i++) {
        for (int j = 0; j < 301; j++) {
            d[i][j] = 1e32;
        }
    }
    for (int i = 0; i < 301; i++) {
        d[i][i] = 0;
    }
    for (int i = 1; i < 301; i++) {
        double x1 = g->adjLists[i].x;
        double y1 = g->adjLists[i].y;
        LinkedListNode* edge = g->adjLists[i].edges;
        while (edge != NULL) {
            int loc = edge->station;
            double x2 = edge->x;
            double y2 = edge->y;
            double length = 6371.01 * acos(sin(y1)*sin(y2) + cos(y1)*cos(y2)*cos(x1 - x2));
            d[i][loc] = length;
            edge = edge->next;
        }
    }

    vector<vector<int> > p(301, vector<int>(301));
    for (int i = 0; i < 301; i++) {
        for (int j = 0; j < 301; j++) {
            p[i][j] = -1;
        }
    }
    for (int i = 0; i < 301; i++) {
        p[i][i] = i;
    }
    for (int i = 1; i < 301; i++) {
        LinkedListNode* edge = g->adjLists[i].edges;
        while (edge != NULL) {
            int loc = edge->station;
            p[i][loc] = i;
            edge = edge->next;
        }
    }
    for (int k = 1; k < 301; k++) {
        for (int u = 1; u < 301; u++) {
            for (int v = 1; v < 301; v++) {
                if (d[v][k] != 1e32 && d[k][u] != 1e32 && d[u][v] > d[u][k] + d[k][v]) {
                    d[u][v] = d[u][k] + d[k][v];
                    p[u][v] = p[k][v];
                }
            }
        }
    }
    return p;
}

// Recursive function to print path of given vertex `u` from source vertex `v`
void printPath(vector<vector<int> >& path, int v, int u)
{   
    if (path[v][u] == -1) {
        cout<<"Not Connected"<<endl;
        return;
    }
	if (path[v][u] == v) {
		return;
	}
	printPath(path, v, path[v][u]);
    // printPath(path, path[v][u], u);
	cout << path[v][u] << ", "<<endl;
}

// Recursive function to store the shortest path of given vertex `u` from source vertex `v` into a vector.
vector<int> returnPath(vector<vector<int> >& path, int v, int u)
{   
    vector<int> list;
    if (path[v][u] == -1) {
        cout<<"Not Connected"<<endl;
        return list;
    }
	if (path[v][u] == v) {
		return list;
	}
	list = returnPath(path, v, path[v][u]);
    list.push_back(path[v][u]);
	return list;
}