#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include<Source/unit.h>

class ClassUnit : public Unit
{
public:
    virtual void add(const std::shared_ptr<Unit>&, Flags) {
        throw std::runtime_error( "Not supported" );
    }
    virtual std::string compile(unsigned int level = 0) const = 0;
};

#endif // CLASSUNIT_H
