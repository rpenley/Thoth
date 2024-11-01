/*
 * account.h
 *
 * 
 */

#ifndef _account_H_
#define _account_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct account_t account_t;




typedef struct account_t {
    char *account_id; // string
    double balance; //numeric
    char *user_id; // string

} account_t;

account_t *account_create(
    char *account_id,
    double balance,
    char *user_id
);

void account_free(account_t *account);

account_t *account_parseFromJSON(cJSON *accountJSON);

cJSON *account_convertToJSON(account_t *account);

#endif /* _account_H_ */

