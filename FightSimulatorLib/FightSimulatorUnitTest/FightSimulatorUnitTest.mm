//
//  FightSimulatorUnitTest.m
//  FightSimulatorUnitTest
//
//  Created by 中 青宝 on 12-12-5.
//
//

#import "FightSimulatorUnitTest.h"
#import "FightSimulatorHeader.h"

static ITest *pTest = NULL;

@implementation FightSimulatorUnitTest

- (void)setUp
{
    [super setUp];
    
    // Set-up code here.
    pTest = CreateTest();
}

- (void)tearDown
{
    // Tear-down code here.
    DeleteTest(pTest);
    pTest = NULL;
    
    [super tearDown];
}

- (void)testExample
{
    STAssertTrue(1 == 1, @"");
    
    STAssertTrue(pTest->Add(1, 2) == 3, @"");
}

@end
