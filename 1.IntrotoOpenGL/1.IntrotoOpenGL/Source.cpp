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

mat4 projection = glm::perspective(glm::pi<float>() * 0.25f,
	16 / 9.f, 0.1f, 1000.f);
mat4 view = glm::lookAt(vec3(10, 15, 20), vec3(0), vec3(0, 1, 0));

float CurrentTime = glfwGetTime();
float PreviousTime = CurrentTime;
float DeltaTime;

glm::mat4 sun, earth, moon;

float r = 0.5f;
float g = 0.5f;
float b = 0.5f;

GLFWwindow* window;

int start()
{
	if (glfwInit() == false)
		return -1;
	window = glfwCreateWindow(1280, 720,
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

	auto major = ogl_GetMajorVersion();
	auto minor = ogl_GetMinorVersion();
	printf("GL: %i.%i\n", major, minor);

	sun = glm::mat4(1);
	earth = sun * glm::translate(vec3(8, 0, 0));
	moon = earth * glm::translate(vec3(0, 5, 0));
	return 0;
}
bool update()
{
	while (glfwWindowShouldClose(window) == false &&
		glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS) 
	{
		// our game logic and update code goes here!
		// so does our render code!

		glClearColor(r, g, b, 1);
		glEnable(GL_DEPTH_TEST);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Gizmos::clear();
		Gizmos::addTransform(glm::mat4(1));

		vec4 white(1);
		vec4 black(0, 0, 0, 1);

		CurrentTime = glfwGetTime();
		DeltaTime = CurrentTime - PreviousTime;
		PreviousTime = CurrentTime;		

		sun = sun * glm::rotate(glm::radians(100.f) * DeltaTime, vec3(0, 5, 0));
		earth = sun * glm::translate(vec3(8, 0, 0));
		moon = earth * glm::rotate(glm::radians(10.f) * DeltaTime, vec3(0, 8, 0)) * glm::translate(sun, vec3(3, 2, 0));

		for (int i = 0; i < 21; ++i) 
		{
			Gizmos::addLine(vec3(-10 + i, 0, 10),
				vec3(-10 + i, 0, -10),
				i == 10 ? white : black);
			Gizmos::addLine(vec3(10, 0, -10 + i),
				vec3(-10, 0, -10 + i),
				i == 10 ? white : black);
		}

		//printf("%f, %f, %f \n", sun[3].x, sun[3].y, sun[3].z);
		Gizmos::addSphere(vec3(sun[3]), 5, 40, 40, vec4(0.8f, 0.8f, 0.f, 1), &sun);
		Gizmos::addSphere(vec3(earth[3]), 2, 40, 40, vec4(0.0f, 0.0f, 2.0f, 1), &earth);
		Gizmos::addSphere(vec3(moon[3]), 1, 40, 40, vec4(0.5f, 0.5f, 0.5f, 3), &moon);

		Gizmos::draw(projection * view);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	return true;
}
bool quit()
{
	Gizmos::destroy();
	glfwDestroyWindow(window);
	glfwTerminate();
	return true;
}

int main() 
{
	start();
	update();
	quit();

	return 0;
}


