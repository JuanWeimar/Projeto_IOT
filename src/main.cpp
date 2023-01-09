#include <Arduino.h>

#define LED_AZUL 2

//Firebase Arduino Client Library for ESP8266 and ESP32@
#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>

//Wi-fi
#define WIFI_SSID "pipoca"
#define WIFI_PASSWORD "rafa2011"

//Firebase
#define API_KEY "AIzaSyCXFeh73mT8dmmIGLYpD2SLMfHAPoZPqrg"
#define DATABASE_URL "https://projeto-iot-38e2a-default-rtdb.firebaseio.com/" //a URL deve ser bem formada https://domínio/
//Variáveis globais para manipular o Firebase
FirebaseData fbdo; //Define Firebase Data object
FirebaseAuth auth; //Define Firebase Auth object
FirebaseConfig config; //Define Firebase Config object

//Inicializa o wifi
void wifiSetup(){
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}

//inicializa e authentica no Firebase
void firebaseSetup(){
  
  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  // Assign the user sign in credentials
  auth.user.email = "teste@teste.com";
  auth.user.password = "Teste123";

  // Initialize the library with the Firebase authentication and config
  Firebase.begin(&config, &auth);

  // Optional, set AP reconnection in setup()
  Firebase.reconnectWiFi(true);
}

void setup() {
  // put your setup code here, to run once:
  //inicializando o terminal
  Serial.begin(9600);
  //inicializa o Wifi e o Firebase
  Serial.println();
  Serial.println("Setup Wifi e Firebase");
  wifiSetup();
  firebaseSetup();
  pinMode(LED_AZUL,OUTPUT); //seta o pino 2 do led azul para output
}

//variávais globais para o loop
int count_int = 0;
int count_json = 0;

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  if (Firebase.ready()){
    //Escrevendo e lendo um Inteiro no RTDB
    //Escrevendo com set
    Serial.println("\n\nConectou no firebase");
    
    /*
      Simulação de leituras nós casas no RTDB
    */
    //Lendo um Inteiro no RTDB
    Serial.println("");
    Serial.println("Estado da /casa1/area/lampada");
    //
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa1/area/lampada"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());
    Serial.println("");
    //Liga ou desliga o Led Azul conforme o estado lido no Firebase
    fbdo.to<int>() == 0 
      ? digitalWrite(LED_AZUL,LOW) 
      : digitalWrite(LED_AZUL,HIGH);

    delay(2000);

    Serial.println("Estado da /casa1/banheiro/lampada");
    //
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa1/banheiro/lampada"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());
    Serial.println("");
    //Liga ou desliga o Led Azul conforme o estado lido no Firebase
    fbdo.to<int>() == 0 
      ? digitalWrite(LED_AZUL,LOW) 
      : digitalWrite(LED_AZUL,HIGH);

    delay(2000);

    Serial.println("Estado da /casa1/circulacao/lampada");
    //
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa1/circulacao/lampada"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());
    Serial.println("");
    //Liga ou desliga o Led Azul conforme o estado lido no Firebase
    fbdo.to<int>() == 0 
      ? digitalWrite(LED_AZUL,LOW) 
      : digitalWrite(LED_AZUL,HIGH);

    delay(2000);

    Serial.println("Estado da /casa1/cozinha/lampada");
    //Lendo com get  
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa1/cozinha/lampada"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());
    Serial.println("");
    //Liga ou desliga o Led Azul conforme o estado lido no Firebase
    fbdo.to<int>() == 0 
      ? digitalWrite(LED_AZUL,LOW) 
      : digitalWrite(LED_AZUL,HIGH);
    
    delay(2000);

    Serial.println("Estado da /casa1/cozinha/ar-condicionado");
    //
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa1/cozinha/ar-condicionado"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());
    Serial.println("");
    //Liga ou desliga o Led Azul conforme o estado lido no Firebase
    fbdo.to<int>() == 0 
      ? digitalWrite(LED_AZUL,LOW) 
      : digitalWrite(LED_AZUL,HIGH);

    delay(2000);

    Serial.println("Estado da /casa1/dormitorio1/lampada");
    //
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa1/dormitorio1/lampada"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());
    Serial.println("");
    //Liga ou desliga o Led Azul conforme o estado lido no Firebase
    fbdo.to<int>() == 0 
      ? digitalWrite(LED_AZUL,LOW) 
      : digitalWrite(LED_AZUL,HIGH);

    delay(2000);

    Serial.println("Estado da /casa1/dormitorio1/ar-condicionado");
    //
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa1/dormitorio1/ar-condicionado"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());
    Serial.println("");
    //Liga ou desliga o Led Azul conforme o estado lido no Firebase
    fbdo.to<int>() == 0 
      ? digitalWrite(LED_AZUL,LOW) 
      : digitalWrite(LED_AZUL,HIGH);

    delay(2000);

    Serial.println("Estado da /casa1/dormitorio2/lampada");
    //
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa1/dormitorio2/lampada"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());
    Serial.println("");
    //Liga ou desliga o Led Azul conforme o estado lido no Firebase
    fbdo.to<int>() == 0 
      ? digitalWrite(LED_AZUL,LOW) 
      : digitalWrite(LED_AZUL,HIGH);

    delay(2000);

    Serial.println("Estado da /casa1/dormitorio2/ar-condicionado");
    //
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa1/dormitorio2/ar-condicionado"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());
    Serial.println("");
    //Liga ou desliga o Led Azul conforme o estado lido no Firebase
    fbdo.to<int>() == 0 
      ? digitalWrite(LED_AZUL,LOW) 
      : digitalWrite(LED_AZUL,HIGH);

    delay(2000);

    Serial.println("Estado da /casa1/dormitorio3/lampada");
    //
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa1/dormitorio3/lampada"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());
    Serial.println("");
    //Liga ou desliga o Led Azul conforme o estado lido no Firebase
    fbdo.to<int>() == 0 
      ? digitalWrite(LED_AZUL,LOW) 
      : digitalWrite(LED_AZUL,HIGH);

    delay(2000);

    Serial.println("Estado da /casa1/dormitorio3/ar-condicionado");
    //
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa1/dormitorio3/ar-condicionado"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());
    Serial.println("");
    //Liga ou desliga o Led Azul conforme o estado lido no Firebase
    fbdo.to<int>() == 0 
      ? digitalWrite(LED_AZUL,LOW) 
      : digitalWrite(LED_AZUL,HIGH);

    delay(2000);

    Serial.println("Estado da /casa1/sala-estar/lampada");
    //
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa1/sala-estar/lampada"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());
    Serial.println("");
    //Liga ou desliga o Led Azul conforme o estado lido no Firebase
    fbdo.to<int>() == 0 
      ? digitalWrite(LED_AZUL,LOW) 
      : digitalWrite(LED_AZUL,HIGH);

    delay(2000);

    Serial.println("Estado da /casa1/sala-estar/ar-condicionado");
    //
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa1/sala-estar/ar-condicionado"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());
    Serial.println("");
    //Liga ou desliga o Led Azul conforme o estado lido no Firebase
    fbdo.to<int>() == 0 
      ? digitalWrite(LED_AZUL,LOW) 
      : digitalWrite(LED_AZUL,HIGH);

  }
}