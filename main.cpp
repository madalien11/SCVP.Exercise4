#include <systemc.h>

#include "place.h"
#include "transition.h"
#include "subnet.h"

// Toplevel:
// TODO
SC_MODULE(toplevel) {
    private:
    TRANSITION t1;
    TRANSITION t2;
    place<unsigned int> place1;
    place<unsigned int> place2;

    public:
    SC_CTOR(toplevel) : t1("t1"), t2("t2"), place1(1), place2(0) {
        t1.in.bind(place1);
        t1.out.bind(place2);
        t2.in.bind(place2);
        t2.out.bind(place1);
        SC_THREAD(process);
    }

    void process() {
        while (true) {
            wait(10, SC_NS);
            t1.fire();
            wait(10, SC_NS);
            t1.fire();
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
