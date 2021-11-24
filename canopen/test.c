#include "canopen.h"
#include <stdint.h>
#include <stdio.h>

int main(void) {
  uint8_t c5e_id = 0x70;
  uint32_t id = 0;
  uint8_t data[8] = {0};
  sdo_read(c5e_id, 0x6041, 0x00, &id, data);
  printf("id: %X\n", id);
  printf("data: ");
  for (int i = 0; i < 8; i++) {
    printf(" %X", data[i]);
  }
  printf("\n");

  uint16_t yeet = 0x1F4;
  sdo_write(c5e_id, 0x1017, 0x00, &yeet, 2, &id, data);
  printf("id: %X\n", id);
  printf("data: ");
  for (int i = 0; i < 8; i++) {
    printf(" %X", data[i]);
  }
  printf("\n");
  return 0;
}