#include "Usart.h"

void setup() {
  // start communication at a baud rate of 115200
  USART.begin( 115200);   
}

void loop() {
  // write some data
  USART.write( "Hello I am here, now send me the data!");
  
  // some delay waiting for data/response
  _delay_ms( 25);
  
  // read the response data
  while ( USART.available() > 0 ) {
    // here do something with the received data...
  }
}
