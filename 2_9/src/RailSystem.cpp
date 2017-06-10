#pragma warning (disable:4786)
#pragma warning (disable:4503)

#include <stack>
#include "RailSystem.h"

void RailSystem::reset(void)
{

    // TODO: reset the data objects of the
    // City objects' contained in cities
    map<string, City*>::iterator c_iter;

    for (c_iter = cities.begin(); c_iter != cities.end(); ++c_iter)
    {
        City* city = c_iter->second;

        //reset
        city->total_fee = INT_MAX;
        city->visited = false;
        city->from_city = "";
    }

}

RailSystem::RailSystem(string const &filename)
{

    load_services(filename);
}

void RailSystem::load_services(string const &filename)
{

    ifstream inf(filename.c_str());
    string from, to;
    int fee, distance;

    while (inf.good())
    {
        // Read in the from city, to city, the fee, and distance.
        inf >> from >> to >> fee >> distance;

        if (inf.good())
        {
            //Add new city
            if (!is_valid_city(from))
            {
                City* city = new City();
                city->name = from;
                cities[from] = city;
            }

            if (!is_valid_city(to))
            {
                City* city = new City();
                city->name = to;
                cities[to] = city;
            }

            Service* service = new Service(to, fee, distance);
            outgoing_services[from].push_back(service);

        }
    }

    inf.close();
}

RailSystem::~RailSystem(void)
{
    //delete cities
    map<string, City*>::iterator c_iter;

    for (c_iter = cities.begin(); c_iter != cities.end(); ++c_iter)
    {
        City* city = (*c_iter).second;

        delete city;
    }



    //delete Services
    map<string, list<Service*> >::iterator iter;

    for (iter = outgoing_services.begin(); iter != outgoing_services.end(); ++iter)
    {
        list<Service*> &lst = iter->second;

        for (list<Service*>::iterator it = lst.begin(); it != lst.end(); ++it)
        {
            Service* service = *it;

            delete service;
        }
    }

}

void RailSystem::output_cheapest_route(const string &from,
                                       const string &to, ostream &out)
{

    reset();
    pair<int, int> totals = calc_route(from, to);

    if (totals.first == INT_MAX)
    {
        out << "There is no route from " << from << " to " << to << "\n";
    } else
    {
        out << "The cheapest route from " << from << " to " << to << "\n";
        out << "costs " << totals.first << " euros and spans " << totals.second
            << " kilometers\n";
        cout << recover_route(to) << "\n\n";
    }
}

bool RailSystem::is_valid_city(const string &name)
{

    return cities.count(name) == 1;
}

pair<int, int> RailSystem::calc_route(string from, string to)
{
    // You can use another container
    priority_queue<City*, vector<City*>, Cheapest> candidates;


    //setup first fee and distance 0
    cities[from]->total_fee = 0;
    cities[from]->total_distance = 0;

    //fill queue

    candidates.push(cities[from]);

    while (!candidates.empty())
    {

        City* city = candidates.top();
        candidates.pop();

        if (!city->visited)
        {
            city->visited = true;

            list<Service*> &lst = outgoing_services[city->name];

            for (list<Service*>::iterator it = lst.begin(); it != lst.end(); ++it)
            {
                Service* service = *it;

                //get destination
                string name = service->destination;

                if (!cities[name]->visited)
                {
                    int fee = city->total_fee + service->fee;
                    int distance = city->total_distance + service->distance;

                    if (fee < cities[name]->total_fee)
                    {
                        //setup fee & distance
                        cities[name]->total_fee = fee;
                        cities[name]->total_distance = distance;

                        //place city from
                        cities[name]->from_city = city->name;

                        candidates.push(cities[name]);
                    }
                }
            }
        }
    }

    // Return the total fee and total distance.
    // Return (INT_MAX, INT_MAX) if not path is found.
    if (cities[to]->visited)
    {
        return pair<int, int>(cities[to]->total_fee, cities[to]->total_distance);
    } else
    {
        return pair<int, int>(INT_MAX, INT_MAX);
    }

}

string RailSystem::recover_route(const string &city)
{
    stack<string> st;

    City* city1 = cities[city];
    st.push(city);
    vector<string> vector1;

    string str = "";

    //recover proper route
    while (city1->from_city != "")
    {
        str = city1->from_city;
        st.push(str);
        city1 = cities[str];
    }

    str = "";

    //recover proper look
    while (!st.empty())
    {
        str += st.top();

        if (st.size() > 1)
            str += " to ";


        st.pop();
    }

    return str;
}


Route RailSystem::getCheapestRoute(const string &from, const string &to)
{
    assert(is_valid_city(from));
    assert(is_valid_city(to));
    reset();
    pair<int, int> p = calc_route(from, to);
    return Route(from, to, p.first, p.second);
}