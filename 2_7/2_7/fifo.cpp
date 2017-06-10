//
// Created by Евгений Лебедев on 28.02.17.
//
#include <fstream>
#include "fifo.h"

void fifo::simulate(string file)
{
    //load all events
    loadworkload(file);

    string path = file.substr(0,file.size()-4);
    path += "1.out";

    ofstream of(path);

    if(of)
    {
        of << "FIFO Simulation:\n\n";

        unsigned long totalJobs = workload.size();
        int latency = 0;

        int counter = 0; // current second
        queue<event> waiting;

        event e; // сurrent event

        bool isPrinting = false;
        int nextTime = 0; // when printing must stop


        while (!workload.empty() || !waiting.empty())
        {
            e = workload.front();

            //Arrive
            while (counter == e.arrival_time())
            {
                of << "Arriving: " << e.getjob().getnumpages() << " pages from " << e.getjob().getuser() << " at "
                   << e.arrival_time() << " seconds";
                of << endl;

                waiting.push(e);
                workload.pop();

                e = workload.front();
            }

            //start print if free
            if (!isPrinting && !waiting.empty())
            {
                e = waiting.front();

                //pring servicing
                of << "   Servicing: " << e.getjob().getnumpages() << " pages from " << e.getjob().getuser() << " at "
                   << counter << " seconds";
                of << endl;

                //get time when printing will stop
                nextTime = e.getjob().getnumpages() * seconds_per_page + counter;
                waiting.pop();

                //increment latency
                latency += (counter - e.arrival_time());

                isPrinting = true;
            }

            counter++;

            //stop printing one job
            if (nextTime == counter)
                isPrinting = false;
        }

        of << endl;
        of << "Total jobs: " << totalJobs << endl;
        of << "Aggregate  latency: " << latency << endl;
        of << "Mean latency: " << (double) latency / totalJobs << endl;

        of.close();
    }

}