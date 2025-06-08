#include <iostream>

#include <GLFW/glfw3.h>

#include "object.h"

using namespace std;

static void print(const char* text)
{
	cout << text << endl;
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(void)
{
	if (!glfwInit())
	{
		print("Failed to initialize glfw");
		return 1;
	}

	GLFWwindow* window = nullptr;

	window = glfwCreateWindow(640, 480, "Pong", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwSetKeyCallback(window, key_callback);

	glfwMakeContextCurrent(window);

	Rect bar_left({.050f, .40f}, {-.95f, 0.f});
	Rect bar_right({ .050f, .40f }, { .95f, 0.f });
	Circle ball(.05f, { 0.f, 0.f });

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		for (int i = 0; i < object_index; ++i) {
			if (!object_array[i])
			{
				cout << "INVALID OBJECT DETECTED" << endl;
				return 1;
			}
			object_array[i]->draw();
		}

		// rendering draws on back buffer
		// so when we call swap buffers we take
		// the actual screen buffer and replace
		// it with our back buffer
		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}