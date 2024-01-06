#ifndef SUBNET_H
#define SUBNET_H

#include <systemc.h>

#include "place.h"
#include "transition.h"

// Subnet:
// TODO
SC_MODULE(SUBNET) {
    public:
    TRANSITION<1,1,1> ACT;
    TRANSITION<1,1,0> RD;
    TRANSITION<1,1,0> PRE;
    TRANSITION<1,1,0> WR;
    place<1,1> ACTIVE;
    sc_port<placeInterface> idle;

    SC_CTOR(SUBNET) : ACT("ACT"), RD("RD"), PRE("PRE"), WR("WR"), ACTIVE(0), idle("idle") {
        ACT.in.bind(idle);
        ACT.out.bind(ACTIVE);
        ACT.inhibitors.bind(ACTIVE);

        RD.in.bind(ACTIVE);
        RD.out.bind(ACTIVE);
        RD.inhibitors.bind(ACTIVE);
        
        PRE.in.bind(ACTIVE);
        PRE.out.bind(idle);
        PRE.inhibitors.bind(ACTIVE);
        
        WR.in.bind(ACTIVE);
        WR.out.bind(ACTIVE);
        WR.inhibitors.bind(ACTIVE);
    }
};
#endif // SUBNET_H
