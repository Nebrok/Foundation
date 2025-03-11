#include <iostream>
#include "ownLib\LibraryInclude.h"
#include "NeuralNetworkTest\NeuralNetwork.h"

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

	NeuralNetwork testNetwork(4, 6, 10, 0.5);

	KTools::Matrix<double> testInput(4, 1);
	testInput.SetAll(1.4);

	testNetwork.Query(testInput);

	testNetwork.PrintNetwork();

	return 0;
}