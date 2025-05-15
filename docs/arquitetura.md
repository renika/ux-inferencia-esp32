# Arquitetura - UX Inferência ESP32

## 🧠 Visão Geral

Este documento descreve a arquitetura lógica e física do projeto **UX Inferência ESP32**, cujo objetivo é oferecer uma malha de comunicação local inteligente, baseada em dispositivos de baixo custo (ESP32), com inferência semântica embutida e experiência de usuário invisível.

---

## 📡 Estrutura de Rede

### Malha de Comunicação

- **ESP-NOW:** Utilizado para comunicação entre os dispositivos ESP32 de forma peer-to-peer, com baixa latência e sem necessidade de infraestrutura Wi-Fi.
- **Wi-Fi Local (modo AP):** Utilizado para interação com o usuário (ex: configuração inicial, leitura de dados via browser local).

---

## 🧩 Componentes da Arquitetura

| Componente           | Descrição                                                               |
|----------------------|-------------------------------------------------------------------------|
| **ESP32 - Emissor**  | Envia dados e sinais semânticos (ex: presença, temperatura, evento)     |
| **ESP32 - Inferência**| Recebe dados, aplica regras e decide ações localmente                  |
| **ESP32 - Display/UX**| Interface de saída (ex: LED, buzzer, display e-ink) invisível ou passiva |
| **Gateway (opcional)**| Raspberry Pi ou outro ESP32 conectado à internet para sincronização     |

---

## 🧠 Inferência Local

- Baseada em proposições simples ou encadeadas (Ex: `presenca == true && temperatura > 28`)
- Pode ser embutida no firmware em forma de regras configuráveis
- Permite decisões locais mesmo sem retorno ou resposta da rede

---

## 🔄 Fluxo de Comunicação

```plaintext
[SENSOR] --> [ESP Emissor] --ESP-NOW--> [ESP Inferência] --> [Ação local / UX passiva]
                                                      |
                                                (opcional)
                                                      ↓
                                              [Gateway / Log]
```

---

## 🔒 Segurança

- Comunicação entre ESPs com MAC whitelisting
- Possibilidade de assinatura de pacotes e validação semântica
- Sem dependência de servidores externos

---

## 🎯 Aplicações

- Malhas de sensores distribuídos
- Dispositivos de alerta comunitário
- UX invisível para espaços públicos e escolas
- Malha educacional resiliente (Trafega compatível)

---

## 🌱 Filosofia

A arquitetura prioriza:
- **Simplicidade**
- **Resiliência**
- **Presença**
- **Interpretação local**
- **Inclusão sem dependência**
