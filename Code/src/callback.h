#ifndef CALLBACK
#define CALLBACK

#include <iostream>
using namespace std;

namespace dbi
{
    int get_orgs_cb(void* data, int num_columns, char** values, char** column_names);
}


#endif