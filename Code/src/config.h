#ifndef CONFIG
#define CONFIG

#include <iostream>
using namespace std;

class Config {
    string config_path;
    string database_path;
public:
    Config(string& config_dir);
    void configure();
    void save_configs();
    string& peek_database_path();
};

#endif