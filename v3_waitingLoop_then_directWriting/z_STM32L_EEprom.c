/*
 * z_STM32L_Internal_EEprom.c
 *
 *  Created on: May 16, 2024
 *      Author: mauro
 */


#include "main.h"



void STM32L_WaitForWritingComplete() {
	uint32_t temp;

	while (READ_BIT(FLASH->SR, FLASH_SR_BSY)) {}
}






void STM32L_EraseEeprom(uint32_t Cmd, uint32_t address) {
	uint32_t temp;


	STM32L_WaitForWritingComplete();

	switch (Cmd) {
	case FLASH_TYPEERASEDATA_BYTE:
		*(uint8_t*)address = 0;
		break;
	case FLASH_TYPEERASEDATA_HALFWORD:
		*(uint16_t*)address = 0;
		break;
	case FLASH_TYPEERASEDATA_WORD:
		*(uint32_t*)address = 0;
		break;
	}
}




void STM32L_ProgramEeprom(uint32_t Cmd, uint32_t address, uint32_t value) {
	uint32_t temp;

	STM32L_WaitForWritingComplete();

	switch (Cmd) {
	case FLASH_TYPEPROGRAMDATA_FASTBYTE:
	case FLASH_TYPEPROGRAMDATA_FASTHALFWORD:
	case FLASH_TYPEPROGRAMDATA_FASTWORD:
	    CLEAR_BIT(FLASH->PECR, FLASH_PECR_FTDW);
		break;
	default:
	    SET_BIT(FLASH->PECR, FLASH_PECR_FTDW);
		break;
	}

	switch (Cmd) {
	case FLASH_TYPEPROGRAMDATA_BYTE:
	case FLASH_TYPEPROGRAMDATA_FASTBYTE:
		*(uint8_t*)address = (uint8_t) value;
		break;
	case FLASH_TYPEPROGRAMDATA_HALFWORD:
	case FLASH_TYPEPROGRAMDATA_FASTHALFWORD:
		*(uint16_t*)address = (uint16_t) value;
		break;
	case FLASH_TYPEPROGRAMDATA_WORD:
	case FLASH_TYPEPROGRAMDATA_FASTWORD:
		*(uint32_t*)address = value;
		break;
	}
}





void STM32L_LockEeprom() {
	uint32_t temp;
	STM32L_WaitForWritingComplete();
	HAL_FLASHEx_DATAEEPROM_Lock();
}


void STM32L_UnlockEeprom() {
	uint32_t temp;
	STM32L_WaitForWritingComplete();
	HAL_FLASHEx_DATAEEPROM_Unlock();
}



