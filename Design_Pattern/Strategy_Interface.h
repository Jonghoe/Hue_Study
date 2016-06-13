#pragma once
#include<iostream>
class Behavior{
public:
	 virtual void Fly() = 0;
	 virtual void Quack() = 0;
};

class L_F_QQ: public Behavior{
public:
	void Fly(){
		std::cout << "Fly long" << std::endl;
	}
	void Quack(){
		std::cout << "Quack Quack" << std::endl;
	}
};
class S_F_Q : public Behavior{
public:
	void Fly(){
		std::cout << "Fly Short" << std::endl;
	}
	void Quack(){
		std::cout << "Quack" << std::endl;
	}
};
class N_F_Q : public Behavior{
public:
	void Fly(){
		std::cout << "Can not Fly" << std::endl;
	}
	void Quack(){
		std::cout << "Quack" << std::endl;
	}
};