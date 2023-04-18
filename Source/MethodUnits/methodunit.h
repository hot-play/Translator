#ifndef METHODUNIT_H
#define METHODUNIT_H

#include<Source/unit.h>

class MethodUnit : public Unit {
public:
    virtual void add(const std::shared_ptr<Unit>&, Flags) {
        throw std::runtime_error( "Not supported" );
    }
    virtual std::string compile(unsigned int level = 0) const = 0;
};

#endif // METHODUNIT_H
