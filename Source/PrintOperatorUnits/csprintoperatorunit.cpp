#include "csprintoperatorunit.h"

CsPrintOperatorUnit::CsPrintOperatorUnit(const std::string &t) {
    text = t;
}

std::string CsPrintOperatorUnit::compile(unsigned int level) const {
    return generateShift( level ) + "Console.WriteLine( \"" + text + "\" );\n";
}
