#ifndef CSFACTORY_H
#define CSFACTORY_H

#include<Source/unit.h>
#include<Source/Factories/factory.h>
#include<Source/ClassUnits/csclassunit.h>
#include<Source/MethodUnits/csmethodunit.h>
#include<Source/PrintOperatorUnits/csprintoperatorunit.h>

class CsFactory : public Factory
{
public:
    CsFactory() = default;
    ~CsFactory() = default;
    UnitPtr createClass(const std::string& name) const override {
        return std::make_shared<CsClassUnit>(name);
    }
    UnitPtr createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) const override {
        return std::make_shared<CsMethodUnit>(name, returnType, flags);
    }
    UnitPtr createPrintOperator(const std::string& text) const override {
        return std::make_shared<CsPrintOperatorUnit>(text);
    }
};

#endif // CSFACTORY_H
