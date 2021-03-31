
#include <iostream>
#include <fstream>
#include "config.h"
#include "util.h"

using namespace std;

/**
 * Constructor forConfig
 * 
 * Takes a string to the path of the config.
 */
Config::Config(string& config_dir) {

    // assign config path
    this->config_path = config_dir + "/passmgr.config";

    // init other fields
    this->database_path = config_dir + "/passwords.sqlite";
}

/**
 * This method reads the configuration file and 
 * configures the configure class.
 */
void Config::configure() {

    // create the document if it doesn't exist
    ofstream create;
    create.open(this->config_path, ios::app);
    create.close();
    
    // read the config file
    ifstream config_file;
    config_file.open(this->config_path);

    // iterate over every line of the config file
    string line;
    while(getline(config_file, line)) {
        

        // get the config's name and value
        string config_name = breakoff(line);
        string config_value = breakoff(line);

        // make sure config_value isn't nothing
        if(config_value != "" && config_name != "") {
            // if the config name is database-path, set this->database_path
            if(config_name == "database-path:") {
                this->database_path = config_value;
            }
        }
    }

    // close the config file
    config_file.close();

    // write to the config file
    this->save_configs();
}

/**
 * Saves the current state of the configurations
 * to the config file.
 */
void Config::save_configs() {

    // open the ofstream
    ofstream config_file;
    config_file.open(this->config_path,ios::out);

    // write the database path to the config file
    config_file << "database-path: " << this->database_path << endl;

    // close the config file
    config_file.close();
}