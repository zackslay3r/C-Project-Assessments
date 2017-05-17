#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

/*
	RUN THE PROJECT TO GENERATE FUNCTIONS
	COPY AND PASTE DIRECTLY INTO YOUR OWN SOLUTION

	CHANGE THE FORMAT BELOW TO SUIT YOUR PROJECT
*/



//names of axes
std::string axes = "xyzw";

//names of vector and dll macro
std::string DLL_MACRO = ""; //if you have DLLs implemented
std::string VECTOR_HEAD = "Vector"; //what your vectors are called before the number eg. |Vector|3 or |Vec|4 or |v|2
std::string VECTOR_END = ""; //any abitirary vector name after the number (before the template) eg. Vector3|T| or vec2|coord|

//template specifications
bool includeTemplate = false; //set this to false if you don't have templates
std::string VECTOR_T_ADD = ""; //template typename with brackers eg. Vector3T|<T>| or vec4T|<real>| or v2coord|<vecType>|, NOTE: """""set to nothing if there are no templates""""
std::string TEMPLATE_MACRO = ""; //if you have templates implemented



/*

EXAMPLE USAGE

std::string DLL_MACRO = "";
std::string VECTOR_HEAD = "vec";
std::string VECTOR_END = "";
std::string VECTOR_T_ADD = "";
std::string TEMPLATE_MACRO = "";
bool includeTemplate = false;
*/



//file streams
std::ofstream cpp2;
std::ofstream cpp3;
std::ofstream cpp4;
std::ofstream h2;
std::ofstream h3;
std::ofstream h4;



//converts a string to upper-case
std::string upper(std::string inp)
{
	std::string b;

	for (int i = 0; i < (int)inp.size(); i++)
	{
		b += toupper(inp[i]);
	}

	return b;
}

//generates .cpp functions
void generateCode(std::ofstream& cpp, int axisAmount, int outputAmount, std::string order)
{
	std::string up = upper(order);

	cpp << "//swizzling" << '\n';

	if (includeTemplate)
	{
		cpp << TEMPLATE_MACRO.c_str() << '\n';
	}

	cpp << VECTOR_HEAD.c_str() << outputAmount << VECTOR_END.c_str() << VECTOR_T_ADD.c_str() << " " << VECTOR_HEAD.c_str() << axisAmount << VECTOR_END.c_str() << VECTOR_T_ADD.c_str() << "::" << "Get" << up.c_str() << "()" << '\n';
	cpp << "{" << '\n';

	std::string b = "";

	//generate bracketed order
	b += "{";

	for (size_t i = 0; i < order.size(); i++)
	{
		b += order[i];

		if (i < order.size() - 1)
		{
			b += ",";
		}
		else
		{
			b += "}";
		}
	}


	cpp << "\t" << "return " << VECTOR_HEAD.c_str() << outputAmount << VECTOR_END.c_str() << VECTOR_T_ADD.c_str() << b.c_str() << ";" << '\n';
	cpp << "}" << '\n';
}

//generates .h declarations with HD comments
void generateHeader(std::ofstream& h, int axisAmount, int outputAmount, std::string order)
{
	std::string up = upper(order);

	h << "/*" << '\n';
	h << "* " << "Get" << up.c_str() << '\n';
	h << "* " << '\n';
	
	std::string b = "";

	//generate bracketed order
	b += "(";

	for (size_t i = 0; i < order.size(); i++)
	{
		b += order[i];

		if (i < order.size() - 1)
		{
			b += ",";
		}
		else
		{
			b += ")";
		}
	}

	h << "* " << "swizzles vector to " << b.c_str() << '\n';
	h << "* " << '\n';
	h << "* " << "@returns " << VECTOR_HEAD.c_str() << outputAmount  << VECTOR_END.c_str() << VECTOR_T_ADD.c_str() << " - the swizzled vector" << '\n';
	h << "*/" << '\n';
	h << DLL_MACRO.c_str() << " " << VECTOR_HEAD.c_str() << outputAmount << VECTOR_END.c_str() << VECTOR_T_ADD.c_str() << " Get" << up.c_str() << "();" << '\n';
}

//2D swizzling generator
void doPermutes2(std::ofstream& cpp, std::ofstream& h, int axis)
{

	for (int x = 0; x < axis; x++)
	{
		for (int y = 0; y < axis; y++)
		{
			if (axis == 2 && x == 0 && y == 1)
			{
				continue;
			}

			std::string b = "";

			b += axes[x];
			b += axes[y];

			generateCode(cpp, axis, 2, b);
			generateHeader(h, axis, 2, b);

			cpp << '\n';
			h << '\n';
		}
	}
}

//3D swizzling generator
void doPermutes3(std::ofstream& cpp, std::ofstream& h, int axis)
{

	for (int x = 0; x < axis; x++)
	{
		for (int y = 0; y < axis; y++)
		{
			for (int z = 0; z < axis; z++)
			{
				if (axis == 3 && x == 0 && y == 1 && z == 2)
				{
					continue;
				}

				std::string b = "";

				b += axes[x];
				b += axes[y];
				b += axes[z];

				generateCode(cpp, axis, 3, b);
				generateHeader(h, axis, 3, b);

				cpp << '\n';
				h << '\n';
			}
		}
	}
}

//4D swizzling generator
void doPermutes4(std::ofstream& cpp, std::ofstream& h, int axis)
{
	for (int x = 0; x < axis; x++)
	{
		for (int y = 0; y < axis; y++)
		{
			for (int z = 0; z < axis; z++)
			{
				for (int w = 0; w < axis; w++)
				{
					if (axis == 4 && x == 0 && y == 1 && z == 2 && w == 3)
					{
						continue;
					}

					std::string b = "";

					b += axes[x];
					b += axes[y];
					b += axes[z];
					b += axes[w];

					generateCode(cpp, axis, 4, b);
					generateHeader(h, axis, 4, b);

					cpp << '\n';
					h << '\n';
				}
			}
		}
	}
}

int main()
{
	
	//files are stored in the project dir
	cpp2.open("cpp2.txt");
	cpp3.open("cpp3.txt");
	cpp4.open("cpp4.txt");

	h2.open("h2.txt");
	h3.open("h3.txt");
	h4.open("h4.txt");

	//all the functions
	doPermutes2(cpp2, h2, 2);
	doPermutes2(cpp3, h3, 3);
	doPermutes2(cpp4, h4, 4);

	doPermutes3(cpp2, h2, 2);
	doPermutes3(cpp3, h3, 3);
	doPermutes3(cpp4, h4, 4);

	doPermutes4(cpp2, h2, 2);
	doPermutes4(cpp3, h3, 3);
	doPermutes4(cpp4, h4, 4);

	return 0;
}