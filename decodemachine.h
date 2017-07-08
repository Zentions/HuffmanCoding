#ifndef DECODEMACHINE_H
#define DECODEMACHINE_H
#include "huffmantree.h"

class DecodeMachine
{
private:
    string text;
    HuffmanTree *tree;
public:
    DecodeMachine();
    void readTree();
    void traverse(TreeNode *);
    void start();
    void decode();
    string readCodeText();
    QString getText(){return QString::fromStdString(text);}
};

#endif // DECODEMACHINE_H
