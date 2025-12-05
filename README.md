# Ecu251128-02
Projeto Automasensor: Ecu251128-02

# Entradas Digitais
IN1: Entrada Segurança <br>
IN2: Entrada Acionamento <br>

# Escopo
Projeto feito com a placa ECU-GPS V1 <br>
A placa realiza a leitura do acionamento somente quando a entrada segurança está ativada <br>
Quando a entrada acionamento liga (retenção), a placa deve acionar o relé 1 por 2s e então desligar, após isso, aguardar 5s e então acionar o relé 2 em retenção. <br>
Ao sair o sinal do acionamento desliga tudo. <br>
Acionando novamente retoma o processo. <br>
Caso o sinal da segurança desligue no meio do processo desliga e reinicia tudo, porém para acionar novamente o sinal do acionamento deve desligar e ligar novamente <br>
<br>
O led D5 (verde) ascende quando está em operação (processo dos relés ativado). <br>
O led D6 (amarelo) pisca em meio hertz, indicando cpu rodando. <br>
