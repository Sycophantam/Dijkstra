#include "graph.h"


/**********************************************************
 *
 * Constructor Graph: Class Graph
 *_________________________________________________________
 * This method constructs the Graph class
 *_________________________________________________________
 * PRE-CONDITIONS
 *     none
 *
 * POST-CONDITIONS
 *     This function will construct a Graph class with adjacency matrix
 ***********************************************************/
Graph::Graph()
{
    paths.push_back(Seattle);
    paths.push_back(San_Francisco);
    paths.push_back(Los_Angeles);
    paths.push_back(Denver);
    paths.push_back(Kansas_City);
    paths.push_back(Chicago);
    paths.push_back(Boston);
    paths.push_back(New_York);
    paths.push_back(Atlanta);
    paths.push_back(Dallas);
    paths.push_back(Houston);
    paths.push_back(Miami);

    cities.push_back({"Seattle", Seattle, INF, vector<string>(), false});
    cities.push_back({"San Francisco", San_Francisco, INF,
                      vector<string>(), false});

    cities.push_back({"Los Angeles", Los_Angeles, INF,
                      vector<string>(), false});

    cities.push_back({"Denver", Denver, INF, vector<string>(), false});
    cities.push_back({"Kansas City", Kansas_City, INF,
                      vector<string>(), false});

    cities.push_back({"Chicago", Chicago, INF, vector<string>(), false});
    cities.push_back({"Boston", Boston, INF, vector<string>(), false});
    cities.push_back({"New York", New_York, INF, vector<string>(), false});
    cities.push_back({"Atlanta", Atlanta, INF, vector<string>(), false});
    cities.push_back({"Dallas", Dallas, INF, vector<string>(), false});
    cities.push_back({"Houston", Houston, INF, vector<string>(), false});
    cities.push_back({"Miami", Miami, INF, vector<string>(), false});

}
////Seattle, San Francisco, Los Angeles, Denver, Kansas City, Chicago,
////Boston, New York, Atlanta, Dallas, Houston, Miami


/**********************************************************
 *
 * Method Dijkstra(): Class Graph
 *_________________________________________________________
 * This method runs Dijkstra's algorithm and prints the paths
 *_________________________________________________________
 * PRE-CONDITIONS
 *     start: number of the city to start at
 *
 * POST-CONDITIONS
 *     This function returns nothing
 ***********************************************************/
void Graph::Dijkstra(int start)
{

    for(unsigned i = 0; i < cities.size(); i++)
    {
        cities.at(i).total = INF;
        cities.at(i).from.clear();
    }


    first = true;
    runDijkstra(cities.at(start));
    printPaths();
}

/**********************************************************
 *
 * Method Prim(): Class Graph
 *_________________________________________________________
 * This method finds the minimum spanning tree using Prim's
 * algorithm
 *_________________________________________________________
 * PRE-CONDITIONS
 *     start: number of the city to start at
 *
 * POST-CONDITIONS
 *     This function returns nothing
 ***********************************************************/
void Graph::Prim(unsigned start)
{
    int mileage = 0;
    CitiesVisited.clear();
    for(unsigned i = 0; i < cities.size(); i++)
    {
        cities.at(i).total = INF;
        cities.at(i).from.clear();
        cities.at(i).visited = false;
    }

    cities.at(start).total = 0;
    unsigned city1, city2;
    CitiesVisited.push_back(convertNumtoName(start));
    int count = 1;
    while(CitiesVisited.size() < SIZE)
    {
        unsigned min = INF;
        city1 = 0;
        city2 = 0;
        for(unsigned i = 0; i < SIZE; i++)
        {
            if(contains(CitiesVisited, convertNumtoName(i)))
            {
                for(unsigned j = 0; j < SIZE; j++)
                {
                    if(!contains(CitiesVisited,convertNumtoName(j)) &&
                            (cities.at(i).path.at(j) > 0 &&
                             cities.at(i).path.at(j) != INF))
                    {
                        if(min > cities.at(i).path.at(j))
                        {
                            min = cities.at(i).path.at(j);
                            city1 = i;
                            city2 = j;
                        }
                    }
                }
            }
        }
        cout << count << ": " << "(" << convertNumtoName(city1) << ", "
             << convertNumtoName(city2) << ") "
             << cities.at(city1).path.at(city2) << endl;
        CitiesVisited.push_back(convertNumtoName(city2));
        count++;
        mileage += cities.at(city1).path.at(city2);

    }
    cout << "Total mileage: " << mileage << endl;

}

