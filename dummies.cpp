//Create Dummy Files to test Rename.cpp
//dummy.cpp

//DISCLAIMER: This is an exe file that deletes any file 
//whose name contains the word "dummy" then creates 
//5 million "dummy ().txt" files to be renamed.

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;


void read_directory(const string& name)
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
      size_t found = str.find("dummy");
      if(found != string::npos)
        DeleteFile(file.cFileName);
    }while(FindNextFile(search_handle, &file) != 0);
    FindClose(search_handle);
  }
}



int main()
{
  //read and delete previous dummy files
  read_directory(".");

  //create new dummy files to be renamed
  int i = 0;
  //NUMBER OF DUMMY FILES
  while(i < 5000000)
  {
    string fileName = "dummy" + to_string(i) + " ().txt";
    HANDLE create_handle = CreateFile(fileName.c_str(),
                                        GENERIC_WRITE,
                                        0,
                                        0,
                                        CREATE_ALWAYS,
                                        FILE_ATTRIBUTE_NORMAL,
                                        0);
    if(create_handle)
    {
      //cout << "CreateFile(" << to_string(i) << ") Succeeded\n";
      CloseHandle(create_handle);
    }
    else
    {
      cerr << "CreateFile(" << to_string(i) << ") Failed: " << GetLastError() << endl;
      exit(-1);
    }

    i = i + 1;
  }

  return 0;
}
