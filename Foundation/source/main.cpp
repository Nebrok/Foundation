#include <iostream>
#include "ownLib\Array.h"
#include "ownLib\List.h"
#include "ownLib\Vector3.h"

#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

class Mesh
{
private:
	KTools::List<KTools::Vector3<int>*>* _vertices;

public:
	Mesh(int width, int height)
	{
		_vertices = new KTools::List<KTools::Vector3<int>*>(width * height);
		for (int i = 0; i < height * width; i++)
		{
			KTools::Vector3<int>* vector = new KTools::Vector3<int>(1, 1, 1);
			_vertices->Add(vector);
		}
	}

	~Mesh()
	{
		delete _vertices;
	}
};

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Mesh testMesh = Mesh(10, 10);

	return 0;
}