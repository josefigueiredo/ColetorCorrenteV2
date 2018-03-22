/*
 * EnviarDados.cpp
 *
 *  Created on: 14 de mar de 2018
 *      Author: jose
 */

#include "EnviarDados.h"

EnviarDados::EnviarDados(Ambiente a) {
	// TODO Auto-generated constructor stub
	_amb = a;
}

EnviarDados::~EnviarDados() {
	// TODO Auto-generated destructor stub
}

void EnviarDados::enviar(float *dados, String nome){
	Serial.print("Enviar de: ");
	Serial.println(nome);

	for (int i = 0; i < _amb.getAmostras(); ++i) {
		Serial.print(dados[i]);
		Serial.print(",");
	}
}

