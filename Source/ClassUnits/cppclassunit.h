#ifndef CPPCLASSUNIT_H
#define CPPCLASSUNIT_H

#include<Source/ClassUnits/classunit.h>

class CppClassUnit : public ClassUnit
{
public:
    explicit CppClassUnit(const std::string& name);
    void add(const UnitPtr& unit, Flags flags) override;
    std::string compile(unsigned int level = 0) const override;
};

#endif // CPPCLASSUNIT_H
