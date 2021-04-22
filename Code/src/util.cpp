#include <iostream>

using namespace std;

/**
 * Prints the application's usage notes.
 */
void print_usage() {
    std::cout << "Usage: passmmgr\n";
}


/**
 * breaks the first word in a string off
 *
 * @param string the buffer
 * @param word the first word, quoted or unquoted
 */
std::string breakoff(std::string& string) {

    // gets the string's size
    int length = string.size();

    // creates the word and rest strings
    std::string word;
    std::string rest;

    // checks if the first character is a quote
    if(string[0] == '"') {

        // iterate over the quoted part of the string
        int i = 1;
        while(string[i] != '"') {
            word += string[i];
            i++;
        }

        // skip the quote and the space
        i += 2;

        // put the rest of the string
        while(i < length) {
            rest += string[i];
            i++;
        }
    } else {

        // iterate over the first word in the string
        int i = 0;
        while(i < length && string[i] != ' ') {
            word += string[i];
            i++;
        }

        // skip  the space
        i++;

        // fill the rest of the string
        while(i < length) {
            rest += string[i];
            i++;
        }
    }

    // update the buffer so that is only contains the rest of the string
    string = rest;

    return word;
}

/**
 * creates an organization in the database
 * 
 * @param database_path the path to the database
 * @return whether or not successful
 */
bool addorg(string& database_path, string& org_name)
{
    // check if the organization exists



    return true;
}