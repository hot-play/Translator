#ifndef CSMETHODUNIT_H
#define CSMETHODUNIT_H

#include<Source/MethodUnits/methodunit.h>

class CsMethodUnit : public MethodUnit {
public:
    CsMethodUnit(const std::string& name, const std::string& returnType, Flags flags) :
        m_name( name ),
        m_returnType( returnType ),
        m_flags( flags ) { }

    void add(const UnitPtr& unit, Flags flags) {
        m_body.push_back(unit);
    }

    std::string compile(unsigned int level = 0) const {
        std::string result = generateShift( level );
        if(m_flags & STATIC) {
            result += "static ";
        } else if(m_flags & VIRTUAL) {
            result += "virtual ";
        }
        result += m_returnType + " ";
        result += m_name + "()";
        if(m_flags & CONST) {
            result += " const";
        }
        result += " {\n";
        for( const auto& b : m_body ) {
            result += b->compile( level + 1 );
        }
        result += generateShift( level ) + "}\n";
        return result;
    }
private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<UnitPtr> m_body;
};

#endif // CSMETHODUNIT_H
