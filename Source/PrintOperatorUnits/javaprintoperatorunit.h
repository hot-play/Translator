#ifndef JAVAPRINTOPERATORUNIT_H
#define JAVAPRINTOPERATORUNIT_H

#include<Source/PrintOperatorUnits/printoperatorunit.h>

class JavaPrintOperatorUnit : public PrintOperatorUnit {
public:
    explicit JavaPrintOperatorUnit(const std::string& text) : m_text(text) { }
    std::string compile(unsigned int level = 0) const {
        return generateShift(level) + "System.out.print( \"" + m_text + "\" )";
    }
private:
    std::string m_text;
};

#endif // JAVAPRINTOPERATORUNIT_H
