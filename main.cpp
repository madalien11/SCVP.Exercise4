#include <systemc.h>

#include "place.h"
#include "transition.h"
#include "subnet.h"

// Toplevel:
// TODO
SC_MODULE(toplevel) {
    private:
    TRANSITION<1,2> t1;
    TRANSITION<2,1> t2;
    TRANSITION<1,1> t3;
    place<1,1> place1;
    place<1,1> place2;
    place<1,1> place3;
    place<1,1> place4;

    public:
    SC_CTOR(toplevel) : t1("t1"), t2("t2"), t3("t3"), place1(1), place2(0), place3(0), place4(0) {
        t1.in.bind(place1);
        t1.out.bind(place2);
        t1.out.bind(place3);

        t2.in.bind(place2);
        t2.in.bind(place4);
        t2.out.bind(place1);
        
        t3.in.bind(place3);
        t3.out.bind(place4);

        SC_THREAD(process);
    }

    void process() {
        while (true) {
            wait(10, SC_NS);
            t1.fire();
            wait(10, SC_NS);
            t2.fire();
            wait(10, SC_NS);
            t3.fire();
            wait(10, SC_NS);
            t2.fire();
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
