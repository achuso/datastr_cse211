#include <iostream>
#include <stdlib.h> 
#include "bank.h"
using namespace std;


int main()
{

	Bank bank211;
	
	bank211.add(30,1);
	bank211.add(20,1);
	bank211.add(25,1);
	bank211.add(35,1);
	bank211.add(40,2);
	cout<<bank211.serveNext()<<" is served\n";
	bank211.add(65,2);
	bank211.add(24,2);
	bank211.serveAll();

}
