#ifndef CSCLASSUNIT_H
#define CSCLASSUNIT_H

#include<Source/ClassUnits/classunit.h>

class CsClassUnit : public ClassUnit
{
public:
    explicit CsClassUnit(const std::string& name) : m_name(name) {
        m_fields.resize( ACCESS_MODIFIERS.size());
    }
    void add(const UnitPtr& unit, Flags flags) {

        int accessModifier = PRIVATE;

        if( flags < ACCESS_MODIFIERS.size() ) {
            accessModifier = flags;
        }
        m_fields[ accessModifier ].push_back(unit);
    }
    std::string compile( unsigned int level = 0 ) const {
        std::string result = generateShift(level) + "class " + m_name + " {\n";

        for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
            if (m_fields[ i ].empty()) {
                continue;
            }
            result += ACCESS_MODIFIERS[ i ] + ":\n";
            for( const auto& f : m_fields[ i ] ) {
                result += f->compile( level + 1 );
            }
            result += "\n";
        }
        result += generateShift( level ) + "};\n";
        return result;
    }
private:
    std::string m_name;
    using Fields = std::vector<UnitPtr>;
    std::vector< Fields > m_fields;
};

#endif // CSCLASSUNIT_H
