#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "graph.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
using namespace std;
using namespace cs225;

void drawLine(int x1, int y1, int x2, int y2, PNG* pic);

void Draw(Graph* g);
