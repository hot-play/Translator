#ifndef FACTORY_H
#define FACTORY_H

#include <Source/unit.h>
#include <Source/ClassUnits/classunit.h>

// Абстрактная фабрика
class Factory
{
public:
    virtual UnitPtr createClass(const std::string& name) const;
    virtual UnitPtr createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) const;
    virtual UnitPtr createPrintOperator(const std::string& text) const;
};

#endif // FACTORY_H
