#ifndef CSPRINTOPERATORUNIT_H
#define CSPRINTOPERATORUNIT_H

#include<Source/PrintOperatorUnits/printoperatorunit.h>

class CsPrintOperatorUnit : public PrintOperatorUnit {
public:
    explicit CsPrintOperatorUnit(const std::string& text);
    std::string compile(unsigned int level = 0) const override;
};

#endif // CSPRINTOPERATORUNIT_H
