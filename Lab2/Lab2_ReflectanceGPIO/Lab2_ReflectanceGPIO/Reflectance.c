// Reflectance.c

/*

Simplified BSD License (FreeBSD License)
Copyright (c) 2017, Jonathan Valvano, All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are
those of the authors and should not be interpreted as representing official
policies, either expressed or implied, of the FreeBSD Project.
*/

#include "msp432.h"
#include "..\inc\Clock.h"
#include <stdint.h>

#define RSLK_MAX 1

// ------------Reflectance_Init------------

void Reflectance_Init(void) {

        P5->SEL0 &= ~0x08;
        P5->SEL1 &= ~0x08;
        P5->DIR  |=  0x08;
        P5->OUT  &= ~0x08;


        P9->SEL0 &= ~0x04;
        P9->SEL1 &= ~0x04;
        P9->DIR  |=  0x04;
        P9->OUT  &= ~0x04;


        P7->SEL0 &= ~0xFF;
        P7->SEL1 &= ~0xFF;
        P7->DIR  &= ~0xFF;
}

// ------------Reflectance_Read------------

uint8_t Reflectance_Read(uint32_t time) {
  uint8_t result;
  Reflectance_Start();
  Clock_Delay1us(time);
  result = Reflectance_End();


  return result;
}

// ------------Reflectance_Center------------

uint8_t Reflectance_Center(uint32_t time) {
  uint8_t result;
  
  result = Reflectance_Read(time) & 0x18;


  return result;
}

// Input: data is 8-bit result from line sensor
// Output: position in 0.1mm relative to center of line
  int32_t Reflectance_Position(uint8_t data) {
  int32_t position = 0;
  int32_t sum = 0;
  int32_t count = 0;

  int32_t W[8] = {334, 238, 143, 48, -48, -143, -238, -334};

  for (int i = 0; i < 8; i++) {
          if (data & (1 << i)) {
              sum += W[i];
              count++;
          }
      }


      if (count > 0) {
          position = sum / count;
      } else {
          position = 0;
      }
  return position;
}

// ------------Reflectance_Start------------
// Begin the process of reading the eight sensors

void Reflectance_Start(void) {


        P5->OUT |= 0x08;
        P9->OUT |= 0x04;


        P7->DIR |= 0xFF;
        P7->OUT |= 0xFF;


        Clock_Delay1us(10);


        P7->DIR &= ~0xFF;



  
}

// ------------Reflectance_End------------
// Finish reading the eight sensors

uint8_t Reflectance_End(void) {
  uint8_t result;


      result = P7->IN;


      P5->OUT &= ~0x08;
      P9->OUT &= ~0x04;
  
  
  return result;
}
