//
//  prova.cpp
//  prova
//
//  Created by Diogene Alessandro Dei Tos on 04/03/15.
//  Copyright (c) 2015 Diogene Alessandro Dei Tos. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <math.h>

const static double MY_PI = atan2(0.0,-1.0);  // clever way to define pi
const double convertDegreesToRadians( const double degrees)
{
    return degrees / 180.0 * MY_PI;
}

int main( )
{
    double myDegrees;
    std::cout << "Input the degress you wish to convert" << std::endl;
    std::cin >> myDegrees;
    //std::cout << std::endl;
    const double myRadians = convertDegreesToRadians( myDegrees );
    std::cout << myDegrees << " degrees = " << myRadians
    << " radians" << std::endl;
    return EXIT_SUCCESS;
}
