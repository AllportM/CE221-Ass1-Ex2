#include "BarController.h"
#include "ReadWords.h"

#include <string>
#include <iostream>

using namespace std;

void createRW(ReadWords *&obj, string &input) // instantiates ReadWord objects
{
  bool validFile = false; // control variable for valid input file string
  while (!validFile)
  {
    getline(cin, input);
    if (input == "quit") exit(1);
    const char *cInput = input.c_str(); // converts string to Cstring
    try
    {
      obj = new ReadWords(cInput);
      validFile = true;
    }
    catch (int e) // catches unable to open filename of given Cstring error
    {
      cout << "Please re-enter the filename, or 'quit' to exit: "; // prompts user
      // to re-input filename, or quit to exit
    }
  }
}

int main()
{
  ReadWords *bigFile = nullptr;
  ReadWords *checkFile = nullptr;
  string anal;
  string check;
  string outF;
	cout << "Please enter filename of the text file to be analysed: ";
  createRW(bigFile, anal);
  cout << "Please enter the name of the file containing search words: ";
  createRW(checkFile, check);
  cout << "Please enter the name of your desired output file: ";
  getline(cin, outF);
  BarController barCont(*bigFile, *checkFile, outF);
  if (!barCont.populateMap())
  {
    cout << "No words found in " << check;
    barCont.closeMemFile();
  }
  else
  {
    if (!barCont.findWords())
    {
		cout << "No matching words found from '"
    	<< check << "' in '" << anal;
    	barCont.closeMemFile();
	}
    else
    {
      barCont.doBar();
    }
  }
}