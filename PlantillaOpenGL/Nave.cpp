#include "stdafx.h"
#include "Nave.h"



Nave::Nave() {

	angulo = 0.0f;
	
	coordenadas = vec3(0.0f, 0.0f, 0.0f);

	//Establece el valor como una matriz identidad
	transformaciones = mat4(1.0f);

	Vertice v1 = {
		vec4(0.0f, 0.1f, 0.0f, 1.0f),
		vec4(1.0f, 0.0f, 0.0f, 1.0f)
	};

	Vertice v2 = {
		vec4(-0.1f, -0.1f, 0.0f, 1.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v3 = {
		vec4(0.1f, -0.1f, 0.0f, 1.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	vertices.push_back(v1);
	vertices.push_back(v2);
	vertices.push_back(v3);

}

void Nave::rotar(Direccion direccion) {

	float rotacion = velocidadAngular;
	if(direccion == Direccion::Derecha){

		rotacion = -rotacion;
	
	}
	angulo += rotacion;

}

void Nave::avanzar() {
	
	if (velocidad < velocidadMaxima) {
		velocidad += aceleracion * tiempoDiferencial;
	}

	float anguloDesfasado = angulo + 90.0f;

	vec3 traslacion = vec3(
		cos(anguloDesfasado * 3.14159 / 180.0f) * velocidad, //x
		sin(anguloDesfasado * 3.14159 / 180.0f) * velocidad, //y
		0.0f //z
	);

	coordenadas += traslacion;

	actualizarMatrizTransformacion();
		
}


void Nave::actualizarMatrizTransformacion() {
	
	//Partir siempre de una matriz identidad
	transformaciones = mat4(1.0f);
	//Aplicar las transformaciones
	transformaciones = translate(transformaciones, coordenadas);
	transformaciones = rotate(transformaciones, (angulo * 3.14159f / 180.0f), vec3(0.0f, 0.0f, 1.0f));
	

}

void Nave::teletransportar() {

	if (coordenadas.x < -1.1f) {
		coordenadas.x += 2.0f;
	}
	else if (coordenadas.x > 1.1f) {
		coordenadas.x -= 2.0f;
	}

	if (coordenadas.y < -1.1f) {
		coordenadas.y += 2.0f;
	}
	else if (coordenadas.y > 1.1f) {
		coordenadas.y -= 2.0f;

	}
}

void Nave::detener() {

	velocidad -= aceleracion * tiempoDiferencial;
	if (velocidad < 0) {
		velocidad = 0.0f;
	}

	float anguloDesfasado = angulo + 90.0f;

	vec3 traslacion = vec3(
		cos(anguloDesfasado * 3.14159 / 180.0f) * velocidad, //x
		sin(anguloDesfasado * 3.14159 / 180.0f) * velocidad, //y
		0.0f //z
	);

	coordenadas += traslacion;

	actualizarMatrizTransformacion();

}