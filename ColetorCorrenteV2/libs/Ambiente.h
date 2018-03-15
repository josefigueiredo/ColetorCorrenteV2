/*
 * Ambiente.h
 *
 *  Created on: 8 de mar de 2018
 *      Author: jose
 */

#include <Arduino.h>

#ifndef LIBS_AMBIENTE_H_
#define LIBS_AMBIENTE_H_

class Ambiente {
private:
	uint8_t _nAmostras;
	uint8_t _nHarmonicas;
	uint8_t _freq;
	uint8_t _tEstimadoConversao;

public:
	Ambiente(uint8_t,uint8_t,uint8_t);
	Ambiente();
	virtual ~Ambiente();

	uint8_t getFreq() const ;
	uint8_t getAmostras() const;
	uint8_t getHarmonicas() const;
	void estimaTempoConversao();
	uint8_t getEstimadoConversao() const;
	void setEstimadoConversao(uint8_t estimadoConversao);
};

#endif /* LIBS_AMBIENTE_H_ */
