/*
 * global.h
 *
 *  Created on: Aug 23, 2023
 *      Author: User
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define VERSAO_FIRMWARE 1

enum BOOL {
	false,
	true
};

enum OPERACAO {
	OPERACAO_STANDBY,
	OPERACAO_RL1,
	OPERACAO_AGUARDA_RL1,
	OPERACAO_AGUARDA_ENTRE_RELES,
	OPERACAO_RL2
};

#define TEMPO_PULSO 20
#define TEMPO_ENTRE_RELES 50

extern uint8_t
	flagEntradaAcionamento,
	flagEntradaSeguranca,

	flagOperacao;

extern uint8_t
	contadorTempoPulso,
	contadorTempoEntreReles,

	passoOperacao;
#endif /* INC_GLOBAL_H_ */
