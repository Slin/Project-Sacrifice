#if __APPLE__
#if TARGET_OS_IPHONE
#include <SFML/Main.hpp>
#endif
#endif

#include <iostream>
#include "World.h"

using namespace std;

int main(int argc, char* argv[])
{
	PS::World::GetInstance()->Loop();
	return 0;
}
