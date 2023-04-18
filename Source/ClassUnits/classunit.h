#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include<Source/unit.h>

class ClassUnit : public Unit
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    static const std::vector<std::string> ACCESS_MODIFIERS;
public:
    virtual void add(const UnitPtr&, Flags) {
        throw std::runtime_error( "Not supported Class" );
    }
    virtual std::string compile(unsigned int level = 0) const = 0;
};

#endif // CLASSUNIT_H
