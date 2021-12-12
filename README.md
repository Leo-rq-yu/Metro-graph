# ruiqing6-ziruiw5-weixuan2-zeyangz2
Final Project for ruiqing6-ziruiw5-weixuan2-zeyangz2

This is a project for getting the nearst path between two stations of Beijing subway and building a subway map.

The make graph function, BFS function, and FloyWarshall(shortest path function) are in the graph.h and graph.cpp files. The subway map graph drawing is in the draw.h and draw.cpp files. The data are all in the txt files. We change the formate of the data to: number of the station, Chinese name of station, English name of station, x coordinate, y coordinate.
For exmaple:
1 苹果园 Pingguoyuan 116.17778 39.9263 
1 is the number of station, 苹果园 is the Chinese name of the station, Pingguoyuan is the English name of the station, 116.17778 is the x coordinate, 39.9263 is the y coordinate

The results are in the main.cpp. The graph.png file is the graph that we draw. In the main function, we can run all of our functions.
To compile the code, just type make. To run the code, use ./graph.

Firstly, we need to build our graph first. We can use the function: createSubway(vector<string> filename). The filename is a vector of string. For example, we can create a graph like this: 
    vector<string> graph;
    graph.push_back("line1.txt");
    graph.push_back("line2.txt");
    Graph* g = createSubway(graph);
The number of the station starts from 1.
Since we use adjacent list for building the graph, we can get the neighbors of a station and their x and y coordinates like this:
    LinkedListNode* cur =  g->adjLists[176].edges;
    while (cur != NULL) {
        cout<<cur->station<<endl;
        cout<<cur->x<<endl;
        cout<<cur->y<<endl;
        cur = cur->next;
    }

To make a BFS of our graph, we can use function: map<pair<int, int>, string> BFS(Graph* g, int startingIdx). The startingIdx should start from 1. The input are a pointer to a graph that we build before and a starting node. 
For exmaple: map<pair<int, int>, string> bfs = BFS(g, 1). The output is a map of two stations to a string. For example, cout<<bfs[pair<int, int> (1, 2)]<<endl will give DISCOVERY, since we find a discovery edge between station 1 and 2. If the edge is a cross edge, the map will map the two stations to CROSS. 
  
To find the shortest path from one station to another station, we need to use vector<vector<int> > FloyWarshall(Graph* g). The input is a pointer to the graph we make. The output is a matrix that be used to find the shortest path. After building the matrix, we can use void printPath(vector<vector<int> >& path, int v, int u) to print the shortest path. This is a recursive function to print path of given vertex `u` from source vertex `v`. The input path is the matrix we get before from FloyWarshall. If two stations are not connected by any paths, the function will return "not connected". Else, the function will return the stations' number from v to u. The order of the numbers is the shortest path from v to u. 
For example: 
  vector<vector<int> > p = FloyWarshall(g);
  printPath(p, 7, 250);

  To draw the graph, we use the function in the draw.cpp file: void Draw(Graph* g). This function will take a pointer to a graph and produce a PNG called graph.png. 
  For example:
    Draw(g);
  


