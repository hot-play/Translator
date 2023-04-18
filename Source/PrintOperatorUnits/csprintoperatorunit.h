#ifndef CSPRINTOPERATORUNIT_H
#define CSPRINTOPERATORUNIT_H

#include<Source/PrintOperatorUnits/printoperatorunit.h>

class CsPrintOperatorUnit : public PrintOperatorUnit {
public:
    explicit CsPrintOperatorUnit(const std::string& text) : m_text(text) { }
    std::string compile( unsigned int level = 0 ) const {
        return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
    }
private:
    std::string m_text;
};

#endif // CSPRINTOPERATORUNIT_H
