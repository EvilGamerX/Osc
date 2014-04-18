#include <iostream>
#include <string>
#include <ctime>
#include <cmath>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int main(int __argc, char** __argv)
{
	if(__argc < 4)
	{
		cout << "Please run with the following perameters: Waveform, rate, depth" <<  endl;
		exit(0);
	}

	int waveform, rate, depth;
	string str(__argv[1]);
	time_t now, start;
	

	(str.compare("Triangle") ? (str.compare("Sine") ? (str.compare("Sawtooth") ? waveform = -1 : waveform = 2) : waveform = 1) : waveform = 0);
	rate = atoi(__argv[2]);
	depth = atoi(__argv[3]);
	cout << str.compare("Triangle") << "|" << str.compare("Sine") << "|" << str.compare("Sawtooth");

	if(waveform != -1 && rate && depth)
	{
		cout <<"1";
		time(&start);
		cout << waveform;
		switch(waveform)
		{
		case 0: while(1)
				{
					time(&now);
					cout << sin(2 * M_PI * difftime(now, start)) << endl;
				}
				break;
		case 1:while(1)
				{
					cout << "  2";
					time(&now);
					cout << abs((now - start) - floor(now - start + .5)) << endl;
				}
			   break;
	   case 2:while(1)
				{
					time(&now);
					cout << (now - start) - floor(now - start + .5) << endl;
				}
			  break;
	   default: cout << "default";
		   break;
		}
	}else
	{
		cout << "GOOFED" << endl;
	}

	cin.ignore();

	return 0;
}