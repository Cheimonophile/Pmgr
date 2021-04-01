
// includes
#include <iostream>
#include <filesystem>
#include <sqlite3.h>
#include "util.h"
#include "config.h"

using namespace std;

// main method
int main(int argc, char* argv[]) {

    // get environment variables
    string home_dir;
    string config_dir;
    string config_path;
    try {
        home_dir = getenv("HOME");
        config_dir = home_dir + "/.config/passmgr";
        config_path = config_dir + "/passmgr.config";
    }
    catch (const exception& e){
        cout << e.what() << endl;
        return 0;
    }

    // make the directory
    system(("mkdir -p " + config_dir).c_str());

    // make or read from the configurations file
    Config config(config_dir);
    config.configure();

    
    // mainloop with buffer
    cout << "pmgr> ";
    string buffer;
    string token;
    while(getline(cin,buffer)) {

        // read the first token
        token = breakoff(buffer);

        // if the token is exit or quit
        if(token == "quit" || token == "exit") {
            break;
        }

        // print the next prompt
        cout << "pmgr> ";
    }


    // exit code zero
    cout << "Done!\n";
    return 0;
}