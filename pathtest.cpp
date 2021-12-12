#include <iostream>
#include "graph.h"
//#include "graph.cpp"
#include <vector>
#include <string>
#include <map>
using namespace std;

// test case 1: randomly select start and end stations within an arbitrary line. 
// If the FloyWarshall algorithm runs correct, the output route should be the same with the actual result. 
bool pathtest1() {
    cout<<"test within single line"<<endl;
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
    vector<vector<int> > p = FloyWarshall(g);
    vector<int> path = returnPath(p, 7, 18);
    vector<int> list;
    list.push_back(8);
    list.push_back(9);
    list.push_back(10);
    list.push_back(11);
    list.push_back(12);
    list.push_back(13);
    list.push_back(14);
    list.push_back(15);
    list.push_back(16);
    list.push_back(17);
    return (path == list);
}

// test case 2: randomly select start and end stations from two different lines. 
// If the FloyWarshall algorithm runs correct, the output route should be the same with the actual result. 
bool pathtest2() {
    cout<<"test between two lines"<<endl;
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
    LinkedListNode* cur =  g->adjLists[157].edges;
    map<pair<int, int>, string> bfs = BFS(g, 1);
    vector<vector<int> > p = FloyWarshall(g);
    vector<int> path = returnPath(p, 5, 157);
    vector<int> list;
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);
    list.push_back(9);
    list.push_back(10);
    list.push_back(11);
    list.push_back(12);
    list.push_back(13);
    list.push_back(14);
    list.push_back(15);
    list.push_back(16);
    list.push_back(17);
    list.push_back(18);
    list.push_back(31);
    list.push_back(30);
    list.push_back(29);
    return (path == list);
}

// test case 3: randomly select start and end stations from several different lines. 
// If the FloyWarshall algorithm runs correct, the output route should be the same with the actual result. 
bool pathtest3() {
    cout<<"test between multiple lines"<<endl;
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
    LinkedListNode* cur =  g->adjLists[301].edges;
    while (cur != NULL) {
        cur = cur->next;
    }
    map<pair<int, int>, string> bfs = BFS(g, 1);
    vector<vector<int> > p = FloyWarshall(g);
    vector<int> path = returnPath(p, 45, 95);
    vector<int> list;
    list.push_back(46);
    list.push_back(149);
    list.push_back(150);
    list.push_back(182);
    list.push_back(24);
    list.push_back(51);
    list.push_back(52);
    list.push_back(87);
    list.push_back(88);
    list.push_back(67);
    list.push_back(31);
    list.push_back(89);
    list.push_back(90);
    list.push_back(91);
    list.push_back(92);
    list.push_back(93);
    list.push_back(94);
    return (path == list);
}


// test case 4: randomly select start and end stations from two different lines, but station numbers are in reversed order. 
// If the FloyWarshall algorithm runs correct, the output route should be the same with the actual result. 
bool pathtest4() {
    cout<<"test between two lines"<<endl;
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
    LinkedListNode* cur =  g->adjLists[301].edges;
    while (cur != NULL) {
        cur = cur->next;
    }
    map<pair<int, int>, string> bfs = BFS(g, 1);
    vector<vector<int> > p = FloyWarshall(g);
    vector<int> path = returnPath(p, 232, 67);
    vector<int> list;
    list.push_back(231);
    list.push_back(230);
    list.push_back(229);
    list.push_back(42);
    list.push_back(43);
    list.push_back(44);
    list.push_back(45);
    list.push_back(46);
    list.push_back(149);
    list.push_back(150);
    list.push_back(182);
    list.push_back(24);
    list.push_back(51);
    list.push_back(52);
    list.push_back(87);
    list.push_back(88);
    return (path == list);
}