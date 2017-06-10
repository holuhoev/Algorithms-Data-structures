//
// Created by Евгений Лебедев on 28.02.17.
//

#ifndef INC_2_7_FIFO_H
#define INC_2_7_FIFO_H

#include "simulator.h"

class fifo: public simulator
{
public:
    fifo(int seconds_per_page) : simulator(seconds_per_page) {}
     void simulate(string file) override ;  // override
};


#endif //INC_2_7_FIFO_H
