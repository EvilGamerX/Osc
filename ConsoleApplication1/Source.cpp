#include <iostream>
#include <string>
#include <time.h>
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
	clock_t t;
	

	(str.compare("Triangle") ? (str.compare("Sine") ? (str.compare("Sawtooth") ? waveform = -1 : waveform = 2) : waveform = 0) : waveform = 1);
	rate = atoi(__argv[2]);
	depth = atoi(__argv[3]);
	cout << str.compare("Triangle") << "|" << str.compare("Sine") << "|" << str.compare("Sawtooth");

	if(waveform != -1 && rate && depth)
	{
		time(&start);
		cout << waveform;
		switch(waveform)
		{
		case 0: while(1)
				{
					time(&now);
					t = clock();
					cout << depth * sin(2 * M_PI * ((float)t / CLOCKS_PER_SEC) * rate) << endl;
				}
				break;
		case 1:while(1)
				{
					time(&now);
					t = clock();
					cout << depth * abs((((float)t / CLOCKS_PER_SEC) * rate) - floor((((float)t / CLOCKS_PER_SEC) * rate) + .5)) << endl;
				}
			   break;
	   case 2:while(1)
				{
					time(&now);
					t = clock();
					cout << ((((float)t / CLOCKS_PER_SEC) * rate) - floor((((float)t / CLOCKS_PER_SEC) * rate) + .5)) * depth << endl;
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