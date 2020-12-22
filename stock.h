#ifndef STOCK_H_INCLUDED
#define STOCK_H_INCLUDED
#include "appconst.h"
#include <stdint.h>


typedef struct _person_share_ PersonShare;

struct _person_share_{
  char sharename[20];
  char date[10];
  float price;
  int32_t quantity;
  
};

typedef struct _transactions_ Transactions;

struct _transactions_{
  char companyname[20];
  char date[10];
  float price;
  int32_t quantity;
  int8_t transactiontype;
  
};


typedef struct _node_ Node;

struct _node_{
  PersonShare data;
  Node *next;
};

typedef struct _tradingq_ TradingQ;

struct _tradingq_{
  Node *rear; 
  Node *front;
  uint32_t length;
};

typedef struct _transactionnode_ TransactionNode;

struct _transactionnode_{
  Transactions data;
  TransactionNode *next;
};

typedef struct _tradingtransactions_ TradingTransactions;

struct _tradingtransactions_{
  TransactionNode *rear; 
  TransactionNode *front;
  uint32_t length;
};



TradingQ tradingq_new();
TradingTransactions tradingtransaction_new(); 
uint32_t tradingq_length(const TradingQ *tradingq);
uint32_t tradingq_lookup(const TradingQ *tradingq, char company_name[20]);
TradingQ* tradingq_addnode_rear(TradingQ *tradingq, TradingTransactions *transactions, PersonShare val, int8_t dequelength);
TradingQ* tradingq_delnode_front(TradingQ *tradingq, TradingTransactions *transactions, int32_t quantity);
TradingQ* tradingq_modify(TradingQ *tradingq, TradingTransactions *transactions, int32_t newshare);
                                              
#endif // STOCK_H_INCLUDED
