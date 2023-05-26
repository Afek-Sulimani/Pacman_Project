#include "Controller.h"
#include <iostream>
#include "DataManger.h"

int main()
{
	//calling first time to singleton class "Datamanger" c-Tor and load the textures.
	DataManger::instence().LoadObj();   
	DataManger::instence().initDataRow();// initialize the GameBar parameters .
	auto controller = Controller();
	controller.run();
	return 0;
}
