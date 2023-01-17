#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>

#include "User.h"
#include "Helpers.h"
#include "Markup.h"

using namespace std;

class FileWithUsers
{
public:
    FileWithUsers(string nameOfFileWithUsers){};
    void writeUserToFile(User user);
    vector <User> loadAllUsersFromFile();
    void writeAllUsersIntoFile(vector <User> users);
};

#endif
