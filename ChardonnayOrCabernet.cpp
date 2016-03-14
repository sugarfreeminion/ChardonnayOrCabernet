/*************************************************************************
 * Author:          sugarfreeoh
 * Date:            14 March 2016
 * Description:     Write a program that will find the wine name,
 *                  containing all letters.
 *************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream inputFile;

    inputFile.open(argv[1]);
    
    if(inputFile.is_open())
    {
        string line;

        while(getline(inputFile,line))
        {
            size_t delLocation;

            delLocation = line.find('|');

            if(delLocation != string::npos)
            {
                string wines;
                string wineLetters;
                string temp;
                
                vector<string> wine;

                stringstream ss;

                wines = line.substr(0,delLocation-1);
                wineLetters = line.substr(delLocation+2);

                //cout << "Wines: " << wines << endl;
                //cout << "Letters remembered: " << wineLetters << endl;
                
                ss << wines;

                while(getline(ss,temp,' '))
                {
                    string tempWine = temp;

                    size_t letterLocation;

                    bool badWine = false;

                    for(unsigned int index = 0; index < wineLetters.size(); ++index)
                    {
                        //cout << "Search for: " << wineLetters[index] << " inside of: " << tempWine << endl;
                        letterLocation = tempWine.find(wineLetters[index]);
                        //cout << "Found " << wineLetters[index] << " at: " << letterLocation << endl;

                        if(letterLocation != string::npos)
                        {
                            tempWine.erase(letterLocation,1);
                        }
                        else
                        {
                            badWine = true;
                            break;
                        }
                    }

                    //cout << "Temp Wine: " << temp << endl;
                    //cout << "Bad Wine: " << badWine << endl;

                    if(badWine == false)
                    {   
                        wine.push_back(temp);
                    }
                }
                
                if(wine.size() > 0)
                {
                    for(unsigned int index = 0; index < wine.size(); ++index)
                    {
                        if(index < wine.size()-1)
                        {
                            cout << wine[index] << " ";
                        }
                        else
                        {
                            cout << wine[index] << endl;
                        }
                    }    
                }
                else if(wine.size() == 0)
                {
                    cout << "False" << endl;
                }
            }
        }

        inputFile.close();
    }
    else
    {
        cout << "Error opening input file" << endl;
    }

    return 0;
}
