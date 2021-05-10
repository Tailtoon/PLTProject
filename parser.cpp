#include "parser.h"
#include <QRegExp>

Parser::Parser()
{

}

Parser::~Parser()
{

}

Parser::grammartype Parser::checkGrammar(QVector<QChar> Vt, QVector<QChar> Vn, QVector<QString> P)
{
    grammartype answer = TYPE3RIGHT;
    QString t = "[", nt = "[", v = "[";
    for (auto item : Vt)
    {
        t += item;
        v += item;
    }
    for (auto item : Vn)
    {
        nt += item;
        v += item;
    }
    t += ']'; nt += ']'; v += ']';

    QRegExp type3right("^" + nt + "->" + "(" + nt + t + "*|" + nt + ")$");
    for (auto item : P)
    {
        if (!(type3right.exactMatch(item)))
            answer = TYPE3LEFT;
    }

    QRegExp type3left("^" + nt + "->" + "(" + t + "*" + nt + "|" + nt + ")$");
    for (auto item : P)
    {
        if (!(type3left.exactMatch(item)))
            answer = TYPE2;
    }

    QRegExp type2("^" + nt + "->" + t + "*$");
    for (auto item : P)
    {
        if (!(type2.exactMatch(item)))
            answer = TYPE1;
    }

    QRegExp type1("^" + v + "+->" + v + "*$");
    for (auto item : P)
    {
        if (!(type1.exactMatch(item)))
            answer = TYPE0;
    }

    return answer;
}
