const int LED = 13;

void setup(){
    Serial.begin(9600);
    pinMode(LED, OUTPUT);
}

void loop(){
    String perintah = "";
    while(Serial.available() >0){
        char karakter = Serial.read();
        perintah = perintah+karakter;

    }
    if (perintah.equals(""))
        return;
    Serial.println(perintah);
    digitalWrite(LED, HIGH);
}

