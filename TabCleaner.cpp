#include <fstream>
#include <string>

using namespace std;

int main(char* fileName, int tabLen2Set){

    int tabLen = 4;
    string space = "";
    string tab = "\t";

    if (tabLen2Set != 4)
        tabLen = tabLen2Set;

    while (tabLen)
    {
        space += " ";
        tabLen--;
    }

    string line = "";

    ifstream myFile (fileName);

    if (myFile.is_open())
    {
        while ( getline (myFile,line) )
        {
            size_t start_pos = line.find(tab);

            while((start_pos = line.find(tab, start_pos)) != std::string::npos)
            {
                line.replace(start_pos, tab.length(), space);

                start_pos++;
            }
        }

        myFile.close();
    }

    else printf("Unable to open file"); 

    string pause = "";
    scanf("%s", &pause);

    return 0;
}
