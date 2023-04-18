#ifndef METHODUNIT_H
#define METHODUNIT_H

#include<Source/unit.h>

class MethodUnit : public Unit {
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };
public:
    virtual void add(const UnitPtr&, Flags = 0) {
        throw std::runtime_error( "Not supported Method" );
    }
    virtual std::string compile(unsigned int level = 0) const = 0;
};

#endif // METHODUNIT_H
