
    String voice;
    int Green  = 8;  
    int Yellow = 9;  
    int Red    = 10;   
     
    void allon()
    {
         
      digitalWrite(Red, HIGH); 
         
      digitalWrite(Yellow, HIGH); 
         
      digitalWrite(Green, HIGH); 
         
    }
    void alloff()
    {
         
      digitalWrite(Red, LOW); 
         
      digitalWrite(Yellow, LOW); 
         
      digitalWrite(Green, LOW); 
                
    }
    void setup() 
    {
      
      Serial.begin(9600);
        
      
        
      pinMode(Red, OUTPUT); 
      
      pinMode(Yellow, OUTPUT); 
      
      pinMode(Green, OUTPUT); 
      
      
    }
    void loop() 
    {
      
      while (Serial.available())     //Check if there is an available byte to read
      {   
        delay(10);                   //Delay added to make thing stable 
      
        char c = Serial.read();      //Conduct a serial read
      
        if (c == '#') 
        {
          break;                     //Exit the loop when the # is detected after the word
        }   
        voice += c; 
     
      }  
      
      if (voice.length() > 0) 
      {
             
        if(voice == "on" || voice == "nit") 
        {
             
          allon();
        }  
        else if(voice == "off" ||voice == "of")
        {
          alloff();
        } 
        else if(voice == "red") 
        {
          digitalWrite(Red,HIGH);
        } 
      
        else if(voice == "yellow") 
        {
          digitalWrite(Yellow,HIGH);
        }
      
        else if(voice == "green") 
        {
          digitalWrite(Green,HIGH);
        }
      
         else if(voice == "off red" ||voice == "of red") 
        {
          digitalWrite(Red,LOW);
        } 
      
        else if(voice == "off yellow"||voice == "of yellow") 
        {
          digitalWrite(Yellow,LOW);
        }
      
        else if(voice == "off green" ||voice == "of green") 
        {
          digitalWrite(Green,LOW);
        }
      
        voice="";            //Reset variable
      }
       }
