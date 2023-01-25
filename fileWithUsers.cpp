#include "FileWithUsers.h"

void FileWithUsers::writeUserToFile(User user) {

    CMarkup xml;
    bool fileExists = xml.Load("Users.xml");
    if(!fileExists) {
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("userId", user.getUserId());
    xml.AddElem("login", user.getLogin());
    xml.AddElem("password", user.getPassword());
    xml.AddElem("name", user.getName());
    xml.AddElem("surname", user.getSurname());

    xml.Save("Users.xml");
}

vector <User> FileWithUsers::loadAllUsersFromFile() {

    vector <User> users;
    CMarkup xml;
    xml.Load("Users.xml");
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("User")) {
        User tempUser;

        xml.IntoElem();

        xml.FindElem();
        tempUser.setUserId(stoi(xml.GetData()));

        xml.FindElem();
        tempUser.setLogin(xml.GetData());

        xml.FindElem();
        tempUser.setPassword(xml.GetData());

        xml.FindElem();
        tempUser.setName(xml.GetData());

        xml.FindElem();
        tempUser.setSurname(xml.GetData());

        xml.OutOfElem();

        users.push_back(tempUser);
    }

    return users;
}

void FileWithUsers::writeAllUsersIntoFile(vector <User> users) {

    system("pause");
    CMarkup xml;
    xml.AddElem("Users");
    xml.IntoElem();

    for (int i = 0; i < users.size(); i++) {
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem("userId", users[i].getUserId());
        xml.AddElem("login", users[i].getLogin());
        xml.AddElem("password", users[i].getPassword());
        xml.AddElem("name", users[i].getName());
        xml.AddElem("surname", users[i].getSurname());
        xml.OutOfElem();
    }

    xml.Save("users.xml");
}

