#pragma once

#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Shader.h"
#include "Vertice.h"

#include "Modelo.h"

#include "glm/gtx/transform.hpp"
#include "glm/glm.hpp"


class Nave : public Modelo {

public:

	Nave();
	
	enum Direccion {Izquierda, Derecha, Arriba};

	vec3 coordenadas;

	float angulo; //Angulo triangulo

	float anguloTrayectoria = 0.0f;
	
	float velocidadAngular = 0.5f;
	float velocidad = 0.0f;
	
	float velocidadMaxima = 0.008f;

	float velocidadActual = 0.7f;

	float aceleracion = 0.0004f;
	float desaceleracion = 0.0008f;

	float tiempoAnterior = 0.0f;
	float tiempoActual = 0.0f;
	float tiempoDiferencial = 0.0f;

	

	void rotar(Direccion direccion);

	void avanzar();

	void actualizarMatrizTransformacion();

	void teletransportar();

	void detener();

};
