#include "callback.h"
#include "sqlite_interface.h"
#include <forward_list>
#include <iostream>

using namespace std;
using namespace dbi;

/**
 * SQLite callback function that puts all of the organizations into a forward list pointed
 * to by data.
 * 
 * @param data the pointer to the linked list
 * @param num_columns the number of columns in the result table
 * @param values a char pointer array of the values in the columns
 * @param names an array of the column names
 * 
 */
int dbi::get_orgs_cb(void* data, int num_columns, char** values, char** column_names)
{
    // cast data to appropriate structure
    forward_list<Org>* orgs = (forward_list<Org>*) data;

    // create the organization
    Org org = {
        values[0]
    };

    // add the org to the list
    orgs->push_front(move(org));

    // return ok
    return 0;
}