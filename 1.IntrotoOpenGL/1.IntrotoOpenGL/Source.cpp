#include "source\gl_core_4_4.h"
#include <glfw3.h>
#include <iostream>
#define GLM_FORCE_PURE
#include "source/Gizmos.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>
using glm::vec3;
using glm::vec4;
using glm::mat4;

int main() {
	float r = 0.5f;
	float g = 0.5f;
	float b = 0.5f;
	if (glfwInit() == false)
		return -1;
	GLFWwindow* window = glfwCreateWindow(1280, 720,
		"Computer Graphics",
		nullptr, nullptr);
	if (window == nullptr) {
		glfwTerminate();
		return -2;
	}

	glfwMakeContextCurrent(window);
	// the rest of our code goes here!
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED) {
		
		glfwDestroyWindow(window);
		glfwTerminate();
		return -3;
	}
	Gizmos::create();
	mat4 view = glm::lookAt(vec3(10, 15, 20), vec3(0), vec3(0, 1, 0));
	mat4 projection = glm::perspective(glm::pi<float>() * 0.25f,
		16 / 9.f, 0.1f, 1000.f);

	auto major = ogl_GetMajorVersion();
	auto minor = ogl_GetMinorVersion();
	printf("GL: %i.%i\n", major, minor);

	
	

	while (glfwWindowShouldClose(window) == false &&
		glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS) {
		// our game logic and update code goes here!
		// so does our render code!
		
		glClearColor(r, g, b, 1);
		glEnable(GL_DEPTH_TEST);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		/*r += 0.2f;
		g += 0.1f;
		b += 0.3f;
		if (r > 1.0f)
		{
			r = 0.0f;
			g = 0.0f;
			b = 0.0f;
		}*/
		while (glfwWindowShouldClose(window) == false &&
			glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS) {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			Gizmos::clear();
			Gizmos::addTransform(glm::mat4(1));
			vec4 white(1);
			vec4 black(0, 0, 0, 1);
			for (int i = 0; i < 21; ++i) {
				Gizmos::addLine(vec3(-10 + i, 0, 10),
					vec3(-10 + i, 0, -10),
					i == 10 ? white : black);
				Gizmos::addLine(vec3(10, 0, -10 + i),
					vec3(-10, 0, -10 + i),
					i == 10 ? white : black);
			}
			Gizmos::addSphere(vec3(0), 5, 40, 40, vec4(0.8f, 0.8f, 0.f, 1));
			Gizmos::addSphere(vec3(4), 2, 40, 40, vec4(0.0f, 0.0f, 1.0f, 1));
			Gizmos::addSphere(vec3(7), 1, 40, 40, vec4(0.5f, 0.5f, 0.5f, 1));
			Gizmos::draw(projection * view);
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	Gizmos::destroy();
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}


