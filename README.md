# Sistema Inteligente de Correção Postural

## Descrição

O Sistema Inteligente de Correção Postural tem como objetivo monitorar a postura do usuário durante longos períodos sentado, auxiliando na prevenção de dores musculares, fadiga e problemas ergonômicos.

O sistema utiliza um ESP32 conectado a sensores instalados na cadeira para identificar posturas inadequadas. Quando uma postura incorreta é detectada, alertas sonoros e visuais são emitidos ao usuário.

Além disso, os dados coletados podem ser enviados via Wi-Fi para um servidor e armazenados em banco de dados, permitindo o acompanhamento do histórico postural através de uma interface web ou aplicativo móvel.

## Tecnologias Utilizadas

### Hardware

* ESP32
* Sensor de postura (simulado por botão no protótipo)
* LED
* Buzzer
* Resistores

### Software

* Linguagem C/C++
* Arduino IDE
* Comunicação Wi-Fi
* Bluetooth Low Energy (BLE)
* MQTT
* Dashboard Web

## Funcionalidades

* Detecção de postura inadequada
* Alertas sonoros através do buzzer
* Alertas visuais através do LED
* Comunicação via Bluetooth
* Envio de dados pela rede Wi-Fi
* Armazenamento de histórico postural
* Estatísticas de utilização
* Monitoramento remoto

## Arquitetura

Sensores → ESP32 → Wi-Fi/MQTT → Servidor → Banco de Dados → Dashboard

## Segurança

* Comunicação criptografada via TLS
* Acesso autenticado ao sistema
* Proteção de credenciais
* Validação de dados recebidos

## Objetivo

Promover hábitos ergonômicos saudáveis através do monitoramento contínuo da postura e da geração de informações úteis para o usuário.
