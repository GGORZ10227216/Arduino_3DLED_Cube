#define SHCP 3
#define STCP 2
#define selectA 4
#define selectB 5
#define selectC 6

// clockPin == SHCP, latchPin == STCP !!
/*
  How to connect LEDCube and controller :
       #1  #2  #3  #4  #5  #6  #7  #8
  595A 1-1 1-2 1-3 1-4 1-5 1-6 1-7 1-8 
  595B 2-1 2-2 2-3 2-4 2-5 2-6 2-7 2-8 
  595C 3-1 3-2 3-3 4-4 4-5 4-6 4-7 4-8 
  595D 4-1 4-2 4-3 4-4 4-5 4-6 4-7 4-8 
  595E 5-1 5-2 5-3 5-4 5-5 5-6 5-7 5-8 
  595F 6-1 6-2 6-3 6-4 6-5 6-6 6-7 6-8 
  595G 7-1 7-2 7-3 7-4 7-5 7-6 7-7 7-8 
  595H 8-1 8-2 8-3 8-4 8-5 8-6 8-7 8-8 
*/
uint8_t LEDConNum = 8 ; // 8 "74HC595N" for 64 LED
uint8_t dataPins[ 8 ] = { 39, 41, 43, 45, 47, 49, 51, 53 } ;
byte img_HEART[ 8 ] = {B00010000,
B00101000,
B00010010,
B00010101,
B00010010,
B01101010,
B10100100,
B01000000} ;

byte img_BLANK[ 8 ] = { B00000000,
                   B00000000,
                   B00000000,
                   B00000000,
                   B00000000,
                   B00000000,
                   B00000000,
                   B00000000 } ;

byte font_C[ 8 ] = {B00111100,
B01100010,
B11000001,
B10000000,
B10000000,
B11000001,
B01100010,
B00111100} ;

byte font_Y[ 8 ] = {B11000011,
B11000011,
B11000011,
B01100110,
B00111100,
B00011000,
B00011000,
B00011000} ;

byte font_A[ 8 ] = {B00011000,
B00111100,
B00100100,
B00100100,
B01111110,
B01111110,
B11000011,
B11000011} ;

byte font_U[ 8 ] = {B11000011,
B11000011,
B11000011,
B11000011,
B11000011,
B11000011,
B01111110,
B00111100} ;

byte font_T[ 8 ] = {B11111111,
B11111111,
B00011000,
B00011000,
B00011000,
B00011000,
B00011000,
B00011000} ;

byte font_O[ 8 ] = {B00111100,
B01100110,
B11000011,
B10000001,
B10000001,
B11000011,
B01100110,
B00111100} ;

byte font_N[ 8 ] = {B11000011,
B11100011,
B11110011,
B11011011,
B11011111,
B11001111,
B11000111,
B11000011} ;

byte font_R[ 8 ] = {B11111110,
B11000011,
B11000011,
B11000011,
B11111110,
B11001100,
B11000110,
B11000011} ;

byte font_L[ 8 ] = {B11000000,
B11000000,
B11000000,
B11000000,
B11000000,
B11000000,
B11111111,
B11111111} ;

byte img_FILL[ 8 ] = { B11111111,
                   B11111111,
                   B11111111,
                   B11111111,
                   B11111111,
                   B11111111,
                   B11111111,
                   B11111111 } ;

byte img_TEST[ 8 ] = { B01010101,
                   B01010101,
                   B01010101,
                   B01010101,
                   B01010101,
                   B01010101,
                   B01010101,
                   B01010101 } ;

byte img_TEST2[ 8 ] = { B01010101,
                   B10101010,
                   B01010101,
                   B10101010,
                   B01010101,
                   B10101010,
                   B01010101,
                   B10101010 } ;

byte img_TEST3[ 8 ] = { B00001111,
                   B11110000,
                   B00001111,
                   B11110000,
                   B00001111,
                   B11110000,
                   B00001111,
                   B11110000 } ;

byte img_HE[ 1 ] = { B11100110 } ;
                   
byte *img_HEART_ALL[ 8 ] = { img_HEART,
                                 img_HEART,
                                 img_HEART,
                                 img_HEART,
                                 img_HEART,
                                 img_HEART,
                                 img_HEART,
                                 img_HEART } ;
                                 								  
