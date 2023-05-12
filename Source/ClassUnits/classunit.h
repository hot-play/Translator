#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include<Source/unit.h>

class ClassUnit : public Unit
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        PRIVATE_PROTECTED,
        FILE,
        ITERNAL,
        PROTECTED_ITERNAL,
    };
    static const std::vector<std::string> ACCESS_MODIFIERS;
public:
    virtual void add(const UnitPtr&, Flags) = 0;
    virtual std::string compile(unsigned int level = 0) const = 0;
protected:
    std::string className;
    using Fields = std::vector<UnitPtr>;
    std::vector< Fields > fields;
};

#endif // CLASSUNIT_H
