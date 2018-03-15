/*
 * DFT.h
 *
 *  Created on: 12 de dez de 2017
 *      Author: jose
 */
#include <Arduino.h>


#ifndef LIBS_DFT_H_
#define LIBS_DFT_H_

class DFT {
private:
	uint8_t _amostras;
	float *_realX,*_magX,*_imagX,*_phaseX;
	float _piVezes2 = 2 * M_PI;
public:
	DFT(uint8_t);
	DFT();
	virtual ~DFT();
	void calcHarmonicas(float *);
	void calcMagnitude(uint8_t);

	float getImagX(uint8_t );
	float getRealX(uint8_t );
	float getMagX(uint8_t);
};

#endif /* LIBS_DFT_H_ */
