#include "entrypoint.h"
#include "sqlite3.h"
#include "knob.h"

#include <time.h>
#include <stdlib.h>

#define LOG_SQLITE3_ERROR(db) knob_log(KNOB_ERROR, "%s:%d: SQLITE3 ERROR: %s\n", __FILE__, __LINE__, sqlite3_errmsg(db))

void see_state_fruits(sqlite3* db,char* state_name){
    sqlite3_stmt* stmt = NULL;
    char content[] =
    "SELECT fruit,price\n"
    "FROM FruitsForSale\n"
    "WHERE etat=?;";
    int ret = sqlite3_prepare_v2(db,content,-1,&stmt,NULL);

    if(ret != SQLITE_OK){
        LOG_SQLITE3_ERROR(db);
    }

    if(sqlite3_bind_text(stmt,1,state_name,-1,SQLITE_STATIC) != SQLITE_OK){
        LOG_SQLITE3_ERROR(db);
    }

    for(int ret = sqlite3_step(stmt);ret != SQLITE_DONE;ret = sqlite3_step(stmt)){
        if(ret != SQLITE_ROW){
            LOG_SQLITE3_ERROR(db);
        }
        int column = 0;
        const unsigned char* fruit = sqlite3_column_text(stmt,column++);
        float price = sqlite3_column_double(stmt,column);
        knob_log(KNOB_INFO,"Etat %s a le fruit %s avec le prix %.2f$",state_name,fruit,price);
    }

    sqlite3_finalize(stmt);
}
const char* fruits[] = {
    "Banana",
    "Orange",
    "Grape",
    "Pear",
    "Kumqat"
};
const char* states[] = {
    "CA",
    "SC",
    "NC",
    "FL",
    "HA"
};

const char* nomsLieux[] = {
    "Haunted Mines",
    "Dark Forest",
    "Troll Village"
};
const char* descriptionsLieux[] = {
    "Abandonned dwarvish mines, believed to be haunted by their ghosts.",
    "->INSERT FOREST DESCRIPTION HERE",
    "->INSERT VILLAGE DESCRIPTION HERE"
};

void seeDescriLieux(sqlite3 *db, char *name, int numLieu){
    sqlite3_stmt* stmt = NULL;
    char content[] =
    "SELECT descri\n"
    "FROM lieux\n"
    "WHERE access = 1;";
    int ret = sqlite3_prepare_v2(db,content,-1,&stmt,NULL);

    if(ret != SQLITE_OK){
        LOG_SQLITE3_ERROR(db);
    }
    
    int column = 0;
    const unsigned char* n = sqlite3_column_text(stmt,column++);
    
    knob_log(KNOB_INFO,"[DESCRIPTION] %s", n);
    
    sqlite3_finalize(stmt);
}

void raylib_start(void){
    srand(time(NULL));
    sqlite3* db = NULL;
    sqlite3_open("./aventure.db", &db);

    seeDescriLieux(db, "Haunted Mines", 0);
    seeDescriLieux(db, "Dark Forest", 1);
    seeDescriLieux(db, "Troll Village", 2);
    sqlite3_close(db);
    return;
}