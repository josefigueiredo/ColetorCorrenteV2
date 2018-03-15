/*
 * EnviarDados.h
 *
 *  Created on: 14 de mar de 2018
 *      Author: jose
 */
#include "Arduino.h"
#include "DFT.h"
#include "Ambiente.h"

#ifndef LIBS_ENVIARDADOS_H_
#define LIBS_ENVIARDADOS_H_

class EnviarDados {
private:
	DFT _dft;
	Ambiente _amb;
public:
	EnviarDados(DFT *, Ambiente);
	virtual ~EnviarDados();
	void enviar();
};

#endif /* LIBS_ENVIARDADOS_H_ */
