#ifndef CPPMETHODUNIT_H
#define CPPMETHODUNIT_H

#include<Source/MethodUnits/methodunit.h>

class CppMethodUnit : public MethodUnit {
public:
    CppMethodUnit(const std::string& name, const std::string& returnType, Flags flags);
    void add(const UnitPtr& unit, Flags flags = 0) override;
    std::string compile( unsigned int level = 0 ) const override;
};

#endif // CPPMETHODUNIT_H
