String readData;

void setup()
{
    Serial.begin(9600);
    pinMode(13, OUTPUT);
    Serial.print("initializing...");
}

void loop()
{
    while(!Serial.available()){}
    // wait until serial com detected 
    while(Serial.available()){
        if (Serial.available() > 0)
        {
            delay(30); 
            char data = Serial.read();
            readData = readData + data;
        }
    }

    if(readData.length() > 0){
        if(readData == "up"){
          digitalWrite(13, HIGH);
        }
        
        if(readData == "low"){
          digitalWrite(13, LOW);
        }
        readData = ""; // empty contained data
    }
}

