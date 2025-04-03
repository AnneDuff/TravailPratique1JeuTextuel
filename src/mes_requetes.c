#include "mes_requete.h"
#include "entrypoint.h"
#include "sqlite3.h"
#include "knob.h"

#include <time.h>
#include <stdlib.h>

void select_all(sqlite3* db){
    char requete[] = 
    "SELECT *\n"
    "FROM joueurs;";   
}

void print_scenario(void){
    printf("SCENARIO!\n");
}

void tables_creation(){
    char t_lieux[] =
    "CREATE TABLE lieux ("
    "nom TEXT"
    ");";
    char t_objets[] =
    "CREATE TABLE objets ("
    "nom TEXT"
    ");";
    char t_joueurs[] =
    "CREATE TABLE joueurs ("
    "nom TEXT"
    ");";
    char t_NPCs[] =
    "CREATE TABLE NPCs ("
    "nom TEXT"
    ");";
    
}



void create_tables(sqlite3* db){
    sqlite3_stmt* stmt = NULL;
    char tables[] =
    "CREATE TABLE lieux ("
    "nom TEXT"
    ");"
    "CREATE TABLE objets ("
    "nom TEXT"
    ");"
    "CREATE TABLE joueurs ("
    "nom TEXT"
    ");"
    "CREATE TABLE NPCs ("
    "nom TEXT"
    ");";
    int ret = sqlite3_prepare_v2(db,tables,-1,&stmt,NULL);

    // if(ret != SQLITE_OK){
    //     LOG_SQLITE3_ERROR(db);
    // }

    // if(sqlite3_bind_text(stmt,1,"FL",-1,SQLITE_STATIC) != SQLITE_OK){
    //     LOG_SQLITE3_ERROR(db);
    // }

    // for(int ret = sqlite3_step(stmt);ret != SQLITE_DONE;ret = sqlite3_step(stmt)){
    //     if(ret != SQLITE_ROW){
    //         LOG_SQLITE3_ERROR(db);
    //     }
    //     int column = 0;
    //     const unsigned char* fruit = sqlite3_column_text(stmt,column++);
    //     float price = sqlite3_column_double(stmt,column);
    //     knob_log(KNOB_INFO,"Etat %s a le fruit %s avec le prix %.2f$",state_name,fruit,price);
    // }

    sqlite3_finalize(stmt);
}