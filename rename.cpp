//Jay Ofemi
//9/28/17
//
//Rename.cpp
//Renames files in batch in the case a certain portion of the 
//filename must be kept, and retains the file extension.
//ex:
// "dummyFile1 (01/21/2013).txt" --> "dummyFile1.txt"
//// In this case, the program targets any file with the 
//// parenthesis character "()" but that can be changed to any
//// unique identifier.

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;
typedef vector<string> stringVec;


void read_directory(const string& name, stringVec& v)
{
  string pattern(name);
  pattern.append("\\*");
  WIN32_FIND_DATA file;
  HANDLE search_handle = FindFirstFile(pattern.c_str(), &file);
  if(search_handle != INVALID_HANDLE_VALUE)
  {
    do
    {
      string str(file.cFileName);
      //UNIQUE IDENTIFIER
      size_t found = str.find("(");
      if(found != string::npos)
        v.push_back(str.substr(0, str.find(" ", 0)));
    }while(FindNextFile(search_handle, &file) != 0);
    FindClose(search_handle);
  }
}


void rename_directory(const string& name, stringVec& v1, stringVec& v2)
{
  string pattern(name);
  pattern.append("\\*");
  WIN32_FIND_DATA file;
  HANDLE search_handle = FindFirstFile(pattern.c_str(), &file);
  if(search_handle != INVALID_HANDLE_VALUE)
  {
    int count = 0;
    do
    {
      string str(file.cFileName);
      //UNIQUE IDENTIFIER
      size_t found = str.find("(");
      if(found != string::npos)
      {
        const char* fileName = (str.substr(0, str.find(" ", 0))).c_str();
        string ext = str.substr(str.find("."));

        if(strcmp(v1[count].c_str(), fileName))
        {
          string newName = (v1[count] + ext);
          if(rename(file.cFileName, newName.c_str()) == 0)
            count = count + 1;
          else
          {
            cout << "Error! Renaming: " << str << " Failed." << endl;
            exit(-1);
          }
 
        }
        else
        {
          cerr << "Error! File names do not match." << endl;
          exit(-1);
        }
        v2.push_back(file.cFileName); 
      }
    }while(FindNextFile(search_handle, &file) != 0);
    FindClose(search_handle);

    cout << "Number of Files Renamed: " << count << endl;
  }
}


int main()
{
  stringVec v1; //vector containing part of the file name we want
  stringVec v2; //vector containing the files we want to change
  //read the directory and extract part of the file name needed
  read_directory(".", v1);
  //rename the files in the directory to the proper names
  rename_directory(".", v1, v2);

  // //print out v1
  // copy(v1.begin(), v1.end(), ostream_iterator<string>(cout, "\n"));
  // //print out v2
  // copy(v2.begin(), v2.end(), ostream_iterator<string>(cout, "\n"));

  return 0;
}

