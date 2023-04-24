#ifndef CSCLASSUNIT_H
#define CSCLASSUNIT_H

#include<Source/ClassUnits/classunit.h>

class CsClassUnit : public ClassUnit
{
public:
    explicit CsClassUnit(const std::string& name);
    void add(const UnitPtr& unit, Flags flags) override;
    std::string compile(unsigned int level = 0) const override;
};

#endif // CSCLASSUNIT_H
