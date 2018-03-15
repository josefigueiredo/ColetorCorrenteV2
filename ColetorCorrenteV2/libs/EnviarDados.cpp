/*
 * EnviarDados.cpp
 *
 *  Created on: 14 de mar de 2018
 *      Author: jose
 */

#include "EnviarDados.h"

EnviarDados::EnviarDados(DFT *d, Ambiente a) {
	// TODO Auto-generated constructor stub
	_dft = d;
	_amb = a;
}

EnviarDados::~EnviarDados() {
	// TODO Auto-generated destructor stub
}

void EnviarDados::enviar(){
	Serial.println("Enviar os valores a seguir:");
	for (int var = 0; var < _amb.getAmostras(); ++var) {
		Serial.print(_dft.getMagX(var));
	}
}

