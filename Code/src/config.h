#ifndef CONFIG
#define CONFIG

#include <iostream>

class Config {
    std::string config_path;
    std::string database_path;
public:
    Config(std::string& config_dir);
    void configure();
    void save_configs();
};

#endif