#ifndef CPPFACTORY_H
#define CPPFACTORY_H

#include<Source/unit.h>
#include<Source/Factories/factory.h>
#include<Source/ClassUnits/cppclassunit.h>
#include<Source/MethodUnits/cppmethodunit.h>
#include<Source/PrintOperatorUnits/cppprintoperatorunit.h>

class CppFactory : public Factory
{
public:
    CppFactory() = default;
    ~CppFactory() = default;
    UnitPtr createClass(const std::string& name) const override {
        return std::make_shared<CppClassUnit>(name);
    }
    UnitPtr createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) const override {
        return std::make_shared<CppMethodUnit>(name, returnType, flags);
    }
    UnitPtr createPrintOperator(const std::string& text) const override {
        return std::make_shared<CppPrintOperatorUnit>(text);
    }
};

#endif // CPPFACTORY_H
