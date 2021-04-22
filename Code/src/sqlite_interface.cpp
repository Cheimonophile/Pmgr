#include "sqlite/sqlite3.h"
#include <exception>
#include <iostream>
using namespace std;


/**
 * create the necessary tables in the database if
 * they don't already exist
 * 
 * @param database_path the path to the database
 * @return whether or not successful
 */
bool create_tables(string& database_path) {

    // init the database
    sqlite3* db;

    // connect to the database
    int rc = sqlite3_open(database_path.c_str(),&db);

    // check if the database was successfully connected to
    if(rc) {

        // throw an exception if not successful
        throw runtime_error(string(sqlite3_errmsg(db)));
    }

    // declare the error message
    char* errmsg;

    // create the orgs table
    const char* sql_orgs =
    "CREATE TABLE IF NOT EXISTS orgs("
    "   id TEXT PRIMARY KEY,"
    "   name TEXT UNIQUE COLLATE NOCASE);";
    rc = sqlite3_exec(db, sql_orgs,nullptr,nullptr,&errmsg);

    // check if there was an error
    if(rc)
    {
        throw string(errmsg);
    }

    // create the vals table
    const char* sql_vals =
    "CREATE TABLE IF NOT EXISTS vals ("
    "    orgid TEXT,"
    "    type TEXT,"
    "    value TEXT,"
    "    PRIMARY KEY (orgid,type),"
    "    FOREIGN KEY (orgid) REFERENCES orgs(id)"
    ");";
    rc = sqlite3_exec(db, sql_vals,nullptr,nullptr,&errmsg);

    // check if there was an error
    if(rc)
    {
        throw string(errmsg);
    }


    // close the database
    sqlite3_close(db);

    // return successful
    return true;
}