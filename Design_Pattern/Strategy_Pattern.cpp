#include<iostream>
#include"Duck.h"
int main(){
	Duck* _Duck;
	Duck* _NDuck;
	std::cout << "Long Fly_Duck\n";
	_Duck = (Duck*)new Long_Fly_Duck("Duck");
	_Duck->D_Fly();
	_Duck->D_Quack();
	delete _Duck;
	std::cout << "\n";

	std::cout << "Short Fly_Duck\n";
	_Duck = (Duck*)new Short_Fly_Duck("Duck");
	_Duck->D_Fly();
	_Duck->D_Quack();
	delete _Duck;
	std::cout << "\n";
	std::cout << "Can not Fly_Duck\n";
	_Duck = (Duck*)new Not_Fly_Duck("Duck");
	_Duck->D_Fly();
	_Duck->D_Quack();
	delete _Duck;
	std::cout << "\n";

	std::cout << "Design pattern ¹ÌÀû¿ë \n";
	std::cout << "Long Fly_Duck\n";
	_NDuck = (Duck*)new NLong_Fly_Duck("Duck");
	_NDuck->D_Fly();
	_NDuck->D_Quack();
	delete _NDuck;
	std::cout << "\n";

	std::cout << "Short Fly_Duck\n";
	_NDuck = (Duck*)new NShort_Fly_Duck("Duck");
	_NDuck->D_Fly();
	_NDuck->D_Quack();
	delete _NDuck;
	std::cout << "\n";

	std::cout << "Can not Fly_Duck\n";
	_NDuck = (Duck*)new NNot_Fly_Duck("Duck");
	_NDuck->D_Fly();
	_NDuck->D_Quack();
	delete _NDuck;
	std::cout << "\n";

}