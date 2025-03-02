#ifndef JAVAFACTORY_H
#define JAVAFACTORY_H

#include<Source/unit.h>
#include<Source/Factories/factory.h>
#include<Source/ClassUnits/javaclassunit.h>
#include<Source/MethodUnits/javamethodunit.h>
#include<Source/PrintOperatorUnits/javaprintoperatorunit.h>

class JavaFactory : public Factory
{
public:
    JavaFactory() = default;
    ~JavaFactory() = default;
    UnitPtr createClass(const std::string& name) const override;
    UnitPtr createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) const override;
    UnitPtr createPrintOperator(const std::string& text) const override;
};

#endif // JAVAFACTORY_H
