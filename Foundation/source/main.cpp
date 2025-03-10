#include <iostream>
#include "ownLib\LibraryInclude.h"

#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

class Mesh
{
private:
	KTools::List<KTools::Vector3<int>>* _vertices;
	int _vertexCount;

public:
	Mesh(int width, int height)
		: _vertexCount(0)
	{
		_vertices = new KTools::List<KTools::Vector3<int>>(width * height);
		for (int i = 0; i < height * width; i++) 
		{
			_vertices->Add(KTools::Vector3<int>(1));
		}
		_vertexCount = _vertices->Count();
	}

	~Mesh()
	{
		delete _vertices;
	}

	int GetVertexCount() { return _vertexCount; }

	KTools::List<KTools::Vector3<int>>* GetVertices() { return _vertices; }

	void DotAll(Mesh& otherMesh)
	{
		if (_vertexCount != otherMesh.GetVertexCount())
		{
			std::cout << "Given mesh not of equal Vertex Count.\n";
			return;
		}

		KTools::List<KTools::Vector3<int>>* otherVertices = otherMesh.GetVertices();


		for (int i = 0; i < _vertexCount; i++)
		{
			//(*_vertices)[i].CrossProduct((*otherVertices)[i]);
			(*_vertices)[i].Normalise();
			//(*otherVertices)[i].Normalise();
		}

	}


};


int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	KTools::Timer timer{};

	int size = 5;

	timer.StartClock();
	KTools::Matrix<KTools::List<int>> testMatrix(size, size);
	KTools::List<int> testList(3);
	testList.Add(1);
	testList.Add(1);
	testList.Add(1);
	testMatrix.SetAll(testList);
	std::cout << "Test List main scope pre operation: " << testList.ToString() << "\n";
	std::cout << "Test Matrix stored List pre operation: " << testMatrix.Get(1, 1).ToString() << "\n";
	testList[1] = 2;
	std::cout << "Test List main scope post operation: " << testList.ToString() << "\n";
	std::cout << "Test Matrix stored List post operation: " << testMatrix.Get(1, 1).ToString() << "\n";
	timer.StopClock();


	return 0;
}