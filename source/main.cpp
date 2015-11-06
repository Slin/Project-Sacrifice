#include <iostream>
#include "World.h"

using namespace std;

int main(int argc, char* argv[])
{
	PS::World *world = PS::World::GetInstance();
	world->Loop();
}
