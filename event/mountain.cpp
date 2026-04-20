#include <iostream>
using namespace std;

void runForestEvent(int eventId, Player &player) {
    
//event 1
    else if (eventId == 1) {
        runBattleGodBlessingEvent(player);
    }

//event 2      
    else if (eventId == 2) {
        runJudgmentEvent(player);
    }

        
//event 3
    else if (eventId == 3) {
        runMerchantEvent(player);
    }


}
