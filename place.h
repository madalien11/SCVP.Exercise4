#ifndef PLACE_H
#define PLACE_H

#include <systemc.h>

// Place Interface:
// TODO
template <class T>
class placeInterface : virtual public sc_interface {
    public:
    virtual void addTokens(unsigned int n) = 0;
    virtual void removeTokens(unsigned int n) = 0;
    virtual unsigned int testTokens() = 0;
};

// Place Channel:
// TODO
template <class T>
class place : public placeInterface<T> {
    private:
    unsigned int tokens;

    public:
    place(unsigned int numOfTokens) : tokens(numOfTokens)
    {
    }

    void addTokens(unsigned int n) {
        tokens += n;
    }

    void removeTokens(unsigned int n) {
        tokens -= n;
    }

    unsigned int testTokens() {
        return tokens;
    }
};

#endif // PLACE_H
