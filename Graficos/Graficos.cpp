// Graficos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"

#include <iostream>
using namespace std;
GLfloat red, green, blue;

//Aqu� est� al cien pa cambiar los valores de las variable de mi programa
void actualizar()
{
	red += 0.001;
	green += 0.002;
	blue += 0.003;

	if (red > 1) red = 0; 
		if (green > 1) green = 0;
	if (blue > 1) blue = 0;


}



void dibujar()
{

}

int main()
{

	//Declaraci�n de ventana.
	GLFWwindow * window;
	//Propiedades de la ventana.
	GLfloat ancho = 1024;
	GLfloat alto = 768;

	//Inicializaci�n de GLFW.
	if (!glfwInit()) 
	{
		//Si no se inici� bien, terminar la ejecuci�n.
		exit(EXIT_FAILURE);
	}

	//Inicializar la ventana.
	window = glfwCreateWindow(ancho, alto, "Gr�ficos", NULL, NULL);
	
	//Verificar si se cre� bien la ventana.
	if (!window)
	{
	//Cerrar todos los procesos de GLFW
		glfwTerminate();
		//Terminar ejecuci�n.
		exit(EXIT_FAILURE);
	}

	//Establecer "window" como contexto.
	glfwMakeContextCurrent(window);

	//Se trae las funciones de OpenGL Moderno.
	glewExperimental = true;

	//Inicializar GLEW
	GLenum glewError = glewInit();

	//Verificar que GLEW se inicializ� bien.
	if (glewError != GLEW_OK)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	const GLubyte *version = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << version << endl;

	red = green = blue = 0.7f;

	//Ciclo de dibujo.
	while (!glfwWindowShouldClose(window))
	{
		//Establecer el area de render (viewport).
		glViewport(0, 0, ancho, alto);
		//Establecer el color con el que se limpia la pantalla.
		glClearColor(red, green, blue, 1);

		//Limpiar la pantalla.
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo.
		actualizar();
		dibujar();

		//Intercambio de buffers.
		glfwSwapBuffers(window);

		//Buscar se�ales de entrada
		glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();



    return 0;
}