/*******************************************************************
 * int find();
 *
 *   Accessor; This method finds the parent of a city
 *------------------------------------------------------------------
 *   Parameters: arr(int[])-Array of cities
 *               i(int)-City to find parent of
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
int find(int arr[], int i);

/**********************************************************
 *
 * Method Kruskal(): Class Graph
 *_________________________________________________________
 * This method finds the minimum spanning tree using Kruskal's
 * algorithm
 *_________________________________________________________
 * PRE-CONDITIONS
 *     none
 *
 * POST-CONDITIONS
 *     This function returns nothing
 ***********************************************************/
void Graph::Kruskal()
{
    CitiesVisited.clear();
    for(unsigned i = 0; i < cities.size(); i++)
    {
        cities.at(i).total = INF;
        cities.at(i).from.clear();
        cities.at(i).visited = false;
    }

    int parent[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        parent[i] = i;
    }
    int count = 0;
    int mileage = 0;
    while(count < SIZE - 1)
    {
        unsigned min = 10000000;
        unsigned city1 = 0, city2 = 0;
        for(unsigned i = 0; i < cities.size(); i++)
        {
            for(unsigned j = 0; j < cities.at(i).path.size(); j++)
            {
//                cout << "City 1: " << convertNumtoName(i) << endl;
//                cout << "City 2: " << convertNumtoName(j) << endl;
//                cout << "min: " << min << endl;
                if(find(parent, i) != find(parent, j)
                        && cities.at(i).path.at(j) < min
                        && cities.at(i).path.at(j) != 0)
                {
//                    cout << endl;
//                    cout << "City 1: " << convertNumtoName(i) << endl;
//                    cout << "City 2: " << convertNumtoName(j) << endl;
//                    cout << "min: " << min << endl;
                    min = cities.at(i).path.at(j);
                    city1 = i;
                    city2 = j;

                }
            }
        }
        int startpoint = find(parent, city1);
        int endpoint = find(parent, city2);
        parent[startpoint] = endpoint;
        cout << count + 1 << ": " << "(" << convertNumtoName(city1) << ", "
             << convertNumtoName(city2) << ") "
             << cities.at(city1).path.at(city2) << endl;

        count++;
        mileage += cities.at(city1).path.at(city2);
    }
    cout << "Total mileage: " << mileage << endl;
}

/**********************************************************
 *
 * Method find()
 *_________________________________________________________
 * This method finds the parent of a city
 *_________________________________________________________
 * PRE-CONDITIONS
 *     arr(int[])-array of numbers
 *     i(int)-Parent value
 *
 * POST-CONDITIONS
 *     This function returns an int
 ***********************************************************/
int find(int arr[], int i)
{
    while(arr[i] != i)
    {
        i = arr[i];
    }
    return i;
}
/**********************************************************
 *
 * Method contains(vector<string> c, string s): Class Graph
 *_________________________________________________________
 * This method checks if string s is within vector c
 *_________________________________________________________
 * PRE-CONDITIONS
 *     c: vector of strings to check
 *     s: string to check
 *
 * POST-CONDITIONS
 *     This function returns true if s is within c
 ***********************************************************/
bool Graph::contains(vector<string> c, string s)
{
    for(unsigned i = 0; i < c.size(); i++)
    {
        if(c.at(i) == s)
            return true;
    }
    return false;
}

/**********************************************************
 *
 * Method runDijkstra(City& start): Class Graph
 *_________________________________________________________
 * This method calculates the shortest paths to each node
 * using Dijkstra's algorithm
 *_________________________________________________________
 * PRE-CONDITIONS
 *     start: City to start at
 *
 * POST-CONDITIONS
 *     This function returns nothing
 ***********************************************************/
