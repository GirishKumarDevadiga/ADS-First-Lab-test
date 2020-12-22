#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include "../Headers/stock.h"


void test(){
    TradingQ q = tradingq_new();
    TradingQ *tradingq = &q;
    PersonShare personshare;
    
    TradingTransactions trans = tradingtransaction_new();
    TradingTransactions *transactions = &trans;

    
    strcpy(personshare.sharename, "GOOGLE");
    strcpy(personshare.date, "22-12-2020");
    personshare.price = 200.0;
    personshare.quantity = 100;

    tradingq = tradingq_addnode_rear(tradingq, transactions, personshare, 0, 0);
    
    assert(tradingq_length(tradingq) == 1);
    
    strcpy(personshare.sharename, "AMAZON");
    strcpy(personshare.date, "20-12-2020");
    personshare.price = 100.0;
    personshare.quantity = 100;

    tradingq = tradingq_addnode_rear(tradingq, transactions, personshare, 0, 0);
    
    assert(tradingq_length(tradingq) == 2);
    
    strcpy(personshare.sharename, "APPLE");
    strcpy(personshare.date, "20-12-2020");
    personshare.price = 100.0;
    personshare.quantity = 100;

    tradingq = tradingq_addnode_rear(tradingq, transactions, personshare, 0, 0);
    
    assert(tradingq_length(tradingq) == 3);
    
    assert(tradingq_lookup(tradingq, "APPLE") == 0);
    
    tradingq = tradingq_delnode_front(tradingq, transactions, 100);
    assert(tradingq_length(tradingq) == 2);
 
    
    tradingq = tradingq_delnode_front(tradingq, transactions, 50);
    assert(tradingq_lookup(tradingq, "AMAZON") == 0);


}


int main() {
  test();
  
  return 0;

}
