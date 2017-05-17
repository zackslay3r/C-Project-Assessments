#include <iostream>

/*
A class definition starts with the keyword class followed by the class name; and the class body, enclosed by a pair of curly braces. 
A class definition must be followed either by a semicolon or a list of declarations.
For example, we defined the Box data type using the keyword class as follows
*/

/*
The keyword public determines the access attributes of the members of the class that follow it.
A public member can be accessed from outside the class anywhere within the scope of the class object.
You can also specify the members of a class as private or protected which we will discuss in a sub-section.
*/

class Box {
public:
	// Variables.
	
	double length;   // Length of a box
	double breadth;  // Breadth of a box
	double height;   // Height of a box



	//Function prototypes. 
	
	// this wil return a double value that recieves void as input
	double getVolume(void);

	// these sets the the value for our box object within the int main.
	void setLength(double len);
	void setBreadth(double bre);
	void setHeight(double hei);

};

// Function definitions
// When doing function definitions, Have the object, followed by '::' and then the name of the function prototpye


double Box::getVolume(void)
{
	return length * breadth * height;
}


// len in the input thats inputted into this function as a parameter.
void Box::setLength(double len)
{
	// sets the length of a box object equal to the parameter.
	length = len;
}

void Box::setBreadth(double bre)
{
	breadth = bre;
}

void Box::setHeight(double hei)
{
	height = hei;
}

double length, breadth, height;

int main() 
{
	
	// This creates a copy of the 'Box' class named Box1
	Box Box1;
	// This creates a copy of the 'Box' class named Box1
	Box Box2;

	//a value to store the volume of the box
	double volume = 0.0;

	
	std::cout << "Please input 3 values for box1";
	// This sets the values of within the box.
	// if you want to assign a value within a 'Box' object. all you have to do is put a dot in front of the object name 
	//followed by with value you'd like to change. 
	// for example
	std::cin >> length;
	std::cin >> breadth;
	std::cin >> height;
	
	Box1.setLength(length);
	Box1.setBreadth(breadth);
	Box1.setHeight(height);


	// sets volume equal to the method listed.
	volume = Box1.getVolume();
	std::cout << "Volume is " << volume << std::endl;

	// and for box 2







	return 0;
}