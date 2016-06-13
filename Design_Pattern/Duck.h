#pragma once
#include<iostream>
#include<string>

#include"Strategy_Interface.h"
class Duck{
protected:
	std::string name;
	Behavior* _Behavior;
public:
	Duck(std::string _name) { name.insert(0, _name); _Behavior = NULL; }
	virtual void D_Fly() = 0;
	virtual void D_Quack() = 0;
};

class Long_Fly_Duck :Duck{
public:
	Long_Fly_Duck(std::string _name) :Duck(_name){ this->_Behavior = new L_F_QQ(); }
	void D_Fly(){ _Behavior->Fly(); }
	void D_Quack(){ _Behavior->Quack(); }
};
class Short_Fly_Duck :Duck{
public:
	Short_Fly_Duck(std::string _name) :Duck(_name){ this->_Behavior = new S_F_Q(); }
	void D_Fly(){ _Behavior->Fly(); }
	void D_Quack(){ _Behavior->Quack(); }
};
class Not_Fly_Duck :Duck{
public:
	Not_Fly_Duck(std::string _name) :Duck(_name){ this->_Behavior = new N_F_Q(); }
	void D_Fly(){ _Behavior->Fly(); }
	void D_Quack(){ _Behavior->Quack(); }
};

//------------------------------- Design_Pattern ¹ÌÀû¿ë --------------------------------------------------------//
class NDuck{
protected:
	std::string name;
public:
	NDuck(std::string _name) { name.insert(0, _name);}
	virtual void D_Fly() = 0;
	virtual void D_Quack() = 0;
};

class NLong_Fly_Duck :Duck{
public:
	NLong_Fly_Duck(std::string _name) :Duck(_name){ }
	void D_Fly(){ std::cout << "Fly long" << std::endl; }
	void D_Quack(){ std::cout << "Quack Quack" << std::endl; }
};
class NShort_Fly_Duck :Duck{
public:
	NShort_Fly_Duck(std::string _name) :Duck(_name){ }
	void D_Fly(){ std::cout << "Fly Short" << std::endl; }
	void D_Quack(){ std::cout << "Quack" << std::endl; }
};
class NNot_Fly_Duck :Duck{
public:
	NNot_Fly_Duck(std::string _name) :Duck(_name){ }
	void D_Fly(){ std::cout << "Can not Fly " << std::endl; }
	void D_Quack(){ std::cout << "Quack Quack" << std::endl; }
};
