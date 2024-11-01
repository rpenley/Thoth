/*
 * order.h
 *
 * 
 */

#ifndef _order_H_
#define _order_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct order_t order_t;


// Enum TYPE for order

typedef enum  { stock_trading_api_order_TYPE_NULL = 0, stock_trading_api_order_TYPE_buy, stock_trading_api_order_TYPE_sell } stock_trading_api_order_TYPE_e;

char* order_type_ToString(stock_trading_api_order_TYPE_e type);

stock_trading_api_order_TYPE_e order_type_FromString(char* type);

// Enum STATUS for order

typedef enum  { stock_trading_api_order_STATUS_NULL = 0, stock_trading_api_order_STATUS_open, stock_trading_api_order_STATUS_filled, stock_trading_api_order_STATUS_canceled } stock_trading_api_order_STATUS_e;

char* order_status_ToString(stock_trading_api_order_STATUS_e status);

stock_trading_api_order_STATUS_e order_status_FromString(char* status);



typedef struct order_t {
    char *order_id; // string
    char *symbol; // string
    double quantity; //numeric
    stock_trading_api_order_TYPE_e type; //enum
    stock_trading_api_order_STATUS_e status; //enum
    char *account_id; // string

} order_t;

order_t *order_create(
    char *order_id,
    char *symbol,
    double quantity,
    stock_trading_api_order_TYPE_e type,
    stock_trading_api_order_STATUS_e status,
    char *account_id
);

void order_free(order_t *order);

order_t *order_parseFromJSON(cJSON *orderJSON);

cJSON *order_convertToJSON(order_t *order);

#endif /* _order_H_ */

