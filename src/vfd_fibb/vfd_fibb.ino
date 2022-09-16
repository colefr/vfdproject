/* vfd_fibb.ino
 *  Displays the fibbonacci sequency over 4 digits on the VFD display.
 *  Cole Frauzel
 *  August 2022
 */

/* Pin numbers */
#define SDA 6
#define SCK 8
#define SRL 7

/* These values correspond to bits on or off for each segment of a digit
 *  7 segments + a dot. The table was precalculated, see "segment_bits.pdf"
 */
byte digits[10] = {0xb7, 0xa0, 0x3b, 0xb9, 0xac, 0x9d, 0x9f, 0xb0, 0xbf, 0xbd};
byte F = 0x1e;
byte eq = 0x09;

byte digit_arr[4] = {};

void setup() {
  pinMode(SDA, OUTPUT);
  pinMode(SCK, OUTPUT);
  pinMode(SRL, OUTPUT);
}

void int_to_digits(int n){
  int x = 0;
  int nn = n;

/* The int value is split up into individual digits. */
  if(n < 10000) {
    x = n / 1000;
    digit_arr[3] = digits[x];
    n = n - (1000 * x);
  
    x = n / 100;
    digit_arr[2] = digits[x];
    n = n - (100 * x);
  
    x = n / 10;
    digit_arr[1] = digits[x];
    n = n - (10 * x);
  
    digit_arr[0] = digits[n];

    /* Pad the leftmost digits with zeros */
    if(nn<1000) digit_arr[3] = 0x00;
    if(nn<100 ) digit_arr[2] = 0x00;
    if(nn<10  ) digit_arr[1] = 0x00;
  }  
}

void output_digits() {
  digitalWrite(SRL, LOW);
  for(byte i=0; i<4; i++){    
    shiftOut(SDA, SCK, LSBFIRST, digit_arr[i]);    
  }
  digitalWrite(SRL, HIGH);
}

void loop() {
  int a = 0;
  int b = 1;
  int c = 0;
  int f = 0;

  while(c < 10000) {
    /* The fibbonacci calculation */
    c = a + b;
    a = b;
    b = c;
    f++;

    if(c > 10000) break;

    /* This flashes an "F=NN" where NN is the index of the
     *  fibb' sequence. It's multiplied by 10 as an easy
     *  way to bump it over a digit to the right.
     */
    int_to_digits(f * 10);
    digit_arr[3] = F;
    digit_arr[0] = eq;
    output_digits();
    delay(500);

    int_to_digits(c);
    output_digits();
    delay(750);    
  }

  int_to_digits(0);
  digit_arr[0] = 0x00;
  output_digits();
  delay(1000);
}
