//
//  FightSimulator.h
//  FightSimulatorLib
//
//  Created by 中 青宝 on 12-12-5.
//
//

#ifndef __FightSimulatorLib__FightSimulator__
#define __FightSimulatorLib__FightSimulator__

#include <iostream>
#include "FightSimulatorHeader.h"

class FightSimulator : public IFightSimulator
{
public:
    FightSimulator();
    ~FightSimulator();
    
public:
    
    virtual void SetTeamList(const FSTeamList &list);
    virtual const FSTeamList &GetTeamList();
    
    virtual void SetTurnList(const FSTurnList &list);
    virtual const FSTurnList &GetTurnList();
    
private:
    FSTeamList teamList;
    FSTurnList turnList;
};

#endif /* defined(__FightSimulatorLib__FightSimulator__) */
