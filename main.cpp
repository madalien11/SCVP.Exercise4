#include <systemc.h>

#include "place.h"
#include "transition.h"
#include "subnet.h"

// Toplevel:
// TODO
SC_MODULE(toplevel) {
    private:
    TRANSITION<1,1> ACT;
    TRANSITION<1,1> RD;
    TRANSITION<1,1> PRE;
    TRANSITION<1,1> WR;
    place<1,1> IDLE;
    place<1,1> ACTIVE;

    public:
    SC_CTOR(toplevel) : ACT("ACT"), RD("RD"), PRE("PRE"), WR("WR"), IDLE(1), ACTIVE(0){
        ACT.in.bind(IDLE);
        ACT.out.bind(ACTIVE);

        RD.in.bind(ACTIVE);
        RD.out.bind(ACTIVE);
        
        PRE.in.bind(ACTIVE);
        PRE.out.bind(IDLE);
        
        WR.in.bind(ACTIVE);
        WR.out.bind(ACTIVE);

        SC_THREAD(process);
    }

    void process() {
        while (true) {
            wait(10, SC_NS);
            ACT.fire();
            wait(10, SC_NS);
            ACT.fire();
            wait(10, SC_NS);
            RD.fire();
            wait(10, SC_NS);
            WR.fire();
            wait(10, SC_NS);
            PRE.fire();
            wait(10, SC_NS);
            ACT.fire();
            sc_stop();
        }
    }
};

int sc_main(int, char**)
{
    // TODO
    toplevel t("toplevel");

    sc_start();
    return 0;
}
