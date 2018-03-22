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
	_nAmostras = _amb.getAmostras();
	_nHarmonicas = _amb.getHarmonicas();

	//intervalo entre uma amostra e outra conforme a frequencia
	_periodo = (_amb.getFreq() == 60) ? 16666 : 20000;
	_intervalo = (_periodo / _nAmostras) - _amb.getEstimadoConversao();

	_valsTensao = new float[_nAmostras];
	_valsCorrente = new float[_nAmostras];
	_magnitudes = new float[(_nAmostras/ 2)+1];
}

Fase::~Fase() {
	// TODO Auto-generated destructor stub
}

void Fase::processar() {
	EnviarDados enviador(_amb);

	dft(_valsTensao,_magnitudes);
	enviador.enviar(_magnitudes,"tensao");

	dft(_valsCorrente,_magnitudes);
	enviador.enviar(_magnitudes,"corrente");
}

void Fase::dft(float *origem, float *resultados){
	float *_realX = new float[(_nAmostras / 2)+1];
	float *_imagX = new float[(_nAmostras / 2)+1];
	float *_magX = new float[(_nAmostras / 2)+1];
	float *_phaseX = new float[(_nAmostras / 2)+1];
	float _piX2 = 2 * M_PI;

	float accReal = 0.0, accImag = 0.0;

	//aplica a dft gerando dois vetores: Real e Imaginario
	for (int k = 0; k < _nAmostras / 2; k++) {
		for (int i = 0; i < _nAmostras; i++) {
			accReal += origem[i] * cos(_piX2 * k * i / _nAmostras);
			accImag += origem[i] * sin(_piX2 * k * i / _nAmostras);
		}
		if(k == 0){
			_realX[k] = accReal/_nAmostras;
			_imagX[k] = accImag/_nAmostras;
		}else{
			_realX[k] = 2*accReal/_nAmostras;
			_imagX[k] = 2*accImag/_nAmostras;
		}
		accReal = 0;
		accImag = 0;
	}

	_magX[0] = sqrt(_realX[0]*_realX[0]);
	for (int i = 1; i <= _nHarmonicas; i++) {
		_magX[i] = sqrt(_realX[i] *_realX[i] + _imagX[i] *_imagX[i]);
	}
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

