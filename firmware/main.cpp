#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>

// Identificador do dispositivo
#define DEVICE_NAME "esp_node_01"

// LED para feedback
#define LED_PIN 2

// Estrutura de dados para envio e recebimento
typedef struct struct_message {
  char sender[16];
  char tipo[16];
  char conteudo[128];
} struct_message;

struct_message incomingMessage;

// Callback de recebimento
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&incomingMessage, incomingData, sizeof(incomingMessage));
  Serial.print("Mensagem recebida de: ");
  Serial.println(incomingMessage.sender);
  Serial.print("Tipo: ");
  Serial.println(incomingMessage.tipo);
  Serial.print("Conteúdo: ");
  Serial.println(incomingMessage.conteudo);

  // Lógica de inferência simples
  if (strcmp(incomingMessage.tipo, "comando") == 0) {
    if (strstr(incomingMessage.conteudo, "ligar led")) {
      digitalWrite(LED_PIN, HIGH);
    }
    if (strstr(incomingMessage.conteudo, "desligar led")) {
      digitalWrite(LED_PIN, LOW);
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  if (esp_now_init() != ESP_OK) {
    Serial.println("Erro ao iniciar ESP-NOW");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);
  Serial.println("ESP32 pronto para inferência e escuta semântica.");
}

void loop() {
  // Sem loop ativo. A escuta e inferência são eventos passivos.
}
