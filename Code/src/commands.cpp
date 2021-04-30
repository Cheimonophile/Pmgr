#include <iostream>
#include "util.h"
#include "commands.h"
#include "dbi/sqlite_interface.h"

using namespace std;

/**
 * creates an organization in the database
 * 
 * @param database_path the path to the database
 */
void addorg(string& database_path, string& org_name)
{
    // if no org name is supplied
    if(org_name == "")
    {
        throw runtime_error("No organization name provided.");
    }

    // ask if orgname ok
    cout << "Is \"" << org_name << "\" ok? [y|n] ";

    // init response buffer
    string response;

    // make  sure the org name is ok and end function if otherwise
    getline(cin,response);
    response = breakoff(response);
    if(response != "y") return;

    // check if the organization exists
    bool org_exists = dbi::org_exists(database_path, org_name);

    // if the organization exists, print a message and exit
    if(org_exists)
    {
        cout << "Organization \"" << org_name << "\" already exists." << endl;
        return;
    }

    // add the organization
    dbi::add_org(database_path, org_name);
}