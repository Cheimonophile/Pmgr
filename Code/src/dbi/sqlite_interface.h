#ifndef SQLITE_INTERFACE
#define SQLITE_INTERFACE

#include <iostream>
#include <forward_list>
using namespace std;

// namespace
namespace dbi
{
    // structs
    struct Org
    {
        string name;
    };
    struct Val
    {
        string org_name;
        string type;
        string value;
    };

    // functions
    bool create_tables(string& database_path);
    forward_list<Org> get_orgs(string& database_path);
    bool org_exists(string& database_path, string& org_name);
}

#endif