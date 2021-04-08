#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <array>

using namespace std;
class Graph
{
public:
    Graph();

    /***************
     ** ACCESSORS **
     ***************/
    void Dijkstra(int start = 0);       //Number of the city to start at
    void Prim(unsigned start = 0);      //Number of the city to start at
    void Kruskal();

private:
    struct City{
        string name;            //City name
        vector<unsigned> path;  //List of the adjacent paths
        unsigned total;         //Total distance
        vector<string> from;    //List of path cities
        bool visited;           //Checks if the city has been visited

        bool operator=(City& other)
        {
            if(name == other.name)
                return true;
            return false;
        }
    };

    /***************
     ** ACCESSORS **
     ***************/
    bool contains(vector<string> c,         //Vector of string to look at
                  string s);                //String to check if exists in c
    void runDijkstra(City& start);          //City to start running
    string convertNumtoName(unsigned num);  //Number to convert
    void printPaths();



    static const unsigned INF = -1;     //Value to represent infinity
    static const int SIZE = 12;         //Amount of vertices in the graph
    bool first = true;      //Checks if it's the first time running Dijkstra

    //Seattle, San Francisco, Los Angeles, Denver, Kansas City, Chicago,
    //Boston, New York, Atlanta, Dallas, Houston, Miami
    vector<unsigned> Seattle =
    {   0,  807,  INF, 1331,  INF, 2097,  INF,  INF,  INF,  INF,  INF,  INF};
    vector<unsigned>San_Francisco =
    { 807,    0,  381, 1267,  INF,  INF,  INF,  INF,  INF,  INF,  INF,  INF};
    vector<unsigned>Los_Angeles =
    { INF,  381,    0, 1015, 1663,  INF,  INF,  INF,  INF, 1435,  INF,  INF};
    vector<unsigned>Denver =
    {1331, 1267, 1015,    0,  599, 1003,  INF,  INF,  INF,  INF,  INF,  INF};
    vector<unsigned>Kansas_City =
    { INF,  INF, 1663,  599,    0,  533,  INF, 1260,  864,  496,  INF,  INF};
    vector<unsigned>Chicago =
    {2097,  INF,  INF, 1003,  533,    0,  983,  787,  INF,  INF,  INF,  INF};
    vector<unsigned>Boston =
    { INF,  INF,  INF,  INF,  INF,  983,    0,  214,  INF,  INF,  INF,  INF};
    vector<unsigned>New_York =
    { INF,  INF,  INF,  INF, 1260,  787,  214,    0,  888,  INF,  INF,  INF};
    vector<unsigned>Atlanta =
    { INF,  INF,  INF,  INF,  864,  INF,  INF,  888,    0,  781,  810,  661};
    vector<unsigned>Dallas =
    { INF,  INF, 1435,  INF,  496,  INF,  INF,  INF,  781,    0,  239,  INF};
    vector<unsigned>Houston =
    { INF,  INF,  INF,  INF,  INF,  INF,  INF,  INF,  810,  239,    0, 1187};
    vector<unsigned>Miami =
    { INF,  INF,  INF,  INF,  INF,  INF,  INF,  INF,  661,  INF, 1187,    0};


    vector<vector<unsigned> >paths; //Vector containing all paths
    vector<City> cities;            //Vector of cities
    vector<string> CitiesVisited;   //Visited cities


};


/******************************
 ******** CONSTRUCTOR *********
 ******************************/

/****************************************************************
 * Graph(int runways);
 *   Constructor; Initialize class attributes
 *   Parameters: none
 *   Return: none
 ***************************************************************/

/***************
 ** ACCESSORS **
 ***************/

/*******************************************************************
 * void Dijkstra();
 *
 *   Accessor; This method calls runDijkstra and then prints the data
 *------------------------------------------------------------------
 *   Parameters: start(int)-Number of the city to start at-default value 0
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void Prim();
 *
 *   Accessor; This method finds the minimum spanning tree using Prim's
 *             algorithm
 *------------------------------------------------------------------
 *   Parameters: start(unsigned)-Number of the city to start at-default value 0
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void Kruskal();
 *
 *   Accessor; This method finds the minimum spanning tree using Kruskal's
 *             algorithm
 *------------------------------------------------------------------
 *   Parameters: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * bool contains();
 *
 *   Accessor; This method checks if a string is in a vector
 *------------------------------------------------------------------
 *   Parameters: c(vector<string>)-Vector of strings
 *              s(string)-string to check
 *------------------------------------------------------------------
 *   Return: true if s is in c
 *******************************************************************/

/*******************************************************************
 * void runDijkstra();
 *
 *   Accessor; This method runs Dijkstra's algorithm
 *------------------------------------------------------------------
 *   Parameters: start(City)-City to start at
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * string convertNumtoName();
 *
 *   Accessor; This method translates a number to its corresponding city name
 *------------------------------------------------------------------
 *   Parameters: num(unsigned)-number to convert
 *------------------------------------------------------------------
 *   Return: string
 *******************************************************************/

/*******************************************************************
 * string convertNumtoName();
 *
 *   Accessor; This method converts the number of a city to its
 *             corresponding name
 *------------------------------------------------------------------
 *   Parameter: num(int)-the number of the city
 *------------------------------------------------------------------
 *   Return: string-name of the city that matches with the number
 *******************************************************************/

/*******************************************************************
 * void printPaths();
 *
 *   Accessor; This method prints the shortest paths of each node
 *------------------------------------------------------------------
 *   Parameters: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/


#endif // GRAPH_H
