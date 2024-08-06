const int len = 60;
char my_str[len];
int  pos = 0;
int incomingByte=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  pinMode(13,OUTPUT);

}

void loop() {

}
void serialEvent(){
  output();
}
void output(){
  if (Serial.available()>0){
    incomingByte = Serial.read();
    my_str[pos]=incomingByte;
    pos++;
}
if(incomingByte==10){
  pos=0;
}
if(my_str[0]=='t'){
  Serial.print("t,HIGH,\n");
  digitalWrite(13, HIGH);
}
else{
  digitalWrite(13, LOW);
  Serial.print("not t, LOW,\n");
}
Serial.print(my_str);
for(int i =0; i<=len-1;i++){
  my_str[i] = 0;
}
}

