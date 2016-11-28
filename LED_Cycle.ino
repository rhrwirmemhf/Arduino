
char ledPinD1 = 13;
char ledPinD2 = 12;
char ledPinD3 = 11;
char ledPinD4 = 10;

int KEY_ADD = A1;
int KEY_DEC = A2;

int Flag_up = 1;
int Flag_up1 = 1;

int Count =  800;

void setup()
{
	Serial.begin(9600);

	pinMode(ledPinD4, OUTPUT);
	pinMode(ledPinD3, OUTPUT);
	pinMode(ledPinD2, OUTPUT);
	pinMode(ledPinD1, OUTPUT);
        
	digitalWrite(ledPinD4, HIGH);
	digitalWrite(ledPinD3, HIGH);
	digitalWrite(ledPinD2, HIGH);
	digitalWrite(ledPinD1, HIGH);
}

void loop()
{
	if( ScanKeyUp() == 1)
	{
		switch(abs(Count%4))
		{
			case 0:
				digitalWrite(ledPinD4, HIGH);
				digitalWrite(ledPinD3, HIGH);
				digitalWrite(ledPinD2, HIGH);
				digitalWrite(ledPinD1, LOW);
				break;
			case 1:
				digitalWrite(ledPinD4, HIGH);
				digitalWrite(ledPinD3, HIGH);
				digitalWrite(ledPinD2, LOW);
				digitalWrite(ledPinD1, HIGH);
				break;
			case 2:
				digitalWrite(ledPinD4, HIGH);
				digitalWrite(ledPinD3, LOW);
				digitalWrite(ledPinD2, HIGH);
				digitalWrite(ledPinD1, HIGH);
				break;
			case 3:
				digitalWrite(ledPinD4, LOW);
				digitalWrite(ledPinD3, HIGH);
				digitalWrite(ledPinD2, HIGH);
				digitalWrite(ledPinD1, HIGH);
				break;
		}    
		Count++;
	}
   
	if( ScanKeyDown() == 1)
	{
		Count--;
	
		switch(abs(Count%4))
		{
			case 0:
				digitalWrite(ledPinD4, LOW);
				digitalWrite(ledPinD3, HIGH);
				digitalWrite(ledPinD2, HIGH);
				digitalWrite(ledPinD1, HIGH);
				break;
			case 1:
				digitalWrite(ledPinD4, HIGH);
				digitalWrite(ledPinD3, HIGH);
				digitalWrite(ledPinD2, HIGH);
				digitalWrite(ledPinD1, LOW);
				break;
			case 2:
				digitalWrite(ledPinD4, HIGH);
				digitalWrite(ledPinD3, HIGH);
				digitalWrite(ledPinD2, LOW);
				digitalWrite(ledPinD1, HIGH);
				break;
			case 3:
				digitalWrite(ledPinD4, HIGH);
				digitalWrite(ledPinD3, LOW);
				digitalWrite(ledPinD2, HIGH);
				digitalWrite(ledPinD1, HIGH);
				break;
		}    
	}
}


unsigned char ScanKeyDown()
{
	if(Flag_up && digitalRead(KEY_ADD) == LOW)
	{
		Flag_up = 0;

		if(digitalRead(KEY_ADD) == LOW)
		{
		  return 1;
		}
	}
	
	if(digitalRead(KEY_ADD) == HIGH)
	{
		Flag_up = 1;
	}
	
	return 0;
}

unsigned char ScanKeyUp()
{
	if(Flag_up1 && digitalRead(KEY_DEC) == LOW)
	{
		Flag_up1 = 0;

		if(digitalRead(KEY_DEC) == LOW)
		{
		  return 1;
		}
	}
	
	if(digitalRead(KEY_DEC) == HIGH)
	{
		Flag_up1 = 1;
	}
	
	return 0;
}
