#ifndef CSMETHODUNIT_H
#define CSMETHODUNIT_H

#include<Source/MethodUnits/methodunit.h>

class CsMethodUnit : public MethodUnit {
public:
    CsMethodUnit(const std::string& name, const std::string& returnType, Flags flags);
    void add(const UnitPtr& unit, Flags flags = 0) override;
    std::string compile(unsigned int level = 0) const override;
};

#endif // CSMETHODUNIT_H
