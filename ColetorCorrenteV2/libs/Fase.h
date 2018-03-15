/*
 * Fase.h
 *
 *  Created on: 1 de mar de 2018
 *      Author: jose
 */
#include <Arduino.h>
#include "Sensor.h"
#include "Ambiente.h"
#include "EnviarDados.h"
#include "DFT.h"


#ifndef LIBS_FASE_H_
#define LIBS_FASE_H_

class Fase {
private:
	Sensor *_corrente;
	Sensor *_tensao;
	Ambiente _amb;
	uint8_t _nAmostras,_nHarmonicas;
	boolean _dbg;

	float *_valsTensao,*_valsCorrente;
	uint16_t _periodo,_intervalo;

public:
	Fase(Sensor *, Sensor *, Ambiente, boolean);
	virtual ~Fase();
	void processar();
	void coletar();
	void mostrarColetas();
	void enviarDados(DFT);
};

#endif /* LIBS_FASE_H_ */
