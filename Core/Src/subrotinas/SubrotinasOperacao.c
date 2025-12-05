///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    SubrotinasOperacao
//AUTOR:      Fábio Almeida
//CIRADO:     25/04/2024
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "global.h"
/*=============================================================================
OPERACAO
==============================================================================*/
void operacao() {
	static uint8_t reentrada = true;

	if(flagOperacao) {
		reentrada = true;
		on(LED_ON_GPIO_Port, LED_ON_Pin);

		switch(passoOperacao) {
			case OPERACAO_RL1:
				on(OUT1_GPIO_Port, OUT1_Pin);
				contadorTempoPulso = 1;
				passoOperacao = OPERACAO_AGUARDA_RL1;
				break;

			case OPERACAO_AGUARDA_RL1:
				on(OUT1_GPIO_Port, OUT1_Pin);
				if(contadorTempoPulso >= TEMPO_PULSO) {
					contadorTempoPulso = 0;
					contadorTempoEntreReles = 1;
					passoOperacao = OPERACAO_AGUARDA_ENTRE_RELES;
					off(OUT1_GPIO_Port, OUT1_Pin);
				}
				break;

			case OPERACAO_AGUARDA_ENTRE_RELES:
				if(contadorTempoEntreReles >= TEMPO_ENTRE_RELES) {
					contadorTempoEntreReles = 0;
					passoOperacao = OPERACAO_RL2;
					on(OUT2_GPIO_Port, OUT2_Pin);
				}
				break;

			case OPERACAO_RL2:
				on(OUT2_GPIO_Port, OUT2_Pin);
				break;
		}

		if(!flagEntradaAcionamento || !flagEntradaSeguranca) {
			flagOperacao = false;
		}

		return;
	}

	off(OUT1_GPIO_Port, OUT1_Pin);
	off(OUT2_GPIO_Port, OUT2_Pin);
	off(LED_ON_GPIO_Port, LED_ON_Pin);

	if(reentrada) {
		if(!flagEntradaAcionamento) {
			reentrada = false;
		}
		return;
	}

	if(flagEntradaAcionamento && flagEntradaSeguranca) {
		flagOperacao = true;
		contadorTempoPulso = 0;
		contadorTempoEntreReles = 0;
		passoOperacao = OPERACAO_RL1;
	}
}
/*=============================================================================
FIM DO ARQUIVO
==============================================================================*/
