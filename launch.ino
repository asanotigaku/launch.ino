// ピンの役割
#define PIN_LED		13	// LED
#define PIN_RELAY	11	// イグナイタ点火用のリレー
#define COUNT		60	// カウントダウン秒数
#define TIMEOUT		60	// タイムアウト

// 指定秒カウントしつつシリアルモニタに数値を送信
void countdown(int);
// イグナイタ点火・打ち上げ
void launch();
// ストップ
void stop();

void setup(){
	// 初期化
	Serial.begin(9600);
	pinMode(PIN_LED, OUTPUT);
	pinMode(PIN_RELAY, OUTPUT);
	digitalWrite(PIN_LED, LOW);
	digitalWrite(PIN_RELAY, LOW);

	// どうせ一度しかやらないのでここでやってしまう
	countdown(COUNT);
	launch();

	// さすがに点火できている or 失敗している
	delay(TIMEOUT * 1000);
	stop();
}

void loop(){
	int input = Serial.read();
	if(input == -1) return;
	switch(input){
	case 'g':
		Serial.println("status: ok");
		break;
	case 'l':
		launch();
		break;
	case 's':
		stop();
		break;
	default:
		break;
	}
}

void countdown(int count){
	for(;count!=0;count--){
		if(count%2) digitalWrite(PIN_LED, HIGH);
		else digitalWrite(PIN_LED, LOW);
		Serial.println(String(count));
		delay(1000);
	}
}

void launch(){
	Serial.println("launch!");
	digitalWrite(PIN_RELAY, HIGH);
	digitalWrite(PIN_LED, HIGH);
}

void stop(){
	Serial.println("stop");
	digitalWrite(PIN_RELAY, LOW);
	digitalWrite(PIN_LED, LOW);
}
