#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "account.h"



account_t *account_create(
    char *account_id,
    double balance,
    char *user_id
    ) {
    account_t *account_local_var = malloc(sizeof(account_t));
    if (!account_local_var) {
        return NULL;
    }
    account_local_var->account_id = account_id;
    account_local_var->balance = balance;
    account_local_var->user_id = user_id;

    return account_local_var;
}


void account_free(account_t *account) {
    if(NULL == account){
        return ;
    }
    listEntry_t *listEntry;
    if (account->account_id) {
        free(account->account_id);
        account->account_id = NULL;
    }
    if (account->user_id) {
        free(account->user_id);
        account->user_id = NULL;
    }
    free(account);
}

cJSON *account_convertToJSON(account_t *account) {
    cJSON *item = cJSON_CreateObject();

    // account->account_id
    if (!account->account_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "accountId", account->account_id) == NULL) {
    goto fail; //String
    }


    // account->balance
    if (!account->balance) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "balance", account->balance) == NULL) {
    goto fail; //Numeric
    }


    // account->user_id
    if (!account->user_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "userId", account->user_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

account_t *account_parseFromJSON(cJSON *accountJSON){

    account_t *account_local_var = NULL;

    // account->account_id
    cJSON *account_id = cJSON_GetObjectItemCaseSensitive(accountJSON, "accountId");
    if (!account_id) {
        goto end;
    }

    
    if(!cJSON_IsString(account_id))
    {
    goto end; //String
    }

    // account->balance
    cJSON *balance = cJSON_GetObjectItemCaseSensitive(accountJSON, "balance");
    if (!balance) {
        goto end;
    }

    
    if(!cJSON_IsNumber(balance))
    {
    goto end; //Numeric
    }

    // account->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(accountJSON, "userId");
    if (!user_id) {
        goto end;
    }

    
    if(!cJSON_IsString(user_id))
    {
    goto end; //String
    }


    account_local_var = account_create (
        strdup(account_id->valuestring),
        balance->valuedouble,
        strdup(user_id->valuestring)
        );

    return account_local_var;
end:
    return NULL;

}
