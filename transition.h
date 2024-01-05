#ifndef TRANSITION_H
#define TRANSITION_H

#include <systemc.h>

#include "place.h"

// Transition:
// TODO
SC_MODULE(TRANSITION) {
    sc_port< placeInterface<unsigned int> > in;
    sc_port< placeInterface<unsigned int> > out;

    SC_CTOR(TRANSITION) {}

    void fire() {
        unsigned int tokens = in->testTokens();
        if(tokens > 0) {
            std::cout << this->name() << ": Fired" << std::endl;
            in->removeTokens(1);
            out->addTokens(1);
        } else if (tokens == 0) {
            std::cout << this->name() << ": NOT Fired" << std::endl;
        }
    }
};

#endif // TRANSITION_H
