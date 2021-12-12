#include <iostream>
#include "graph.h"
#include "draw.h"
#include <vector>
#include <string>
#include <map>
#include "pathtest.cpp"
#include "bfstest.cpp"

using namespace std;

int main() {
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
    graph.push_back("line14_1.txt");
    graph.push_back("line14_2.txt");
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
    LinkedListNode* cur =  g->adjLists[176].edges;
    while (cur != NULL) {
        cur = cur->next;
    }
    map<pair<int, int>, string> bfs = BFS(g, 1);
    bool bfsresult1 = bfstest1();
    cout<<"bfs test result 1: "<<bfsresult1<<endl;
    bool bfsresult2 = bfstest2();
    cout<<"bfs test result 2: "<<bfsresult2<<endl;
    bool bfsresult3 = bfstest3();
    cout<<"bfs test result 3: "<<bfsresult3<<endl;
    bool bfsresult4 = bfstest4();
    cout<<"bfs test result 4: "<<bfsresult4<<endl;

    vector<vector<int> > p = FloyWarshall(g);
    bool pathresult1 = pathtest1();
    cout<<"path test result 1: "<<pathresult1<<endl;
    bool pathresult2 = pathtest2();
    cout<<"path test result 2: "<<pathresult2<<endl;
    bool pathresult3 = pathtest3();
    cout<<"path test result 3: "<<pathresult3<<endl;
    bool pathresult4 = pathtest4();
    cout<<"path test result 4: "<<pathresult4<<endl;
    
    Draw(g);
    return 1;
}

