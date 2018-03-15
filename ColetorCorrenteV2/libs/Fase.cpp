/*
 * Fase.cpp
 *
 *  Created on: 1 de mar de 2018
 *      Author: jose
 */

#include "Fase.h"

Fase::Fase(Sensor *t, Sensor *c, Ambiente amb, boolean dbg) {
	// TODO Auto-generated constructor stub
	_tensao = t;
	_corrente = c;
	_dbg = dbg;

	_amb = amb;

	//intervalo entre uma amostra e outra conforme a frequencia
	_periodo = (_amb.getFreq() == 60) ? 16666 : 20000;
	_intervalo = (_periodo / _nAmostras) - _amb.getEstimadoConversao();
}

Fase::~Fase() {
	// TODO Auto-generated destructor stub
}

void Fase::processar() {
	//instancia um objeto da DFT para execuçãodos cálculos


	_valsTensao = new float[_nAmostras];
	_valsCorrente = new float[_nAmostras];

	coletar();
	mostrarColetas();

	//chamar aqui a dft
	DFT dft(_nAmostras);
	dft.calcHarmonicas(_valsTensao);
	dft.calcMagnitude(_nHarmonicas);

	EnviarDados envio(&dft,_amb);
	envio.enviar();
}


void Fase::mostrarColetas() {
	Serial.println();
	Serial.println("Valores coletados para tensao:");
	for (uint8_t i = 0; i < _nAmostras; i++) {
		Serial.print(_valsTensao[i]);
		Serial.print(";");

	}
	Serial.println();
	Serial.println("Valores coletados para corrente:");
	for (uint8_t i = 0; i < _nAmostras; i++) {
		Serial.print(_valsCorrente[i]);
		Serial.print(";");

	}
}

void Fase::coletar() {
	//coletar valores dos sensores da fase
	for (uint8_t i = 0; i < _nAmostras; i++) {
		_valsTensao[i] = (float) _tensao->getValor() * 5 / 1023;
		_valsCorrente[i] = (float) _corrente->getValor() * 5 / 1023;
		delayMicroseconds(_intervalo);
	}
}


