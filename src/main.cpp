#include <algorithm>
#include <iostream>
#include <math.h>
#include <thread>
#include <chrono>
#include <iterator>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cerrno>
#include <cstring>
#include <dirent.h>
#include <time.h>
#include <unistd.h>

#include "util.h"
#include "constants.h"

using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;
using std::istream_iterator;
using std::stof;

class ProcessParcer
{
    public:
        static string getCmd( string pid );
        static vector<string> getPidList();
        static string getVmSize( string pid );
        static long int getSysUpTime();
        static string getProcUpTime( string pid );
        static string getprocUser( string pid );
        static vector<string> getSysCpuPercent( string coreNumber = "" );
        static float getSysRamPercent();
        static string getSysKernelVersion();
        static int getTotalThreads();
        static int getTotalNumberOfProcesses();
        static int getNumberOfRunningProcesses();
        static int getOsName();
        static string printCpuStats(vector<string> values1, vector<string> values2);
};

string ProcessParcer::getVmSize( string pid )
{
    string line;
    string name = "VM-Data";
    string value;
    float result;

    ifstream stream = Util::getStream( ( Path::basePath() + pid + Path::statusPath() ) );

    while( getline( stream, line ) )
    {
        if( line.compare( 0, name.size(), name ) == 0 )
        {
            istringstream buffer( line );
            istream_iterator<string> begin( buffer ), end;
            vector<string> values( begin, end );

            result = ( stof( values[1] ) / float( 1024 * 1024 ) );

            break;
        }
    }

    return to_string( result );
}

int main()
{
    std::cout<<ProcessParcer::getVmSize("24728")<<std::endl;
}