//
//  FightSimulatorHeader.h
//  FightSimulatorLib
//
//  Created by 中 青宝 on 12-12-5.
//
//

#ifndef FightSimulatorLib_FightSimulatorHeader_h
#define FightSimulatorLib_FightSimulatorHeader_h

#include "stdio.h"
#include <vector>

typedef unsigned int FSRoleId;
typedef unsigned int FSTeamId;
typedef unsigned int FSSkillId;

#define INVALID_FSROLE_ID (0)
#define INVALID_FSTEAM_ID (0)
#define INVALID_FSSKILL_ID (0)

#pragma mark -
#pragma mark fight result define

#define MAX_FSREWARD_PARAM (2)
#define MAX_FSREWARD_AMOUNT (10)

enum
{
    FSRewardInvalid = 0,
    FSRewardCoin,
    FSRewardExp,
    FSRewardWeapon,
    FSRewardStone,
};
typedef int FSRewardType;

typedef struct
{
    FSRewardType rewardType;
    int param[MAX_FSREWARD_PARAM];
} FSReward;

enum
{
    FSResultDraw = 0,
    FSResultWin,
    FSResultLose,
};
typedef int FSResult;

#pragma mark -
#pragma mark role and team

#define MAX_FSSKILL_AMOUNT (5)
#define MAX_FSROLE_AMOUNT (3)

typedef struct
{
    FSRoleId roleId;
    int type;
    int healthPoint;
    
    FSSkillId skillList[MAX_FSSKILL_AMOUNT];
} FSRole;

typedef struct
{
    FSTeamId teamId;
    FSRole roleList[MAX_FSROLE_AMOUNT];
    
    FSResult result;
    FSReward rewardList[MAX_FSREWARD_AMOUNT];
} FSTeam;

typedef std::vector<FSTeam> FSTeamList;

#pragma mark -
#pragma mark Skill data define

#define MAX_FSSKILL_TARGET (3)

typedef struct
{
    FSRoleId targetId;
    int damage;
    bool isDie;
} FSSkillTarget;

typedef struct
{
    FSSkillId skillId;
    FSRoleId sourceRoleId;
    
    FSSkillTarget targetList[MAX_FSSKILL_TARGET];
} FSSkillEffect;

#pragma mark -
#pragma mark Turn data define

// 暂定游戏一个回合就是一个技能的释放
typedef FSSkillEffect FSTurn;

// 回合列表
typedef std::vector<FSTurn> FSTurnList;

#pragma mark -
#pragma mark interface

struct IFightSimulator
{
    virtual void SetTeamList(const FSTeamList &list) = 0;
    virtual const FSTeamList &GetTeamList() = 0;
    
    virtual void SetTurnList(const FSTurnList &list) = 0;
    virtual const FSTurnList &GetTurnList() = 0;
};

extern "C" IFightSimulator* CreateFightSimulator();
extern "C" void DeleteFightSimulator(IFightSimulator* pFightSimulator);

#endif
