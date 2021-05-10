#ifndef PARSER_H
#define PARSER_H

#include <QString>
#include <QVector>

class Parser
{
public:
    Parser();
    ~Parser();

    enum grammartype
    {
        TYPE0,
        TYPE1,
        TYPE2,
        TYPE3LEFT,
        TYPE3RIGHT
    };

    Parser::grammartype checkGrammar(QVector<QChar> Vt, QVector<QChar> Vn, QVector<QString> P);
};

#endif // PARSER_H
