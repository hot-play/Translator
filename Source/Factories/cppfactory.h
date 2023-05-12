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
    UnitPtr createClass(const std::string& name) const override;
    UnitPtr createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) const override;
    UnitPtr createPrintOperator(const std::string& text) const override;
};

#endif // CPPFACTORY_H
