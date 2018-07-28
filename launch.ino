void setup(){
	Serial.begin(9600);
	pinMode(7, OUTPUT);
	digitalWrite(7, LOW);

	Serial.write("start\n\r");
}

void countdown(int count){
	for(int i=count;i>0;i--){
		Serial.write('0'+i);
		Serial.write("\n\r");
		delay(1000);
	}
	Serial.write("0\n\r");
}

void launch(){
	countdown(5);
	Serial.write("launch!\n\r");
	digitalWrite(7, HIGH);
}

void loop(){
	int input = Serial.read();
	if(input == -1) return;
	switch(input){
	case 'g':
		Serial.write("status: ok\n\r");
		break;
	case 'l':
		launch();
		break;
	case 's':
		digitalWrite(7, LOW);
	default:
		break;
	}
}
