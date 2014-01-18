#ifndef PIONFACTORY_HPP
#define PIONFACTORY_HPP

using namespace std;

class PionFactory{
private:
    PionFactory();
    PionFactory(PionFactory &);
    void operator=(PionFactory &);
    vector<Pion> pions;
public:
    static PionFactory &getInstance();
    Pion getPion (string);
};

#endif
