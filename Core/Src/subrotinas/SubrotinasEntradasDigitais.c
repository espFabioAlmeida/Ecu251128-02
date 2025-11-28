///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    SubrotinasEntradasDigitais
//AUTOR:      Fábio Almeida
//CIRADO:     25/04/2024
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "global.h"
/*=============================================================================
LEITURA ENTRADAS DIGITAIS
==============================================================================*/
void entradasDigitais() {
	if(flagEntradaSeguranca) {
		if(debounceInverso(IN1_GPIO_Port, IN1_Pin)) {
			flagEntradaSeguranca = false;
		}
	}
	else {
		if(debounce(IN1_GPIO_Port, IN1_Pin)) {
			flagEntradaSeguranca = true;
		}
	}

	if(flagEntradaSeguranca) {
		if(flagEntradaAcionamento) {
			if(debounceInverso(IN2_GPIO_Port, IN2_Pin)) {
				flagEntradaAcionamento = false;
			}
		}
		else {
			if(debounce(IN2_GPIO_Port, IN2_Pin)) {
				flagEntradaAcionamento = true;
			}
		}

		return;
	}

	flagOperacao = false;
}
/*=============================================================================
FIM DO ARQUIVO
==============================================================================*/
