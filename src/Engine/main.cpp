#include <Engine/RenderApplication.hpp>
#include <Meshes/Mesh.hpp>

int main()
{
	RenderApplication app;

	try
	{
		app.run();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}