//Luke Miller ljmbm5@umsystem.edu  Lab 5
#include <iostream>
#include <cmath> //http://www.cplusplus.com/reference/clibrary/cmath/
#include <cstdlib> //https://cplusplus.com/reference/cstdlib/
#include <iomanip> //include setprecision, fixed and get_time //https://cplusplus.com/reference/iomanip/?kw=iomanip
#include <limits>
#include <cstring>  // tools for working with character arrays
#include <cctype> // tools for working with strings isalpha(), toupper, etc
#include "lab5fn.h"  
#include <fstream>
#include <vector>
#include<Windows.h>
using namespace std;




double calcDistance(double x1, double x2, double y1, double y2, double z1, double z2) {
	double distance;
	double base = pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(y1 - y2, 2);
	distance = sqrt(base);
	return distance;
}