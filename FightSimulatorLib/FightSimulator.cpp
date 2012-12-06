//
//  FightSimulator.cpp
//  FightSimulatorLib
//
//  Created by 中 青宝 on 12-12-5.
//
//

#include "FightSimulator.h"

FightSimulator::FightSimulator()
{}

FightSimulator::~FightSimulator()
{}

void FightSimulator::SetTeamList(const FSTeamList &list)
{
    teamList.clear();
    teamList = list;
}

const FSTeamList &FightSimulator::GetTeamList()
{
    return teamList;
}

void FightSimulator::SetTurnList(const FSTurnList &list)
{
    turnList.clear();
    turnList = list;
}

const FSTurnList &FightSimulator::GetTurnList()
{
    return turnList;
}

extern "C" IFightSimulator* CreateFightSimulator()
{
    return new FightSimulator();
}

extern "C" void DeleteFightSimulator(IFightSimulator* pFightSimulator)
{
    delete static_cast<FightSimulator *>(pFightSimulator);
}
