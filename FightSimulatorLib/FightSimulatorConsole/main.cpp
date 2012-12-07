//
//  main.cpp
//  FightSimulatorConsole
//
//  Created by 中 青宝 on 12-12-6.
//
//

#ifdef WIN32
#include <windows.h>
#define sleep(time) Sleep(time)
#endif

#include <iostream>
using std::cout;
using std::endl;

#include "FightSimulatorHeader.h"

void printTeam(const FSTeam &team)
{
    cout << "id = " << team.teamId << endl;
    
    for (int i = 0; i < MAX_FSROLE_AMOUNT; ++i)
    {
        FSRole role = team.roleList[i];
        if (role.roleId == INVALID_FSROLE_ID)
        {
            cout << "位置" << i + 1 << "无角色" << endl;
        }
        else
        {
            cout << "位置" << i + 1
            << ",角色id = " << role.roleId
            << ",角色类型 = " << role.type
            << ",生命值 = " << role.healthPoint
            << endl;
        }
    }
}

void printTurn(const FSTurn &turn)
{
    cout << "角色" << turn.sourceRoleId
    << ", 释放技能" << turn.skillId << ":" << endl;
    for (int i = 0; i < MAX_FSSKILL_TARGET; ++i)
    {
        FSSkillTarget target = turn.targetList[i];
        
        if (target.targetId != INVALID_FSROLE_ID)
        {
            cout << "技能" << turn.skillId
            << "对角色" << target.targetId
            << "造成伤害" << target.damage << endl;
            
            if (target.isDie)
            {
                cout << "角色" << target.targetId << "死亡！！" << endl;
            }
        }
    }
}

void printReward(FSReward reward)
{
    switch (reward.rewardType)
    {
        case FSRewardCoin:
        {
            cout << "获得金币" << reward.param[0] << endl;
        }break;
        case FSRewardExp:
        {
            cout << "获得经验" << reward.param[0] << endl;
        }break;
        case FSRewardWeapon:
        {
            cout << "获得\"武器" << reward.param[0] << "\"" << reward.param[1] << "个" << endl;
        }break;
        case FSRewardStone:
        {
            cout << "获得\"魔石" << reward.param[0] << "\"" << reward.param[1] << "个" << endl;
        }break;
        default:
            break;
    }
}

//void printResult(const FSTeam &team)
//{
//    if (<#condition#>) {
//        <#statements#>
//    }
//}

void printFight(IFightSimulator *pFightSimulator)
{
    // 1 打印队伍信息
    for (unsigned int i = 0; i < pFightSimulator->GetTeamList().size(); ++i)
    {
        cout << "\nTeam " << i + 1 << ":" << endl;
        printTeam(pFightSimulator->GetTeamList()[i]);
    }

	sleep(1000);
    
    // 2 打印回合信息
    cout << "\n战斗开始!!" << endl;
    for (unsigned int i = 0; i < pFightSimulator->GetTurnList().size(); ++i)
    {
        printTurn(pFightSimulator->GetTurnList()[i]);
		sleep(1000);
    }
    
    // 3 打印战斗结果
    
    cout << "\n战斗结束" << endl;    for (unsigned int i = 0; i < pFightSimulator->GetTeamList().size(); ++i)
    {
        FSTeam team = pFightSimulator->GetTeamList()[i];
        
        cout << "\nTeam " << i + 1 << ":";
        if (team.result == FSResultWin)
        {
            cout << "胜利!" << endl;
        }
        else if (team.result == FSResultDraw)
        {
            cout << "平局!" << endl;
        }
        else
        {
            cout << "失败!" << endl;
        }
        
        for (int i = 0; i < MAX_FSREWARD_AMOUNT; ++i)
        {
            printReward(team.rewardList[i]);
        }
    }
    
}

int main(int argc, const char * argv[])
{
    IFightSimulator *pFightSimulator = CreateFightSimulator();
    
    // 设置队伍信息
    FSTeamList teamList;
    {
        FSTeam team = {};
        team.teamId = 1;
        team.roleList[0].roleId = 1;
        team.roleList[0].type = 1;
        team.roleList[0].healthPoint = 100;
        team.roleList[0].skillList[0] = 1;
        team.roleList[0].skillList[1] = 2;
        
        team.result = FSResultWin;
        team.rewardList[0].rewardType = FSRewardCoin;
        team.rewardList[0].param[0] = 100;
        team.rewardList[1].rewardType = FSRewardExp;
        team.rewardList[1].param[0] = 200;
        team.rewardList[2].rewardType = FSRewardWeapon;
        team.rewardList[2].param[0] = 10;
        team.rewardList[2].param[1] = 2;
        team.rewardList[3].rewardType = FSRewardStone;
        team.rewardList[3].param[0] = 1;
        team.rewardList[3].param[1] = 10;
        
        teamList.push_back(team);
    }
    
    {
        FSTeam team = {};
        team.teamId = 2;
        team.roleList[0].roleId = 3;
        team.roleList[0].type = 1;
        team.roleList[0].healthPoint = 50;
        team.roleList[0].skillList[0] = 1;
        team.roleList[0].skillList[1] = 2;
        
        team.result = FSResultLose;
        team.rewardList[0].rewardType = FSRewardCoin;
        team.rewardList[0].param[0] = 10;
        team.rewardList[1].rewardType = FSRewardExp;
        team.rewardList[1].param[0] = 20;
        
        teamList.push_back(team);
    }
    
    pFightSimulator->SetTeamList(teamList);
    
    // 设置回合信息
    FSTurnList turnList;
    {
        FSTurn turn = {};
        turn.skillId = 1;
        turn.sourceRoleId = 1;
        turn.targetList[0].targetId = 2;
        turn.targetList[0].damage = 50;
        turn.targetList[0].isDie = true;
        
        turnList.push_back(turn);
    }
    
    pFightSimulator->SetTurnList(turnList);
    
    printFight(pFightSimulator);
    
    DeleteFightSimulator(pFightSimulator);
    
	getchar();
    return 0;
}

