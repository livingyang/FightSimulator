//
//  FightSimulatorUnitTest.m
//  FightSimulatorUnitTest
//
//  Created by 中 青宝 on 12-12-5.
//
//

#import "FightSimulatorUnitTest.h"
#import "FightSimulatorHeader.h"

static IFightSimulator *pFightSimulator = NULL;

@implementation FightSimulatorUnitTest

- (void)setUp
{
    [super setUp];
    
    // Set-up code here.
    pFightSimulator = CreateFightSimulator();
}

- (void)tearDown
{
    // Tear-down code here.
    DeleteFightSimulator(pFightSimulator);
    pFightSimulator = NULL;
    
    [super tearDown];
}

- (void)testSetData
{
    STAssertTrue(pFightSimulator->GetTeamList().size() == 0, @"");
    
    FSTeam team = {};
    FSTeamList teamList;
    teamList.push_back(team);
    
    pFightSimulator->SetTeamList(teamList);
    STAssertTrue(pFightSimulator->GetTeamList().size() == 1, @"");
    
    STAssertTrue(pFightSimulator->GetTurnList().size() == 0, @"");
    
    FSTurn turn = {};
    FSTurnList list;
    list.push_back(turn);
    
    pFightSimulator->SetTurnList(list);
    STAssertTrue(pFightSimulator->GetTurnList().size() == 1, @"");
}

@end
