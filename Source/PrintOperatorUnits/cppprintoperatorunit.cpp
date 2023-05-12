#include "cppprintoperatorunit.h"

CppPrintOperatorUnit::CppPrintOperatorUnit(const std::string &t) {
    text = t;
}

std::string CppPrintOperatorUnit::compile(unsigned int level) const {
    return generateShift( level ) + "printf( \"" + text + "\" );\n";
}
