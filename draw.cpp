
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include "draw.h"


using namespace std;
using namespace cs225;

//draw a line that connects (x1, y1) and (x2, y2) on a PNG.
//x, y are PNG positions (top left corner is (0, 0), bottom right corner is (width, height) ), not coordinate in rectangluar coordinate system
void drawLine(int x1, int y1, int x2, int y2, PNG* pic) {
    //initialize line color
    HSLAPixel line_color(0.7, 0.5, 0.5);
    //check to avoid divide by 0
    if (x1 == x2) {
        //initialize starting y-coordinate as the smaller of y1 and y2
        for (int y = min(y1, y2); y <= max(y1, y2); y++) {
            HSLAPixel& curr_pixel = pic->getPixel(x1, y);
            curr_pixel = line_color;
        }
        return;
    }
    //if |slope| is smaller than 1 (flatter), increase x one unit per step and compute y value at corresponding points
    //if |slope| is greater than 1 (steeper), increase y one unit per step and compute x value at corresponding points
    double slope = double(y1 - y2)/double(x1 - x2);
    if (abs(slope) <= 1) {
        //draw by increasing x and computing y
        //initialize starting point x-coordinate (smaller one)
        //and y_position corresponding to starting point
        int x_start = -1;
        int x_end = -2;
        double y_pos = -1;
        if (x1 < x2) {
            x_start = x1;
            y_pos = double(y1);
            x_end = x2;
        } else {
            x_start = x2;
            y_pos = double(y2);
            x_end = x1;
        }
       
        if (x_start < 0) {
            return;
        }
        for (int x = x_start; x < x_end; x++) {
            //y_approx: the int that approximates the actual double y_coordinate
            int y_approx = int(y_pos);
            HSLAPixel& curr_pixel = pic->getPixel(x, y_approx);
            curr_pixel = line_color;
            //update y_pos to be the y-coordinate of the next point
            y_pos = y_pos + slope;
            
        }
    } else {
        //draw by increasing y and computing x
        int y_start = -1;
        int y_end = -2;
        double x_pos = -1;
        if (y1 < y2) {
            y_start = y1;
            x_pos = double(x1);
            y_end = y2;
        } else {
            y_start = y2;
            x_pos = double(x2);
            y_end = y1;
        }
        for (int y = y_start; y < y_end; y++) {
            //x_approx: the int that approximates the actual double x_coordinate
            int x_approx = int(x_pos);
            HSLAPixel& curr_pixel = pic->getPixel(x_approx, y);
            curr_pixel = line_color;
            //update y_pos to be the y-coordinate of the next point
            x_pos = x_pos + (1/slope);
            
        }
    }
}

void Draw(Graph* g) {
   //convert lat and longt into x and y
   //ignore z
   //find the smallest x and y coordinate and use it as the origin

   //a map that maps station number(int) to its x, y position(pair<double, double>)
   map<int, pair<double, double> > converted_pos;
   //stores min and max value of x and y coordinate
   int x_min = 1e8;
   int y_min = 1e8;
   int x_max = -1e8;
   int y_max = -1e8;
   for (int i = 1; i < int(g->adjLists.size()); i++) {
       //calculate converted rectangular coordinates
       AdjacencyList curr_node = g->adjLists[i];
       double x_converted = curr_node.x/360;
       double y_converted = 0.5 - (log(tan((curr_node.y*3.14159/360) + (3.14159/4)))/(2*3.14159));
       x_converted = x_converted*20000;
       y_converted = y_converted*20000;
       //update max and min x, y accordingly
       if (x_converted < x_min) {
           x_min = x_converted;
       }
       if (x_converted > x_max) {
           x_max = x_converted;
       }
       if (y_converted < y_min) {
           y_min = y_converted;
       }
       if (y_converted > y_max) {
           y_max = y_converted;
       }
       //add converted coordinates to map
       pair<double, double> coordinate_temp;
       coordinate_temp.first = x_converted;
       coordinate_temp.second = y_converted;
       converted_pos[i] = coordinate_temp;
   }
   //calculate offset value (origin of the coordinate system) based on min x and y values
   //offset value is smaller than min x, y since we don't want to draw points at the edge of our png
   //(x, y) coordinate of any station on the png is given by (actual_x - x_offset)*scaling_factor
   //to draw onto png we take only the int part of this number. To get a more precise picture, scaling factor should be large.
   double x_offset = x_min - 10;
   double y_offset = y_min - 10;
   int scale = 50;
   //determine upper bound of x and y(and the size of the png) based on max x and y values
   //initialize png
   int x_upper = int((x_max - x_offset)*scale) + 100;
   int y_upper = int((y_max - y_offset)*scale) + 100;
   
   PNG* output = new PNG(x_upper, y_upper);
   //draw all stations in the position map
   //each station is represented by a square with side length of 11, centered at converted (x, y)
   HSLAPixel station_color(0.5, 0.5, 0.5);
   for (int i = 1; i < int(converted_pos.size()) + 1; i++) {
       //since y = 0 for a png starts at the top row (opposite to usual coordinate frame), y = png.size() corresponds to y = 0 in our coordinate system
       int x_center = int((converted_pos[i].first - x_offset)*scale);
       int y_center = int((converted_pos[i].second - y_offset)*scale);
      
       //update converted_pos map to prepare to draw lines
       pair<int, int> png_pos;
       png_pos.first = x_center;
       png_pos.second = y_center;
       converted_pos[i] = png_pos;
       //draw a square centered at (x_center, y_center)
       for (int x = x_center - 5; x <= x_center + 5; x++) {
           for (int y = y_center - 5; y <= y_center + 5; y++) {
               
               HSLAPixel& curr_pixel = output->getPixel(x, y);
               curr_pixel = station_color;
           }
       }
   }
   //draw lines: if two stations are connected, draw a line between them
   for (int i = 1; i < int(g->adjLists.size()); i++) {
       //here i is station number
       //get neighbor index
       LinkedListNode* neighbor = g->adjLists[i].edges;
       //draw a line that connects current station to all neighbors
       while (neighbor != NULL) {
           int neighbor_idx = neighbor->station;
           drawLine(converted_pos[i].first, converted_pos[i].second, converted_pos[neighbor_idx].first, converted_pos[neighbor_idx].second, output);
           //go to next neighbor
           neighbor = neighbor->next;
       }
   }
   output->writeToFile("graph"+ string(".png"));
}