void Graph::runDijkstra(City& start)    //City to start at
{
//    cout << "We are at " << start.name << endl;
//    cout << endl;
    start.from.push_back(start.name);
    if(first)
    {
        first = false;
        for(unsigned i = 0; i < SIZE; i++)
        {
            if(convertNumtoName(i) == start.name)
            {
                start.total = 0;
            }

//            cout << "City: " << cities.at(i).name << endl;
//            cout << "Total: " << cities.at(i).total << endl;
//            cout << "Visited: " << cities.at(i).visited << endl;
        }
    }
    vector<City> next;  //Vector containing location for the next nodes

    //Searching though each
    for(unsigned i = 0; i < SIZE; i++)
    {
        //cout << "Working with " << convertNumtoName(i) << endl;
        if((start.path.at(i) != INF) && (start.path.at(i) > 0))
        {
            //cout << "In if" << endl;
//            if(contains(start.from, convertNumtoName(i)))
//            {
//                cout << "Already visited " << convertNumtoName(i) << endl;
//            }

//            cout << "start.total + the path to get to "
//                 << convertNumtoName(i) << ": "
//                 << start.total + start.path.at(i) << endl;
//            cout << "Current cost to get to " << convertNumtoName(i)
//                 << ": " << cities.at(i).total << endl;

            if(!contains(start.from, convertNumtoName(i)) &&
                    start.total + start.path.at(i) < cities.at(i).total)
            {
                //Clearing previous path. If there is no change to the path,
                //it will be added back anyway. Otherwise, the path is changed
                cities.at(i).from.clear();
                //cout << "cities.at(i).total: " << cities.at(i).total << endl;

                //Setting this prevents a slight bug where distances are
                //measured as one less than they should be
                if(cities.at(i).total == INF)
                {
                    cities.at(i).total = 0;
                }

                //Updating total pathways
                cities.at(i).total = start.path.at(i) + start.total;

                //Adding the cities from the previous path
                for(unsigned k = 0; k < start.from.size(); k++)
                {
                    //Checks if the path doesn't contain the city previously
                    if(!contains(cities.at(i).from, start.from.at(k)))
                        cities.at(i).from.push_back(start.from.at(k));
                }

                //Checks if the path doesn't contain the city previously
                if(!contains(cities.at(i).from, convertNumtoName(i)))
                    cities.at(i).from.push_back(convertNumtoName(i));


                //Adding the adjacent cities to the next queue
                next.push_back(cities.at(i));
            }
        }
    }
    //cout << "Next up: " << endl;
//    for(unsigned i = 0; i < next.size(); i++)
//    {
//        cout << next.at(i).name << endl;
//    }
    for(unsigned i = 0; i < next.size(); i++)
    {
        //printPaths();
        runDijkstra(next.at(i));
    }

    //cout << endl << endl << endl;
    //printPaths();
    //cout << endl;
}


/**********************************************************
 *
 * Method printPaths(): Class Graph
 *_________________________________________________________
 * This method prints the shortest paths to each node
 *_________________________________________________________
 * PRE-CONDITIONS
 *     c: vector of strings to check
 *     s: string to check
 *
 * POST-CONDITIONS
 *     This function returns true if s is within c
 ***********************************************************/
void Graph::printPaths()
{
    for(unsigned i = 0; i < SIZE; i++)
    {
        if(!cities.at(i).from.empty())
        {
            cout << cities.at(i).name << ": " << cities.at(i).total << " {";
            cout << cities.at(i).from.at(0);
            for(unsigned j = 1; j < cities.at(i).from.size(); j++)
            {
                cout << ", " << cities.at(i).from.at(j);
            }
            cout << "}" << endl;
        }

    }
}

/**********************************************************
 *
 * Method convertNumtoName(): Class Graph
 *_________________________________________________________
 * This method returns the City name associated with the number given
 *_________________________________________________________
 * PRE-CONDITIONS
 *     num: number of the city to return
 *
 * POST-CONDITIONS
 *     This function returns the name of the city associated with num
 ***********************************************************/
string Graph::convertNumtoName(unsigned num)
{
    switch (num) {
    case 0:
        return "Seattle";
    case 1:
        return "San Francisco";
    case 2:
        return "Los Angeles";
    case 3:
        return "Denver";
    case 4:
        return "Kansas City";
    case 5:
        return "Chicago";
    case 6:
        return "Boston";
    case 7:
        return "New York";
    case 8:
        return "Atlanta";
    case 9:
        return "Dallas";
    case 10:
        return "Houston";
    case 11:
        return "Miami";
    }
}

