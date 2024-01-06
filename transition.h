#ifndef TRANSITION_H
#define TRANSITION_H

#include <systemc.h>

#include "place.h"

// Transition:
// TODO
template<unsigned int N = 1, unsigned int M = 1, unsigned int L = 0>
SC_MODULE(TRANSITION) {
    public:
    sc_port<placeInterface, N, SC_ALL_BOUND> in;
    sc_port<placeInterface, M, SC_ALL_BOUND> out;
    sc_port<placeInterface, L, SC_ZERO_OR_MORE_BOUND> inhibitors;
    
    SC_CTOR(TRANSITION) {}

    void fire() {
        bool haveTokens = true;
        for (int i = 0; i < N; i++) {
            if(!in[i]->testTokens()) {
                haveTokens = false;
                break;
            }
        }
         
        if (haveTokens) {
            for (int i = 0; i < L; i++) {
                if(inhibitors[i]->testTokens()) {
                    haveTokens = false;
                    break;
                }
            }
        }

        if(haveTokens) {
            for (int i = 0; i < N; i++) {
                in[i]->removeTokens();
            }
            
            for (int i = 0; i < M; i++) {
                out[i]->addTokens();
            }

            std::cout << this->name() << ": Fired" << std::endl;
        } else {
            std::cout << this->name() << ": NOT Fired" << std::endl;
        }
        
    }
};

#endif // TRANSITION_H
