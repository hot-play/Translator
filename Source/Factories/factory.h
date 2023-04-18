#ifndef FACTORY_H
#define FACTORY_H

#include <Source/unit.h>
#include <Source/ClassUnits/classunit.h>
class Factory
{
public:
    virtual UnitPtr createClass(const std::string& name) const = 0;
    virtual UnitPtr createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) const = 0;
    virtual UnitPtr createPrintOperator(const std::string& text) const = 0;
};

#endif // FACTORY_H
