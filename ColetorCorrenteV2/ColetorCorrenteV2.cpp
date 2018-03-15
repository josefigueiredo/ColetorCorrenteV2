#include <Arduino.h>
#include "libs/Sensor.h"
#include "libs/Fase.h"
#include "libs/Ambiente.h"

#define DEBUG true

const uint8_t ps64 = (1 << ADPS2) | (1 << ADPS1) | (0 << ADPS0);
const uint8_t ps128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

Ambiente ambiente(60,64,12);

//definição dos sensores
//sensores de corrente e tensão para FASE 1
Sensor tensao_f1("5.36,5.33,5.35,5.35,5.35,5.36,5.37,5.37,5.38,5.38,5.38,5.39,5.39",
		ambiente, A0);
Sensor corrente_f1("5.36,5.33,5.35,5.35,5.35,5.36,5.37,5.37,5.38,5.38,5.38,5.39,5.39",
		ambiente, A1);
Fase fase1(&tensao_f1,&corrente_f1,ambiente,DEBUG);

//sensores de corrente e tensão para FASE 2
Sensor tensao_f2("5.36,5.33,5.35,5.35,5.35,5.36,5.37,5.37,5.38,5.38,5.38,5.39,5.39",
		ambiente, A2);
Sensor corrente_f2("5.36,5.33,5.35,5.35,5.35,5.36,5.37,5.37,5.38,5.38,5.38,5.39,5.39",
		ambiente, A3);
Fase fase2(&tensao_f2,&corrente_f2,ambiente,DEBUG);

//sensores de corrente e tensão para FASE 3
Sensor tensao_f3("5.36,5.33,5.35,5.35,5.35,5.36,5.37,5.37,5.38,5.38,5.38,5.39,5.39",
		ambiente, A4);
Sensor corrente_f3("5.36,5.33,5.35,5.35,5.35,5.36,5.37,5.37,5.38,5.38,5.38,5.39,5.39",
		ambiente, A5);
Fase fase3(&tensao_f3,&corrente_f3,ambiente,DEBUG);
//fim da definição dos sensores

void setup() {
	//alteração do prescaler do conversor AD
	//ativa prescaler 64
	ADCSRA &= ~ps128;
	ADCSRA |= ps64;

	Serial.begin(9600);

	ambiente.estimaTempoConversao();

	Serial.print("Tempo estimado: ");
	Serial.println(ambiente.getEstimadoConversao());
}

void loop() {
	fase1.processar();
	delay(1000);

	fase2.processar();
	delay(1000);

	fase3.processar();
	delay(1000);

}
