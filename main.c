#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "../Headers/stock.h"


void test(){
    TradingQ q = tradingq_new();
    TradingQ *tradingq = &q;
    PersonShare personshare;
    
    TradingTransactions trans = tradingtransaction_new();
    TradingTransactions *transactions = &trans;
    
    personshare = {"GOOGLE", "22-12-2020", 200.0, 100}; 
    tradingq = tradingq_addnode_rear(tradingq, transactions, personshare, 0);
    
    personshare = {"AMAZON", "2012-2020", 280.0, 160}; 
    tradingq = tradingq_addnode_rear(tradingq, transactions, personshare, 0);
    
    personshare = {"APPLE", "12-12-2020", 100.0, 90}; 
    tradingq = tradingq_addnode_rear(tradingq, transactions, personshare, 0);
    
    personshare = {"SAMSUNG", "12-12-2020", 100.0, 90}; 
    tradingq = tradingq_addnode_rear(tradingq, transactions, personshare, 0);
    
    assert(tradingq_length(tradingq) == 4);
    


int main() {
  test()
  
  return 0;

}
