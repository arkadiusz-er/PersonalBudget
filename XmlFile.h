#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
//#include <fstream>
#include "Markup.h"

using namespace std;

class XmlFile {
    const string FILE_NAME;

public:
    XmlFile(string fileName) : FILE_NAME(fileName) {};

    string getFileName() {
        return FILE_NAME;
    }
/*
    bool checkIfFileIsEmpty() {
        bool emptyFile = true;
        CMarkup xmlFile;
        xmlFile.Load(getFileName().c_str());

        if (xmlFile.good() == true) {
            xmlFile.seekg(0, ios::end);
            if (xmlFile.tellg() != 0)
                emptyFile = false;
        }

        xmlFile.close();
        return emptyFile;
    }
*/
};

#endif
