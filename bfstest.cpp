#include <iostream>
#include "graph.h"
//#include "graph.cpp"
#include <vector>
#include <string>
#include <map>
using namespace std;

//test case 1: randomly select two stations from the graph, and test whether the edge between them is DISCOVERY or CROSS
bool bfstest1() {
    cout<<"test cross edge case 1"<<endl;
    vector<string> graph;
    graph.push_back("line1.txt");
    graph.push_back("line2.txt");
    graph.push_back("line4.txt");
    graph.push_back("line5.txt");
    graph.push_back("line6.txt");
    graph.push_back("line7.txt");
    graph.push_back("line8.txt");
    graph.push_back("line9.txt");
    graph.push_back("line10.txt");
    graph.push_back("line13.txt");
    graph.push_back("line14.txt");
    graph.push_back("line15.txt");
    graph.push_back("line16.txt");
    graph.push_back("linebatong.txt");
    graph.push_back("linechangping.txt");
    graph.push_back("linedaxing.txt");
    graph.push_back("linefangshan.txt");
    graph.push_back("linejichang.txt");
    graph.push_back("lineS1.txt");
    graph.push_back("lineyizhuang.txt");
    Graph* g = createSubway(graph);
    map<pair<int, int>, string> bfs = BFS(g, 1);
    pair<int, int> p;
    p.first = 55;
    p.second = 36;
    map<pair<int,int>, string>::iterator it;
    it = bfs.find(p);
    string str = it->second;
    string result = "CROSS";
    return (str == result);
}

//test case 2: randomly select two stations from the graph, and test whether the edge between them is DISCOVERY or CROSS
bool bfstest2() {
    cout<<"test cross edge case 2"<<endl;
    vector<string> graph;
    graph.push_back("line1.txt");
    graph.push_back("line2.txt");
    graph.push_back("line4.txt");
    graph.push_back("line5.txt");
    graph.push_back("line6.txt");
    graph.push_back("line7.txt");
    graph.push_back("line8.txt");
    graph.push_back("line9.txt");
    graph.push_back("line10.txt");
    graph.push_back("line13.txt");
    graph.push_back("line14.txt");
    graph.push_back("line15.txt");
    graph.push_back("line16.txt");
    graph.push_back("linebatong.txt");
    graph.push_back("linechangping.txt");
    graph.push_back("linedaxing.txt");
    graph.push_back("linefangshan.txt");
    graph.push_back("linejichang.txt");
    graph.push_back("lineS1.txt");
    graph.push_back("lineyizhuang.txt");
    Graph* g = createSubway(graph);
    map<pair<int, int>, string> bfs = BFS(g, 1);
    pair<int, int> p;
    p.first = 20;
    p.second = 162;
    map<pair<int,int>, string>::iterator it;
    it = bfs.find(p);
    string str = it->second;
    string result = "CROSS";
    return (str == result);
}

//test case 3: randomly select two stations from the graph, and test whether the edge between them is DISCOVERY or CROSS
bool bfstest3() {
    cout<<"test discovery edge case 1"<<endl;
    vector<string> graph;
    graph.push_back("line1.txt");
    graph.push_back("line2.txt");
    graph.push_back("line4.txt");
    graph.push_back("line5.txt");
    graph.push_back("line6.txt");
    graph.push_back("line7.txt");
    graph.push_back("line8.txt");
    graph.push_back("line9.txt");
    graph.push_back("line10.txt");
    graph.push_back("line13.txt");
    graph.push_back("line14.txt");
    graph.push_back("line15.txt");
    graph.push_back("line16.txt");
    graph.push_back("linebatong.txt");
    graph.push_back("linechangping.txt");
    graph.push_back("linedaxing.txt");
    graph.push_back("linefangshan.txt");
    graph.push_back("linejichang.txt");
    graph.push_back("lineS1.txt");
    graph.push_back("lineyizhuang.txt");
    Graph* g = createSubway(graph);
    map<pair<int, int>, string> bfs = BFS(g, 1);
    pair<int, int> p;
    p.first = 44;
    p.second = 45;
    map<pair<int,int>, string>::iterator it;
    it = bfs.find(p);
    string str = it->second;
    string result = "DISCOVERY";
    return (str == result);
}

//test case 4: randomly select two stations from the graph, and test whether the edge between them is DISCOVERY or CROSS
bool bfstest4() {
    cout<<"test discovery edge case 2"<<endl;
    vector<string> graph;
    graph.push_back("line1.txt");
    graph.push_back("line2.txt");
    graph.push_back("line4.txt");
    graph.push_back("line5.txt");
    graph.push_back("line6.txt");
    graph.push_back("line7.txt");
    graph.push_back("line8.txt");
    graph.push_back("line9.txt");
    graph.push_back("line10.txt");
    graph.push_back("line13.txt");
    graph.push_back("line14.txt");
    graph.push_back("line15.txt");
    graph.push_back("line16.txt");
    graph.push_back("linebatong.txt");
    graph.push_back("linechangping.txt");
    graph.push_back("linedaxing.txt");
    graph.push_back("linefangshan.txt");
    graph.push_back("linejichang.txt");
    graph.push_back("lineS1.txt");
    graph.push_back("lineyizhuang.txt");
    Graph* g = createSubway(graph);
    map<pair<int, int>, string> bfs = BFS(g, 1);
    pair<int, int> p;
    p.first = 225;
    p.second = 226;
    map<pair<int,int>, string>::iterator it;
    it = bfs.find(p);
    string str = it->second;
    string result = "DISCOVERY";
    return (str == result);
}