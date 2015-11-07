#include <iostream>
#include "World.h"

using namespace std;

int main(int argc, char* argv[])
{
	PS::World::GetInstance()->Loop();
}
