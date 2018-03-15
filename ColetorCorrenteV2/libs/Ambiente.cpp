/*
 * Ambiente.cpp
 *
 *  Created on: 8 de mar de 2018
 *      Author: jose
 */

#include "Ambiente.h"
/**
 * Classe ambiente: utilizada para definir valores do ambiente como frequencia,
 * numero de amostras e número de harmonicas
 * @param: frequenciaRede ->> frequncia da rede
 * @param: numeroAmostras ->> amostras a serem coletadas
 * @param: numeroHarmonicas ->> número de harmonicas
 */
Ambiente::Ambiente(uint8_t frequenciaRede, uint8_t numeroAmostras,
		uint8_t numeroHarmonicas) {
	// TODO Auto-generated constructor stub
	_freq = frequenciaRede;
	_nAmostras = numeroAmostras;
	_nHarmonicas = numeroHarmonicas;
	_tEstimadoConversao = 1;
}
Ambiente::Ambiente(){

}


Ambiente::~Ambiente() {
	// TODO Auto-generated destructor stub
}

uint8_t Ambiente::getFreq() const {
	return _freq;
}

uint8_t Ambiente::getAmostras() const {
	return _nAmostras;
}

uint8_t Ambiente::getHarmonicas() const {
	return _nHarmonicas;
}

uint8_t Ambiente::getEstimadoConversao() const {
	return _tEstimadoConversao;
}

void Ambiente::setEstimadoConversao(uint8_t t) {
	_tEstimadoConversao = t;
}

/**
 * Este metodo deve ser utilizado apenas para estimar o tempo de conversão para uma leitura de tensão e uma de corrente
 * para cada fase. Sao duas leituras por fase. Este tempo pode mudar conforme o prescaler do conversor AD for alterado
 * Descarta a primeira leitura de cada canal, executa o número de coletas conf. a quant. de amostras prevsitas e faz o de tempo medio
 * este tempo vai servir de intervalo na leitura regular...
 */
void Ambiente::estimaTempoConversao() {
	//uma leitura para inicializar o conversor AD e descartar o tempo.
	uint16_t valor = analogRead(A0);
	valor = analogRead(A1);

	unsigned long ini = 0, fim = 0;
	//laço para fazer calcular otempo médio
	for (uint8_t i = 0; i < _nAmostras; i++) {
		valor = analogRead(A0);
		valor = analogRead(A1);

		fim += micros();
	}
	setEstimadoConversao((fim - ini) / _nAmostras);
}
