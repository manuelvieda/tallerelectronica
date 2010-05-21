/**
 * -------------------------------------------------------------------
 * Copyright (c) 2010 - Todos los derechos reservados
 * Manuel Eduardo Vieda Salomon <me.vieda372@gmail.com
 * Ingeniero Electronico, Ingeniero de Sistemas y Computacion
 * Universidad de los Andes. Bogota, Colombia.
 * -------------------------------------------------------------------
 *
 * Archivo:				USART.h
 * Fecha Creacion:		Mayo  15 de 2010
 * Fecha Modificacion:	Mayo  18 de 2010
 * Version (Revision):	0.1 (2)
 *
 * Descripcion:	Libreria que facilita el uso del modulo de comunicación
 *              asincrona y asincrona de los microcontroladores ATmega
 *
 *
 * --------------------------------------------------------------------
 * LICENCIA:
 * 
 * Se encuentra totalmente permitido el uso y distribucion en forma de codigo y
 * binario bajo la condicion de cumplir con las siguientes condiciones de uso:
 *
 *   - Toda redistribucion del codigo fuente debe mantener sin ningun cambio la
 *     presente notificacion de copyright, la lista de condiciones y la descripcion
 *     del archivo.
 *
 *   - Ni el nombre del poseedor del presente copyright o el nombre
 *     de cualquier colaborador puede ser usado para la promocion de productos
 *     derivados de este programa/codigo sin una autorizacion escrita y especifica
 *     por parte del autor.
 *
 *   - Si considera que este contenido le ha sido bastante util, puedes invitarme
 *     a una ronda de cervezas. (The Beer-Ware License, Revision 42)
 * ---------------------------------------------------------------------
 */


#ifndef _USART_H_
#define _USART_H_

//-------------------------------------------------------------------------------
//  PARAMAETROS DE CONFIGURACION QUE PUEDEN SER MODIFICADOS POR EL USUARIO
//-------------------------------------------------------------------------------

/**
 *  Tasa de transmision en Baudios
 */
#define BAUDRATE 9600

/**
 * ASY_SYN=1  Selecciona el modo de operacion asincrono de la USART
 * ASY_SYN=0  Selecciona el modo de operacion sincrono de la USART
 */
#define ASY_SYN 1


/**
 * INT_TX_COMPLETA=1  Se genera una interrupcion(Si estan habilitadas globalmente) cuando
 *                    se completa la transmisión de lo que se encuentra en el registro de salida
 * ITN_TX_COMPLETA=0  No se genera la interrupcion
 */
#define INT_TX_COMPLETA 1

/**
 * INT_RX_COMPLETA=1  Se genera una interrupcion(Si estan habilitadas globalmente) cuando
 *                    se completa la recepcion de un dato en la USART
 * INT_RX_COMPLETA=0  No se genera la interrupcion
 */
#define INT_RX_COMPLETA 0

/**
 * SPEED_2X=1  Se habilita el doble de velocidad de transmision si se esta trabajanod en modo
 *             asincrono. Tener en cuenta que se realizaran menos muestro, por lo que solo debe
 *             activarse con un BAUDRATE adecuado y en medios de bajo ruido.
 * SPEED_2X=0  Velocidad de transmision normal
 */
#define SPEED_2X 0

/**
 * CONTROL_PARIEDAD=0  No se realiza ningun tipo de control de pariedad en la informacion transmitida
 * CONTROL_PARIEDAD=1  Se genera automaticamente un bit de pariedad PAR al enviar un dato y el
 *                     receptor se encarga de comprobarlo. Esta dato se revisa manualmente.
 * CONTROL_PARIEDAD=2  Se genera automaticamente un bit de pariedad IMPAR al enviar un dato y el
 *                     receptor se encarga de comprobarlo. Esta dato se revisa manualmente.
 */
#define CONTROL_PARIEDAD 1

/**
 * Se define el numero de bits de STOP que se envia en cada comunicacion. Puede tomar el valor de 1 o 2
 */
#define NUM_STOP 1


//-------------------------------------------------------------------------------
//  FUNCIONES OFRECIDAS QUE PUEDEN SER LLAMADAS POR EL USUARIO
//-------------------------------------------------------------------------------

/**
 * Se define el valor del registro que controla la tasa de transimision en baudios
 */
#define UBRRVAL ((F_CPU/(BAUDRATE*16UL))-1)


/**
 * USAR_init
 * Este metodo se encarga de realizar la unicializacion del modulo USART que entra por
 * parametro y en el modo selecccionado (Sincrono o asincrono), configurando la velocidad
 * y demás parámetros con la definicion de las constantes en el archivo de definiciones
 *
 * @PARAMS: uint8_t puerto -> Numero del modulo Usart (Generalmente 0 o 1)
 *          uint8_t as     -> Establece el modulo Sincrono o Asincrono
 * @PRE:    Los parametros se encuentran bien definidos
 * @POST:   Se inicializa el puerto USART seleccionado en el modo seleccionado, quedando
 *          listo para enviar y recibir datos.
 * @RETURN: Void
 */
void USART_init(uint8_t puerto, uint8_t as);

#endif /* _USART_H */
