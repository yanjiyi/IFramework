#include "../IObject.h"

int main(int,char**)
{
	IObject a;
	IObject b(&a);
	IObject * d1 = new IObject(&b);
	IObject * c = new IObject(&b);
	IObject * d = new IObject(&b);
	IObject * d2 = new IObject(d);
	delete d;
	
	std::cout <<"Unrelease Pointer C : " << c << std::endl;
	std::cout <<"Unrelease Pointer D1 : " << d1 << std::endl;
	std::cout <<"Unrelease Pointer D2 - D : " << d2 << std::endl;

	return 0;
}
