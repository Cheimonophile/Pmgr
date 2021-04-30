#include <exception>
#include <iostream>
#include "sqlite/sqlite3.h"
#include "sqlite_interface.h"
#include "forward_list"
#include "callback.h"
using namespace std;
using namespace dbi;



/**
 * create the necessary tables in the database if
 *  they don't already exist
 * 
 * @param database_path the path to the database
 * @return whether or not successful
 */
bool dbi::create_tables(string& database_path) {

    // init the database
    sqlite3* db;

    // connect to the database
    int rc = sqlite3_open(database_path.c_str(),&db);

    // check if the database was successfully connected to
    if(rc) {

        // throw an exception if not successful
        throw runtime_error(sqlite3_errmsg(db));
    }

    // declare the error message
    char* errmsg;

    // create the orgs table
    const char* sql_orgs =
    "CREATE TABLE IF NOT EXISTS orgs("
    "   name TEXT PRIMARY KEY UNIQUE COLLATE NOCASE);";
    rc = sqlite3_exec(db, sql_orgs,nullptr,nullptr,&errmsg);

    // check if there was an error
    if(rc)
    {
        throw runtime_error(errmsg);
        sqlite3_free(errmsg);
    }

    // create the vals table
    const char* sql_vals =
    "CREATE TABLE IF NOT EXISTS vals ("
    "    orgname TEXT,"
    "    type TEXT,"
    "    value TEXT NOT NULL,"
    "    PRIMARY KEY (orgname,type),"
    "    FOREIGN KEY (orgname) REFERENCES orgs(name)"
    ");";
    rc = sqlite3_exec(db, sql_vals,nullptr,nullptr,&errmsg);

    // close the database
    sqlite3_close(db);

    // check if there was an error
    if(rc)
    {
        string msg = errmsg;
        sqlite3_free(errmsg);
        throw runtime_error(msg);
    }

    // return successful
    return true;
}

/**
 * Returns the organizations in the database 
 * 
 */
forward_list<Org> dbi::get_orgs(string& database_path)
{
    // create the orgs list
    forward_list<Org> orgs;

    // open the database
    sqlite3* db;

    // connect to the database
    int errcode = sqlite3_open(database_path.c_str(),&db);

    // check if the database was successfully connected to
    if(errcode) {

        // throw an exception if not successful
        throw runtime_error(sqlite3_errmsg(db));
    }

    // write sql
    string sql = "SELECT * FROM orgs;";

    // execute sql
    char* errmsg = 0;
    errcode = sqlite3_exec(db, sql.c_str(), dbi::get_orgs_cb, (void*)&orgs, &errmsg);

    // close the database
    sqlite3_close(db);

    // report any errors
    if(errcode)
    {
        string msg = errmsg;
        sqlite3_free(errmsg);
        throw runtime_error(msg);
    }

    // return if successful
    return orgs;
}


/**
 * Checks if the organization is in the database
 * 
 * @param database_path the path of the sqlite database file
 * @param org_name the name of the organization
 * 
 * @return whether or not org exists in the database
 */
bool dbi::org_exists(string& database_path, string& org_name)
{
    // create the orgs list
    forward_list<Org> orgs;

    // open the database
    sqlite3* db;

    // connect to the database
    int errcd = sqlite3_open(database_path.c_str(),&db);

    // check if the database was successfully connected to
    if(errcd) {

        // throw an exception if not successful
        throw runtime_error(sqlite3_errmsg(db));
    }

    // write sql
    string sql = "SELECT * FROM orgs WHERE name LIKE '" + org_name + "';";

    // execute sql
    char* errmsg = 0;
    errcd = sqlite3_exec(db, sql.c_str(), get_orgs_cb, (void*)&orgs, &errmsg);

    // close the database
    sqlite3_close(db);

    // report any errors
    if(errcd)
    {
        string msg = errmsg;
        sqlite3_free(errmsg);
        throw runtime_error(msg);
    }

    // return if successful
    return !orgs.empty();
}


/**
 * Adds an organization to the database.
 * 
 * @param database_path the path of the sqlite database file
 * @param org_name the name of the organization
 */
void dbi::add_org(string& database_path, string& org_name)
{
    // open the database
    sqlite3* db;

    // connect to the database
    int errcd = sqlite3_open(database_path.c_str(),&db);

    // check if the database was successfully connected to
    if(errcd) {

        // throw an exception if not successful
        throw runtime_error(sqlite3_errmsg(db));
    }

    // write sql
    string sql = "INSERT INTO orgs VALUES ('" + org_name + "');";

    // execute sql
    char* errmsg = 0;
    errcd = sqlite3_exec(db, sql.c_str(), 0, 0, &errmsg);

    // close the database
    sqlite3_close(db);

    // report any errors
    if(errcd)
    {
        string msg = errmsg;
        sqlite3_free(errmsg);
        throw runtime_error(msg);
    }
}