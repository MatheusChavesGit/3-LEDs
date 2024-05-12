
bool lig_Desl = 0;    // definição das variaveis de liga desliga.
bool estado_LED_verde = 0;  //definição dos estados dos LEDs.
bool estado_LED_amarelo = 0;
bool estado_LED_vermelho = 0;
bool estado_LED_ligado = 0;

//unsigned long debounceDelay = 10;
//unsigned long debounceDelay2 = 100;


enum state {
  desligado,
  LED_verde,
  LED_amarelo,
  LED_vermelho,
  ligado_apagado
};
state estado = desligado;

void setup() {
  // put your setup code here, to run once:
pinMode(0, OUTPUT); //LED vermelho
pinMode(1, OUTPUT); //LED amarelo
pinMode(2, OUTPUT); //LED verde
pinMode(4, INPUT);  //botão vermelho
pinMode(5, INPUT);  //botão amarelo
pinMode(6, INPUT);  //botão branco
pinMode(7, INPUT);  //botão azul
pinMode(3, OUTPUT);  //led ligado

}

void loop() {
  // put your main code here, to run repeatedly:

  switch (estado){
    case desligado:
    //estado tudo apagado e botões dos LEDs não funcionam.
      estado_LED_verde = 0;  //definição dos estados dos LEDs.
      estado_LED_amarelo = 0;
      estado_LED_vermelho = 0;
      estado_LED_ligado = 0;
      digitalWrite(2, estado_LED_verde);
      digitalWrite(1, estado_LED_amarelo);
      digitalWrite(0, estado_LED_vermelho);
      digitalWrite(3, estado_LED_vermelho);
      delay(10);
      if(digitalRead(7) == 0){
      delay(100);
      if(digitalRead(7) == 1){
      
        estado = ligado_apagado;
      }
      }
      break;

    case ligado_apagado:
      //estado aguardando comando de ascender.
      //if(digitalRead(7) == 0){
      estado_LED_verde = 0;  //definição dos estados dos LEDs.
      estado_LED_amarelo = 0;
      estado_LED_vermelho = 0;
      digitalWrite(2, estado_LED_verde);
      digitalWrite(1, estado_LED_amarelo);
      digitalWrite(0, estado_LED_vermelho);
      estado_LED_ligado = 1;
      digitalWrite(3, estado_LED_ligado);
      delay(10);
      if(digitalRead(6) == 1){
        
        estado = LED_verde;
          //estado_LED_verde = 1;
          //digitalWrite(2, estado_LED_verde)
      }
      delay(10);
      if(digitalRead(5) == 1){
      
        estado = LED_amarelo;
          //estado_LED_amarelo = 1;
          //digitalWrite(1, estado_LED_verde)
      }
      delay(10);
      if(digitalRead(4) == 1){
      
        estado = LED_vermelho;
          //estado_LED_vermelho = 1;
          //digitalWrite(0, estado_LED_verde)
      
      }
      delay(10);
      if(digitalRead(7) == 0){
        delay(100);
      if(digitalRead(7) == 1){
        estado = desligado;
      }
      }
      break;

    case  LED_verde:
      estado_LED_verde = 0;  //definição dos estados dos LEDs.
      estado_LED_amarelo = 0;
      estado_LED_vermelho = 0;
      estado_LED_ligado = 0;
      digitalWrite(2, estado_LED_verde);
      digitalWrite(1, estado_LED_amarelo);
      digitalWrite(0, estado_LED_vermelho);
      digitalWrite(3, estado_LED_ligado);
      estado_LED_ligado = 1;
      digitalWrite(3, estado_LED_ligado);
      estado_LED_verde = 1;
      digitalWrite(2, estado_LED_verde);
      //if(digitalRead(6) == 0){
      delay(10);
      if(digitalRead(7) == 1){
        
        estado = desligado;
      }
      delay(10);
      while ((digitalRead(6)) == HIGH){
         delay(10);
      }
      if(digitalRead(5) == 1){
        
        estado = LED_amarelo;
          //estado_LED_amarelo = 1;
          //digitalWrite(1, estado_LED_verde)
      }
      delay(10);
      if(digitalRead(4) == 1){
        
        estado = LED_vermelho;
          //estado_LED_vermelho = 1;
          //digitalWrite(0, estado_LED_verde)
      
      }
      break;

    case  LED_amarelo:
      estado_LED_verde = 0;  //definição dos estados dos LEDs.
      estado_LED_amarelo = 0;
      estado_LED_vermelho = 0;
      estado_LED_ligado = 0;
      digitalWrite(2, estado_LED_verde);
      digitalWrite(1, estado_LED_amarelo);
      digitalWrite(0, estado_LED_vermelho);
      estado_LED_amarelo = 1;
      digitalWrite(3, estado_LED_ligado);
      estado_LED_ligado = 1;
      digitalWrite(3, estado_LED_ligado);
      digitalWrite(1, estado_LED_amarelo);
      //if(digitalRead(5) == 0){
      delay(10);
      if(digitalRead(7) == 1){
        
        estado = desligado;
      }
      delay(10);
      while ((digitalRead(5)) == HIGH){
         delay(10);
      }
      if(digitalRead(6) == 1){
        
        estado = LED_verde;
          //estado_LED_amarelo = 1;
          //digitalWrite(1, estado_LED_verde)
      }
      delay(10);
      if(digitalRead(4) == 1){
        
        estado = LED_vermelho;
          //estado_LED_vermelho = 1;
          //digitalWrite(0, estado_LED_verde)
      
      }
      break;

    case  LED_vermelho:
      estado_LED_verde = 0;  //definição dos estados dos LEDs.
      estado_LED_amarelo = 0;
      estado_LED_vermelho = 0;
      estado_LED_ligado = 0;
      digitalWrite(2, estado_LED_verde);
      digitalWrite(1, estado_LED_amarelo);
      digitalWrite(0, estado_LED_vermelho);
      digitalWrite(3, estado_LED_ligado);
      estado_LED_ligado = 1;
      digitalWrite(3, estado_LED_ligado);
      estado_LED_vermelho = 1;
      digitalWrite(0, estado_LED_vermelho);
      //if(digitalRead(4) == 0){
      delay(10);
      if(digitalRead(7) == 1){
        
        estado = desligado;
      }
      while ((digitalRead(4)) == HIGH){
         delay(10);
      }      
      delay(10);
      if(digitalRead(5) == 1){
        
        estado = LED_amarelo;
          //estado_LED_amarelo = 1;
          //digitalWrite(1, estado_LED_verde)
      }
      delay(10);
      if(digitalRead(6) == 1){
        
        estado = LED_verde;
          //estado_LED_vermelho = 1;
          //digitalWrite(0, estado_LED_verde)
      
      }
      break;   
      }
      }


