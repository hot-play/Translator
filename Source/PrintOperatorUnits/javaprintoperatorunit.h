#ifndef JAVAPRINTOPERATORUNIT_H
#define JAVAPRINTOPERATORUNIT_H

#include<Source/PrintOperatorUnits/printoperatorunit.h>

class JavaPrintOperatorUnit : public PrintOperatorUnit {
public:
    explicit JavaPrintOperatorUnit(const std::string& t) {
        text = t;
    }
    std::string compile(unsigned int level = 0) const override {
        return generateShift(level) + "System.out.print( \"" + text + "\" );\n";
    }
};

#endif // JAVAPRINTOPERATORUNIT_H
