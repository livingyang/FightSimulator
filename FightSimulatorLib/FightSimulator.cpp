//
//  FightSimulator.cpp
//  FightSimulatorLib
//
//  Created by 中 青宝 on 12-12-5.
//
//

#include "FightSimulator.h"

int Test::Add(int num1, int num2)
{
    return num1 + num2;
}


extern "C" ITest* CreateTest()
{
    return new Test();
}

extern "C" void DeleteTest(ITest* pTest)
{
    delete static_cast<Test *>(pTest);
}
