#include "../IObject.h"

int main(int,char**)
{
	IObject a;
	IObject b(&a);

	IObject * c = new IObject(&b);
	IObject * d = new IObject(&b);

	delete d;
	
	std::cout <<"Unrelease Pointer C : " << c << std::endl;
	return 0;
}
