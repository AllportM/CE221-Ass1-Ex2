using namespace std;

#include "BarController.h"
#include "ReadWords.h"
#include <string>
#include <fstream>
#include <unordered_map>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cmath>

BarController::BarController(ReadWords &bigFile, ReadWords &checkWords, string outFname):
outF(outFname), bigWords(&bigFile), checkWords(&checkWords) // uses initialization list
{
}

bool BarController::populateMap() // populates the words to be searched for map
{
  int i = 0;
  while (checkWords->isNextWord())
  {
    string toAdd = checkWords->getNextWord();
    checkMap[toAdd] = 0;
    i++;
  }
  return i > 0 ? true: false; // used to determine if any words have been added
}

bool BarController::findWords() // counts frequency of mapped words in text to be analysed
{
  int i = 0;
  while (bigWords->isNextWord())
  {
    string toAdd = bigWords->getNextWord();
    unordered_map<string, int>::iterator match = checkMap.find(toAdd);
    if (match != checkMap.end())
    {
      match->second++;
    }
    i++;
  }
  return i > 0 ? true: false; // used to determine if any words have been found
}

void BarController::doBar() // outputs the bar chart to file and cli
{
  cout << string(*this);
  outF << string(*this);
  closeMemFile(); // closes files, not really required given files close when scope of
  // object is reached and destructed
}

BarController::operator string() const // overrides string operator
{
  double max = 0;
  for (auto entry: checkMap)
  {
    max = entry.second > max ? entry.second: max; // gets maximum value, for amount of *'s
  }
  stringstream s;
  for (auto entry: checkMap)
  {
    int howMany = (entry.second * 20) / max; // how many stars to add for given entry
    howMany += fmod(entry.second*20, max) > 0? 1: 0; // additional star if not entirely divisible
    s << left << setw(10) << entry.first << setw(howMany + 2) <<
    string(howMany, '*') << entry.second << endl; // formats string output
  }
  return s.str();
}

void BarController::closeMemFile() // closes associated ifstreams of ReadWord objects
{
  bigWords->close();
  checkWords->close();
  if (outF.is_open())
  {
	  outF.close();
  }
  else cout << "Output file already closed";
}

