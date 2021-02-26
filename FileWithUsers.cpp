#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user) {

    CMarkup xmlFile;
    bool fileExists = xmlFile.Load(getFileName());

    if (!fileExists)
    {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("users");
    }

    xmlFile.FindElem();
    xmlFile.IntoElem();
    xmlFile.AddElem("user");
    xmlFile.IntoElem();
    xmlFile.AddElem("userId", user.getUserId());
    xmlFile.AddElem("login", user.getLogin());
    xmlFile.AddElem("password", user.getPassword());
    xmlFile.AddElem("name", user.getName());
    xmlFile.AddElem("surname", user.getSurname());

    xmlFile.Save(getFileName());

}

vector <User> FileWithUsers::loadUsersFromFile() {
    User user;
    vector <User> users;

    CMarkup xmlFile;
    xmlFile.Load(getFileName());

    xmlFile.FindElem();
    while ( xmlFile.FindChildElem("user") )
    {
        xmlFile.IntoElem();
        xmlFile.FindChildElem( "userId" );
        user.setUserId(AuxiliaryMethods::convertStringToInt(xmlFile.GetChildData()));
        xmlFile.FindChildElem( "login" );
        user.setLogin(xmlFile.GetChildData());
        xmlFile.FindChildElem( "password" );
        user.setPassword(xmlFile.GetChildData());
        xmlFile.FindChildElem( "name" );
        user.setName(xmlFile.GetChildData());
        xmlFile.FindChildElem( "surname" );
        user.setSurname(xmlFile.GetChildData());
        xmlFile.OutOfElem();
        users.push_back(user);
    }

    return users;
}