void shiftOutLayer( uint8_t dataPins[], uint8_t dataFormat, byte imageData[] ) {
   digitalWrite( STCP, LOW ) ;
   
   for ( uint8_t i = 0 ; i < 8 ; i ++ ) {
      for ( uint8_t j = 0 ; j < LEDConNum ; j ++ ) {
        if ( dataFormat == LSBFIRST ) 
		      digitalWrite( dataPins[ j ], ( imageData[ j ] & ( B00000001 << i ) ) ) ;
		    else
		      digitalWrite( dataPins[ j ], ( imageData[ j ] & ( B00000001 << ( 7 - i ) ) ) ) ;
      } // for j
	  
	  digitalWrite( SHCP, HIGH ) ;
	  digitalWrite( SHCP, LOW ) ;
   } // for i
   
   digitalWrite( STCP, HIGH ) ;
} // shiftOutLayer()  

void shiftOutLayer_R( uint8_t dataPin, uint8_t dataFormat, byte imageData ) {
   digitalWrite( STCP, LOW ) ;
   
   for ( uint8_t i = 0 ; i < 8 ; i ++ ) {
     if ( dataFormat == LSBFIRST ) 
       digitalWrite( dataPin, ( imageData & ( B00000001 << i ) ) ) ;
     else
       digitalWrite( dataPin, ( imageData & ( B00000001 << ( 7 - i ) ) ) ) ;
    
    digitalWrite( SHCP, HIGH ) ;
    digitalWrite( SHCP, LOW ) ;
   } // for i
   
   digitalWrite( STCP, HIGH ) ;
} // shiftOutLayer()  

void showLayer( uint8_t layerNum ) {
  for ( int i = 14 ; i <= 21 ; i ++ )
    digitalWrite( i, i != layerNum + 14 ) ;
} // showLayer()

void showALL( byte *cubeData[ 8 ], int fps ) {
  for ( int i = 0 ; i < 8 ; i ++ ) {
    shiftOutLayer( dataPins, LSBFIRST, cubeData[ i ] ) ;
    showLayer( i ) ;
  } // for
  
  delay( 1000 / fps ) ;
} // showALL()
								  
void setup() {
  for ( uint8_t i = STCP ; i <= 11 ; i ++ )
    pinMode( i, OUTPUT ) ;
  // Notice, dataPin should declare in an ARRAY!!
  for ( uint8_t k = 14 ; k <= 21 ; k ++ )
    pinMode( k, OUTPUT ) ;
  for ( uint8_t j = 0 ; j < 8 ; j ++ )
    pinMode( dataPins[ j ], OUTPUT ) ;

  for ( int i = 0 ; i < 8 ; i ++ ) {
    for ( int j = 0 ; j < 8 ; j ++ )
      shiftOutLayer_R( dataPins[ i ], LSBFIRST,img_BLANK[ j ] ) ;
  } // for
} // setup()

void showFont( byte fontData[], int delayTime, int datapinNum ) {
  for ( int t = 0 ; t < delayTime ; t += 17 ) {
    for ( int i = 0 ; i < 8 ; i ++ ) {
      showLayer( i ) ;
      shiftOutLayer_R( dataPins[ datapinNum ], LSBFIRST,fontData[ i ] ) ;
      delayMicroseconds( 1500 ) ;
      shiftOutLayer_R( dataPins[ datapinNum ], LSBFIRST,img_BLANK[ i ] ) ;
      delayMicroseconds( 500 ) ;
    } // for

    delay( 1 ) ;
  } // for
} // showFont()

void loop() {
  byte *text[ 16 ] = { font_C, font_Y, font_A, font_C, img_HEART, font_A,
                       font_U, font_T, font_O, font_C, font_O, font_N, 
                       font_T, font_R, font_O, font_L } ;
  for ( int i = 0 ; i < 16 ; i ++ ) {
    for ( int j = 0 ; j < 8 ; j ++ ) {
      if ( j != 7 ) 
        showFont( text[ i ], 100, j ) ;
      else
        showFont( text[ i ], 100, j ) ;
    } // for
  } // for
} // loop()
