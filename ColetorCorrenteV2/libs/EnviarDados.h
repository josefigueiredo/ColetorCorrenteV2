/*
 * EnviarDados.h
 *
 *  Created on: 14 de mar de 2018
 *      Author: jose
 */
#include "Arduino.h"
#include "Ambiente.h"

#ifndef LIBS_ENVIARDADOS_H_
#define LIBS_ENVIARDADOS_H_

class EnviarDados {
private:
	Ambiente _amb;
public:
	EnviarDados(Ambiente);
	virtual ~EnviarDados();
	void enviar(float *,String);
};

#endif /* LIBS_ENVIARDADOS_H_ */
