/*
 * z_STM32L_Internal_EEprom.c
 *
 *  Created on: May 16, 2024
 *      Author: mauro
 */


#include "main.h"




void STM32L_EraseEeprom(uint32_t Cmd, uint32_t address) {
	  FLASH_WaitForLastOperation(FLASH_TIMEOUT_VALUE);
	  HAL_FLASHEx_DATAEEPROM_Erase(Cmd, address);
}

void STM32L_ProgramEeprom(uint32_t Cmd, uint32_t address, uint32_t value) {
	  FLASH_WaitForLastOperation(FLASH_TIMEOUT_VALUE);
	  HAL_FLASHEx_DATAEEPROM_Program(Cmd, address, value);
}


void STM32L_LockEeprom() {
    FLASH_WaitForLastOperation(FLASH_TIMEOUT_VALUE);
	HAL_FLASHEx_DATAEEPROM_Lock();
}


void STM32L_UnlockEeprom() {
	  FLASH_WaitForLastOperation(FLASH_TIMEOUT_VALUE);
	  HAL_FLASHEx_DATAEEPROM_Unlock();
}


