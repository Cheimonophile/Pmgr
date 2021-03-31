
// includes
#include <iostream>
#include <filesystem>
#include <sqlite3.h>


// main method
int main(int argc, char* argv[]) {

    // get environment variables
    std::string home_dir;
    std::string config_dir;
    std::string config_path;
    try {
        home_dir = std::getenv("HOME");
        config_dir = home_dir + "/.config/passmgr";
        config_path = config_dir + "/passmgr.config";
    }
    catch (const std::exception& e){
        std::cout << e.what() << std::endl;
        return 0;
    }

    // make the directory
    system(("mkdir -p " + config_dir).c_str());

    



    std::cout << config_path << "\n";
    // exit code zero
    std::cout << "Done!\n";
    return 0;
}