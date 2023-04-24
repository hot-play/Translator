#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H

#include<Source/unit.h>

class PrintOperatorUnit : public Unit {
public:
    virtual std::string compile(unsigned int level = 0) const = 0;
protected:
    std::string text;
};

#endif // PRINTOPERATORUNIT_H
