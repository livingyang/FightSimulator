//
//  FightSimulatorHeader.h
//  FightSimulatorLib
//
//  Created by 中 青宝 on 12-12-5.
//
//

#ifndef FightSimulatorLib_FightSimulatorHeader_h
#define FightSimulatorLib_FightSimulatorHeader_h

struct ITest
{
    virtual int Add(int num1, int num2) = 0;
};

extern "C" ITest* CreateTest();
extern "C" void DeleteTest(ITest* pTest);


#endif
