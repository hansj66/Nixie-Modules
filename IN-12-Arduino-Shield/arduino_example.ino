int SRCLK_Pin = 0; // SRCLK
int RCLK_Pin = 1; // RCLK
int SER_Pin = 2; // SER


#define shift_registers 2 
#define numOfRegisterPins shift_registers * 8

boolean registers[numOfRegisterPins];

// K155ID1      // 74HC595
// D C B A      A B C D 
// 0 0 0 0  0   0 0 0 0
// 0 0 0 1  1   1 0 0 0
// 0 0 1 0  2   0 1 0 0
// 0 0 1 1  3   1 1 0 0
// 0 1 0 0  4   0 0 1 0
// 0 1 0 1  5   1 0 1 0
// 0 1 1 0  6   0 1 1 0
// 0 1 1 1  7   1 1 1 0
// 1 0 0 0  8   0 0 0 1
// 1 0 0 1  9   1 0 0 1

byte leds = 0;

boolean digits[10][16] = {
0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, // 0 
1,0,0,0, 1,0,0,0, 1,0,0,0, 1,0,0,0, // 1
0,1,0,0, 0,1,0,0, 0,1,0,0, 0,1,0,0, // 2 
1,1,0,0, 1,1,0,0, 1,1,0,0, 1,1,0,0, // 3 
0,0,1,0, 0,0,1,0, 0,0,1,0, 0,0,1,0, // 4 
1,0,1,0, 1,0,1,0, 1,0,1,0, 1,0,1,0, // 5
0,1,1,0, 0,1,1,0, 0,1,1,0, 0,1,1,0, // 6
1,1,1,0, 1,1,1,0, 1,1,1,0, 1,1,1,0, // 7 
0,0,0,1, 0,0,0,1, 0,0,0,1, 0,0,0,1, // 8
1,0,0,1, 1,0,0,1, 1,0,0,1, 1,0,0,1, // 9
};

boolean banner[11][16] = {
0,0,0,0, 1,0,0,0, 0,1,0,0, 1,1,0,0,
1,0,0,0, 0,1,0,0, 1,1,0,0, 0,0,1,0, 
0,1,0,0, 1,1,0,0, 0,0,1,0, 1,0,1,0, 
1,1,0,0, 0,0,1,0, 1,0,1,0, 0,1,1,0,
0,0,1,0, 1,0,1,0, 0,1,1,0, 1,1,1,0, 
1,0,1,0, 0,1,1,0, 1,1,1,0, 0,0,0,1,
0,1,1,0, 1,1,1,0, 0,0,0,1, 1,0,0,1, 
1,1,1,0, 0,0,0,1, 1,0,0,1, 0,0,0,0, 
0,0,0,1, 1,0,0,1, 0,0,0,0, 0,0,0,0, 
1,0,0,1, 0,0,0,0, 0,0,0,0, 0,0,0,0,  
0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,
};

void setup() 
{
  pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);
}


//set all register pins to LOW
void clearRegisters(){
  for(int i = numOfRegisterPins - 1; i >=  0; i--)
  {
     registers[i] = LOW;
  }
} 

//Set and display registers
void writeRegisters(){

  digitalWrite(RCLK_Pin, LOW);

  for(int i = numOfRegisterPins - 1; i >=  0; i--)
  {
    digitalWrite(SRCLK_Pin, LOW);
    bool val = registers[i];
    digitalWrite(SER_Pin, val);
    digitalWrite(SRCLK_Pin, HIGH);
  }
  digitalWrite(RCLK_Pin, HIGH);
}

//set an individual pin HIGH or LOW
void setRegisterPin(int index, int value)
{
  registers[index] = value;
}


void loop()
{

  for (int d=0; d<10; d++) 
  {
    for (int i=15; i>=0; i--)
    {
      if (digits[d][i] == 1) {
        setRegisterPin(i, HIGH);
      } else {
        setRegisterPin(i, LOW);
      }
    }
    writeRegisters(); 
    delay (500);
  }

  for (int d=0; d<11; d++) 
  {
    for (int i=15; i>=0; i--)
    {
      if (banner[d][i] == 1) {
        setRegisterPin(i, HIGH);
      } else {
        setRegisterPin(i, LOW);
      }
    }
    writeRegisters(); 
    delay (500);
  }

}


