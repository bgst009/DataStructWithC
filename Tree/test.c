//
// Created by bgst on 2020/8/26.
//

#include "test.h"

int main() {
    testBT();

    return 0;
}


void testBT() {
    BiTree Tree;

//    InitBiTree(&Tree);

    CreateBiTree(&Tree);

    PreOrderTravers(Tree);

//    LevelOrderTravers(Tree);

}
