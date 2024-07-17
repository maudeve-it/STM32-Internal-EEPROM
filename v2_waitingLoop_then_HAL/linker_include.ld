/* add to linker script the below lines    */
/* (for cat.5 uC like L152RE)              */


/* Memories definition */
MEMORY
{
	....
  EEPROM_B1	(rw)	: ORIGIN = 0x8080000,   LENGTH = 8K
  EEPROM_B2	(rw)	: ORIGIN = 0x8082000,   LENGTH = 8K
}


/* Sections */
SECTIONS
{
  Bank1Section :
  {
	*(Bank1Section Bank1Section.*)
	*(-gnu-linkonce.r.*)
    . = ALIGN(0x4);
  } >EEPROM_B1

  Bank2Section :
  {
	*(Bank2Section Bank2Section.*)
	*(-gnu-linkonce.r.*)
    . = ALIGN(0x4);
  } >EEPROM_B2

...
